package org.avanox.chainOfResponsability.graphicLibrairy;

import org.avanox.visitor.Draw;

public abstract class ExpertCOR implements Expert {
    protected ExpertCOR _next;

    public ExpertCOR(ExpertCOR next) {
        this._next = next;
    }

    protected abstract Draw resolve1(String str);

    @Override
    public Draw resolve(String str) {
        Draw shape = resolve1(str);

        if (shape != null)
            return shape;
        else if (_next != null)
            return _next.resolve(str);

        return null;
    }
}