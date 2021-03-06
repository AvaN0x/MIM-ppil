package org.avanox.chainOfResponsability.shapes;

import org.avanox.Utils;
import org.avanox.Shapes.Point;
import org.avanox.Shapes.Segment;
import org.avanox.visitor.Draw;

public class ExpertSegment extends ExpertShapes {

    public ExpertSegment(ExpertShapes next) {
        super(next);
    }

    @Override
    protected boolean resolve1(String str, Draw graphicLibrary) {
        int idx = str.indexOf("|", 1);
        if (idx == -1)
            return false;

        String subStr = str.substring(1, idx);

        String[] matches = subStr.split(";");
        if (matches.length != 6)
            return false;

        if (matches[0].equalsIgnoreCase("segment")) {
            try {
                Segment segment = new Segment(
                        new Point(Integer.parseInt(matches[1]), Integer.parseInt(matches[2])),
                        new Point(Integer.parseInt(matches[3]), Integer.parseInt(matches[4])),
                        Utils.hexToRGBA(matches[5]));

                graphicLibrary.visit(segment);
                return true;
            } catch (NumberFormatException e) {
                return false;
            }
        }

        return false;
    }

}
