package com.liu.grammarparse.impl;

import java.util.Map;

import com.liu.grammarparse.inter.ICalProcedentTable;
import com.liu.grammarparse.inter.IParserBootstrap;
import com.liu.grammarparse.inter.IValidator;

/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：运用中介者模式(Mediator-Pattern)来降低各个模块耦合性  <br> 
 * 类名称：com.liu.grammarparse.impl.Mediator<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 上午11:59:48<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 上午11:59:48<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public class Mediator {


	private IParserBootstrap bootStrap=null;
	private ICalProcedentTable calPTable=null;
	private IValidator validator=null;
	
	/**
	 * 
	 * Title:  Mediator构造函数
	 * Description: 避免高层模块依赖三个接口实现类，直接在Mediator中初始化,符合迪米特法则
	 */
	public Mediator(){
		bootStrap=new ParseBootStrap();
		calPTable=new Parser();
		validator=new ValidatorGrammar();
	}
	
	/**
	 * 
	 * @Title: init  
	 * @Description: 注入相关依赖的属性,包括非终结符和终结符字符串，文法左右部映射
	 * @param wenfa 要解析的文法
	 */
	public void init(String wenfa){
/*		if(bootStrap==null || calPTable==null || validator==null){
			throw new RuntimeException("请先注入三个接口,再初始化");
		}
*/		
		Character[] NTernimal=bootStrap.parseNTernimal(wenfa);
		Map<String, String[]> partors=bootStrap.parseWenFaPartors(wenfa);
		((Parser)calPTable).setNTernimal(NTernimal);
		((Parser)calPTable).setLRpartors(partors);
		((ValidatorGrammar)validator).setStartFlag(wenfa.charAt(0)+"");
		((ValidatorGrammar)validator).setLRpartors(partors);
		((ValidatorGrammar)validator).setNTernimal(NTernimal);
	}
	
	/**
	 * 
	 * @Title: getProcedentTable  
	 * @Description: 返回简单优先级表给高层模块
	 * @return 获得简单优先关系表，其中数组的元素意义为：<br>
	 * 		0：相等关系   <br>
	 * 		-1：小于关系(数组行元素小于列元素)  <br>
	 *      1：大于关系(数组行元素大于列元素)   <br>
	 */
	public Character[][] getProcedentTable(){
		Integer [][] table=calPTable.getProcedentTable();
		((ValidatorGrammar)validator).setProcedentTable(table);
		
		Character[][] deco=((Parser)calPTable).decorateTable(table);
		
		return deco;
	}
	
	/**
	 * 
	 * @Title: getValidatorGrammar  
	 * @Description: TODO(这里用一句话描述这个方法的作用)  
	 * @param terminalStr
	 * @return map映射,键值关系为： <br>
	 * 		"status":true(符合文法)，false(不符合)  <br>
	 *     "process":String(字符串，代表验证的过程) <br>
	 */
	public Map<String, Object> getValidatorGrammar(String terminalStr){
		return validator.validateGrammar(terminalStr);
	}
}
