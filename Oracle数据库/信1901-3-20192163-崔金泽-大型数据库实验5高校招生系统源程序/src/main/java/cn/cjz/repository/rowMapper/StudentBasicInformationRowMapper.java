package cn.yjy.repository.rowMapper;

import cn.yjy.pojo.Student;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by yjy on 17-1-1.
 */
public class StudentBasicInformationRowMapper implements RowMapper<Student> {
    @Override
    public Student mapRow(ResultSet resultSet, int i) throws SQLException {
        Student student = new Student();
        try {
            student.setNumber(resultSet.getInt("STUDENT_NUMBER"));
            student.setName(resultSet.getString("STUDENT_NAME"));
            student.setGender(resultSet.getString("GENDER").charAt(0));
            student.setGrade(resultSet.getInt("GRADE"));
            return student;
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
