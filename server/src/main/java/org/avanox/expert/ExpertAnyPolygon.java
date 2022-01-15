package org.avanox.expert;

import java.util.LinkedList;

import org.avanox.Shapes.AnyPolygon;
import org.avanox.Shapes.Point;
import org.avanox.Shapes.Shape;

public class ExpertAnyPolygon extends ExpertCOR {

    public ExpertAnyPolygon(ExpertCOR next) {
        super(next);
    }

    @Override
    protected Shape resolve1(String str) {
        int idx = str.indexOf("|", 1);
        if (idx == -1)
            return null;

        String subStr = str.substring(1, idx);

        String[] matches = subStr.split(",");

        if (matches[0].equalsIgnoreCase("anypolygon")) {
            int length = matches.length;
            if (length < 7 || length % 2 == 0)
                return null;

            LinkedList<Point> points = new LinkedList<>();
            for (int i = 1; i < length; i += 2) {
                if (i != 0) {
                    Point point = new Point(
                            Double.parseDouble(matches[i]),
                            Double.parseDouble(matches[i + 1]));
                    points.addFirst(point);
                }
            }
            return new AnyPolygon(points);
        }

        return null;
    }

}
