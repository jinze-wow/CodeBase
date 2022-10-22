package com.liu.grammarparse.inter;

import java.util.Map;

/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：验证终结符号串是否符合文法,这是一个接口   <br> 
 * 类名称：com.liu.grammarparse.inter.IValidator<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 上午11:15:09<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 上午11:15:09<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public interface IValidator {

	/**
	 * 
	 * @Title: validateGrammar  
	 * @Description: 验证某一终结符号串是否符合文法 
	 * @param terminalStr 终结符号串
	 * @return map映射,键值关系为： <br>
	 * 		"status":true(符合文法)，false(不符合)  <br>
	 *     "process":String(字符串，代表验证的过程) <br>
	 */
	Map<String,Object> validateGrammar(String terminalStr);
}
