package cn.yjy.service.imp;

import cn.yjy.repository.EnrollRepository;
import cn.yjy.service.EnrollService;
import org.springframework.stereotype.Service;

/**
 * Created by yjy on 17-1-4.
 */
@Service
public class EnrollServiceImp implements EnrollService {

    private EnrollRepository enrollRepository;

    public EnrollServiceImp(EnrollRepository enrollRepository) {
        this.enrollRepository=enrollRepository;
    }

    @Override
    public void AutoEnroll() {
        enrollRepository.autoEnroll();
    }

    @Override
    public void ClearStatus() {
        enrollRepository.clearStatus();
    }
}
