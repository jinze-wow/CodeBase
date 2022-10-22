package com.liu.grammarparse.impl;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

import com.liu.grammarparse.inter.IParserBootstrap;

/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：解析器的初始步骤  <br> 
 * 类名称：com.liu.grammarparse.impl.ParseBootStrap<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 上午11:53:39<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 上午11:53:39<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public class ParseBootStrap implements IParserBootstrap {

	@Override
	public Character[] parseNTernimal(String wenfa) {
		//去掉文法中的空格和跳格符
		wenfa=wenfa.replace(" ", "").replace("\t", "");
		
		//用set存储，可以保证互异性
		Set<Character> set=new HashSet<Character>();
		
		for(char ch:wenfa.toCharArray()){
			if(!"=>|\n\r\t".contains(ch+"")) //按要求加入符合标准的字符
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
			//用=>分割产生式的左右部分
			String[] split=tmp.split("=>");
			//用 | 将产生式右部分割
			String [] rpart=split[1].split("\\|",0);  //regular language | 要进行转义
			
			partors.put(split[0], rpart);
		}
		
		scan.close();
		
		return partors;
	}

}
