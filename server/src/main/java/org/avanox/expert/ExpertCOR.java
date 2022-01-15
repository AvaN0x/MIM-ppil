package org.avanox.expert;

import org.avanox.Shapes.Shape;

public abstract class ExpertCOR implements Expert {
    protected ExpertCOR _next;

    public ExpertCOR(ExpertCOR next) {
        this._next = next;
    }

    protected abstract Shape resolve1(String str);

    @Override
    public Shape resolve(String str) {
        Shape shape = resolve1(str);

        return (shape != null ? shape : this._next.resolve1(str));
    }

    public void getSuivant() {
        System.out.println("Suivant est : " + _next);
    }

}
