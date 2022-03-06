import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;

import org.avanox.chainOfResponsability.shapes.*;
import org.avanox.visitor.Draw;
import org.avanox.visitor.DrawAWT;
import org.junit.Test;

public class TestDrawAWT {

    @Test
    public void testCircle() {
        Draw graphicLibrary = new DrawAWT(400, 320);
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

        String tooManyArguments = "|Circle;0;0;0;0;#ff0000ff|";
        String tooFewArguments = "|Circle;0;0;#ff0000ff|";
        String wrongSyntax = "|Circle;0|0;3;#ff0000ff|";
        String correct = "|Circle;50;50;100;#ff0000ff|";

        // Will fail
        result = expert.resolve(tooManyArguments, graphicLibrary);
        assertFalse(result);

        // Will fail
        result = expert.resolve(tooFewArguments, graphicLibrary);
        assertFalse(result);

        // Will fail
        result = expert.resolve(wrongSyntax, graphicLibrary);
        assertFalse(result);

        // Will succeed
        result = expert.resolve(correct, graphicLibrary);
        assertNotNull(result);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        graphicLibrary.closeDraw();
    }

    @Test
    public void testTriangle() {
        Draw graphicLibrary = new DrawAWT(400, 320);
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

        String tooManyArguments = "|Triangle;0;0;0;0;0;0;0;#ff0000ff|";
        String tooFewArguments = "|Triangle;0;0;#ff0000ff|";
        String wrongSyntax = "|Triangle;0;0;0;0|0;0;0;#ff0000ff|";
        String correct = "|Triangle;50;50;150;50;100;150;#ff0000ff|";

        // Will fail
        result = expert.resolve(tooManyArguments, graphicLibrary);
        assertFalse(result);

        // Will fail
        result = expert.resolve(tooFewArguments, graphicLibrary);
        assertFalse(result);

        // Will fail
        result = expert.resolve(wrongSyntax, graphicLibrary);
        assertFalse(result);

        // Will succed
        result = expert.resolve(correct, graphicLibrary);
        assertNotNull(result);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        graphicLibrary.closeDraw();
    }

    @Test
    public void testAnyPolygon() {
        Draw graphicLibrary = new DrawAWT(400, 320);
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

        String modulo2Arguments = "|AnyPolygon;0;0;0;0;0;0;0;#ff0000ff|";
        String tooFewArguments = "|AnyPolygon;0;0;0;#ff0000ff|";
        String wrongSyntax = "|AnyPolygon;0;0;0;0|0;0;0;#ff0000ff|";
        String correct = "|AnyPolygon;50;50;100;50;75;100;#ff0000ff|";
        String correct2 = "|AnyPolygon;50;350;100;350;100;250;50;250;#ff0000ff|";
        String correct3 = "|AnyPolygon;350;350;250;350;150;250;200;250;250;100;#ff0000ff|";

        // Will fail
        result = expert.resolve(modulo2Arguments, graphicLibrary);
        assertFalse(result);

        // Will fail
        result = expert.resolve(tooFewArguments, graphicLibrary);
        assertFalse(result);

        // Will fail
        result = expert.resolve(wrongSyntax, graphicLibrary);
        assertFalse(result);

        // Will succed
        result = expert.resolve(correct, graphicLibrary);
        assertNotNull(result);

        result = expert.resolve(correct2, graphicLibrary);
        assertNotNull(result);

        result = expert.resolve(correct3, graphicLibrary);
        assertNotNull(result);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        graphicLibrary.closeDraw();
    }

    @Test
    public void testSegment() {
        Draw graphicLibrary = new DrawAWT(400, 320);
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

        String tooManyArguments = "|Segment;0;0;0;0;0;0;0;#ff0000ff|";
        String tooFewArguments = "|Segment;0;0;0;#ff0000ff|";
        String wrongSyntax = "|Segment;0;0|0;0;0;0;0;#ff0000ff|";
        String correct = "|Segment;350;50;250;150;#ff0000ff|";

        // Will fail
        result = expert.resolve(tooManyArguments, graphicLibrary);
        assertFalse(result);

        // Will fail
        result = expert.resolve(tooFewArguments, graphicLibrary);
        assertFalse(result);

        // Will fail
        result = expert.resolve(wrongSyntax, graphicLibrary);
        assertFalse(result);

        // Will succed
        result = expert.resolve(correct, graphicLibrary);
        assertNotNull(result);

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        graphicLibrary.closeDraw();
    }
}
