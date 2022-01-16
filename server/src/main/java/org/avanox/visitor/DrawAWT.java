package org.avanox.visitor;

import org.avanox.Shapes.*;
import java.util.logging.Logger;

import java.awt.image.BufferStrategy;
import java.awt.Window;
import java.awt.Canvas;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

public class DrawAWT extends Draw {
    private static DrawAWT instance;
    private static Frame frame;
    private static final Logger LOGGER = Logger.getLogger("Serveur");

    public DrawAWT() {
        frame = new Frame("Frame toute simple");
        frame.setBounds(0, 0, 400, 400);
        LOGGER.info("La fenetre awt a ete initialisee");
    }

    @Override
    public void visit(Triangle triangle) {
        System.out.println("Je vais dessiner un triangle en AWT");
        BufferStrategy strategie = frame.getBufferStrategy();
        Graphics graphics = strategie.getDrawGraphics();
        // le graphics sert à dessiner sur le tampon

        // graphics.drawPolygon(xPoints, yPoints, 3);

        // triangle.getA().getX(),
        // triangle.getA().getY(),
        // triangle.getB().getX(),
        // triangle.getB().getY()

        strategie.show(); // place le tampon sur l'écran : la technique utilisée dépend du type de
                          // stratégie utilisé : blitting, pointeur vidéo, etc.

        graphics.dispose();
    }

    @Override
    public void visit(Circle circle) {
        System.out.println("Je vais dessiner un cercle en AWT");

    }

    @Override
    public void visit(Segment segment) {
        System.out.println("Je vais dessiner un segment en AWT");

    }

    @Override
    public void visit(AnyPolygon other) {
        System.out.println("Je vais dessiner un polygone quelconque fermé en AWT");

    }

    public static DrawAWT getInstance() {
        if (instance == null)
            instance = new DrawAWT();
        return instance;
    }

    @Override
    public void init() {
        // TODO Auto-generated method stub

    }
}
