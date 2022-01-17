package org.avanox.chainOfResponsability.shapes;

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

        String[] matches = subStr.split(",");

        if (matches[0].equalsIgnoreCase("anypolygon")) {
            int length = matches.length;
            if (length < 7 || length % 2 == 0)
                return false;

            LinkedList<Point> points = new LinkedList<>();
            for (int i = 1; i < length; i += 2) {
                if (i != 0) {
                    Point point = new Point(
                            Integer.parseInt(matches[i]),
                            Integer.parseInt(matches[i + 1]));
                    points.addFirst(point);
                }
            }
            graphicLibrairy.visit(new AnyPolygon(points));
            return true;
        }

        return false;
    }

}
