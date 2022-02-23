package org.avanox.chainOfResponsability.graphicLibrairy;

import org.avanox.visitor.Draw;
import org.avanox.visitor.DrawSwing;

public class ExpertSwing extends ExpertGL {

    public ExpertSwing(ExpertGL next) {
        super(next);
    }

    @Override
    protected Draw resolve1(String str) {
        int idx = str.indexOf("|", 1);
        if (idx == -1)
            return null;

        String subStr = str.substring(1, idx);

        String[] matches = subStr.split(";");
        if (matches.length != 3)
            return null;

        if (matches[0].equalsIgnoreCase("swing")) {
            try {
                return new DrawSwing(Integer.parseInt(matches[1]), Integer.parseInt(matches[2]));
            } catch (NumberFormatException e) {
                return null;
            }
        }

        return null;
    }

}
