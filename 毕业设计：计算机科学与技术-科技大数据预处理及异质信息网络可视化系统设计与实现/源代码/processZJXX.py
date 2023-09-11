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
data = pd.read_excel('data-main/ZJK_ZJXX改.xlsx', header=0)


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

title = ['XM', 'XB', 'CSRQ', 'ZJBH', 'CSD', 'MZ', 'DP', 'SFDM', 'TJDWID', 'ZW', 'ISYS', 'SHJZ', 'WHCD', 'ZGXW', 'HDHD',
         'SXZY', 'CSZY', 'YJLY', 'GZDWID', 'TXDZ', 'DWYZBM', 'DZYX', 'GZDWDH', 'JTZZ', 'ZZDH', 'ZZYB', 'CZH', 'YDDH',
         'MSM', 'MSDZYX', 'MSDH', 'SXXK1', 'SXXK2', 'SXXK3', 'SXXK4', 'SXXK5', 'XSBJ', 'XSCJ', 'LWLZ', 'KL', 'ZJEJGZDW',
         'ISTIJ', 'ISSH', 'ISTUIJ', 'SHBZ', 'TUIJBZ', 'ZJCZBZ', 'ZJLX', 'SHSJ', 'TUIJSJ', 'TIJSJ', 'ISBODAO', 'ZSH',
         'DRSJ', 'ISSELF', 'ZJDJ', 'ZC', 'DLSJ', 'BYYX', 'FYDDH', 'ZJYHM', 'JTYYXK2', 'JTYYXK3', 'SXYYXK2', 'SXYYXK3',
         'JTJCXK2', 'JTJCXK3', 'SXJCXK2', 'SXJCXK3', 'GZDWLX', 'ND', 'GZDWLXZZ', 'DXSFZT', 'JSJB', 'DXYZM', 'DXCS',
         'DXSJ', 'JSLY2', 'JSLY1', 'TCYY', 'TCSJ', 'GJZ', 'ZJLB', 'ZJGJ', 'CJSWPS', 'KHYH', 'YHKH']
for i in data.values:
    value = i
    sql = sqlgenerate('app_ZJXX', title, value)
    # print(sql)
    cursor.execute(sql)
    conn.commit()

cursor.close()  # 关闭游标
conn.close()  # 关闭连接
