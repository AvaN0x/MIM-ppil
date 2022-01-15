package org.avanox.expert;

import org.avanox.Shapes.Circle;
import org.avanox.Shapes.Point;
import org.avanox.Shapes.Shape;

public class ExpertCircle extends ExpertCOR {

    public ExpertCircle(ExpertCOR next) {
        super(next);
    }

    @Override
    protected Shape resolve1(String str) {
        System.out.println("I'm resolving for circle");
        System.out.println("str is : " + str);
        int idx = str.indexOf(".", 1);
        if (idx == -1)
            return null;

        String subStr = str.substring(1, idx);
        System.out.println("subStr is : " + subStr);

        String[] matches = subStr.split(",");
        if (matches[0].equalsIgnoreCase("circle")) {
            return new Circle(
                    new Point(Double.parseDouble(matches[1]), Double.parseDouble(matches[2])),
                    Double.parseDouble(matches[3]));
        }
        System.out.println("I return null");

        return null;

    }

}
