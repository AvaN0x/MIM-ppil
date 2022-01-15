import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import java.util.LinkedList;

import org.avanox.Shapes.AnyPolygon;
import org.avanox.Shapes.Circle;
import org.avanox.Shapes.Point;
import org.avanox.Shapes.Segment;
import org.avanox.Shapes.Shape;
import org.avanox.Shapes.Triangle;
import org.avanox.chainOfResponsability.shapes.*;
import org.junit.Test;

public class TestChainOfResponsability {

    @Test
    public void testCircle() {
        ExpertCOR expert = null;

        expert = new ExpertCircle(expert);
        assertNotNull(expert);

        expert = new ExpertSegment(expert);
        assertNotNull(expert);

        expert = new ExpertTriangle(expert);
        assertNotNull(expert);

        expert = new ExpertAnyPolygon(expert);
        assertNotNull(expert);

        String tooManyArguments = "|Circle,0,0,0,0|";
        String tooLessArguments = "|Circle,0,0|";
        String wrongSyntax = "|Circle,0.5|0.4,3.8|";
        String correct = "|Circle,0.5,0.4,3.8|";

        // Will fail
        Shape result = expert.resolve(tooManyArguments);
        assertNull(result);

        // Will fail
        result = expert.resolve(tooLessArguments);
        assertNull(result);

        // Will fail
        result = expert.resolve(wrongSyntax);
        assertNull(result);

        // Will succed
        result = expert.resolve(correct);
        assertNotNull(result);
        assertEquals(result, new Circle(new Point(0.5, 0.4), 3.8));
    }

    @Test
    public void testTriangle() {
        ExpertCOR expert = null;

        expert = new ExpertTriangle(expert);
        assertNotNull(expert);

        expert = new ExpertCircle(expert);
        assertNotNull(expert);

        expert = new ExpertSegment(expert);
        assertNotNull(expert);

        expert = new ExpertAnyPolygon(expert);
        assertNotNull(expert);

        String tooManyArguments = "|Triangle,0,0,0,0,0,0,0|";
        String tooLessArguments = "|Triangle,0,0|";
        String wrongSyntax = "|Triangle,0,0,0,0|0,0,0|";
        String correct = "|Triangle,0.1,0.2,0.3,0.4,0.5,0.6|";

        // Will fail
        Shape result = expert.resolve(tooManyArguments);
        assertNull(result);

        // Will fail
        result = expert.resolve(tooLessArguments);
        assertNull(result);

        // Will fail
        result = expert.resolve(wrongSyntax);
        assertNull(result);

        // Will succed
        result = expert.resolve(correct);
        assertNotNull(result);
        assertEquals(result, new Triangle(
                new Point(0.1, 0.2),
                new Point(0.3, 0.4),
                new Point(0.5, 0.6)));
    }

    @Test
    public void testAnyPolygon() {
        ExpertCOR expert = null;

        expert = new ExpertAnyPolygon(expert);
        assertNotNull(expert);

        expert = new ExpertTriangle(expert);
        assertNotNull(expert);

        expert = new ExpertCircle(expert);
        assertNotNull(expert);

        expert = new ExpertSegment(expert);
        assertNotNull(expert);

        String modulo2Arguments = "|AnyPolygon,0,0,0,0,0,0,0|";
        String tooLessArguments = "|AnyPolygon,0,0,0|";
        String wrongSyntax = "|AnyPolygon,0,0,0,0|0,0,0|";
        String correct = "|AnyPolygon,0.1,0.2,0.3,0.4,0.5,0.6|";
        String correct2 = "|AnyPolygon,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8|";
        String correct3 = "|AnyPolygon,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0|";

        // Will fail
        Shape result = expert.resolve(modulo2Arguments);
        assertNull(result);

        // Will fail
        result = expert.resolve(tooLessArguments);
        assertNull(result);

        // Will fail
        result = expert.resolve(wrongSyntax);
        assertNull(result);

        LinkedList<Point> points = new LinkedList<Point>();
        points.addFirst(new Point(0.1, 0.2));
        points.addFirst(new Point(0.3, 0.4));
        points.addFirst(new Point(0.5, 0.6));

        // Will succed
        result = expert.resolve(correct);
        assertNotNull(result);
        assertEquals(result, new AnyPolygon(points));

        points.add(new Point(0.7, 0.8));

        result = expert.resolve(correct2);
        assertNotNull(result);
        assertEquals(result, new AnyPolygon(points));

        points.add(new Point(0.9, 1.0));

        result = expert.resolve(correct3);
        assertNotNull(result);
        assertEquals(result, new AnyPolygon(points));
    }

    @Test
    public void testSegment() {
        ExpertCOR expert = null;

        expert = new ExpertSegment(expert);
        assertNotNull(expert);

        expert = new ExpertAnyPolygon(expert);
        assertNotNull(expert);

        expert = new ExpertTriangle(expert);
        assertNotNull(expert);

        expert = new ExpertCircle(expert);
        assertNotNull(expert);

        String tooManyArguments = "|Segment,0,0,0,0,0,0,0|";
        String tooLessArguments = "|Segment,0,0,0|";
        String wrongSyntax = "|Segment,0,0|0,0,0,0,0|";
        String correct = "|Segment,0.1,0.2,0.3,0.4|";

        // Will fail
        Shape result = expert.resolve(tooManyArguments);
        assertNull(result);

        // Will fail
        result = expert.resolve(tooLessArguments);
        assertNull(result);

        // Will fail
        result = expert.resolve(wrongSyntax);
        assertNull(result);

        // Will succed
        result = expert.resolve(correct);
        assertNotNull(result);

        assertEquals(result, new Segment(
                new Point(0.1, 0.2),
                new Point(0.3, 0.4)));
    }
}
