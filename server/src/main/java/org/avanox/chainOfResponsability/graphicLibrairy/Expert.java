package org.avanox.chainOfResponsability.graphicLibrairy;

import org.avanox.visitor.Draw;

public interface Expert {
    public Draw resolve(String str);
}
