package cn.yjy.repository.imp;

import cn.yjy.pojo.College;
import cn.yjy.pojo.Student;
import cn.yjy.repository.StudentRepository;
import cn.yjy.repository.rowMapper.SimpleCollegeRowMapper;
import cn.yjy.repository.rowMapper.StudentBasicInformationRowMapper;
import cn.yjy.repository.rowMapper.StudentWillRowMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * Created by yjy on 16-12-16.
 */
@Repository
public class StudentRepositoryImp implements StudentRepository {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    private StudentBasicInformationRowMapper studentBasicInformationRowMapper = new StudentBasicInformationRowMapper();

    private StudentWillRowMapper studentWillRowMapper = new StudentWillRowMapper();

    private SimpleCollegeRowMapper simpleCollegeRowMapper = new SimpleCollegeRowMapper();

    @Override
    public List<Student> getAllStudent() {
        return jdbcTemplate.query("select * from YJY_HOMEWORK.STUDENT", new Object[]{}, studentBasicInformationRowMapper);
    }

    @Override
    public Student getBasicInformation(int sno) {
        return jdbcTemplate.queryForObject("select * from YJY_HOMEWORK.STUDENT WHERE STUDENT_NUMBER=?", new Object[]{sno}, studentBasicInformationRowMapper);
    }

    @Override
    public Student getWill(int sno) {
        Student student = null;
        try {
            student = jdbcTemplate.queryForObject("select * from YJY_HOMEWORK.ALL_WILL WHERE STUDENT_NUMBER=?", new Object[]{sno}, studentWillRowMapper);
        } catch (DataAccessException e) {
            e.printStackTrace();
        }
        return student;
    }

    @Override
    public College getEnrollCollege(int sno) {
        try {
            return jdbcTemplate.queryForObject("select * from YJY_HOMEWORK.ENROLL_RESULT WHERE SNO=?", new Object[]{sno}, simpleCollegeRowMapper);
        } catch (DataAccessException e) {
            e.printStackTrace();
            College college = new College();
            college.setName("暂无录取信息");
            return college;
        }
    }
}
