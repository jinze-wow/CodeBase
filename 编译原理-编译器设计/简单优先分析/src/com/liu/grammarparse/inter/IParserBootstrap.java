package com.liu.grammarparse.inter;

import java.util.Map;
/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：解析文法的启动项  <br> 
 * 类名称：com.liu.grammarparse.inter.IParserBootstrap<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 上午11:40:00<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 上午11:40:00<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public interface IParserBootstrap {

	/**
	 * 
	 * @Title: parseNTernimal  
	 * @Description: 解析出终结字符和非终结字符
	 * @param wenfa 文法
	 * @return  解析出的终结字符和非终结字符数组
	 */
	Character[] parseNTernimal(String wenfa);
	
	
	/**
	 * 
	 * @Title: parseWenFaPartors  
	 * @Description: 解析出文法的左部和右部，比如：S=>(a) | Ebs 解析结果为:
	 *      左部         右部    <br>
	 *       S         (a)   <br>
	 *       S         Ebs   <br> 
	 * @param wenfa  要解析的文法
	 * @return  返回映射，key为左部，value为右部，"S":["(a)","Ebs"]
	 */
	Map<String, String[]>  parseWenFaPartors(String wenfa);
}
