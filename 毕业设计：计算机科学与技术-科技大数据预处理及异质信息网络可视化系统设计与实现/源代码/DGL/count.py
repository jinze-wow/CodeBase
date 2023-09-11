# -*- coding: utf-8 -*-
import pandas as pd

# 读取csv文件
df = pd.read_csv('C:/Users/cjz/Desktop/professional/DGL/data/ZJK_ZJXX.csv', engine='python')

# 计算SXZY列有多少种不同的数据(P)
num_distinct = df['SXZY'].nunique()
print(num_distinct)
# 按照SXZY列分组，计算每个SXZY值出现的次数
grouped = df.groupby('SXZY').size().reset_index(name='counts')

# 输出结果到另一个excel文件
grouped.to_excel('C:/Users/cjz/Desktop/python/data/output.xlsx', index=False)
