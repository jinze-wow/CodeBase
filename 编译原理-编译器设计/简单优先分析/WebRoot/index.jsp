<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
 <head>
  <meta http-equiv="content-type" content="text/html;charset=utf-8" />
  <title>简单优先语法解析</title>
	
  <link rel="stylesheet" href="css/sweetalert.css" type="text/css" />
  <link rel="stylesheet" href="css/animate.css" type="text/css" />
  <style type="text/css">
  	/*general start*/
	*{padding:0;margin:0;}
	body{font-size:14px;font-family:"微软雅黑";background:url(images/757.jpg);
		background-position: center 0;color:white;}
	.clear{clear:both;}
	.left{float:left;}
	.right{float:right;}
    /*end general*/
  	/*core start*/ 
	.con{width:800px;margin:50px auto;padding:10px;}
    /*end core*/
	/*wenfa模块 start*/
	.con .wenfa{width:380px;height:300px;border-radius:14px;background:rgb(10,10,10);
			opacity:0.5;filter:alpha(opacity=50);}
	.con .wenfa .header{height:35px;padding-left:30px;line-height:35px;background:#555;
		font-size:16px;border-top-right-radius:14px;border-top-left-radius:14px;}
	.con .wenfa .header #add,.con .wenfa .header #parse{width:20px;height:20px;
		background:url(images/ht_icon.png) -46px -19px;margin:5px 8px;display:block;}
	.con .wenfa .header #add:hover{cursor:pointer;background:url(images/ht_icon.png) -46px 5px;}
	.con .wenfa .header #parse{background:url(images/ht_icon.png) -23px -19px;}
	.con .wenfa .header #parse:hover{cursor:pointer;background:url(images/ht_icon.png) -23px 5px;}

	.con .wenfa .input_form{padding:26px 25px 15px 25px;overflow:auto;height:210px;}
	.con .wenfa .input_form .item{margin-bottom:5px;}
	.con .wenfa .input_form input{border:none;outline:none;height:25px;border-radius:4px;padding-left:7px;
		color:black;font-weight:bold;}
	.con .wenfa .input_form input.Lpart{width:70px;text-align:right;padding-right:5px;}
	.con .wenfa .input_form input.Rpart{width:200px;}
    /*end wenfa模块*/

	/*table start*/
	.con .table{width:400px;height:300px;background:rgb(10,10,10);opacity:0.5;
		overflow: auto;filter:alpha(opacity=50);border-radius:14px;}
  	.con .table #ptable{margin:15px auto;}
  	.con .table #ptable td{width:32px;height:26px;line-height:26px;text-align:center;
  		border: 1px solid red;}
  	/*end table*/
  	
  	/*parse_panel start*/
  	.con .parse_panel{width:99%;height:230px;border:1px solid green;margin:10px auto;border-radius:12px;
		opacity:0.6;background:#000;}
	.con .parse_panel .header{height:35px;padding-left:30px;line-height:35px;background:#111;
		font-size:16px;border-top-right-radius:12px;border-top-left-radius:12px;}
	.con .parse_panel .header .text{height:35px;line-height:35px;margin-right:10px;}
	.con .parse_panel .header input{margin-left:6px;margin-right:8px;border:0;outline:none;border-radius:4px;padding:3px;}
	.con .parse_panel .header #validate{display:inline-block;text-decoration:none;width:82px;height:22px;
		line-height:22px;text-align:center;background:blue;color:white;border-radius:4px;}
	.con .parse_panel .header #validate:hover{cursor:pointer;background:lightblue;}

	.con .parse_panel .parser_command{width:760px;height:174px;color:green;overflow:auto;font-size: 21px;
		font-weight: bold;padding-top:15px;padding-left:25px;}
  	/*end parse_panel*/
  </style>
 </head>
  
 <body>
  
  <div class="con">
  	<!-- wenfa_area start -->
	<div class="wenfa animated wobble left">
		<div class="header">添加产生式
			<a href="javascript:void(0)" id="parse" title="开始解析" class="right"></a>
			<a href="javascript:void(0)" id="add" title="添加文法" class="right"></a>
		</div>
		<div class="input_form">
			<form id="form_data">
			   <div class="item">
			     <input type="text" id="L1"  class="Lpart" spellcheck="false" maxLength="35"/>&nbsp;=>&nbsp;
			     <input type="text" id="R2"  class="Rpart" spellcheck="false" maxLength="35" />
			   </div>
			</form>
		</div>
	</div>
	<!-- end wenfa_area -->
	
	<!-- table start -->
	<div class="table animated wobble right">
	</div>
	<!-- end table -->
	
	<div class="clear"></div>
	
	<!-- parse start -->
	<div class="parse_panel animated swing">
	  <div class="header">验证字符串的合法性
		<div class="text right">
			请输入字符串:<input type="text" id="RT" /> 
			<a href="javascript:void(0)" id="validate">验证</a>
		</div>
	  </div>
	  <div class="parser_command">
		<div class="command" id="command">
			<pre id="pre"></pre>
		</div>
	  </div>
	</div>
	<!-- end parse -->
	
  </div>
  	
  <script type="text/javascript" src="js/jquery2.js"></script>
  <script type="text/javascript" src="js/sweetalert.min.js"></script>
  <script type="text/javascript">
	$(function(){
		var index=1;
		var isParsed=false;
		$('#add').click(function(){
			++index;
			//实例化一个产生式组
			var tar=$('<div class="item"></div>');
			var template=$('.input_form').find('.item')[0];
			$(tar).html($(template).html());
			$(tar).find('.Lpart').attr('id','L'+index);
			$(tar).find('.Rpart').attr('id','R'+index);
			//添加特效
			if(index%2==0)
				$(tar).find('input').addClass('animated rotateInDownLeft');
			else
				$(tar).find('input').addClass('animated rotateInDownRight');
			//添加到DOM
			$('.input_form').append(tar);	
		});

		$('#validate').click(function(){
			if(!isParsed){
				swal("提示！", "请先解析文法得到简单优先表，才能验证!!!");
				return;				
			}
			var con=$('#RT').val();
			if(con=='') {
				swal("提示！", "提交的字符串不能为空!");
				return;
			}
			
			$.ajax({
				  type:'post',
				  url:'<%=path%>/parse',
				  data:{string:con,cmd:'validate'},
				  success:function(r){
					  if(r!=''){
						$('#pre').html('');
						var arr=r.split("\n");
						
/* 					for(var i=0;i<arr.length;i++){
							setTimeout(function(){
								$('#pre').html(arr[i]+"\n");
							},700);
						}	
 */						
 						var i=0;
 						var id=setInterval(function(){	
 							$('#pre').append(arr[i++]+"\n");
 							
 						/* 	var h=$('#pre').scrollHeight();
 							$('.parser_command').css({'scrollTop':h+'px'}); */
 							if(i==arr.length)
 								clearInterval(id);
 						},700);
					  }				  
				  }
				});

			
		});
		
		//var encodedStr = window.btoa(“Hello world”); //字符串编码
		//var decodedStr = window.atob(encodedStr); //字符串解码
		$('#parse').click(function(){
			var result='';
	 		var ls=$('.Lpart');
			var rs=$('.Rpart');
			//拼接querystring
			for(var i=0;i<ls.length;i++){
			  var leftcon=$(ls[i]).val();
			  var rightcon=$(rs[i]).val();

			  if(leftcon!=""&&rightcon=="" || leftcon==""&&rightcon!=""){
				swal("提示！", "任何一个产生式要么都为空，要么都不为空!");		
				return;
			  }
			  
			  if(leftcon!=""){
			    var t=leftcon+"=>"+rightcon+"\n";
			    result+=t;
			  }
			} 

			if(result=='')	return;
			
			$.ajax({
			  type:'post',
			  url:'<%=path%>/parse',
			  data:{wenfa:result,cmd:'getTable'},
			  success:function(r){
				  if(r!=''){
					  $('.table').html(r);
					  swal("干得漂亮！", "解析成功哦！", "success");
					  isParsed=true;
				  }				  
			  }
			});
	
		});

	});
	
  </script>  
 </body>
</html>
