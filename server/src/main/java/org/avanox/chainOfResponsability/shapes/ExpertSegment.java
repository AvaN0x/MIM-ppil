package org.avanox.chainOfResponsability.shapes;

import org.avanox.Shapes.Point;
import org.avanox.Shapes.Segment;
import org.avanox.Shapes.Shape;

public class ExpertSegment extends ExpertCOR {

    public ExpertSegment(ExpertCOR next) {
        super(next);
    }

    @Override
    protected Shape resolve1(String str) {
        int idx = str.indexOf("|", 1);
        if (idx == -1)
            return null;

        String subStr = str.substring(1, idx);
        // System.out.println("subStr is : " + subStr);

        String[] matches = subStr.split(",");
        if (matches.length != 5)
            return null;

        if (matches[0].equalsIgnoreCase("segment")) {
            return new Segment(
                    new Point(Double.parseDouble(matches[1]), Double.parseDouble(matches[2])),
                    new Point(Double.parseDouble(matches[3]), Double.parseDouble(matches[4])));
        }

        return null;
    }

}
