package cn.yjy.controller;

import cn.yjy.pojo.College;
import cn.yjy.pojo.Student;
import cn.yjy.service.CollegeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.Set;

/**
 * Created by yjy on 16-12-27.
 */
@RestController
public class CollegeController {

    @Autowired
    private CollegeService collegeService;

    @RequestMapping("/college")
    public List<College> listCollege(){
        return collegeService.findAllCollege();
    }

    @RequestMapping("/college/enrollreport")
    public List<College> listEnrollReport(){
        return collegeService.findEnrollReport();
    }

    @RequestMapping("/college/{cno}")
    public College findCollege(@PathVariable Integer cno){
        return collegeService.findBasicCollegeInformation(cno);
    }

    @RequestMapping("/college/{cno}/enrolllist")
    public List<Student> findEnrollListOfCollege(@PathVariable Integer cno){
        return collegeService.findEnrollListOfCollege(cno);
    }
}
