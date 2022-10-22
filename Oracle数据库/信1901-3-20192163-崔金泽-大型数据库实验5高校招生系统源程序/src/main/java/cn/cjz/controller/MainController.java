package cn.yjy.controller;

import cn.yjy.service.EnrollService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;

/**
 * Created by yjy on 16-12-25.
 */

@Controller
public class MainController {

    @Autowired
    private EnrollService enrollService;

    @RequestMapping({"","/"})
    public String index(HttpServletRequest request){
        return "index.html";
    }

    @RequestMapping(value = "/enrollmanipulator",method = RequestMethod.GET)
    public ModelAndView manipulator(ModelAndView modelAndView){
        modelAndView.setViewName("manipulator.html");
        return modelAndView;
    }

    @RequestMapping(value = "/enrollmanipulator",method = RequestMethod.POST)
    public @ResponseBody
    ResponseEntity<String> manipulator_POST(@RequestParam("request_type") Integer request_type){
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.add("Access-Control-Allow-Origin","*");
        try {
            if (request_type == 1){
                enrollService.AutoEnroll();
                return  new ResponseEntity<String>("自动投档已完成",httpHeaders,HttpStatus.OK);
            }else if (request_type == 2){
                enrollService.ClearStatus();
                return new ResponseEntity<String>("一键还原已完成",httpHeaders,HttpStatus.OK);
            }else {
                return new ResponseEntity<String>("请求格式错误",httpHeaders,HttpStatus.BAD_REQUEST);
            }
        } catch (Exception e) {
            e.printStackTrace();
            return new ResponseEntity<String>("出错啦！",httpHeaders,HttpStatus.BAD_REQUEST);
        }
    }
}
