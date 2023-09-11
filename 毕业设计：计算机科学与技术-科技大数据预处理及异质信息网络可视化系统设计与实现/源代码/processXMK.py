import json
import pandas as pd
import numpy as np
import re



import pymysql

# 创建数据库连接
conn = pymysql.connect(
    host='127.0.0.1',  # 连接主机, 默认127.0.0.1
    user='root',  # 用户名
    passwd='281227',  # 密码
    port=3306,  # 端口，默认为3306
    db='professional',  # 数据库名称
    charset='utf8'  # 字符编码
)
cursor = conn.cursor()
# data = pd.read_csv("data-main/ZJK_LWK改.csv", "r", encoding="gbk",names=['LY','ND','TM','DYZZ','TXZZ','QBZZ','CBS','NFJM','FBSJ'], lineterminator ='\n' )
data = pd.read_excel('data-main/ZJK_XMK改.xlsx', header=0)
def sqlgenerate(table, title, data):
    sql = "replace  into " + str(table) + " ("

    for index, t in enumerate(title):
        if index < len(title) - 1:
            sql = sql + str(t) + ','
        else:
            sql = sql + str(t)
    sql = sql + ') VALUES ('
    for index, d in enumerate(data):
        if index < len(data) - 1:
            sql = sql + "'" + str(d).replace("'",'').replace("Timestamp(",'').replace(")",'') + "',"
        else:
            sql = sql + "'" + str(d).replace("'",'').replace("Timestamp(",'').replace(")",'') + "'"
    sql = sql + ')'
    return sql

# datalist=list(data)
print(type(data))


title=['XMMC','FZR','DWMC','XMJJ','XMJB','ND']
for i in data.values:


    value =i
    # print(value)
    # a
    sql = sqlgenerate('app_XMK', title, value)
    print(sql)
    print()
    cursor.execute(sql)
    conn.commit()

cursor.close()  # 关闭游标
conn.close()  # 关闭连接
