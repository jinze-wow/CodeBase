import re
from collections import Counter
import wordcloud as wc
import numpy as np
import pandas as pd
from PIL import Image
from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from matplotlib import colors, pyplot as plt


import json
import pymysql
def cloud(type):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )
    cursor = conn.cursor()


    # sql = "SELECT DWMC FROM app_zjxx "
    sql = "SELECT DWMC FROM app_XMK "

    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []

    for r in resultst:
        results.append(r[0])
    # df = pd.DataFrame(results,
    #                   columns=[])
    # words = df['commentMainTag'].values
    text = (' '.join(results)).replace('Nan','').replace('nan','')

    mask = np.array(Image.open("ciyuntu.png"))
    color_list = ['#BF212E', '#F25270', '#04C4D9', '#9EBF24', '#F28B30']
    colormap = colors.ListedColormap(color_list)
    word_cloud = wc.WordCloud(
        scale=8, font_path="msyh.ttc",
        background_color='white', random_state=10, mask=mask, prefer_horizontal=0.7
        , max_font_size=180, collocations=False, colormap=colormap)
    word_cloud.generate(text)
    plt.imshow(word_cloud)
    word_cloud.to_file("static/wordcloud_"+str(type)+".png")
    plt.axis("off")
    print(type,end='')
    print("词云绘制完成")

# cloud("zjxx")
cloud("dwmc")

