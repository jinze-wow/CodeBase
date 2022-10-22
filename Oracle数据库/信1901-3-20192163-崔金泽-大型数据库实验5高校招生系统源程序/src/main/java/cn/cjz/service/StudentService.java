package cn.yjy.service;

import cn.yjy.pojo.College;
import cn.yjy.pojo.Student;

import java.util.List;
import java.util.Set;

/**
 * Created by yjy on 16-12-27.
 */
public interface StudentService {
    List<Student> findAllStudent();

    Student findStudentBasicInformation(Integer sno);

    Student findAllStudentWill(Integer sno);

    College findStudentEnroll(Integer sno);
}
