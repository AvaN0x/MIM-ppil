package org.avanox.chainOfResponsability.graphicLibrary;

import org.avanox.visitor.Draw;

public interface Expert {
    /**
     * Resolve the graphic library
     * 
     * @param str the graphic library to resolve
     */
    public Draw resolve(String str);
}
