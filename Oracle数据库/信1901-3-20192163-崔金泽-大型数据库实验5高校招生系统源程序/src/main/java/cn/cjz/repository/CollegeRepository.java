package cn.yjy.repository;

import cn.yjy.pojo.College;
import cn.yjy.pojo.Student;

import java.util.List;
import java.util.Set;

/**
 * Created by yjy on 16-12-26.
 */
public interface CollegeRepository {

    List<College> getAllCollege();
    College getBasicCollegeInformation(int cno);
    College getAllCollegeInformation(int cno);
    List<Student> getStudentList(Integer cno);

    List<College> getEnrollReport();
}
