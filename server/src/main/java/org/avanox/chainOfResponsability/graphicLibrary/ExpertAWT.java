package org.avanox.chainOfResponsability.graphicLibrary;

import org.avanox.visitor.Draw;
import org.avanox.visitor.DrawAWT;

public class ExpertAWT extends ExpertGL {

    public ExpertAWT(ExpertGL next) {
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

        if (matches[0].equalsIgnoreCase("awt")) {
            try {
                return new DrawAWT(Integer.parseInt(matches[1]), Integer.parseInt(matches[2]));
            } catch (NumberFormatException e) {
                return null;
            }
        }

        return null;
    }

}
