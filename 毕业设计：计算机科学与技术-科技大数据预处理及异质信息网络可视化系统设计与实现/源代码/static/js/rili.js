function clickCanlendar(){
	var date = new Date();
	var month = date.getMonth();
	var day = date.getDate();
	if(month >= 1 && month <= 9){
		month = '0' + month
	}
	if(day >= 1 && day <= 9){
		day = '0' + day;
	};
	var currentDate = date.getFullYear() + month + day;
	ShowCalendar(currentDate);
}


function ShowCalendar(SY_OPERATION){
	//判断exit 节点是否存在
	if($("#exit").length > 0){
		$("#exit").detach();
		return;
	}else{
		var Calendar = '<div id= "exit" class="main clearfix" style="position: absolute;background:white;">' +
					       '<div class="menu clearfix tomove"> '+
					           ' <a class="select-prev fl" href="javascript:;">&lt;</a>' + 
					           ' <div class="select month fl pr">' + 
					                '<div class="select-text"><span class="year-text" value="2016">2016年</span><span class="month-text" value="">1月</span></div>' + 
					           ' </div>' + 
					            '<a class="select-next fl" href="javascript:;">&gt;</a>' + 
					            '<a class="select-today fl" href="javascript:;">返回今天</a>' + 
					            '<div class="time fl">10:40:05</div>' + 
					        '</div>' + 
					        '<ul class="title">' + 
					           ' <li>日</li><li>一</li><li>二</li><li>三</li><li>四</li><li>五</li><li>六</li>' + 
					        '</ul>' + 
					        '<ul class="table">' + 
					           ' <li><span>1</span></li><li><span>2</span>' + 
					       ' </ul>' + 
					    '</div>';

	    $(Calendar).insertBefore("#showCalendar");
								    
        $(function(){
	        var init = {
//				startYear: 1900, //年份列表开始年
//				endYear: 2050 //年份列表结束年
	        };
	        var fun = {
	            init: function(){
	                this.timeBox();
	                this.dateBox();
	            },
	            timeBox: function(){ //系统时间
	                (function(){
	                    var date = new Date();
	                    var h = date.getHours(),
	                        m = date.getMinutes(),
	                        s = date.getSeconds();
	                    var time = h + ':' + m + ':' + s;
	                    var time = fun.timeBu(time);
	                    $('.time').html(time);
	                    setTimeout(arguments.callee, 1000);
	                })();
	            },
	            timeBu: function(val){
	                var arr = val.split(':');
	                for(var i = 0; i < arr.length; i++){
	                    if(arr[i] < 10){
	                        arr[i] = '0' + arr[i];
	                    }
	                };
	                return arr.join(':');
	            },
	            showDate: function(year, month){ //日历展示
	                //改变下拉
	                $('.year-text').text(year + '年').attr('value', year);
	                $('.month-text').text(month + '月').attr('value', month);
	                $('.select-list li').removeClass('selected');
	                //为当前已经默认的年份和有份标为选中
	                $('.select-list li').addClass(function(i){
	                    var value = $(this).attr('value');
	                    if(value == year || value == month){
	                        return 'selected';
	                    }
	                });
    	
	                var setDate = new Date();
	                setDate.setFullYear(year); //设置年份
	                setDate.setMonth(month-1); //设置月份，因为系统的月份都是比真实的小1
	                setDate.setDate(1); //设置成当前月第一天
    	
	                var num = setDate.getDay(); //得到本月第一天是星期几
    	
	                setDate.setMonth(month); //设置成正确的真实月份
	                var lastDate = new Date(setDate.getTime() - 1000*60*60*24); //计算得到当前月最后一天的日期格式
	                var lastDay = lastDate.getDate(); //获取本月最后一天是几号
    	
	                //利用得到的当前月总天数来循环出当前月日历
	                var html = '';
	                for(var i = 1; i <= lastDay; i++){
	                    html += '<li><span>'+i+'</span></li>';
	                };
	                $('.table').html(html);
    	
	                var first = $('.table li:first'),
	                    w = first.outerWidth();
	                first.css('marginLeft', w * num + 'px'); //根据得到的本月第一天是周几得出第一个li所在的位置，从而排列好整个日历
    	
	                var nowDate = new Date(), //得到系统当前的真实时间
	                    nowYear = nowDate.getFullYear(),
	                    nowMonth = nowDate.getMonth() + 1,
	                    today = nowDate.getDate(); //获取当前是几号
	                if(nowYear == year && nowMonth == month){ //验证当前展示中是否包含今天
	                    $('.table li').eq(today-1).find('span').addClass('today'); //标出今天
	                }
    	            
	            },
	            dateBox: function(){
	                var date = new Date(),
	                    year = date.getFullYear(), //获取当前是哪一年
	                    month = date.getMonth() + 1; //获取当前月
    	            
	                //初始化日历
	                fun.showDate(year, month);
    	            
	            }
	        }
	        fun.init(); //运行
	        $(document).on('click', function(){
	            $('.select-list').hide();
	            $('.select-text').removeClass('current');
	        });
	        //切换年，月
	        $('.select-list li').on('click', function(){
	            if($(this).hasClass('selected')){ //如果是已经选中的则不用在重新初始化日历
	                return;
	            };
	            var self = $(this),
	                text = self.text(),
	                value = self.attr('value');
	            self.addClass('selected').siblings().removeClass('selected');
	            self.parent().next().find('span').text(text).attr('value', value);
	            var year = $('.year-text').attr('value'),
	                month = $('.month-text').attr('value');
	            fun.showDate(year, month);
	        });
    	
	        //返回今天
	        $('.select-today').on('click', function(){
	            fun.dateBox();
	        });
    	
	        //日期选择
	        //日期悬浮时
	        $('body').on({
	            'mouseenter': function(){
	                $(this).addClass('on');
	            },
	            'mouseleave': function(){
	                $(this).removeClass('on');
	            }
	        }, '.table span');
	        //点击日期
	        $('body').on('click', '.table span', function(){
	            var year = $('.year-text').attr('value'),
	                month = $('.month-text').attr('value'),
	                day = $(this).text();
	                
	            if(month < 10){
	                month = "0" + month;
	            }
	            if(day < 10){
	                day = "0" + day;
	            }
                var YYY = "000" + (year-1911).toString();
                YYY = YYY.substr(3, 3);
                var datetime = YYY + month + day;  
                ShowOperation(SY_OPERATION, datetime);
	        });
    	
	        //前一个月
	        $('.select-prev').on('click', function(){
	            var year = parseInt($('.year-text').attr('value')),
	                month = parseInt($('.month-text').attr('value'));
	            if(month - 1 > 0){
	                month = month - 1;
	            }else{
	                month = 12;
	                year = year - 1;
	                if(year < init.startYear){
	                    return;
	                }
	            };
	            fun.showDate(year, month);
	        });
	        //后一个月
	        $('.select-next').on('click', function(){
	            var year = parseInt($('.year-text').attr('value')),
	                month = parseInt($('.month-text').attr('value'));
	            if(month + 1 <= 12){
	                month = month + 1;
	            }else{
	                month = 1;
	                year = year + 1;
	                if(year > init.endYear){
	                    return;
	                }
	            };
	            fun.showDate(year, month);
	        })
	    })
	 }
  }
 
