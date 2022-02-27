package org.avanox.chainOfResponsability.shapes;

import org.avanox.visitor.Draw;

public abstract class ExpertShapes implements Expert {
    protected ExpertShapes _next;

    public ExpertShapes(ExpertShapes next) {
        _next = next;
    }

    /**
     * Internal function to resolve the shape
     * 
     * @param str            the shape to resolve
     * @param graphicLibrary the graphic library to use
     * @return the shape has been resolved
     */
    protected abstract boolean resolve1(String str, Draw graphicLibrary);

    @Override
    public boolean resolve(String str, Draw graphicLibrary) {
        boolean isRevolved = resolve1(str, graphicLibrary);

        if (isRevolved)
            return true;
        else if (_next != null)
            return _next.resolve(str, graphicLibrary);

        return false;
    }
}
