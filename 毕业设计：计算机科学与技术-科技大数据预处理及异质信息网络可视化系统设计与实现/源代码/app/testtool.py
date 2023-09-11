import re
from collections import Counter

import pymysql

conn = pymysql.connect(
    host='127.0.0.1',
    user='root',
    passwd='281227',
    port=3306,
    db='professional',
    charset='utf8'
)
cursor = conn.cursor()
sql = "SELECT * FROM app_json01 where company_name like '%点掌%' limit 1"
cursor.execute(sql)
resultst = cursor.fetchall()
print("@@@@@")
# print(resultst)
unified_code=resultst[0][19]
company_name=resultst[0][1]
legal_person=resultst[0][3]
reg_capital=resultst[0][4]
start_date=resultst[0][2]
org_no=resultst[0][8]
license_number=resultst[0][20]
tax_no=resultst[0][9]
ent_type=resultst[0][11]
open_time=resultst[0][13]
open_status=resultst[0][17]
district=resultst[0][5]
reg_addr=resultst[0][6]
authority=resultst[0][14]
industry=resultst[0][12]
scope=resultst[0][7]
print(unified_code)
