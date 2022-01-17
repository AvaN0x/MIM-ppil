package org.avanox.chainOfResponsability.shapes;

import org.avanox.Shapes.Point;
import org.avanox.Shapes.Triangle;
import org.avanox.visitor.Draw;

public class ExpertTriangle extends ExpertShapes {
    public ExpertTriangle(ExpertShapes next) {
        super(next);
    }

    @Override
    protected boolean resolve1(String str, Draw graphicLibrairy) {
        int idx = str.indexOf("|", 1);
        if (idx == -1)
            return false;

        String subStr = str.substring(1, idx);

        String[] matches = subStr.split(",");
        if (matches.length != 7)
            return false;

        if (matches[0].equalsIgnoreCase("triangle")) {
            Triangle triangle = new Triangle(
                    new Point(Integer.parseInt(matches[1]), Integer.parseInt(matches[2])),
                    new Point(Integer.parseInt(matches[3]), Integer.parseInt(matches[4])),
                    new Point(Integer.parseInt(matches[5]), Integer.parseInt(matches[6])));
            graphicLibrairy.visit(triangle);
            return true;
        }

        return false;
    }
}
