package cn.itcast.goods.category.service;

import cn.itcast.goods.category.dao.CategoryDao;
import cn.itcast.goods.category.domain.Category;

import java.sql.SQLException;
import java.util.List;

/**
 * 分类模块业务层
 */
public class CategoryService {
	private CategoryDao categoryDao = new CategoryDao();
	
	/**
	 * 查询指定父分类下子分类的个数
	 */
	public int findChildrenCountByParent(String pid) {
		try {
			return categoryDao.findChildrenCountByParent(pid);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * 删除分类
	 */
	public void delete(String cid) {
		try {
			categoryDao.delete(cid);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * 修改分类
	 */
	public void edit(Category category) {
		try {
			categoryDao.edit(category);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * 加载分类
	 */
	public Category load(String cid) {
		try {
			return categoryDao.load(cid);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * 添加分类
	 */
	public void add(Category category) {
		try {
			categoryDao.add(category);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * 查询所有分类
	 */
	public List<Category> findAll() {
		try {
			return categoryDao.findAll();
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * 获取所有父分类，不带子分类
	 */
	public List<Category> findParents() {
		try {
			return categoryDao.findParents();
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
}