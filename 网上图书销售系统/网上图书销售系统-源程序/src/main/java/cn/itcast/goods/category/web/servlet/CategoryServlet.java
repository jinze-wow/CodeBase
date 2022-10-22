package cn.itcast.goods.category.web.servlet;

import cn.itcast.goods.category.domain.Category;
import cn.itcast.goods.category.service.CategoryService;
import cn.itcast.servlet.BaseServlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

/**
 * 分类模块WEB层
 */
public class CategoryServlet extends BaseServlet {
	private CategoryService categoryService = new CategoryService();	
	
	/**
	 * 查询所有分类
	 */
	public String findAll(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		List<Category> parents = categoryService.findAll();
		req.setAttribute("parents", parents);
		return "f:/jsps/left.jsp";
	}
 }
