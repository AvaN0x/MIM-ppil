package org.avanox.chainOfResponsability.shapes;

import java.awt.Color;
import java.util.LinkedList;

import org.avanox.Shapes.AnyPolygon;
import org.avanox.Shapes.Point;
import org.avanox.visitor.Draw;

public class ExpertAnyPolygon extends ExpertShapes {

    public ExpertAnyPolygon(ExpertShapes next) {
        super(next);
    }

    @Override
    protected boolean resolve1(String str, Draw graphicLibrairy) {
        int idx = str.indexOf("|", 1);
        if (idx == -1)
            return false;

        String subStr = str.substring(1, idx);

        String[] matches = subStr.split(";");

        if (matches[0].equalsIgnoreCase("anypolygon")) {
            int length = matches.length;
            if (length < 8 || length % 2 != 0)
                return false;

            LinkedList<Point> points = new LinkedList<>();
            try {
                for (int i = 1; i < length - 1; i += 2) {
                    Point point = new Point(
                            Integer.parseInt(matches[i]),
                            Integer.parseInt(matches[i + 1]));
                    points.addFirst(point);
                }

                Color color = Color.decode(matches[length - 1]);

                graphicLibrairy.visit(new AnyPolygon(points, color));
                return true;

            } catch (NumberFormatException e) {
                return false;
            }
        }

        return false;
    }

}
