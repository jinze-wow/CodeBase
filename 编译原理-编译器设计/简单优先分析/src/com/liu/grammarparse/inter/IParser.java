package com.liu.grammarparse.inter;

/**
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * ������������һ�����ڱ���ԭ���﷨������IParser�ӿ� <br> 
 * �����ƣ�com.liu.grammarparse.inter.IParser<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����10:54:12<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����10:54:12<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public interface IParser {
	
	/**
	 * 
	 * @Title: parseFirstMetrix  
	 * @Description: ����First����
	 * @return  ���ؾ���
	 */
	Integer[][]  parseFirstMetrix();
	
	/**
	 * 
	 * @Title: parseLastMetrix  
	 * @Description: ����Last����  
	 * @return  ���ؾ���
	 */
	Integer[][]  parseLastMetrix();

	/**
	 * 
	 * @Title: parseEqualProcedent  
	 * @Description: �������ڹ�ϵ�����ȼ�����
	 * @return ���ؾ���
	 */
	Integer[][]  parseEqualProcedent();
	
	/**
	 * 
	 * @Title: parseGreaterProcedent  
	 * @Description: �������ڹ�ϵ�����ȼ�����  
	 * @return ���ؾ���
	 */
	Integer[][]  parseGreaterProcedent();
	
	/**
	 * 
	 * @Title: parseLesserProcedent  
	 * @Description: �������ڹ�ϵ�����ȼ�����  
	 * @return ���ؾ���
	 */
	Integer[][]  parseLesserProcedent();
}
