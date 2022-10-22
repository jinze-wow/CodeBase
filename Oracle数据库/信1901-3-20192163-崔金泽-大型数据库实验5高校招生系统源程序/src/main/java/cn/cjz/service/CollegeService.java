package cn.yjy.service;

import cn.yjy.pojo.College;
import cn.yjy.pojo.Student;

import java.util.List;
import java.util.Set;

/**
 * Created by yjy on 16-12-27.
 */
public interface CollegeService {
    List<College> findAllCollege();

    College findBasicCollegeInformation(Integer cno);

    College findAllStudentInformation(Integer cno);

    List<Student> findEnrollListOfCollege(Integer cno);

    List<College> findEnrollReport();
}
