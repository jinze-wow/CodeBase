package cn.yjy.repository.rowMapper;

import cn.yjy.pojo.College;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by yjy on 17-1-1.
 */
public class SimpleCollegeRowMapper implements RowMapper<College> {
    @Override
    public College mapRow(ResultSet resultSet, int i) throws SQLException {
        College college = new College();
        try {
            college.setNumber(resultSet.getInt("CNO"));
            college.setName(resultSet.getString("COLLEGE_NAME"));
            return college;
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
