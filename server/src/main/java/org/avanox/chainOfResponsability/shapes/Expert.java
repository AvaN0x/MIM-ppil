package org.avanox.chainOfResponsability.shapes;

import org.avanox.visitor.Draw;

public interface Expert {
    /**
     * Resolve the shape
     * 
     * @param str            the shape to resolve
     * @param graphicLibrary the graphic library to use
     * @return
     */
    public boolean resolve(String str, Draw graphicLibrary);
}
