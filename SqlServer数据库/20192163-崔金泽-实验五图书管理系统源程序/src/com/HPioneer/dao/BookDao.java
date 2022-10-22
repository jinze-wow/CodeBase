package com.HPioneer.dao;

import java.sql.ResultSet;
import java.sql.SQLException;

import com.HPioneer.model.Book;
import com.HPioneer.model.BookType;
import com.HPioneer.util.StringUtil;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.PreparedStatement;

/**
 * 图书Dao类
 * @author H_Pioneer
 *
 */
public class BookDao {
	
	/**
	 * 图书添加
	 * @param con
	 * @param book
	 * @return
	 * @throws Exception
	 */
	public int add(Connection con,Book book)throws Exception{
		//这个可以写有参构造，不要id，就方便了，以后多注意吧
		String sql="insert into t_book values(null,?,?,?,?,?,?)";
		PreparedStatement pstmt=(PreparedStatement) con.prepareStatement(sql);
		pstmt.setString(1, book.getBookName());
		pstmt.setString(2, book.getAuthor());
		pstmt.setString(3, book.getSex());
		pstmt.setFloat(4, book.getPrice());
		pstmt.setInt(5, book.getBookTypeId());
		pstmt.setString(6, book.getBookDesc());
		return pstmt.executeUpdate();
	}
	
	/**
	 * 图书信息查询
	 * @param con
	 * @param book
	 * @return
	 * @throws Exception
	 */
	public ResultSet list(Connection con,Book book)throws Exception{
		StringBuffer sb=new StringBuffer("select * from t_book b,t_bookType bt where b.bookTypeId=bt.id");
		if(StringUtil.isNotEmpty(book.getBookName())){
			sb.append(" and b.bookName like '%"+book.getBookName()+"%'");
		}
		if(StringUtil.isNotEmpty(book.getAuthor())){
			sb.append(" and b.author like '%"+book.getAuthor()+"%'");
		}
		if(book.getBookTypeId()!=null && book.getBookTypeId()!=-1){
			sb.append(" and b.bookTypeId="+book.getBookTypeId());
		}
		PreparedStatement pstmt=(PreparedStatement) con.prepareStatement(sb.toString());
		return pstmt.executeQuery();
	}
	
	/**
	 * 图书信息删除
	 * @param con
	 * @param id
	 * @return
	 * @throws SQLException
	 */
	public int delete(Connection con,String id)throws Exception{
		String sql="delete from t_book where id=?";
		PreparedStatement pstmt=(PreparedStatement) con.prepareStatement(sql);
		pstmt.setString(1, id);
		return pstmt.executeUpdate();
	}
	
	/**
	 * 图书信息修改
	 * @param con
	 * @param book
	 * @return
	 * @throws Exception
	 */
	public int update(Connection con,Book book)throws Exception{
		String sql="update t_book set bookName=?,author=?,sex=?,price=?,bookDesc=?,bookTypeId=? where id=?";
		PreparedStatement pstmt=(PreparedStatement) con.prepareStatement(sql);
		
		
		pstmt.setString(1, book.getBookName());
		pstmt.setString(2, book.getAuthor());
		pstmt.setString(3, book.getSex());
		pstmt.setFloat(4, book.getPrice());
		pstmt.setString(5, book.getBookDesc());
		pstmt.setInt(6, book.getBookTypeId());
		pstmt.setInt(7, book.getId());
		return pstmt.executeUpdate();
	}
	
	/**
	 * 
	 * @param con
	 * @param bookTypeId
	 * @return
	 * @throws Exception
	 */
	public boolean existBookByBookTypeId(Connection con,String bookTypeId)throws Exception{
		String sql="select * from t_book where bookTypeId=?";
		PreparedStatement pstmt=(PreparedStatement) con.prepareStatement(sql);
		//我记错了，是getXX();
		pstmt.setString(1, bookTypeId);
		//this is can do .
		//在打完pstmt.executeQuery();后
		//按alt +shift+ L然后修改下变量name。
		ResultSet rs = pstmt.executeQuery();
		String string = new String();
		return rs.next();
	}
	
	
	//pstmt.setString(1, bookTypeId);
	//类似这种，是不是可以写一个函数，根据参数直接调用
	//一直手打，有部分感觉很难受啊
	
}
