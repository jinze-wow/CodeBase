   M S B A M L   `   `   `  ????=  9OS, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null!clr-namespace:OS.ViewOS.View  5      +clr-namespace:OS.ViewModelOS.ViewModel  5      #clr-namespace:OS.ModelOS.Model  5      O Kmscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e0891&clr-namespace:System;assembly=mscorlibSystem 5	          OS.View.ListControl   5      R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      'localclr-namespace:OS.View     5      )vmclr-namespace:OS.ViewModel     5      (modelclr-namespace:OS.Model     5      9system&clr-namespace:System;assembly=mscorlib     5	      .??5      ? $	??600??6   $	??110??6     ? ColumnDefinitions  5   
   ?? 5      $	??100 ?6   ?? 5      $??* ?6    ? RowDefinitions 5   
   ?? 5      .+?5   
   ? ???	#FFA0A0A0.+?5      ?? -   5         ??Name$ 	textBlock??5      $
??Wrap=?6+   $??Center=?6~   $??24(?6?   $??Center=?6?   
???   ?$??0??6?   $??0??6?   ??6?   ?? *
ListName+ ?? UpdateSourceTrigger$ PropertyChanged=?6?   5      ?? 5   
   $
??Auto=?6   $
??Auto=?6<   $??Stretch=?6_   $??Stretch=?6}   $??1??6?   $??0??6?    ? 	Resources 5      ??%\   (??       5       */-SystemParameters.HorizontalScrollBarHeightKey+)X?6   10Q?6e   5      .??5      ?? -   5        $??ProcessLists??5      ???	#FFA0A0A0$
??Left=?6?   $
??Left=?6?   ??6/   ?? *ProcessItems+$ PropertyChanged=???5      ?? 5      .R?5      A?  A? Rows$ 1??6&   5       ??5#      ?? 5$       ?? DataType$%  {x:Type model:ProcessModel.PCB??6#   .R?5%      ? $
??Left=?6   $??Center=?6:   $	??100??6U   $	??100??6a    J? 
RenderSize$ 100,100??6n   .+?5&      ? $??80??6#   $??80??61   $??Center=?6@   $??Center=?6]   .+?5'   "   ?? $
??rect??69   
????????? 5(   "   $??Center=?6,   $??18,18,18,44q?6I   	Process6g   ?? 5)   "   $??id??6I   $??Center=?6,   $??44??6S    ?? TextAlignment$ Center=?6^   $??18,41,18,20q?6u   ??6?   ?? *Pid+6?   ?? 5*   "   	 ??Name$
	 info??6*   $
??Left=?68   $	??120??6S   
 ?? TextWrapping$

 Wrap=?6`   $?? ??6t   $	??Top=?6|   $??80??6?   $y?	Collapsed=?6?    ?? TextAlignment$ Center=?6?   $??10(?6?   $??0,-37.2,0,-7.6q?6?    ?? 
IsReadOnly . 6?   5+      5,      5-      5/      50      51      52      