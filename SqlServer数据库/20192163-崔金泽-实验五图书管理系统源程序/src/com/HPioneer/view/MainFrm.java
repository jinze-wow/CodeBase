package com.HPioneer.view;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import java.awt.GridLayout;
import javax.swing.SpringLayout;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.ImageIcon;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JDesktopPane;
import java.awt.Color;
import java.awt.SystemColor;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class MainFrm extends JFrame {

	private JPanel contentPane;
	private JDesktopPane table = null;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainFrm frame = new MainFrm();
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
	public MainFrm() {
		setTitle("图书管理主界面");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		JMenu menu = new JMenu("基本数据维护");
		menu.setIcon(new ImageIcon(MainFrm.class.getResource("/images/base.png")));
		menuBar.add(menu);
		
		JMenu mnNewMenu = new JMenu("图书类别管理");
		mnNewMenu.setIcon(new ImageIcon(MainFrm.class.getResource("/images/bookTypeManager.png")));
		menu.add(mnNewMenu);
		
		JMenuItem menuItem = new JMenuItem("图书类别添加");
		menuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BookTypeAddInterFrm bookTypeAddInterFrm = new BookTypeAddInterFrm();
				bookTypeAddInterFrm.setVisible(true);
			    table.add(bookTypeAddInterFrm);
			}
		});
		menuItem.setIcon(new ImageIcon(MainFrm.class.getResource("/images/add.png")));
		mnNewMenu.add(menuItem);
		
		JMenuItem menuItem_2 = new JMenuItem("图书类别维护");
		menuItem_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BookTypeManagerInterFrm bookTypeManagerInterFrm = new BookTypeManagerInterFrm();
				bookTypeManagerInterFrm.setVisible(true);
			    table.add(bookTypeManagerInterFrm);
			}
		});
		menuItem_2.setIcon(new ImageIcon(MainFrm.class.getResource("/images/edit.png")));
		mnNewMenu.add(menuItem_2);
		
		JMenu mnNewMenu_1 = new JMenu("图书管理");
		mnNewMenu_1.setIcon(new ImageIcon(MainFrm.class.getResource("/images/bookManager.png")));
		menu.add(mnNewMenu_1);
		
		JMenuItem menuItem_1 = new JMenuItem("图书添加");
		menuItem_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BookAddInterFrm bookAddInterFrm = new BookAddInterFrm();
				bookAddInterFrm.setVisible(true);
			    table.add(bookAddInterFrm);
				
			}
		});
		menuItem_1.setIcon(new ImageIcon(MainFrm.class.getResource("/images/add.png")));
		mnNewMenu_1.add(menuItem_1);
		
		JMenuItem mntmNewMenuItem = new JMenuItem("图书维护");
		mntmNewMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BookManageInterFrm bookManagerInterFrm = new BookManageInterFrm();
				bookManagerInterFrm.setVisible(true);
			    table.add(bookManagerInterFrm);
			}
		});
		mntmNewMenuItem.setIcon(new ImageIcon(MainFrm.class.getResource("/images/edit.png")));
		mnNewMenu_1.add(mntmNewMenuItem);
		
		JMenuItem menuItem_3 = new JMenuItem("安全退出");
		menuItem_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			    int result =JOptionPane.showConfirmDialog(null,"是否退出系统");
			    
			}
		});
		menuItem_3.setIcon(new ImageIcon(MainFrm.class.getResource("/images/exit.png")));
		menu.add(menuItem_3);
		
		JMenu menu_1 = new JMenu("关于我们");

		menu_1.setIcon(new ImageIcon(MainFrm.class.getResource("/images/about.png")));
		menuBar.add(menu_1);
		
		JMenuItem mntmhpioneer = new JMenuItem("关于HPioneer");
		mntmhpioneer.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				 HPioneer1234InterFrm hPioneer1234InterFrm = new HPioneer1234InterFrm();
				    hPioneer1234InterFrm.setVisible(true);
				    table.add(hPioneer1234InterFrm);
			}
		});
		mntmhpioneer.setIcon(new ImageIcon(MainFrm.class.getResource("/images/userName.png")));
		menu_1.add(mntmhpioneer);
		contentPane = new JPanel();
		contentPane.setForeground(Color.BLUE);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));
		
        table = new JDesktopPane();		
		table.setBackground(Color.WHITE);
		contentPane.add(table);
		
		//设置Jrame最大化
		this.setExtendedState(JFrame.MAXIMIZED_BOTH);
	}
}
