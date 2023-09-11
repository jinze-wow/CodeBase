import pandas as pd

# 读取CSV文件
df = pd.read_csv('C:/Users/cjz/Desktop/professional/DGL/data/1.csv', engine='python')

# 初始化计数器和初始值
counter = 1
prev_value = df['SXZY'][0]

# 遍历每一行数据
for i, row in df.iterrows():
    # 如果当前行和前一行不同，计数器加1
    if row['SXZY'] != prev_value:
        counter += 1
    # 在SXZY列右侧添加一个名为Count1的新列，并将计数器值写入
    print(counter)
    df.loc[i, 'Count1'] = counter
    # 更新前一个值为当前值
    prev_value = row['SXZY']

# 打印结果
#print(df)