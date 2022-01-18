import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;

import org.avanox.chainOfResponsability.shapes.*;
import org.avanox.visitor.Draw;
import org.avanox.visitor.DrawAWT;
import org.junit.Test;

public class TestDrawAWT {

    @Test
    public void testCircle() {
        Draw graphicLibrairy = new DrawAWT();
        ExpertShapes expert = null;
        boolean result = false;

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
        String wrongSyntax = "|Circle,0|0,3|";
        String correct = "|Circle,50,50,100|";

        // Will fail
        result = expert.resolve(tooManyArguments, graphicLibrairy);
        assertFalse(result);

        // Will fail
        result = expert.resolve(tooLessArguments, graphicLibrairy);
        assertFalse(result);

        // Will fail
        result = expert.resolve(wrongSyntax, graphicLibrairy);
        assertFalse(result);

        // Will succed
        result = expert.resolve(correct, graphicLibrairy);
        assertNotNull(result);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        graphicLibrairy.closeDraw();
    }

    @Test
    public void testTriangle() {
        Draw graphicLibrairy = new DrawAWT();
        ExpertShapes expert = null;
        boolean result;

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
        String correct = "|Triangle,50,50,150,50,100,150|";

        // Will fail
        result = expert.resolve(tooManyArguments, graphicLibrairy);
        assertFalse(result);

        // Will fail
        result = expert.resolve(tooLessArguments, graphicLibrairy);
        assertFalse(result);

        // Will fail
        result = expert.resolve(wrongSyntax, graphicLibrairy);
        assertFalse(result);

        // Will succed
        result = expert.resolve(correct, graphicLibrairy);
        assertNotNull(result);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        graphicLibrairy.closeDraw();
    }

    @Test
    public void testAnyPolygon() {
        Draw graphicLibrairy = new DrawAWT();
        ExpertShapes expert = null;
        boolean result;

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
        String correct = "|AnyPolygon,50,50,100,50,75,100|";
        String correct2 = "|AnyPolygon,50,350,100,350,100,250,50,250|";
        String correct3 = "|AnyPolygon,350,350,250,350,150,250,200,250,250,100|";

        // Will fail
        result = expert.resolve(modulo2Arguments, graphicLibrairy);
        assertFalse(result);

        // Will fail
        result = expert.resolve(tooLessArguments, graphicLibrairy);
        assertFalse(result);

        // Will fail
        result = expert.resolve(wrongSyntax, graphicLibrairy);
        assertFalse(result);

        // Will succed
        result = expert.resolve(correct, graphicLibrairy);
        assertNotNull(result);

        result = expert.resolve(correct2, graphicLibrairy);
        assertNotNull(result);

        result = expert.resolve(correct3, graphicLibrairy);
        assertNotNull(result);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        graphicLibrairy.closeDraw();
    }

    @Test
    public void testSegment() {
        Draw graphicLibrairy = new DrawAWT();
        ExpertShapes expert = null;
        boolean result;

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
        String correct = "|Segment,350,50,250,150|";

        // Will fail
        result = expert.resolve(tooManyArguments, graphicLibrairy);
        assertFalse(result);

        // Will fail
        result = expert.resolve(tooLessArguments, graphicLibrairy);
        assertFalse(result);

        // Will fail
        result = expert.resolve(wrongSyntax, graphicLibrairy);
        assertFalse(result);

        // Will succed
        result = expert.resolve(correct, graphicLibrairy);
        assertNotNull(result);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        graphicLibrairy.closeDraw();
    }
}
