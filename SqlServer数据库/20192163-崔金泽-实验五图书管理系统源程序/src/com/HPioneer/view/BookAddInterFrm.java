package com.HPioneer.view;

import java.awt.EventQueue;

import javax.swing.JInternalFrame;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.border.LineBorder;

import com.HPioneer.dao.BookDao;
import com.HPioneer.dao.BookTypeDao;
import com.HPioneer.model.Book;
import com.HPioneer.model.BookType;
import com.HPioneer.util.DbUtil;
import com.HPioneer.util.StringUtil;
import com.mysql.jdbc.Connection;

import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.JTextArea;
import javax.swing.JComboBox;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.awt.event.ActionEvent;
import javax.swing.ImageIcon;

public class BookAddInterFrm extends JInternalFrame {
	private JTextField bookNameTxt;
	private JTextField authorTxt;
	private final ButtonGroup buttonGroup = new ButtonGroup();
	private JTextField priceTxt;
	
	private DbUtil dbUtil = new DbUtil();
	private BookTypeDao bookTypeDao = new BookTypeDao();
	private BookDao bookDao = new BookDao();
	private	JComboBox bookTypeJcb;
	private JTextArea bookDescTxt;
	private JRadioButton manJrb; 
	private JRadioButton femaleJrb;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					BookAddInterFrm frame = new BookAddInterFrm();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public BookAddInterFrm() {
		setIconifiable(true);
		setClosable(true);
		setTitle("图书添加");
		setBounds(100, 100, 450, 463);
		
		JLabel lblNewLabel = new JLabel("图书名字：");
		
		bookNameTxt = new JTextField();
		bookNameTxt.setColumns(10);
		
		JLabel lblNewLabel_1 = new JLabel("图书作者：");
		
		authorTxt = new JTextField();
		authorTxt.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("作者性别：");
		
		manJrb = new JRadioButton("男");
		buttonGroup.add(manJrb);
		manJrb.setSelected(true);
		
		femaleJrb = new JRadioButton("女");
		buttonGroup.add(femaleJrb);
		
		JLabel lblNewLabel_3 = new JLabel("图书价格：");
		
		priceTxt = new JTextField();
		priceTxt.setColumns(10);
		
		JLabel lblNewLabel_4 = new JLabel("图书描述：");
		
	    bookDescTxt = new JTextArea();
		
		JLabel lblNewLabel_5 = new JLabel("图书类别：");
		
	    bookTypeJcb = new JComboBox();
		
		JButton btnNewButton = new JButton("添加");
		btnNewButton.setIcon(new ImageIcon(BookAddInterFrm.class.getResource("/images/add.png")));
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				bookAddActionPerformed(e);
			}
		});
		
		JButton btnNewButton_1 = new JButton("重置");
		btnNewButton_1.setIcon(new ImageIcon(BookAddInterFrm.class.getResource("/images/add.png")));
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				bookValueActionPerformed(e);
			}
		});
		
		btnNewButton_1.setIcon(new ImageIcon(BookAddInterFrm.class.getResource("/images/reset.png")));
		GroupLayout groupLayout = new GroupLayout(getContentPane());
		groupLayout.setHorizontalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addGroup(groupLayout.createSequentialGroup()
					.addGap(28)
					.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
						.addGroup(groupLayout.createSequentialGroup()
							.addComponent(lblNewLabel_4)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(bookDescTxt, GroupLayout.DEFAULT_SIZE, 262, Short.MAX_VALUE))
						.addGroup(groupLayout.createSequentialGroup()
							.addGroup(groupLayout.createParallelGroup(Alignment.LEADING, false)
								.addGroup(groupLayout.createSequentialGroup()
									.addComponent(lblNewLabel_2)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(manJrb)
									.addPreferredGap(ComponentPlacement.RELATED, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
									.addComponent(femaleJrb))
								.addGroup(groupLayout.createSequentialGroup()
									.addComponent(lblNewLabel)
									.addPreferredGap(ComponentPlacement.RELATED)
									.addComponent(bookNameTxt, GroupLayout.PREFERRED_SIZE, 91, GroupLayout.PREFERRED_SIZE)))
							.addGap(18)
							.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
								.addComponent(lblNewLabel_3)
								.addComponent(lblNewLabel_1))
							.addPreferredGap(ComponentPlacement.RELATED)
							.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
								.addComponent(authorTxt, GroupLayout.DEFAULT_SIZE, 89, Short.MAX_VALUE)
								.addComponent(priceTxt, GroupLayout.DEFAULT_SIZE, 89, Short.MAX_VALUE)))
						.addGroup(groupLayout.createSequentialGroup()
							.addComponent(btnNewButton)
							.addGap(33)
							.addComponent(btnNewButton_1))
						.addGroup(groupLayout.createSequentialGroup()
							.addComponent(lblNewLabel_5)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(bookTypeJcb, 0, 262, Short.MAX_VALUE)))
					.addGap(80))
		);
		groupLayout.setVerticalGroup(
			groupLayout.createParallelGroup(Alignment.LEADING)
				.addGroup(groupLayout.createSequentialGroup()
					.addGap(33)
					.addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNewLabel)
						.addComponent(bookNameTxt, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(authorTxt, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblNewLabel_1))
					.addGap(26)
					.addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNewLabel_2)
						.addComponent(manJrb)
						.addComponent(femaleJrb)
						.addComponent(lblNewLabel_3)
						.addComponent(priceTxt, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
					.addGap(26)
					.addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNewLabel_5)
						.addComponent(bookTypeJcb, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
					.addGap(30)
					.addGroup(groupLayout.createParallelGroup(Alignment.LEADING)
						.addComponent(lblNewLabel_4)
						.addComponent(bookDescTxt, GroupLayout.PREFERRED_SIZE, 140, GroupLayout.PREFERRED_SIZE))
					.addPreferredGap(ComponentPlacement.RELATED, 38, Short.MAX_VALUE)
					.addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
						.addComponent(btnNewButton)
						.addComponent(btnNewButton_1))
					.addGap(50))
		);
		getContentPane().setLayout(groupLayout);

		//显示文本域边框
		bookDescTxt.setBorder(new LineBorder(new java.awt.Color(127,157,185),1,false));
				
		fillBookType();
	}
	/**
	 * 重置事件处理
	 * @param e
	 */
	private void bookValueActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		this.resetValue();
	}

	private void bookAddActionPerformed(ActionEvent evt) {
		// TODO Auto-generated method stub
		String bookName = this.bookNameTxt.getText();
		String author = this.authorTxt.getText();
		String price = this.priceTxt.getText();
		String bookDesc = this.bookDescTxt.getText();
		
		 if(StringUtil.isEmpty(bookName)){
	        	JOptionPane.showMessageDialog(null,"图书名称不能为空");
	        }
		 if(StringUtil.isEmpty(author)){
	        	JOptionPane.showMessageDialog(null,"图书作者不能为空");
	        }
		 if(StringUtil.isEmpty(price)){
	        	JOptionPane.showMessageDialog(null,"图书价格不能为空");
	        }
		 
		 String sex ="";
		 if(manJrb.isSelected()){
			 sex="男";
		 }else{
			 sex="女";
		 }
		 
		 BookType bookType =(BookType) bookTypeJcb.getSelectedItem();
		 int bookTypeId = bookType.getId();
		 
		 Book book = new Book(bookName,author,sex,Float.parseFloat(price),bookTypeId,bookDesc);
		 
		 Connection con = null;
	        try{
	        	con=dbUtil.getCon();
	        	int addNum = bookDao.add(con, book);  	
	            if(addNum == 1){
	            	JOptionPane.showMessageDialog(null,"图书类别添加成功");	
	                resetValue();
	            }else{
	            	JOptionPane.showMessageDialog(null,"图书类别添加失败");
	            }
	        }catch(Exception e){
	        	e.printStackTrace();  
	        	JOptionPane.showMessageDialog(null,"图书类别添加失败");
	        }finally{
	        	try{
	        	dbUtil.closeCon(con);
	        	}catch (Exception e) {
					// TODO: handle exception
	        		e.printStackTrace();	
				}
	        	
	        }
	    }
	/**
	 * 重置表单
	 */
	private void resetValue() {
		// TODO Auto-generated method stub
		this.bookNameTxt.setText("");
		this.authorTxt.setText("");
		this.priceTxt.setText("");
		this.manJrb.setSelected(true);
		this.bookDescTxt.setText("");
		if(this.bookTypeJcb.getItemCount()>0){
			this.bookTypeJcb.setSelectedIndex(0);
			
		}
		
	}
	

	/**
	 * 初始化图书类别下拉框
	 */
	
	private void fillBookType(){
		Connection con = null;
		BookType bookType = null;
		try{
			con = dbUtil.getCon();
			ResultSet rs = bookTypeDao.list(con, new BookType());
		    while( rs.next() ){
		    	bookType = new BookType();
		    	bookType.setId(rs.getInt("id"));
		    	bookType.setBookTypeName(rs.getString("bookTypeName"));
		    	this.bookTypeJcb.addItem(bookType);
		     }
		 }catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}finally{
			
		}
	}
}

		
	