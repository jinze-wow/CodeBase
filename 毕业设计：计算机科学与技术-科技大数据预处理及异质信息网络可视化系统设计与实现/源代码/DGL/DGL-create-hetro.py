import os
os.environ['KMP_DUPLICATE_LIB_OK'] = 'TRUE'
import dgl
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

# 读取CSV文件
dgl1_df = pd.read_csv('C:/Users/cjz/Desktop/professional/DGL/data/DGL1.csv')
dgl2_df = pd.read_csv('C:/Users/cjz/Desktop/professional/DGL/data/DGL2.csv')
dgl3_df = pd.read_csv('C:/Users/cjz/Desktop/professional/DGL/data/DGL3.csv')

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

