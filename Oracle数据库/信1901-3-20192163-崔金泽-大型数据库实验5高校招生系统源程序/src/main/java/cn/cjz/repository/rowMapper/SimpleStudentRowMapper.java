package cn.yjy.repository.rowMapper;

import cn.yjy.pojo.Student;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by yjy on 17-1-1.
 */
public class SimpleStudentRowMapper implements RowMapper<Student> {
    @Override
    public Student mapRow(ResultSet resultSet, int i) throws SQLException {
        Student student = new Student();
        try {
            student.setNumber(resultSet.getInt("SNO"));
            student.setName(resultSet.getString("SNAME"));
            return student;
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
