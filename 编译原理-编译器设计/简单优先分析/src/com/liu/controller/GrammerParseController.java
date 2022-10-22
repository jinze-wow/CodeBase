package com.liu.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;

import javax.jws.soap.InitParam;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.liu.grammarparse.impl.Mediator;
import com.sun.org.apache.xerces.internal.impl.dv.util.Base64;

import sun.misc.BASE64Decoder;

@WebServlet(name="grammarparse",urlPatterns={"/parse"})
public class GrammerParseController extends HttpServlet {

	private static final long serialVersionUID = 1L;
	
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		this.doPost(req, resp);
	}
	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		
		req.setCharacterEncoding("UTF-8");
		resp.setCharacterEncoding("UTF-8");
		
		String cmd=req.getParameter("cmd");
		if(cmd==null || "".equals(cmd))
			return ;
		
		if("getTable".equals(cmd)){
			String wenfa=req.getParameter("wenfa");
			
			if(wenfa==null || "".equals(wenfa))
				return;
			
			Mediator mediator=new Mediator();
			mediator.init(wenfa);
			Character [][] t=mediator.getProcedentTable();
	
			req.getSession().setAttribute("mediator", mediator);
			
			//Map<String,Object> map=mediator.getValidatorGrammar("((a),a)");
			//Map<String,Object> map=mediator.getValidatorGrammar("(i+i)*i");
			//System.out.println(map.get("process"));
			StringBuilder sb=new StringBuilder();
			sb.append("<table id=\"ptable\" cellpadding=\"3\" cellspacing=\"1\">");
			for(int i=0;i<t.length;i++){
				sb.append("<tr>");
				for(int j=0;j<t.length;j++){
					sb.append("<td>"+t[i][j]+"</td>");
				}
				sb.append("</tr>");
			}
			sb.append("</table>");
			
			PrintWriter w=resp.getWriter();
			w.write(sb.toString());
			w.flush();
			w.close();
		}else if("validate".equals(cmd)){
			String RT=req.getParameter("string");
			
			if(RT==null || "".equals(RT))
				return;

			Mediator mediator=(Mediator)req.getSession().getAttribute("mediator");
			Map<String, Object> s=mediator.getValidatorGrammar(RT);
			String process=(String)s.get("process");
			
			PrintWriter w=resp.getWriter();
			w.write(process);
			w.flush();
			w.close();
		}
		
	}

}
