package com.liu.grammarparse.impl;

import java.util.Map;

import com.liu.grammarparse.inter.ICalProcedentTable;
import com.liu.grammarparse.inter.IParserBootstrap;
import com.liu.grammarparse.inter.IValidator;

/**
 * 
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * �������������н���ģʽ(Mediator-Pattern)�����͸���ģ�������  <br> 
 * �����ƣ�com.liu.grammarparse.impl.Mediator<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����11:59:48<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����11:59:48<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public class Mediator {


	private IParserBootstrap bootStrap=null;
	private ICalProcedentTable calPTable=null;
	private IValidator validator=null;
	
	/**
	 * 
	 * Title:  Mediator���캯��
	 * Description: ����߲�ģ�����������ӿ�ʵ���ֱ࣬����Mediator�г�ʼ��,���ϵ����ط���
	 */
	public Mediator(){
		bootStrap=new ParseBootStrap();
		calPTable=new Parser();
		validator=new ValidatorGrammar();
	}
	
	/**
	 * 
	 * @Title: init  
	 * @Description: ע���������������,�������ս�����ս���ַ������ķ����Ҳ�ӳ��
	 * @param wenfa Ҫ�������ķ�
	 */
	public void init(String wenfa){
/*		if(bootStrap==null || calPTable==null || validator==null){
			throw new RuntimeException("����ע�������ӿ�,�ٳ�ʼ��");
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
	 * @Description: ���ؼ����ȼ�����߲�ģ��
	 * @return ��ü����ȹ�ϵ�����������Ԫ������Ϊ��<br>
	 * 		0����ȹ�ϵ   <br>
	 * 		-1��С�ڹ�ϵ(������Ԫ��С����Ԫ��)  <br>
	 *      1�����ڹ�ϵ(������Ԫ�ش�����Ԫ��)   <br>
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
	 * @Description: TODO(������һ�仰�����������������)  
	 * @param terminalStr
	 * @return mapӳ��,��ֵ��ϵΪ�� <br>
	 * 		"status":true(�����ķ�)��false(������)  <br>
	 *     "process":String(�ַ�����������֤�Ĺ���) <br>
	 */
	public Map<String, Object> getValidatorGrammar(String terminalStr){
		return validator.validateGrammar(terminalStr);
	}
}
