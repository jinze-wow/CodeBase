package cn.yjy.repository.imp;

import cn.yjy.repository.EnrollRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

/**
 * Created by yjy on 17-1-4.
 */
@Repository
public class EnrollRepositoryImp implements EnrollRepository {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public void autoEnroll() {
        jdbcTemplate.execute("call AUTO_PROC()");
    }

    @Override
    public void clearStatus() {
        jdbcTemplate.execute("call CLEAR_STATUS()");
    }
}
