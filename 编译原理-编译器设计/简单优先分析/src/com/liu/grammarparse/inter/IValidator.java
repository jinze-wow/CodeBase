package com.liu.grammarparse.inter;

import java.util.Map;

/**
 * 
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * ����������֤�ս���Ŵ��Ƿ�����ķ�,����һ���ӿ�   <br> 
 * �����ƣ�com.liu.grammarparse.inter.IValidator<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����11:15:09<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����11:15:09<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public interface IValidator {

	/**
	 * 
	 * @Title: validateGrammar  
	 * @Description: ��֤ĳһ�ս���Ŵ��Ƿ�����ķ� 
	 * @param terminalStr �ս���Ŵ�
	 * @return mapӳ��,��ֵ��ϵΪ�� <br>
	 * 		"status":true(�����ķ�)��false(������)  <br>
	 *     "process":String(�ַ�����������֤�Ĺ���) <br>
	 */
	Map<String,Object> validateGrammar(String terminalStr);
}
