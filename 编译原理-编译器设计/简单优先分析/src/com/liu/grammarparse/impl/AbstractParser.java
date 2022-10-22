package com.liu.grammarparse.impl;

import java.util.HashMap;
import java.util.Map;

import com.liu.grammarparse.inter.ICalProcedentTable;
import com.liu.grammarparse.inter.IParser;
import com.liu.util.MetrixUtil;
/**
 * 
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * �������������࣬������ģ��ģʽ(Template-Pattern),�����������ķ���  <br> 
 * �����ƣ�com.liu.grammarparse.impl.AbstractParser<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����7:24:31<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����7:24:31<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public abstract class AbstractParser implements IParser, ICalProcedentTable {

	protected Map<String, Integer> charIndex=null;
	protected Character[] NTernimal=null;
	//�ⲿע����ս���ս��ַ���
	//����Ϊ�ַ��������������Ա���߲��Ч��
	public void setNTernimal(Character[] NT){
		this.NTernimal=NT;
		
		Map<String,Integer> index=new HashMap<String, Integer>();
		for(int i=0;i<NT.length;i++)
			index.put(NT[i]+"", i);
		charIndex=index;
	}

	
	protected Map<String, String[]> LRpartors=null;
	//ע��������ķ����Ҳ�
	public void setLRpartors(Map<String, String[]> LR){
		this.LRpartors=LR;
	}

	
	@Override
	public Integer[][] getProcedentTable() {

		Integer[][] first=parseFirstMetrix();    //���First����
		Integer[][] last=parseLastMetrix();    //���Last����
		Integer[][] equal=parseEqualProcedent();   //�����ȹ�ϵ����
		
		//Debug
/*		System.out.println(Arrays.toString(this.NTernimal));
		System.out.println("First:");
		printMetrix(first);
		System.out.println("\nLast:");
		printMetrix(last);
		System.out.println("\nEqual:");
		printMetrix(equal);*/
		
		// С�ڹ�ϵ < === equal*(First+) ��������Ⱦ������ First�Ĵ��ݱհ�
		Integer[][] first_plus=MetrixUtil.transitiveClosuresByWarShall(first);  //��ȡFirst�Ĵ��ݱհ�
		Integer [][]  less=MetrixUtil.multiplyTwoMetrix(equal, first_plus);
		
		
		//���ڹ�ϵ > === (Last+)T (equal) (First*)������Last����Ĵ��ݱհ���ת�� ���� ��Ⱦ��� ���� First �Ĵ����Է��հ�
		Integer [][] last_plus=MetrixUtil.transitiveClosuresByWarShall(last);  //���last�Ĵ��ݱհ�
		Integer[][] last_plus_tran=MetrixUtil.transpositionMetrix(last_plus);  //��last�Ĵ��ݱհ�����ת��
		Integer[][] first_plus_rev=MetrixUtil.getReverseClosure(first_plus, false); //��first���ݱհ�����Է��Ե�
		
		//��������˵õ� ���ڹ�ϵ�ľ���
		Integer[][] temp=MetrixUtil.multiplyTwoMetrix(last_plus_tran, equal);  
		Integer[][] greater=MetrixUtil.multiplyTwoMetrix(temp, first_plus_rev);
		
		Integer[][] table=this.combineThreeProcedentToProcedentTable(equal, less, greater);
		
		return table;
	}
	
	public Character[][] decorateTable(Integer[][] table){
		int n=this.NTernimal.length;
		Character[][] decoratTable=new Character[n+1][n+1];
		
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				if(i==0 && j!=0)
					decoratTable[i][j]=this.NTernimal[j-1];
				else if(i!=0&&j==0)
					decoratTable[i][j]=this.NTernimal[i-1];
				else if(i==0&&j==0)
					decoratTable[0][0]=' ';
				else if(table[i-1][j-1]==0)
					decoratTable[i][j]='=';
				else if(table[i-1][j-1]==-1)
					decoratTable[i][j]='<';
				else if(table[i-1][j-1]==1)
					decoratTable[i][j]='>';
				else if(table[i-1][j-1]==9)
					decoratTable[i][j]='*';
			}
		}

				
		return decoratTable;
	}
	
	/**
	 * 
	 * @Title: combineThreeProcedentToProcedentTable  
	 * @Description: TODO(������һ�仰�����������������)  
	 * @param equal ��ȹ�ϵ����
	 * @param less  С�ڹ�ϵ����
	 * @param great ���ڹ�ϵ����
	 * @return  ���ؼ����ȱ����������Ԫ������Ϊ��<br>
	 * 		0����ȹ�ϵ   <br>
	 * 		-1��С�ڹ�ϵ(������Ԫ��С����Ԫ��)  <br>
	 *      1�����ڹ�ϵ(������Ԫ�ش�����Ԫ��)   <br>
	 *      9��û���κι�ϵ <br>
	 */
	abstract protected Integer[][] combineThreeProcedentToProcedentTable(Integer[][] equal,
			Integer[][] less,Integer[][] great);

/*	Debug
 * private void printMetrix(Integer [][] r){			
		for(int i=0;i<r.length;i++){
			for(int j=0;j<r[i].length;j++)
				System.out.print(r[i][j]+" ");
			
			System.out.println();
		}	
		System.out.println();
	}*/

}
