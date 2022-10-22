package com.HPioneer.util;

import org.junit.Test;

import com.mysql.jdbc.StringUtils;

/**
 * 字符串工具类
 * @author H_Pioneer
 *
 */
public class StringUtil {
	/**
	 * 判断是否为空
	 * @param str
	 * @return
	 */
	
	public static boolean isEmpty(String str){
		if(str==null||"".equals(str.trim())){
			return true;
	}else{
		return false;
	}
	}
	
	/**
	 * 判断不为空
	 * @param str
	 * @return
	 */
	public static boolean isNotEmpty(String str){
		if(str!=null&&!"".equals(str.trim())){
			return true;
	    }else{
		return false;
	    }
	}
	
	
	
	/**
	 * 
	 * mysql-connector-java-5.1.40-bin.jar
	 * 
	 * 这个包里面有判断是否为空的方法，你不用再写了
	 * 
	 * 在StringUtils类里面，他是一个加强的String类
	 * 在不？  恩
	 * 我给你找下
	 * com.mysql.jdbc
	 * StringUtils.class
	 * 你jdbc jar包在哪，我给你加下源码，你看看、mysql-connector-java-5.1.40-bin.jar
	 * 然后呢
	 */
	/*
	@Test
	public void isNotEmptyTest(){
		String string="";
		if(StringUtils.isNullOrEmpty(string))
			System.out.println("Is null");
		else
			System.out.println("It is not null");
		
	}
	
	
    public static boolean isNullOrEmpty(String toTest) {
        return (toTest == null || toTest.length() == 0);
    }
*/
}