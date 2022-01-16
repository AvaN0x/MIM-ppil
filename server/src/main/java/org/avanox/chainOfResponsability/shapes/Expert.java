package org.avanox.chainOfResponsability.shapes;

import org.avanox.visitor.Draw;

public interface Expert {
    public boolean resolve(String str, Draw graphicLibrairy);
}
