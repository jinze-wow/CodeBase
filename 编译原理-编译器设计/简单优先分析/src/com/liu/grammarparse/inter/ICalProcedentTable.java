package com.liu.grammarparse.inter;

/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：计算出简单优先关系的矩阵，这是一个接口 <br> 
 * 类名称：com.liu.grammarparse.inter.ICalProcedentTable<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 上午11:01:51<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 上午11:01:51<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public interface ICalProcedentTable {

	/**
	 * 
	 * @Title: getProcedentTable  
	 * @Description: 获得简单优先关系表，其中数组的元素意义为：<br>
	 * 		0：相等关系   <br>
	 * 		-1：小于关系(数组行元素小于列元素)  <br>
	 *      1：大于关系(数组行元素大于列元素)   <br>
	 * @return  返回矩阵
	 */
	Integer [][] getProcedentTable();
}
