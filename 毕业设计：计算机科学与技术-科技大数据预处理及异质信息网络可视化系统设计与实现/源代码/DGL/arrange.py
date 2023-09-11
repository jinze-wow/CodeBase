import pandas as pd

# 读取 Excel 表格
df = pd.read_excel('C:/Users/cjz/Desktop/professional/DGL/python/data/DGL.xlsx')

# 对 SXZY 列进行升序排序
df = df.sort_values('SXZY', ascending=True)

# 保存排序后的表格到新的 Excel 文件中
df.to_excel('sorted.xlsx', index=False)