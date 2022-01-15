package org.avanox.expert;

import org.avanox.Shapes.Point;
import org.avanox.Shapes.Shape;
import org.avanox.Shapes.Triangle;

public class ExpertTriangle extends ExpertCOR {
    public ExpertTriangle(ExpertCOR next) {
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
        if (matches.length != 7)
            return null;

        if (matches[0].equalsIgnoreCase("triangle")) {
            return new Triangle(
                    new Point(Double.parseDouble(matches[1]), Double.parseDouble(matches[2])),
                    new Point(Double.parseDouble(matches[3]), Double.parseDouble(matches[4])),
                    new Point(Double.parseDouble(matches[5]), Double.parseDouble(matches[6])));
        }

        return null;
    }
}
