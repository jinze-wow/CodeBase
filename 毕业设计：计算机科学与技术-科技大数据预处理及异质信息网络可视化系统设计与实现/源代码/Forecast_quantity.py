import re
from collections import Counter

import pymysql


def mysave(res):
    for index, i in enumerate(res):
        sql = "replace INTO app_Forecast (id,count) VALUES ('" + str(index) + "','" + str(int(i)) + "')"
        cursor.execute(sql)
        print(sql)
        conn.commit()


conn = pymysql.connect(
    host='127.0.0.1',
    user='root',
    passwd='281227',
    port=3306,
    db='professional',
    charset='utf8'
)
cursor = conn.cursor()
sql = "SELECT * FROM app_json01 "
cursor.execute(sql)
resultst = cursor.fetchall()
start_date = []
for r in resultst:
    # print(r[2])
    if r[2] != 'None':
        start_date.append(int(re.findall(r'\b\d{4}\b', str(list(r)[2]))[0]))
fin = sorted(Counter(start_date).items())
date = []
count = []
for i in fin:
    date.append(i[0])
    count.append(int(i[1]))

train = []
test = []
all = count
for i in range(len(all)):
    if len(all) - i < 15:
        continue
    train.append(all[i:i + 10])
    test.append(all[i + 10:i + 15])
import numpy as np

from sklearn.ensemble import RandomForestClassifier

x = train
y = test
x = np.array(x)
y_train = np.array(y)
x_train = np.reshape(x, (x.shape[0], x.shape[1]))
# for i in range(10):
clf = RandomForestClassifier(n_estimators=10, max_features=3, max_depth=5,
                             oob_score=False, random_state=10, n_jobs=-1)
clf.fit(x_train, y_train)
test = [all[len(all) - 11:len(all) - 1]]
test = np.array(test)
test = np.reshape(test, (test.shape[0], test.shape[1]))
res = clf.predict(test)
print(res)
# mysave(res[0])
