package org.avanox.chainOfResponsability.shapes;

import org.avanox.Shapes.Shape;

public interface Expert {
    public Shape resolve(String str);
}
