package org.avanox.chainOfResponsability.graphicLibrairy;

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
        if (subStr.equalsIgnoreCase("awt"))
            return new DrawAWT();
        return null;
    }

}
