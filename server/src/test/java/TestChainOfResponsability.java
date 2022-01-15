import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;

import org.avanox.Shapes.Circle;
import org.avanox.Shapes.Point;
import org.avanox.Shapes.Shape;
import org.avanox.expert.ExpertCOR;
import org.avanox.expert.ExpertCircle;
import org.avanox.expert.ExpertSegment;
import org.avanox.expert.ExpertTriangle;
import org.junit.Test;

public class TestChainOfResponsability {

    @Test
    public void simpleTest() {
        assertEquals("hello world", "hello world");
    }

    @Test
    public void testCircle() {
        ExpertCOR expert = null;

        expert = new ExpertSegment(expert);
        expert.getSuivant();
        assertNotNull(expert);

        expert = new ExpertCircle(expert);
        expert.getSuivant();
        assertNotNull(expert);

        expert = new ExpertTriangle(expert);
        expert.getSuivant();
        assertNotNull(expert);

        String str = ".Circle,0,0,0,0.";
        Shape result = expert.resolve(str);

        System.out.println(result);

        assertNotNull(result);
        assertEquals(result, new Circle(new Point(0, 0), 0));
    }
}
