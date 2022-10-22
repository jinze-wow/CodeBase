package com.liu.util;

/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：有关于矩阵的一些工具类方法  <br> 
 * 类名称：com.liu.util.MetrixUtil<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 下午1:47:17<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 下午1:47:17<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public class MetrixUtil {

	/**
	 * 
	 * @Title: transpositionMetrix  
	 * @Description: 转置一个矩阵
	 * @param metrix 要转置的矩阵
	 * @return 返回转置好的矩阵
	 */
	public static Integer [][] transpositionMetrix(Integer[][] metrix){
		
		if(metrix==null)
			return null;
		if(metrix.length==0)
			return metrix;
		
		Integer [][] r=new Integer[metrix.length][metrix[0].length];
		
		for(int i=0;i<metrix.length;i++){
			for(int j=0;j<=i;j++){
				r[j][i]=metrix[i][j];
				
				if(i!=j) r[i][j]=metrix[j][i];			
			}
		}
		
		return r;
	}
	
	/**
	 * 
	 * @Title: transitiveClosuresByWarShall  
	 * @Description: 用WarShall算法求得关系传递闭包。在算法设计中，可用于图的可达性研究
	 * @param metrix 源矩阵
	 * @return 返回目的矩阵
	 */
	public static Integer [][] transitiveClosuresByWarShall(Integer[][] metrix){
		if(metrix == null)
			return null;
		if(metrix.length == 0)
			return metrix;
		if(metrix.length!=metrix[0].length)
			throw new RuntimeException("求传递闭包必须是方阵！！！(行=列)");

		Integer n=metrix.length;
		Integer [][] r=new Integer[n][n];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				r[i][j]=metrix[i][j];
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(r[j][i]!=0){
					for(int k=0;k<n;k++){
						if(r[i][k]!=0)
							r[j][k]=1;
					}
				}
			}
		}
	
		return r;
	}
	
	/**
	 * 
	 * @Title: multiplyTwoMetrix  
	 * @Description: 两个矩阵相乘 
	 * @param metrixL 第一个矩阵
	 * @param metrixR 第二个矩阵
	 * @return 返回相乘后的矩阵
	 */
	public static Integer [][] multiplyTwoMetrix(Integer[][] metrixL,Integer[][] metrixR){
		if(metrixL==null || metrixR==null)
			throw new RuntimeException("NullPointerException:相乘的两个矩阵必须初始化!!!");
		if(metrixL.length==0 || metrixR.length==0)
			throw new RuntimeException("相乘的两个矩阵都不能为空!!!");
		if(metrixL[0].length!=metrixR.length)
			throw new RuntimeException("相乘的两个矩阵前列数要等于后行数!!!");
		
		//根据矩阵相乘的规则，得到结果矩阵的行列数
		Integer[][] r=new Integer[metrixL.length][metrixR[0].length];
		
		//左矩阵的行数，相当于结果矩阵r的行数
		for(int i=0;i<metrixL.length;i++){     
			 //右矩阵的列数，相当于结果矩阵r的列数
			for(int j=0;j<metrixR[0].length;j++){ 
				//结果矩阵的元素初始化为0,便于后面叠加
				r[i][j]=0;
				//用左矩阵的列数或者右矩阵的行数来迭代
				for(int k=0;k<metrixL[0].length;k++){
					r[i][j]+=metrixL[i][k]*metrixR[k][j];
				}
			}				
		}
		
		return r;
	}
	
	/**
	 * 
	 * @Title: getReverseClosure  
	 * @Description: 获得矩阵的自反矩阵
	 * @param metrix 源矩阵
	 * @param IsCopy 是否复制新的矩阵
	 * @return 目的矩阵
	 */
	public static Integer [][] getReverseClosure(Integer[][] metrix,boolean IsCopy){
		if(metrix==null)
			return null;
		if(metrix.length==0)
			return metrix;
		if(metrix.length!=metrix[0].length)
			throw new RuntimeException("求传递闭包必须是方阵！！！(行=列)");

		int n=metrix.length;
		
		Integer[][] tar=null;
		if(IsCopy){
			tar=new Integer[n][n];	
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==j)
						tar[i][j]=1;
					else
						tar[i][j]=metrix[i][j];
				}
			}
		}else{
			for(int i=0;i<n;i++)
				metrix[i][i]=1;
			tar=metrix;
		}
			
		return tar;
	}
	
}
