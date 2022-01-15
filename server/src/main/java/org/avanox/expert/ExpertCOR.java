package org.avanox.expert;

import org.avanox.Shapes.Shape;

public abstract class ExpertCOR implements Expert {
    protected ExpertCOR _next;

    public ExpertCOR(ExpertCOR next) {
        _next = next;
    }

    protected abstract Shape resolve1(String str);

    @Override
    public Shape resolve(String str) {
        Shape shape = resolve1(str);

        if (shape != null)
            return shape;
        else if (_next != null)
            return _next.resolve(str);

        return null;
    }
}
