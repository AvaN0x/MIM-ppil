package org.avanox.chainOfResponsability.shapes;

import java.awt.Color;

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

        String[] matches = subStr.split(";");

        if (matches.length != 5)
            return false;
        if (matches[0].equalsIgnoreCase("circle")) {
            try {
                graphicLibrairy.visit(
                        new Circle(
                                new Point(
                                        Integer.parseInt(matches[1]),
                                        Integer.parseInt(matches[2])),
                                Integer.parseInt(matches[3]),
                                Color.decode(matches[4])));
                return true;
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return false;
    }
}
