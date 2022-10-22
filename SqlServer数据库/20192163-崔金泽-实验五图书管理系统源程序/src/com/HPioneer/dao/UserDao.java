package com.HPioneer.dao;

import java.sql.ResultSet;

import com.HPioneer.model.User;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.PreparedStatement;
/**
 * 用户Dao类
 * @author H_Pioneer
 *
 */
public class UserDao {
	/**
	 * 登录验证
	 * @param con
	 * @param user
	 * @return
	 * @throws Exception
	 */
	public User login(Connection con,User user)throws Exception {
		User resultUser = null;
		String sql = "select * from t_user where userName=? and password=?";
	    PreparedStatement pstmt = (PreparedStatement) con.prepareStatement(sql);
		pstmt.setString(1,user.getUserName());
		pstmt.setString(2,user.getPassword());
	    ResultSet rs = pstmt.executeQuery();
	    if(rs.next()){
	    	resultUser = new User();
	    	resultUser.setId(rs.getInt("id"));
	    	resultUser.setUserName(rs.getString("userName"));
	    	resultUser.setPassword(rs.getString("password"));
	    }
		return resultUser;
	}

}
