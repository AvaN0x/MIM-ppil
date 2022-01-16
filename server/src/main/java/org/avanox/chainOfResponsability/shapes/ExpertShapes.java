package org.avanox.chainOfResponsability.shapes;

import org.avanox.visitor.Draw;

public abstract class ExpertShapes implements Expert {
    protected ExpertShapes _next;

    public ExpertShapes(ExpertShapes next) {
        _next = next;
    }

    protected abstract boolean resolve1(String str, Draw graphicLibrairy);

    @Override
    public boolean resolve(String str, Draw graphicLibrairy) {
        boolean isRevolved = resolve1(str, graphicLibrairy);

        if (isRevolved)
            return true;
        else if (_next != null)
            return _next.resolve(str, graphicLibrairy);

        return false;
    }
}
