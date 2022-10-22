package cn.yjy.pojo;

import com.fasterxml.jackson.annotation.JsonAutoDetect;
import com.fasterxml.jackson.annotation.JsonRootName;

import java.util.Date;

/**
 * Created by yjy on 16-12-25.
 */
@JsonAutoDetect(fieldVisibility = JsonAutoDetect.Visibility.ANY)
@JsonRootName("student")
public class Student {

    //student表
    private Integer number;
    private String name;
    private Character gender;
    private Integer grade;
    //student_will表
    private Boolean autoAdjust;
    private College aspiration1;
    private College aspiration2;
    //student_enroll表
    private Boolean enroll;
    private College enrollCollege;
    private Integer enrollAspiration;
    private Date enrollDate;
    private String operator;


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
            return ((Student)obj).getNumber() == this.getNumber();
        }catch (Exception e){
            e.printStackTrace();
            return false;
        }
    }

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

    public Character getGender() {
        return gender;
    }

    public void setGender(Character gender) {
        this.gender = gender;
    }

    public Integer getGrade() {
        return grade;
    }

    public void setGrade(Integer grade) {
        this.grade = grade;
    }

    public Boolean getAutoAdjust() {
        return autoAdjust;
    }

    public void setAutoAdjust(Boolean autoAdjust) {
        this.autoAdjust = autoAdjust;
    }

    public College getAspiration1() {
        return aspiration1;
    }

    public void setAspiration1(College aspiration1) {
        this.aspiration1 = aspiration1;
    }

    public College getAspiration2() {
        return aspiration2;
    }

    public void setAspiration2(College aspiration2) {
        this.aspiration2 = aspiration2;
    }

    public Boolean getEnroll() {
        return enroll;
    }

    public void setEnroll(Boolean enroll) {
        this.enroll = enroll;
    }

    public College getEnrollCollege() {
        return enrollCollege;
    }

    public void setEnrollCollege(College enrollCollege) {
        this.enrollCollege = enrollCollege;
    }

    public Integer getEnrollAspiration() {
        return enrollAspiration;
    }

    public void setEnrollAspiration(Integer enrollAspiration) {
        this.enrollAspiration = enrollAspiration;
    }

    public Date getEnrollDate() {
        return enrollDate;
    }

    public void setEnrollDate(Date enrollDate) {
        this.enrollDate = enrollDate;
    }

    public String getOperator() {
        return operator;
    }

    public void setOperator(String operator) {
        this.operator = operator;
    }
}
