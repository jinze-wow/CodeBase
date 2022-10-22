package cn.itcast.goods.cart.web.servlet;


import cn.itcast.commons.CommonUtils;
import cn.itcast.goods.book.domain.Book;
import cn.itcast.goods.cart.domain.CartItem;
import cn.itcast.goods.cart.service.CartItemService;
import cn.itcast.goods.user.domain.User;
import cn.itcast.servlet.BaseServlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;
import java.util.Map;

public class CartItemServlet extends BaseServlet {
	private CartItemService cartItemService = new CartItemService();
	

	
	/**
	 * 添加购物车条目
	 */
	public String add(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		Map map = req.getParameterMap();
		CartItem cartItem = CommonUtils.toBean(map, CartItem.class);
		Book book = CommonUtils.toBean(map, Book.class);
		User user = (User)req.getSession().getAttribute("sessionUser");
		cartItem.setBook(book);
		cartItem.setUser(user);

		cartItemService.add(cartItem);
		return myCart(req, resp);
	}
	
	/**
	 * 我的购物车
	 */
	public String myCart(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		User user = (User)req.getSession().getAttribute("sessionUser");
		String uid = user.getUid();
		List<CartItem> cartItemLIst = cartItemService.myCart(uid);
		req.setAttribute("cartItemList", cartItemLIst);
		return "f:/jsps/cart/list.jsp";
	}
}
