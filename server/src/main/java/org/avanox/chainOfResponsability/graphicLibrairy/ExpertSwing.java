package org.avanox.chainOfResponsability.graphicLibrairy;

import org.avanox.visitor.Draw;
import org.avanox.visitor.DrawSwing;

public class ExpertSwing extends ExpertCOR {

    public ExpertSwing(ExpertCOR next) {
        super(next);
    }

    @Override
    protected Draw resolve1(String str) {
        int idx = str.indexOf("|", 1);
        if (idx == -1)
            return null;

        String subStr = str.substring(1, idx);
        if (subStr.equalsIgnoreCase("swing"))
            return new DrawSwing();
        return null;
    }

}
