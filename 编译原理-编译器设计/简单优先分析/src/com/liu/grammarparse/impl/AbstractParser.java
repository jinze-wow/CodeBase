package com.liu.grammarparse.impl;

import java.util.HashMap;
import java.util.Map;

import com.liu.grammarparse.inter.ICalProcedentTable;
import com.liu.grammarparse.inter.IParser;
import com.liu.util.MetrixUtil;
/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：抽象类，运用了模板模式(Template-Pattern),父类调用子类的方法  <br> 
 * 类名称：com.liu.grammarparse.impl.AbstractParser<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 下午7:24:31<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 下午7:24:31<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public abstract class AbstractParser implements IParser, ICalProcedentTable {

	protected Map<String, Integer> charIndex=null;
	protected Character[] NTernimal=null;
	//外部注入非终结和终结字符串
	//而且为字符串建立索引，以便提高查表效率
	public void setNTernimal(Character[] NT){
		this.NTernimal=NT;
		
		Map<String,Integer> index=new HashMap<String, Integer>();
		for(int i=0;i<NT.length;i++)
			index.put(NT[i]+"", i);
		charIndex=index;
	}

	
	protected Map<String, String[]> LRpartors=null;
	//注入解析的文法左右部
	public void setLRpartors(Map<String, String[]> LR){
		this.LRpartors=LR;
	}

	
	@Override
	public Integer[][] getProcedentTable() {

		Integer[][] first=parseFirstMetrix();    //获得First矩阵
		Integer[][] last=parseLastMetrix();    //获得Last矩阵
		Integer[][] equal=parseEqualProcedent();   //获得相等关系矩阵
		
		//Debug
/*		System.out.println(Arrays.toString(this.NTernimal));
		System.out.println("First:");
		printMetrix(first);
		System.out.println("\nLast:");
		printMetrix(last);
		System.out.println("\nEqual:");
		printMetrix(equal);*/
		
		// 小于关系 < === equal*(First+) ，即：相等矩阵乘以 First的传递闭包
		Integer[][] first_plus=MetrixUtil.transitiveClosuresByWarShall(first);  //获取First的传递闭包
		Integer [][]  less=MetrixUtil.multiplyTwoMetrix(equal, first_plus);
		
		
		//大于关系 > === (Last+)T (equal) (First*)，即：Last矩阵的传递闭包的转置 乘以 相等矩阵 乘以 First 的传递自反闭包
		Integer [][] last_plus=MetrixUtil.transitiveClosuresByWarShall(last);  //获得last的传递闭包
		Integer[][] last_plus_tran=MetrixUtil.transpositionMetrix(last_plus);  //将last的传递闭包进行转置
		Integer[][] first_plus_rev=MetrixUtil.getReverseClosure(first_plus, false); //将first传递闭包变成自反性的
		
		//从左到右相乘得到 大于关系的矩阵
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
	 * @Description: TODO(这里用一句话描述这个方法的作用)  
	 * @param equal 相等关系矩阵
	 * @param less  小于关系矩阵
	 * @param great 大于关系矩阵
	 * @return  返回简单优先表，其中数组的元素意义为：<br>
	 * 		0：相等关系   <br>
	 * 		-1：小于关系(数组行元素小于列元素)  <br>
	 *      1：大于关系(数组行元素大于列元素)   <br>
	 *      9：没有任何关系 <br>
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
