package cn.yjy.controller;

import cn.yjy.pojo.College;
import cn.yjy.pojo.Student;
import cn.yjy.service.StudentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * Created by yjy on 16-12-27.
 */

@RestController
public class StudentController {

    @Autowired
    private StudentService studentService;

    public StudentController(StudentService studentService) {
        this.studentService = studentService;
    }

    @RequestMapping("/student")
    public List<Student> listStudent(){
        return studentService.findAllStudent();
    }

    @RequestMapping("/student/{sno}")
    public Student findStudent(@PathVariable Integer sno){
        return studentService.findStudentBasicInformation(sno);
    }

    @RequestMapping("/student/{sno}/will")
    public Student findStudentDetails(@PathVariable Integer sno){
        return studentService.findAllStudentWill(sno);
    }

    @RequestMapping("/student/{sno}/enrollcollege")
    public College findEnrollCollegeOfStudent(@PathVariable Integer sno){
        return studentService.findStudentEnroll(sno);
    }
}
