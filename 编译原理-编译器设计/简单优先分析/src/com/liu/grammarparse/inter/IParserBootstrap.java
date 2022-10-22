package com.liu.grammarparse.inter;

import java.util.Map;
/**
 * 
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * �������������ķ���������  <br> 
 * �����ƣ�com.liu.grammarparse.inter.IParserBootstrap<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����11:40:00<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����11:40:00<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public interface IParserBootstrap {

	/**
	 * 
	 * @Title: parseNTernimal  
	 * @Description: �������ս��ַ��ͷ��ս��ַ�
	 * @param wenfa �ķ�
	 * @return  ���������ս��ַ��ͷ��ս��ַ�����
	 */
	Character[] parseNTernimal(String wenfa);
	
	
	/**
	 * 
	 * @Title: parseWenFaPartors  
	 * @Description: �������ķ����󲿺��Ҳ������磺S=>(a) | Ebs �������Ϊ:
	 *      ��         �Ҳ�    <br>
	 *       S         (a)   <br>
	 *       S         Ebs   <br> 
	 * @param wenfa  Ҫ�������ķ�
	 * @return  ����ӳ�䣬keyΪ�󲿣�valueΪ�Ҳ���"S":["(a)","Ebs"]
	 */
	Map<String, String[]>  parseWenFaPartors(String wenfa);
}
