from django.forms import ModelForm
from .models import User
from django import forms
class CustomerForm(ModelForm):
    class Meta:
        model = User
        fields='__all__'
        exclude=['time_created']

