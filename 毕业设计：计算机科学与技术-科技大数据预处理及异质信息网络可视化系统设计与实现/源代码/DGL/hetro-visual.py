import os
os.environ['KMP_DUPLICATE_LIB_OK'] = 'TRUE'
import dgl
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

"""
生成pos，用来配置layout，其格式为{0: [-0.95, -0.8],1: [-0.95, -0.48]}
"""


def gen_pos(node_type_num, node_num_array):
    step = round(1.6 / (node_type_num - 1), 2)
    xs = []
    for i in range(node_type_num):
        xs.append(round(-0.95 + i * step, 2))

    ys = []
    for node_num in node_num_array:
        cstep = round(1.6 / (node_num - 1), 2)
        result = []
        for j in range(node_num):
            result.append(round(-0.8 + j * cstep, 2))
        ys.append(result)

        # construct pos
    pos = []
    for aa, bb in zip(xs, ys):
        for b in bb:
            pos.append([aa, b])

    final_pos = {}
    for i, e in enumerate(pos):
        final_pos[i] = e
    return final_pos


pos = gen_pos(4, [20, 10, 10, 10])

## 创建图对象，并添加节点，添加边
GG2 = nx.DiGraph()
# add nodes
GG2.add_nodes_from([0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49])

# add edges
res1 = [(0, 25), (1, 28),(2, 27),(3, 21),(4, 26),(5, 24),(6, 28),(7, 27),(8, 24),(9, 25),(10, 24),(11, 26),(12, 22),(13, 26),(14, 28),(15, 24),(16, 27),(17, 28),(18, 22),(19, 26)]
res2 = [(0, 30), (1, 30),(2, 34),(3, 32),(4, 31),(5, 32),(6, 39),(7, 38),(8, 32),(9, 33),(10, 30),(11, 39),(12, 30),(13, 33),(14, 33),(15, 36),(16, 37),(17, 35),(18, 37),(19, 32)]
res3 = [(0, 47), (1, 40),(3, 47),(3, 45),(4, 48),(5, 43),(6, 45),(7, 44),(8, 42),(9, 48),(10, 49),(11, 47),(12, 48),(13, 47),(14, 49),(15, 40),(16, 46),(17, 42),(18, 47),(19, 48)]
GG2.add_edges_from(res1)
GG2.add_edges_from(res2)
GG2.add_edges_from(res3)

# nodes, 把节点分为三个组(相当于三种类型)，每组独立编号与染色
plt.figure(figsize=(7, 5))
nx.draw_networkx_nodes(GG2, pos, nodelist=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19], node_color="red", label="name")
nx.draw_networkx_nodes(GG2, pos, nodelist=[20,21,22,23,24,25,26,27,28,29], node_color="green", label="subject")
nx.draw_networkx_nodes(GG2, pos, nodelist=[30,31,32,33,34,35,36,37,38,39], node_color="blue", label="school")
nx.draw_networkx_nodes(GG2, pos, nodelist=[40,41,42,43,44,45,46,47,48,49], node_color="yellow", label="city")

# edges，把边分为两个组(相当于两种边类型)，每组独立设置样式
nx.draw_networkx_edges(GG2, pos,edge_color="black", edgelist=res1, width=1, label="major")
nx.draw_networkx_edges(GG2, pos,edge_color="grey", edgelist=res2, width=1, style="-.", label="award")
nx.draw_networkx_edges(GG2, pos,edge_color="brown",edgelist=res3, width=1, style="dashed", label="born")

# node labels，每类节点从0开始编号
labels = {0: "0", 1: "1", 2: "2", 3: "3", 4: "4", 5: "5", 6:"6", 7:"7", 8:"8", 9:"9", 10:"10", 11:"11", 12:"12", 13:"13",14:"14",15:"15",16:"16",17:"17",18:"18",19:"19",
          20:"0",21:"1",22:"2",23:"3",24:"4",25:"5",26:"6",27:"7",28:"8",29:"9",
          30:"0",31:"1",32:"2",33:"3",34:"4",35:"5",36:"6",37:"7",38:"8",39:"9",
          40:"0",41:"1",42:"2",43:"3",44:"4",45:"5",46:"6",47:"7",48:"8",49:"9", }
nx.draw_networkx_labels(GG2, pos, labels, font_size=12, font_color="whitesmoke")

# legend1：渲染节点类型，labelspacing设置节点间距离(垂直方向)、borderpad设置节点与边界间距离(垂直方向)
l1 = plt.legend(bbox_to_anchor=(1, 0.85), labelspacing=1.5, borderpad=0.5)
plt.gca().add_artist(l1)  # 这条语句可使plt添加多个legend

# legend2：渲染边类型
from matplotlib.lines import Line2D

handles = [Line2D([], [], color="black", label="major", linewidth=1),
           Line2D([], [], color="grey", label="award", linewidth=1, ls="-."),
           Line2D([], [], color="brown", label="born", linewidth=1, ls="dashed")]
plt.legend(handles=handles, bbox_to_anchor=(1, 0.3))

# dpi设置清晰度、bbox_inches='tight'保证图片能被完整保存
plt.savefig("C:/Users/cjz/Desktop/professional/DGL/data\\hetero", dpi=1000, bbox_inches='tight')
