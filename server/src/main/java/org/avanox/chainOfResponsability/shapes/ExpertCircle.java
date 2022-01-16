package org.avanox.chainOfResponsability.shapes;

import org.avanox.Shapes.Circle;
import org.avanox.Shapes.Point;
import org.avanox.visitor.Draw;

public class ExpertCircle extends ExpertShapes {

    public ExpertCircle(ExpertShapes next) {
        super(next);
    }

    @Override
    protected boolean resolve1(String str, Draw graphicLibrairy) {
        int idx = str.indexOf("|", 1);
        if (idx == -1)
            return false;

        String subStr = str.substring(1, idx);
        // System.out.println("subStr is : " + subStr);

        String[] matches = subStr.split(",");
        if (matches.length != 4)
            return false;
        if (matches[0].equalsIgnoreCase("circle")) {
            graphicLibrairy.visit(
                    new Circle(
                            new Point(
                                    Double.parseDouble(matches[1]),
                                    Double.parseDouble(matches[2])),
                            Double.parseDouble(matches[3])));
            return true;
        }
        return false;
    }
}
