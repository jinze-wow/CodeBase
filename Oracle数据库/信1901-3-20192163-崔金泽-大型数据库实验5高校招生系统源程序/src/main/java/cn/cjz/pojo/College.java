package cn.yjy.pojo;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.annotation.JsonRootName;

import java.util.List;
import java.util.Set;

/**
 * Created by yjy on 16-12-25.
 */
@JsonAutoDetect(fieldVisibility = JsonAutoDetect.Visibility.ANY)
@JsonRootName("college")
public class College {

    private Integer number;
    private String name;
    private Integer borderline;
    private Integer targetEnroll;
    private Integer actualEnroll;
    private Integer vacancies;

    private List<Student> students;

    public Integer getNumber() {
        return number;
    }

    public void setNumber(Integer number) {
        this.number = number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getBorderline() {
        return borderline;
    }

    public void setBorderline(Integer borderline) {
        this.borderline = borderline;
    }

    public Integer getTargetEnroll() {
        return targetEnroll;
    }

    public void setTargetEnroll(Integer targetEnroll) {
        this.targetEnroll = targetEnroll;
    }

    public Integer getActualEnroll() {
        return actualEnroll;
    }

    public void setActualEnroll(Integer actualEnroll) {
        this.actualEnroll = actualEnroll;
    }

    public Integer getVacancies() {
        return vacancies;
    }

    public void setVacancies(Integer vacancies) {
        this.vacancies = vacancies;
    }

    public List<Student> getStudents() {
        return students;
    }

    public void setStudents(List<Student> students) {
        this.students = students;
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public int hashCode() {
        return getNumber();
    }

    @Override
    public boolean equals(Object obj) {
        try {
            return ((College)obj).getNumber() == this.getNumber();
        }catch (Exception e){
            e.printStackTrace();
            return false;
        }
    }
}
