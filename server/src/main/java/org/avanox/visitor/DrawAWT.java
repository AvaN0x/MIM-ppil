package org.avanox.visitor;

import org.avanox.Shapes.*;

import java.util.ArrayList;
import java.util.logging.Logger;

import java.awt.image.BufferStrategy;
import java.awt.Frame;
import java.awt.Graphics;

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

        int[] xPoints = {
                triangle.getA().getX(),
                triangle.getB().getX(),
                triangle.getC().getX()
        };
        int[] yPoints = {
                triangle.getA().getY(),
                triangle.getB().getY(),
                triangle.getC().getY()
        };

        graphics.drawPolygon(xPoints, yPoints, 3);

        strategie.show();

        graphics.dispose();
    }

    @Override
    public void visit(Circle circle) {
        System.out.println("Je vais dessiner un cercle en AWT");

        BufferStrategy strategie = frame.getBufferStrategy();
        Graphics graphics = strategie.getDrawGraphics();

        graphics.fillOval(
                circle.getCenter().getX(),
                circle.getCenter().getY(),
                circle.getRadius(),
                circle.getRadius());

        strategie.show();

        graphics.dispose();
    }

    @Override
    public void visit(Segment segment) {
        System.out.println("Je vais dessiner un segment en AWT");

        BufferStrategy strategie = frame.getBufferStrategy();
        Graphics graphics = strategie.getDrawGraphics();

        graphics.drawLine(
                segment.getA().getX(),
                segment.getA().getY(),
                segment.getB().getX(),
                segment.getB().getY());

        strategie.show();

        graphics.dispose();

    }

    @Override
    public void visit(AnyPolygon other) {
        System.out.println("Je vais dessiner un polygone quelconque fermé en AWT");

        BufferStrategy strategie = frame.getBufferStrategy();
        Graphics graphics = strategie.getDrawGraphics();

        ArrayList<Integer> xPoints = new ArrayList<Integer>();
        ArrayList<Integer> yPoints = new ArrayList<Integer>();
        for (Point point : other.getSegments()) {
            xPoints.add(point.getX());
            yPoints.add(point.getY());
        }
        graphics.drawPolygon(
                xPoints.stream().mapToInt(i -> i).toArray(),
                yPoints.stream().mapToInt(i -> i).toArray(),
                xPoints.size());

        strategie.show();

        graphics.dispose();

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
