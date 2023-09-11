import os
os.environ['KMP_DUPLICATE_LIB_OK'] = 'TRUE'
import dgl
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

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

# 输出图的信息
print("DGL图信息：")
print(g)
print("节点数量：")
print(g.number_of_nodes())
print("边数量：")
print(g.number_of_edges())

# 转换为同构图
g_hom = dgl.to_homogeneous(g)
print("转换为同构图")
print("同构图信息：")
print(g_hom)
print("节点数量：")
print(g_hom.num_nodes())
print("边数量：")
print(g_hom.num_edges())

# 创建networkx图
nx_G = g_hom.to_networkx()
print("创建networkx图")

# 设置节点颜色和标签
colors = ['#FF5733', '#9B59B6', '#F7DC6F', '#3498DB']
node_colors = [colors[i%4] for i in range(g_hom.number_of_nodes())]
node_labels = dict(zip(range(g_hom.number_of_nodes()), xm_list))

# 使用Kamada-Kawai布局算法将节点分布在更合适的位置上
pos = nx.kamada_kawai_layout(nx_G)
#绘制节点和边
nx.draw(nx_G, pos=pos, node_color=node_colors, node_size=500, with_labels=True, labels=node_labels, font_size=12, font_weight='bold')
nx.draw_networkx_edge_labels(nx_G, pos=pos, font_size=10, font_color='gray')

#设置图例
person_label = plt.Line2D([], [], color='#FF5733', marker='o', linestyle='None',
markersize=10, label='Person')
sxzy_label = plt.Line2D([], [], color='#9B59B6', marker='o', linestyle='None',
markersize=10, label='SXZY')
hdhd_label = plt.Line2D([], [], color='#F7DC6F', marker='o', linestyle='None',
markersize=10, label='HDHD')
csd_label = plt.Line2D([], [], color='#3498DB', marker='o', linestyle='None',
markersize=10, label='CSD')

#显示图例
plt.legend(handles=[person_label, sxzy_label, hdhd_label, csd_label], loc='best')

#dpi设置清晰度、bbox_inches='tight'保证图片能被完整保存
plt.savefig("C:/Users/cjz/Desktop/professional/DGL/data/networkx.png", dpi=1000, bbox_inches='tight')
plt.show()