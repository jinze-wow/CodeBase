package com.liu.grammarparse.impl;
import java.util.HashMap;
import java.util.Map;

import com.liu.grammarparse.inter.IValidator;

/**
 * 
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * ����������֤�﷨�ü����ȱ�  <br> 
 * �����ƣ�com.liu.grammarparse.impl.ValidatorGrammar<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����9:39:16<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����9:39:16<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public class ValidatorGrammar implements IValidator {

	private Integer[][] ProcedentTable=null;
	//ע������ȱ�
	public void setProcedentTable(Integer[][] table){
		this.ProcedentTable=table;
	}
	
	protected Map<String, Integer> charIndex=null;
	private Character[] NTernimal=null;
	//�ⲿע����ս���ս��ַ���
	//����Ϊ�ַ��������������Ա���߲��Ч��
	public void setNTernimal(Character[] NT){
		this.NTernimal=NT;
		
		Map<String,Integer> index=new HashMap<String, Integer>();
		for(int i=0;i<NTernimal.length;i++)
			index.put(NTernimal[i]+"", i);
		charIndex=index;

	}

	protected Map<String, String[]> LRpartors=null;
	//ע��������ķ����Ҳ�
	public void setLRpartors(Map<String, String[]> LR){
		this.LRpartors=LR;
	}
	
	private String startFlag;
	//ע���ķ���ʼ�ַ�
	public void setStartFlag(String s){
		this.startFlag=s;
	}
	
	
	
	@Override
	public Map<String, Object> validateGrammar(String terminalStr) {
		if("".equals(terminalStr))
			throw new RuntimeException("Ҫ������ַ�������Ϊ�գ�");
		
		//��ʼ�����봮
		String TR=terminalStr.trim()+"$";
		//��ʼ������ջ
		char[] stack=new char[TR.length()];
		int top=-1;
		stack[++top]='$';
		
		char [] TRChar=TR.toCharArray();  //�������תΪ�ַ����飬���ڵ���
		StringBuilder sb=new StringBuilder();//������ͼ�����ַ���
		String relation=""; //������ͼ�����ֹ�ϵ
		String handle=""; //������ͼ�����
		String leftChar=""; //����ʽ����
		
		int showtop;
		int cnt=1;
		for(int i=0;i<TRChar.length;i++){
			boolean isGreate=false;
			boolean isDollarGreate=false;
			handle="";
			leftChar="";
			showtop=top;
			if(stack[top]=='$'){      //��������������й�$����
				relation="<";
				stack[++top]=TRChar[i];
			}
			else if(TRChar[i]=='$'){ //�������봮����ַ�$,���ڹ�ϵ
				relation=">";		
				
				//ȡ�þ���ַ�����ջ�еĿ�ʼ����
				int start_pos=getHandlerBeginPosition(stack,top);			
				//��ȡ���
				handle=this.getHandler(stack, start_pos, top);  
				if(handle.equals(this.startFlag)){
					sb.append(String.format("%-4d%-15s%-4s%15s%12s\n", cnt,"$"+handle,"YES",
							"$",""));
					relation="YES";
					break;
				}
				
				//�ҳ����handler��Ӧ���󲿷��ս��
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
							getStr(TRChar,i),"û��"+TRChar[i]+"�������"));
		
					sb.append("NO\n");
					Map<String, Object> map=new HashMap<String, Object>();
					map.put("status", false);
					map.put("process", sb.toString());
					return map;
				}
				
				//��ϵ��ȣ�������ջ
				if(ProcedentTable[row][col]==0){      
					relation="=";
					stack[++top]=TRChar[i];
				}else if( ProcedentTable[row][col]==-1){ //��ϵС�ڣ�������ջ
					relation="<";
					stack[++top]=TRChar[i];
				}else if(ProcedentTable[row][col]==1){	//��ϵ���ڣ������ж�		
					relation=">";
					isGreate=true;    //���ڹ�ϵ��־λ��1��Ϊ��������Ӧ������ջ���ַ����������ֲ�����׼��
					
					//ȡ�þ���ַ�����ջ�еĿ�ʼ����
					int start_pos=getHandlerBeginPosition(stack,top);
					
					//��ȡ���
					handle=this.getHandler(stack, start_pos, top);  
									
					//�ҳ����handler��Ӧ���󲿷��ս��
					leftChar=getLeftChar(handle);
					
					//�Ҳ�����ߵķ���
					if(leftChar==""){
						sb.append(String.format("%-4d%-15s%-4s%15s%12s\n", cnt,getStackStr(stack,showtop),relation,
								getStr(TRChar,i),"û���Ҳ�"+"=>"+handle));
						sb.append("NO\n");
						Map<String, Object> map=new HashMap<String, Object>();
						map.put("status", false);
						map.put("process", sb.toString());
						return map;
					}
						
					//ջ�о������������topָ��ָ������ջ�������Ŀ�ʼλ��
					top=start_pos;										
				}else{
					sb.append(String.format("%-4d%-15s%-4s%15s%12s\n", cnt,getStackStr(stack,showtop),"��ƥ��",
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
			 * Ϊ������м�Ĺ��̣�ͨ��isGreate��־λ��ʵ�֣��ȴ�ӡ����ٸı�ջ�е����
			 */
			if(isGreate || isDollarGreate){
				stack[top]=leftChar.charAt(0);
				i--;
			}
			
			//���̲����1
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
	 * @Description: �ҳ����handler��Ӧ���󲿷��ս�� 
	 * @param handle ���
	 * @return �󲿷��ս��
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
	 * @Description:  ȡ�þ���ַ�����ջ�еĿ�ʼ����
	 * @param stack ����ջ
	 * @param top  ջ��ָ��
	 * @return  ��ʼλ������
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
	
    //����beg-end����ȡstack�е��ַ���
	private String getHandler(char[]stack,int beg,int end){
		StringBuilder sb=new StringBuilder();
		
		for(int i=beg;i<=end;i++)
			sb.append(stack[i]);
		
		return sb.toString();
	}
	
	//ͨ��index����ȡstack����index֮ǰ���ַ���
	private String getStackStr(char[] stack,int index){
		StringBuilder sb=new StringBuilder();
		
		for(int i=0;i<=index;i++)
			sb.append(stack[i]);
		
		return sb.toString();
	}
	
	//ͨ��index,��ȡTR������л�ʣ����ַ�
	private String getStr(char[]arr ,int index){
		StringBuilder sb=new StringBuilder();
		
		for(int i=index;i<arr.length;i++)
			sb.append(arr[i]);
		
		return sb.toString();		
	}
}
