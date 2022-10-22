package cn.yjy.configuration;

import cn.yjy.condition.MyCondition;
import cn.yjy.controller.MainController;
import cn.yjy.repository.CollegeRepository;
import cn.yjy.repository.EnrollRepository;
import cn.yjy.repository.imp.CollegeRepositoryImp;
import cn.yjy.repository.imp.EnrollRepositoryImp;
import cn.yjy.service.CollegeService;
import cn.yjy.service.EnrollService;
import cn.yjy.service.StudentService;
import cn.yjy.service.imp.CollegeServiceImp;
import cn.yjy.service.imp.EnrollServiceImp;
import cn.yjy.service.imp.StudentServiceImp;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Conditional;
import org.springframework.context.annotation.Configuration;
import cn.yjy.repository.StudentRepository;
import cn.yjy.repository.imp.StudentRepositoryImp;
import org.springframework.jdbc.core.JdbcTemplate;

import javax.sql.DataSource;

/**
 * Created by yjy on 16-12-16.
 */

@Configuration
@ComponentScan(basePackageClasses = MainController.class)
public class MyConfiguration {

    @Bean
    public EnrollService enrollService(EnrollRepository enrollRepository){
        return new EnrollServiceImp(enrollRepository);
    }

    @Bean
    public StudentService studentService(@Qualifier("priority1") StudentRepository studentRepository){
        return new StudentServiceImp(studentRepository);
    }

    @Bean
    public CollegeService collegeService(CollegeRepository collegeRepository){
        return new CollegeServiceImp(collegeRepository);
    }

    @Bean
    public EnrollRepository enrollRepository(){
        return new EnrollRepositoryImp();
    }

    @Bean
    @Qualifier("priority1")
    public StudentRepository studentRepository(@Value("${studentRepository.message}") String message){
        return new StudentRepositoryImp();
    }

    @Bean
    public CollegeRepository collegeRepository(@Value("${collegeRepository.message}") String message){
        return new CollegeRepositoryImp();
    }

}
