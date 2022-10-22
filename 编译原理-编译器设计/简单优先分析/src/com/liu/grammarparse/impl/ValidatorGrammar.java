package com.liu.grammarparse.impl;
import java.util.HashMap;
import java.util.Map;

import com.liu.grammarparse.inter.IValidator;

/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：验证语法用简单优先表  <br> 
 * 类名称：com.liu.grammarparse.impl.ValidatorGrammar<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 下午9:39:16<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 下午9:39:16<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public class ValidatorGrammar implements IValidator {

	private Integer[][] ProcedentTable=null;
	//注入简单优先表
	public void setProcedentTable(Integer[][] table){
		this.ProcedentTable=table;
	}
	
	protected Map<String, Integer> charIndex=null;
	private Character[] NTernimal=null;
	//外部注入非终结和终结字符串
	//而且为字符串建立索引，以便提高查表效率
	public void setNTernimal(Character[] NT){
		this.NTernimal=NT;
		
		Map<String,Integer> index=new HashMap<String, Integer>();
		for(int i=0;i<NTernimal.length;i++)
			index.put(NTernimal[i]+"", i);
		charIndex=index;

	}

	protected Map<String, String[]> LRpartors=null;
	//注入解析的文法左右部
	public void setLRpartors(Map<String, String[]> LR){
		this.LRpartors=LR;
	}
	
	private String startFlag;
	//注入文法开始字符
	public void setStartFlag(String s){
		this.startFlag=s;
	}
	
	
	
	@Override
	public Map<String, Object> validateGrammar(String terminalStr) {
		if("".equals(terminalStr))
			throw new RuntimeException("要鉴别的字符串不能为空！");
		
		//初始化输入串
		String TR=terminalStr.trim()+"$";
		//初始化符号栈
		char[] stack=new char[TR.length()];
		int top=-1;
		stack[++top]='$';
		
		char [] TRChar=TR.toCharArray();  //将输出串转为字符数组，便于迭代
		StringBuilder sb=new StringBuilder();//用于视图化的字符串
		String relation=""; //用于视图化各种关系
		String handle=""; //用于视图化句柄
		String leftChar=""; //产生式的左部
		
		int showtop;
		int cnt=1;
		for(int i=0;i<TRChar.length;i++){
			boolean isGreate=false;
			boolean isDollarGreate=false;
			handle="";
			leftChar="";
			showtop=top;
			if(stack[top]=='$'){      //处理特殊情况，有关$符号
				relation="<";
				stack[++top]=TRChar[i];
			}
			else if(TRChar[i]=='$'){ //处理输入串最后字符$,大于关系
				relation=">";		
				
				//取得句柄字符串在栈中的开始索引
				int start_pos=getHandlerBeginPosition(stack,top);			
				//获取句柄
				handle=this.getHandler(stack, start_pos, top);  
				if(handle.equals(this.startFlag)){
					sb.append(String.format("%-4d%-15s%-4s%15s%12s\n", cnt,"$"+handle,"YES",
							"$",""));
					relation="YES";
					break;
				}
				
				//找出句柄handler对应的左部非终结符
				leftChar=getLeftChar(handle);
				
				if(leftChar==""){
					sb.append("NO");
					Map<String, Object> map=new HashMap<String, Object>();
					map.put("status", false);
					map.put("process", sb.toString());
					return map;
				}
	
				top=start_pos;				
				isDollarGreate=true;
				
			}
			else{
				Integer row=this.charIndex.get(stack[top]+"");
				Integer col=this.charIndex.get(TRChar[i]+"");
				if(col==null || row ==null){
					sb.append(String.format("%-4d%-15s%-4s%15s%12s\n", cnt,getStackStr(stack,showtop),relation,
							getStr(TRChar,i),"没有"+TRChar[i]+"这个符号"));
		
					sb.append("NO\n");
					Map<String, Object> map=new HashMap<String, Object>();
					map.put("status", false);
					map.put("process", sb.toString());
					return map;
				}
				
				//关系相等，符号入栈
				if(ProcedentTable[row][col]==0){      
					relation="=";
					stack[++top]=TRChar[i];
				}else if( ProcedentTable[row][col]==-1){ //关系小于，符号入栈
					relation="<";
					stack[++top]=TRChar[i];
				}else if(ProcedentTable[row][col]==1){	//关系大于，进行判断		
					relation=">";
					isGreate=true;    //大于关系标志位置1，为后面句柄对应的左部入栈和字符串索引保持不变做准备
					
					//取得句柄字符串在栈中的开始索引
					int start_pos=getHandlerBeginPosition(stack,top);
					
					//获取句柄
					handle=this.getHandler(stack, start_pos, top);  
									
					//找出句柄handler对应的左部非终结符
					leftChar=getLeftChar(handle);
					
					//找不到左边的符号
					if(leftChar==""){
						sb.append(String.format("%-4d%-15s%-4s%15s%12s\n", cnt,getStackStr(stack,showtop),relation,
								getStr(TRChar,i),"没有右部"+"=>"+handle));
						sb.append("NO\n");
						Map<String, Object> map=new HashMap<String, Object>();
						map.put("status", false);
						map.put("process", sb.toString());
						return map;
					}
						
					//栈中句柄弹出，即：top指针指向句柄在栈中索引的开始位置
					top=start_pos;										
				}else{
					sb.append(String.format("%-4d%-15s%-4s%15s%12s\n", cnt,getStackStr(stack,showtop),"无匹配",
							getStr(TRChar,i),""));
					sb.append("NO\n");
					Map<String, Object> map=new HashMap<String, Object>();
					map.put("status", false);
					map.put("process", sb.toString());
					return map;
				}
			}
			
			sb.append(String.format("%-4d%-15s%-4s%15s%12s\n", cnt,getStackStr(stack,showtop),relation,
					getStr(TRChar,i),"".equals(handle)?"":leftChar+"=>"+handle));
						
			/**
			 * 为了输出中间的过程，通过isGreate标志位来实现，先打印输出再改变栈中的情况
			 */
			if(isGreate || isDollarGreate){
				stack[top]=leftChar.charAt(0);
				i--;
			}
			
			//过程步骤加1
			cnt++;
		}
	
		boolean isFit=relation.equals("YES")?true:false;
		Map<String, Object> map=new HashMap<String, Object>();
		map.put("status", isFit);
		map.put("process", sb.toString());
		return map;
	}


	/**
	 * 
	 * @Title: getLeftChar  
	 * @Description: 找出句柄handler对应的左部非终结符 
	 * @param handle 句柄
	 * @return 左部非终结符
	 */
	public String getLeftChar(String handle){
		String leftChar="";
		
		for(String key:LRpartors.keySet()){
			String [] R=LRpartors.get(key);
			for(String s:R)
				if(s.equals(handle)){
					leftChar=key;
					break;
				}
		}

		return leftChar;
	}
	
	
	/**
	 * 
	 * @Title: getHandlerBeginPosition  
	 * @Description:  取得句柄字符串在栈中的开始索引
	 * @param stack 符号栈
	 * @param top  栈顶指针
	 * @return  开始位置索引
	 */
	public int getHandlerBeginPosition(char[]stack,int top){
		int ii;
		for(ii=top;ii>=1;ii--){
			if(ii==1) break;
			
			int r=this.charIndex.get(stack[ii-1]+"");
			int c=this.charIndex.get(stack[ii]+"");
		
			if(ProcedentTable[r][c]==-1)
				break;
		}

		return ii;
	}
	
    //按照beg-end来获取stack中的字符串
	private String getHandler(char[]stack,int beg,int end){
		StringBuilder sb=new StringBuilder();
		
		for(int i=beg;i<=end;i++)
			sb.append(stack[i]);
		
		return sb.toString();
	}
	
	//通过index，索取stack中在index之前的字符串
	private String getStackStr(char[] stack,int index){
		StringBuilder sb=new StringBuilder();
		
		for(int i=0;i<=index;i++)
			sb.append(stack[i]);
		
		return sb.toString();
	}
	
	//通过index,获取TR输出串中还剩余的字符
	private String getStr(char[]arr ,int index){
		StringBuilder sb=new StringBuilder();
		
		for(int i=index;i<arr.length;i++)
			sb.append(arr[i]);
		
		return sb.toString();		
	}
}
