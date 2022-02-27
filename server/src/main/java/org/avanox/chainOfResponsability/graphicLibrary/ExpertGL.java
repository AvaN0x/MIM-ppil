package org.avanox.chainOfResponsability.graphicLibrary;

import org.avanox.visitor.Draw;

public abstract class ExpertGL implements Expert {
    protected ExpertGL _next;

    public ExpertGL(ExpertGL next) {
        this._next = next;
    }

    /**
     * Internal function to resolve the graphic library
     * 
     * @param str the graphic library to resolve
     * @return the graphic library
     */
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