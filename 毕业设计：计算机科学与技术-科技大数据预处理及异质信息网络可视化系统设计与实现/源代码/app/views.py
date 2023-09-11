import re
from collections import Counter

import pandas as pd
from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from . import models
import json
import pymysql


# 注册
def register(request):
    error_msg = ''
    if request.method == 'POST':
        user = request.POST.get('username')
        password = request.POST.get('password')
        info = models.user.objects.filter(username=user, )
        if info:
            error_msg = '用户名已经存在了'
        else:
            p = models.user.objects.create(username=user,
                                           password=password,
                                           )
            p.save()
            error_msg = '注册成功'
    return render(request, 'register.html', {'error_msg': error_msg})


def login(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )
    cursor = conn.cursor()
    error_msg = ''
    print('!!!!!')
    print(request.POST)
    print(request.GET)
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')
        ret = models.user.objects.filter(username=username, password=password)
        if ret:
            return render(request, 'unit.html' )
        else:
            error_msg = '用户名或密码错误！'
            return render(request, 'login.html', {'error_msg': error_msg})
    else:
        return render(request, 'login.html', )


def mainpage(request):
    return render(request, 'mainpage.html' )

def unit(request):
    return render(request, 'unit.html' )
def Unit_Name(request):
    return render(request, 'Unit_Name.html' )
def field_research(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )

    cursor = conn.cursor()
    sql = "SELECT YJLY FROM app_zjxx"
    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []
    for r in resultst:
        for o in str(r[0]).replace('nan','').split('、'):
            for t in str(o).split('，'):
                if t !='':
                    results.append(t)
    df=pd.DataFrame(results,columns=['ly'])
    date=(list(df['ly'].value_counts().keys())[:10])
    count=(list(df['ly'].value_counts().values)[:10])
    print(date)
    print(count)
    return render(request, 'field_research.html',locals() )
def familiarize(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )

    cursor = conn.cursor()
    sql = "SELECT SXZY FROM app_zjxx"
    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []
    for r in resultst:
        for o in str(r[0]).replace('nan','').split('、'):
            for t in str(o).split('，'):
                if t !='':
                    results.append(t)
    df=pd.DataFrame(results,columns=['zy'])
    date=(list(df['zy'].value_counts().keys())[:10])
    count=(list(df['zy'].value_counts().values)[:10])
    print(date)
    print(count)
    return render(request, 'familiarize.html',locals() )
def subject(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )

    cursor = conn.cursor()
    sql = "SELECT CSZY FROM app_zjxx"
    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []
    for r in resultst:
        for o in str(r[0]).replace('nan','').split('、'):
            for t in str(o).split('，'):
                if t !='':
                    results.append(t)
    df=pd.DataFrame(results,columns=['zy'])
    date=(list(df['zy'].value_counts().keys())[:10])
    count=(list(df['zy'].value_counts().values)[:10])
    print(date)
    print(count)
    return render(request, 'subject.html',locals() )
def trophy(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )

    cursor = conn.cursor()
    sql = "SELECT LY FROM app_LWK"
    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []
    for r in resultst:
        results.append(r[0])
    df=pd.DataFrame(results,columns=['LY'])
    key=(list(df['LY'].value_counts().keys()))
    val=(list(df['LY'].value_counts().values))

    data=[]
    for i in range(3):
        temp={}
        temp.update({'value': val[i]})
        temp.update({'name': key[i]})
        data.append(temp)
    # print(date)  { value: 1048, name: 'Search Engine' }
    # print(count)
    return render(request, 'trophy.html',locals() )
def language(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )

    cursor = conn.cursor()
    sql = "SELECT TM FROM app_LWK"
    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []
    for r in resultst:
        if str(r[0])[0]<'A' or str(r[0])[0]>'z':

            results.append("中文")
        else:
            results.append("英文")
    df=pd.DataFrame(results,columns=['L'])
    key=(list(df['L'].value_counts().keys()))
    val=(list(df['L'].value_counts().values))

    data=[]
    for i in range(2):
        temp={}
        temp.update({'value': val[i]})
        temp.update({'name': key[i]})
        data.append(temp)
    # print(date)  { value: 1048, name: 'Search Engine' }
    # print(count)
    return render(request, 'language.html',locals() )
def amount(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )

    cursor = conn.cursor()
    sql = "SELECT ND FROM app_LWK"
    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []
    for r in resultst:
            results.append(r[0])
    df=pd.DataFrame(results,columns=['ND'])
    key=(list(df['ND'].value_counts(sort=False).sort_index().keys()))
    val=(list(df['ND'].value_counts(sort=False).sort_index().values))
    print(key)
    print(val)
   
    return render(request, 'amount.html',locals() )


def awards_Number(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )

    cursor = conn.cursor()
    sql = "SELECT ND FROM app_XMK"
    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []
    for r in resultst:
        results.append(r[0])
    df = pd.DataFrame(results, columns=['ND'])
    key = (list(df['ND'].value_counts(sort=False).sort_index().keys()))
    val = (list(df['ND'].value_counts(sort=False).sort_index().values))
    print(key)
    print(val)

    return render(request, 'awards_Number.html', locals())


def expert_finding(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )
    cursor = conn.cursor()

    sql = "SELECT XM,CSD,ZW,SXZY,CSZY,YJLY,TXDZ,GZDWDH FROM app_ZJXX limit 2000"
    cursor.execute(sql)
    results = cursor.fetchall()

    return render(request, 'expert_finding.html', {'all_information_list': results})
def project_finding(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )
    cursor = conn.cursor()

    sql = "SELECT XMMC,FZR,DWMC,XMJJ,XMJB,ND FROM app_XMK limit 2000"
    cursor.execute(sql)
    results = cursor.fetchall()

    return render(request, 'project_finding.html', {'all_information_list': results})
def paper_finding(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )
    cursor = conn.cursor()

    sql = "SELECT LY,ND,TM,DYZZ,QBZZ,CBS FROM app_LWK limit 2000"
    cursor.execute(sql)
    results = cursor.fetchall()

    return render(request, 'paper_finding.html', {'all_information_list': results})

def all_information(request):
    conn = pymysql.connect(
        host='127.0.0.1',
        user='root',
        passwd='281227',
        port=3306,
        db='professional',
        charset='utf8'
    )
    cursor = conn.cursor()
    sql = "SELECT XM,CSD,ZW,SXZY,CSZY,YJLY,TXDZ,GZDWDH FROM app_ZJXX limit 2000"
    cursor.execute(sql)
    resultst = cursor.fetchall()
    results = []
    for r in resultst:
        temp = []
        for index, i in enumerate(list(r)):

                if i == 'nan':
                    temp.append('无')
                else:
                    temp.append(i)
        results.append(temp)

    return render(request, 'expert_finding.html', {'all_information_list': results,'username':request.session["username"] })
def atlas(request):

    return render(request, 'atlas.html', )