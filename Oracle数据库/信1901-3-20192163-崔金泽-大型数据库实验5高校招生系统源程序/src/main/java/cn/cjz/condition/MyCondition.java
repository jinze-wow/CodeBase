package cn.yjy.condition;

import org.springframework.context.annotation.Condition;
import org.springframework.context.annotation.ConditionContext;
import org.springframework.core.type.AnnotatedTypeMetadata;

/**
 * Created by yjy on 16-12-16.
 * 不能作为内部类
 */

public class MyCondition implements Condition {

    public boolean matches(ConditionContext conditionContext, AnnotatedTypeMetadata annotatedTypeMetadata) {
        String mode = conditionContext.getEnvironment().getProperty("application.mode");
        return "production".equals(mode);
    }
}