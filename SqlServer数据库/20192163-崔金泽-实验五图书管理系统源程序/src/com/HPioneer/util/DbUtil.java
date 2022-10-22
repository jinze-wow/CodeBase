package com.HPioneer.util;

import java.sql.DriverManager;

import com.mysql.jdbc.Connection;

public class DbUtil {
//也可以这样
//private String dbUrl = "jdbc:mysql:///db_book";
	private String dbUrl = "jdbc:mysql://localhost:3306/db_book";
	private String dbUserName = "root";
	private String dbPassword = "123456";
	private String jdbcName = "com.mysql.jdbc.Driver";
	
	/**
	 * 获取数据库连接
	 * @return
	 * @throws Exception
	 */
	public Connection getCon()throws Exception{
	    Class.forName(jdbcName);
		Connection con = (Connection) DriverManager.getConnection(dbUrl,dbUserName,dbPassword);//链接数据库
		return con;
		
	}
	
	/**
	 * 关闭数据库连接
	 * @param con
	 * @throws Exception
	 */
	public void closeCon (java.sql.Connection con)throws Exception {
		if(con!=null){
			con.close();
		}
	}
	
	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		DbUtil dbUtil = new DbUtil();
		try {
			dbUtil.getCon();
			System.out.println("数据库连接成功");
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();    //在命令行打印异常信息在程序中出错的位置及原因。
			System.out.println("数据库连接");
		}
				
	}

	
}
