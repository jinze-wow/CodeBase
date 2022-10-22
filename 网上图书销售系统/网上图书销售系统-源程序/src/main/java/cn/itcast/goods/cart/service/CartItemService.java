package cn.itcast.goods.cart.service;

import cn.itcast.commons.CommonUtils;
import cn.itcast.goods.cart.dao.CartItemDao;
import cn.itcast.goods.cart.domain.CartItem;

import java.sql.SQLException;
import java.util.List;

public class CartItemService {
	private CartItemDao cartItemDao = new CartItemDao();

	public List<CartItem> loadCartItems(String cartItemIds) {
		try {
			return cartItemDao.loadCartItems(cartItemIds);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	/**
	 * 修改购物车条目数量
	 */
	public CartItem updateQuantity(String cartItemId, int quantity) {
		try {
			cartItemDao.updateQuantity(cartItemId, quantity);
			return cartItemDao.findByCartItemId(cartItemId);
		} catch(SQLException e) {
			throw new RuntimeException(e);
		}
	}
	/**
	 * 批量删除功能
	 */
	public void batchDelete(String cartItemIds) {
		try {
			cartItemDao.batchDelete(cartItemIds);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
	/**
	 * 添加条目
	 */
	public void add(CartItem cartItem) {
		try {
			CartItem _cartItem = cartItemDao.findByUidAndBid(
					cartItem.getUser().getUid(),
					cartItem.getBook().getBid());
			if(_cartItem == null) {
				cartItem.setCartItemId(CommonUtils.uuid());
				cartItemDao.addCartItem(cartItem);
			} else {//如果原来有这个条目，修改数量
				int quantity = cartItem.getQuantity() + _cartItem.getQuantity();
				cartItemDao.updateQuantity(_cartItem.getCartItemId(), quantity);
			}
		} catch(Exception e) {
			throw new RuntimeException(e);
		}
	}
	/**
	 * 我的购物车功能
	 */
	public List<CartItem> myCart(String uid) {
		try {
			return cartItemDao.findByUser(uid);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}
}
