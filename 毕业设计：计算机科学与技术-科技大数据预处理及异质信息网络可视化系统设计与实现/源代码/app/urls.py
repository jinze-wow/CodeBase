#!/usr/bin/env python 
# -*- coding:utf-8 -*-

from django.urls import path
from . import views,admin
#app_name='service'
urlpatterns = [
    path('', views.login),
    path('login/', views.login, name='login'),  # 登录
    path('register/', views.register, name='register'),
    path('mainpage/', views.mainpage, name='mainpage'),
    path('unit/', views.unit, name='unit'),
    path('field_research/', views.field_research, name='field_research'),
    path('familiarize/', views.familiarize, name='familiarize'),
    path('subject/', views.subject, name='subject'),
    path('trophy/', views.trophy, name='trophy'),
    path('language/', views.language, name='language'),
    path('amount/', views.amount, name='amount'),
    path('Unit_Name/', views.Unit_Name, name='Unit_Name'),
    path('awards_Number/', views.awards_Number, name='awards_Number'),
    path('expert_finding/', views.expert_finding, name='expert_finding'),
    path('project_finding/', views.project_finding, name='project_finding'),
    path('paper_finding/', views.paper_finding, name='paper_finding'),

    path('all_information/', views.all_information, name='all_information'),
    path('atlas/', views.atlas, name='atlas'),





]


