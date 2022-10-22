package com.HPioneer.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import com.HPioneer.model.BookType;
import com.HPioneer.util.StringUtil;

/**
 * 图书类别Dao类
 * @author H_Pioneer
 *
 */

public class BookTypeDao {

	/**
	 * 图书类别添加
	 * @param con
	 * @param bookType
	 * @return
	 * @throws Exception
	 */
	public int add(Connection con,BookType bookType)throws Exception{
		String sql="insert into t_bookType values(null,?,?)";
		PreparedStatement pstmt=con.prepareStatement(sql);
		pstmt.setString(1, bookType.getBookTypeName());
		pstmt.setString(2, bookType.getBookTypeDesc());
		return pstmt.executeUpdate();
	}
	
	/**
	 * 查询图书类别集合
	 * @param con
	 * @param bookType
	 * @return
	 * @throws Exception
	 */
	public ResultSet list(Connection con,BookType bookType)throws Exception{
		StringBuffer sb=new StringBuffer("select * from t_bookType");
		if(StringUtil.isNotEmpty(bookType.getBookTypeName())){
			sb.append(" and bookTypeName like '%"+bookType.getBookTypeName()+"%'");
		}
		PreparedStatement pstmt=con.prepareStatement(sb.toString().replaceFirst("and", "where"));
		return pstmt.executeQuery();
	}
	
	/**
	 * 删除图书类别
	 * @param con
	 * @param id
	 * @return
	 * @throws Exception
	 */
	public int delete(Connection con,String id)throws Exception{
		String sql="delete from t_bookType where id=?";
		PreparedStatement pstmt=con.prepareStatement(sql);
		pstmt.setString(1, id);
		return pstmt.executeUpdate();
	}
	
	/**
	 * 更新图示类别
	 * @param con
	 * @param bookType
	 * @return
	 * @throws Exception
	 */
	public int update(Connection con,BookType bookType)throws Exception{
		String sql="update t_bookType set bookTypeName=?,bookTypeDesc=? where id=?";
		PreparedStatement pstmt=con.prepareStatement(sql);
		pstmt.setString(1, bookType.getBookTypeName());
		pstmt.setString(2, bookType.getBookTypeDesc());
		pstmt.setInt(3, bookType.getId());
		return pstmt.executeUpdate();
	}
}
