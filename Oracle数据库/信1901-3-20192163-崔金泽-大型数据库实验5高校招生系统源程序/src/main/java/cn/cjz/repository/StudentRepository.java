package cn.yjy.repository;

import cn.yjy.pojo.College;
import cn.yjy.pojo.Student;

import java.util.List;
import java.util.Set;

/**
 * Created by yjy on 16-12-16.
 */
public interface StudentRepository {

    List<Student> getAllStudent();
    Student getBasicInformation(int sno);
    Student getWill(int sno);
    College getEnrollCollege(int sno);
}
