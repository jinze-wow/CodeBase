package com.liu.grammarparse.impl;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

import com.liu.grammarparse.inter.IParserBootstrap;

/**
 * 
 * ��Ŀ���ƣ�grammarparser<br>     
 *  
 * ���������������ĳ�ʼ����  <br> 
 * �����ƣ�com.liu.grammarparse.impl.ParseBootStrap<br>        
 * �����ˣ���ɳ<br> 
 * ����ʱ�䣺2016��5��8�� ����11:53:39<br>      
 * �޸��ˣ� ��<br>  
 * �޸�ʱ�䣺2016��5��8�� ����11:53:39<br>      
 * �޸ı�ע����<br>      
 * @version   V1.0
 */
public class ParseBootStrap implements IParserBootstrap {

	@Override
	public Character[] parseNTernimal(String wenfa) {
		//ȥ���ķ��еĿո�������
		wenfa=wenfa.replace(" ", "").replace("\t", "");
		
		//��set�洢�����Ա�֤������
		Set<Character> set=new HashSet<Character>();
		
		for(char ch:wenfa.toCharArray()){
			if(!"=>|\n\r\t".contains(ch+"")) //��Ҫ�������ϱ�׼���ַ�
				set.add(ch);
		}
		
		return set.toArray(new Character[0]);
	}

	@Override
	public Map<String, String[]> parseWenFaPartors(String wenfa) {
		wenfa=wenfa.replace(" ", "").replace("\t", "");
		
		//Debug
		//System.out.println(wenfa);
		
		Scanner scan=new Scanner(wenfa);
		Map<String,String[]> partors=new HashMap<String, String[]>();
		
		while(scan.hasNext()){
			String tmp=scan.nextLine();
			//��=>�ָ����ʽ�����Ҳ���
			String[] split=tmp.split("=>");
			//�� | ������ʽ�Ҳ��ָ�
			String [] rpart=split[1].split("\\|",0);  //regular language | Ҫ����ת��
			
			partors.put(split[0], rpart);
		}
		
		scan.close();
		
		return partors;
	}

}
