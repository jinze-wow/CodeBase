package com.liu.grammarparse.inter;

/**
 * 
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * ������������������ȹ�ϵ�ľ�������һ���ӿ� <br> 
 * �����ƣ�com.liu.grammarparse.inter.ICalProcedentTable<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����11:01:51<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����11:01:51<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public interface ICalProcedentTable {

	/**
	 * 
	 * @Title: getProcedentTable  
	 * @Description: ��ü����ȹ�ϵ�����������Ԫ������Ϊ��<br>
	 * 		0����ȹ�ϵ   <br>
	 * 		-1��С�ڹ�ϵ(������Ԫ��С����Ԫ��)  <br>
	 *      1�����ڹ�ϵ(������Ԫ�ش�����Ԫ��)   <br>
	 * @return  ���ؾ���
	 */
	Integer [][] getProcedentTable();
}
