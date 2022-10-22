package com.liu.grammarparse.inter;

/**
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：这是一个关于编译原理语法解析的IParser接口 <br> 
 * 类名称：com.liu.grammarparse.inter.IParser<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 上午10:54:12<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 上午10:54:12<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public interface IParser {
	
	/**
	 * 
	 * @Title: parseFirstMetrix  
	 * @Description: 解析First矩阵
	 * @return  返回矩阵
	 */
	Integer[][]  parseFirstMetrix();
	
	/**
	 * 
	 * @Title: parseLastMetrix  
	 * @Description: 解析Last矩阵  
	 * @return  返回矩阵
	 */
	Integer[][]  parseLastMetrix();

	/**
	 * 
	 * @Title: parseEqualProcedent  
	 * @Description: 解析等于关系的优先级矩阵
	 * @return 返回矩阵
	 */
	Integer[][]  parseEqualProcedent();
	
	/**
	 * 
	 * @Title: parseGreaterProcedent  
	 * @Description: 解析大于关系的优先级矩阵  
	 * @return 返回矩阵
	 */
	Integer[][]  parseGreaterProcedent();
	
	/**
	 * 
	 * @Title: parseLesserProcedent  
	 * @Description: 解析大于关系的优先级矩阵  
	 * @return 返回矩阵
	 */
	Integer[][]  parseLesserProcedent();
}
