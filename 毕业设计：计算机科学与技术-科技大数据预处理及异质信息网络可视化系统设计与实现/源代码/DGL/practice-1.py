import os
os.environ['KMP_DUPLICATE_LIB_OK'] = 'TRUE'
import networkx as nx
import torch
import torch.nn as nn
import torch.nn.functional as F
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd
import dgl


# 读取CSV文件
dgl1_df = pd.read_csv('C:/Users/cjz/Desktop/professional/DGL/data/DGL-networkx1.csv')
dgl2_df = pd.read_csv('C:/Users/cjz/Desktop/professional/DGL/data/DGL-networkx2.csv')
dgl3_df = pd.read_csv('C:/Users/cjz/Desktop/professional/DGL/data/DGL-networkx3.csv')

# 将三个表按照XM整合到一起
xm_set = set(dgl1_df['XM']) | set(dgl2_df['XM']) | set(dgl3_df['XM'])
xm_dict = dict(zip(sorted(xm_set), range(len(xm_set))))
xm_list = [k for k in xm_dict.keys()]
dgl1_df['XM'] = dgl1_df['XM'].map(xm_dict)
dgl2_df['XM'] = dgl2_df['XM'].map(xm_dict)
dgl3_df['XM'] = dgl3_df['XM'].map(xm_dict)

# 创建异质图
g = dgl.heterograph({
    ('person', 'has_sxzy', 'sxzy'): (dgl1_df['XM'], dgl1_df['SXZY']),
    ('person', 'has_hdhd', 'hdhd'): (dgl2_df['XM'], dgl2_df['HDHD']),
    ('person', 'has_csd', 'csd'): (dgl3_df['XM'], dgl3_df['CSD'])
})

# 转换为同构图
g_hom = dgl.to_homogeneous(g)
print(g_hom)
print("节点数量：")
print(g_hom.num_nodes())
print("边数量：")
print(g_hom.num_edges())
# 创建networkx图
nx_G = g_hom.to_networkx().to_undirected()
pos = nx.kamada_kawai_layout(nx_G) ## 生成节点位置
nx.draw(nx_G, pos, with_labels=True, node_color=[[.7, .7, .7]])
plt.savefig("C:/Users/cjz/Desktop/python/data\\networkx2", dpi=1000, bbox_inches='tight')
plt.pause(10)


#为点分配特征
embed = nn.Embedding(53, 5)  # 53 nodes with embedding dim equal to 5
g_hom.ndata['feat'] = embed.weight


#调用GCN层
from dgl.nn.pytorch import GraphConv
class GCN(nn.Module):
    def __init__(self, in_feats, hidden_size, num_classes):
        super(GCN, self).__init__()
        self.conv1 = GraphConv(in_feats, hidden_size)
        self.conv2 = GraphConv(hidden_size, num_classes)

    def forward(self, g, inputs):
        h = self.conv1(g, inputs)
        h = torch.relu(h)
        h = self.conv2(g, h)
        return h

#第一层将大小为5的输入特征转换为隐藏大小为5的隐藏特征。
#第二层对隐层进行转换，生成的输出特征
net = GCN(5, 5, 2)
inputs = embed.weight
labeled_nodes = torch.tensor([9,47]) # 只标记个别结点
labels = torch.tensor([0,1]) # 结点不同

#训练并可视化结果
import itertools

optimizer = torch.optim.Adam(itertools.chain(net.parameters(), embed.parameters()), lr=0.01)
all_logits = []
for epoch in range(100):
    g_hom = dgl.add_self_loop(g_hom)
    logits = net(g_hom, inputs)
    # we save the logits for visualization later
    all_logits.append(logits.detach())
    logp = F.log_softmax(logits, 1)
    # we only compute loss for labeled nodes
    loss = F.nll_loss(logp[labeled_nodes], labels)

    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    print('Epoch %d | Loss: %.4f' % (epoch, loss.item()))

#可视化，用logits作为坐标，画图
def draw(i):
    cls1color = '#99CCFF'
    cls2color = '#FF6600'
    pos = {}
    colors = []
    for v in range(53):
        pos[v] = all_logits[i][v].numpy()
        cls = pos[v].argmax()
        colors.append(cls1color if cls else cls2color)
    ax.cla()
    ax.axis('off')
    ax.set_title('Epoch: %d' % i)
    nx.draw_networkx(nx_G.to_undirected(), pos, node_color=colors,
            with_labels=True, node_size=300, ax=ax)

fig = plt.figure(dpi=150)
fig.clf()
ax = fig.subplots()
draw(0)  # draw the prediction of the first epoch

ani = animation.FuncAnimation(fig, draw, frames=len(all_logits), interval=200)
ani.save('C:/Users/cjz/Desktop/python/data\\practice.gif',writer='pillow', fps=10)
plt.show()