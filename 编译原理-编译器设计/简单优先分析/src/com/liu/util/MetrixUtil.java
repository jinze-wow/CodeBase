package com.liu.util;

/**
 * 
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * ���������й��ھ����һЩ�����෽��  <br> 
 * �����ƣ�com.liu.util.MetrixUtil<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����1:47:17<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����1:47:17<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public class MetrixUtil {

	/**
	 * 
	 * @Title: transpositionMetrix  
	 * @Description: ת��һ������
	 * @param metrix Ҫת�õľ���
	 * @return ����ת�úõľ���
	 */
	public static Integer [][] transpositionMetrix(Integer[][] metrix){
		
		if(metrix==null)
			return null;
		if(metrix.length==0)
			return metrix;
		
		Integer [][] r=new Integer[metrix.length][metrix[0].length];
		
		for(int i=0;i<metrix.length;i++){
			for(int j=0;j<=i;j++){
				r[j][i]=metrix[i][j];
				
				if(i!=j) r[i][j]=metrix[j][i];			
			}
		}
		
		return r;
	}
	
	/**
	 * 
	 * @Title: transitiveClosuresByWarShall  
	 * @Description: ��WarShall�㷨��ù�ϵ���ݱհ������㷨����У�������ͼ�Ŀɴ����о�
	 * @param metrix Դ����
	 * @return ����Ŀ�ľ���
	 */
	public static Integer [][] transitiveClosuresByWarShall(Integer[][] metrix){
		if(metrix == null)
			return null;
		if(metrix.length == 0)
			return metrix;
		if(metrix.length!=metrix[0].length)
			throw new RuntimeException("�󴫵ݱհ������Ƿ��󣡣���(��=��)");

		Integer n=metrix.length;
		Integer [][] r=new Integer[n][n];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				r[i][j]=metrix[i][j];
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(r[j][i]!=0){
					for(int k=0;k<n;k++){
						if(r[i][k]!=0)
							r[j][k]=1;
					}
				}
			}
		}
	
		return r;
	}
	
	/**
	 * 
	 * @Title: multiplyTwoMetrix  
	 * @Description: ����������� 
	 * @param metrixL ��һ������
	 * @param metrixR �ڶ�������
	 * @return ������˺�ľ���
	 */
	public static Integer [][] multiplyTwoMetrix(Integer[][] metrixL,Integer[][] metrixR){
		if(metrixL==null || metrixR==null)
			throw new RuntimeException("NullPointerException:��˵�������������ʼ��!!!");
		if(metrixL.length==0 || metrixR.length==0)
			throw new RuntimeException("��˵��������󶼲���Ϊ��!!!");
		if(metrixL[0].length!=metrixR.length)
			throw new RuntimeException("��˵���������ǰ����Ҫ���ں�����!!!");
		
		//���ݾ�����˵Ĺ��򣬵õ���������������
		Integer[][] r=new Integer[metrixL.length][metrixR[0].length];
		
		//�������������൱�ڽ������r������
		for(int i=0;i<metrixL.length;i++){     
			 //�Ҿ�����������൱�ڽ������r������
			for(int j=0;j<metrixR[0].length;j++){ 
				//��������Ԫ�س�ʼ��Ϊ0,���ں������
				r[i][j]=0;
				//�����������������Ҿ��������������
				for(int k=0;k<metrixL[0].length;k++){
					r[i][j]+=metrixL[i][k]*metrixR[k][j];
				}
			}				
		}
		
		return r;
	}
	
	/**
	 * 
	 * @Title: getReverseClosure  
	 * @Description: ��þ�����Է�����
	 * @param metrix Դ����
	 * @param IsCopy �Ƿ����µľ���
	 * @return Ŀ�ľ���
	 */
	public static Integer [][] getReverseClosure(Integer[][] metrix,boolean IsCopy){
		if(metrix==null)
			return null;
		if(metrix.length==0)
			return metrix;
		if(metrix.length!=metrix[0].length)
			throw new RuntimeException("�󴫵ݱհ������Ƿ��󣡣���(��=��)");

		int n=metrix.length;
		
		Integer[][] tar=null;
		if(IsCopy){
			tar=new Integer[n][n];	
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==j)
						tar[i][j]=1;
					else
						tar[i][j]=metrix[i][j];
				}
			}
		}else{
			for(int i=0;i<n;i++)
				metrix[i][i]=1;
			tar=metrix;
		}
			
		return tar;
	}
	
}
