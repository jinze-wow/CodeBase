package cn.yjy.repository.rowMapper;

import cn.yjy.pojo.College;
import cn.yjy.pojo.Student;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by yjy on 17-1-2.
 */
public class StudentWillRowMapper implements RowMapper<Student> {
    @Override
    public Student mapRow(ResultSet resultSet, int i) throws SQLException {
        Student student = new Student();
        try {
            //学号
            student.setNumber(resultSet.getInt("STUDENT_NUMBER"));
            //志愿1
            College aspiration1 = new College();
            aspiration1.setNumber(resultSet.getInt("ASPIRATION1"));
            aspiration1.setName(resultSet.getString("CNAME1"));
            student.setAspiration1(aspiration1);
            //志愿2
            College aspiration2 = new College();
            aspiration2.setNumber(resultSet.getInt("ASPIRATION2"));
            aspiration2.setName(resultSet.getString("CNAME2"));
            student.setAspiration2(aspiration2);
            //服从调剂
            student.setAutoAdjust(resultSet.getBoolean("AUTO_ADJUST"));
            return student;
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
