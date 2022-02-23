package org.avanox.visitor;

import org.avanox.Shapes.*;

import java.awt.Insets;

import java.util.ArrayList;
import java.util.logging.Logger;

import java.awt.image.BufferStrategy;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.Graphics;

public class DrawAWT extends Draw {
    private Frame frame;
    private BufferStrategy strategie;
    private Graphics graphics;
    private static final Logger LOGGER = Logger.getLogger("Serveur");

    public DrawAWT(int x, int y) {
        this.frame = new Frame("Frame toute simple"); // TODO edit frame name
        this.frame.setBounds(0, 0, x + 16, y + 39);
        this.frame.setVisible(true);
        this.frame.setResizable(false);
        this.frame.createBufferStrategy(2);
        try {
            Thread.sleep(150);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        this.frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent event) {
                frame.dispose();
                strategie.dispose();
                graphics.dispose();
            }
        });

        this.strategie = this.frame.getBufferStrategy();
        this.graphics = this.strategie.getDrawGraphics();

        LOGGER.info("La fenetre awt a ete initialisee");
    }

    @Override
    public void visit(Triangle triangle) {
        Insets insets = frame.getInsets();
        int[] xPoints = {
                insets.left + triangle.getA().getX(),
                insets.left + triangle.getB().getX(),
                insets.left + triangle.getC().getX()
        };
        int[] yPoints = {
                insets.top + triangle.getA().getY(),
                insets.top + triangle.getB().getY(),
                insets.top + triangle.getC().getY()
        };
        graphics.setColor(triangle.getColor());
        graphics.fillPolygon(xPoints, yPoints, 3);

        strategie.show();
    }

    @Override
    public void visit(Circle circle) {
        Insets insets = frame.getInsets();
        graphics.setColor(circle.getColor());
        graphics.fillOval(
                insets.left + circle.getCenter().getX() - circle.getRadius(),
                insets.top + circle.getCenter().getY() - circle.getRadius(),
                circle.getRadius() * 2,
                circle.getRadius() * 2);

        strategie.show();
    }

    @Override
    public void visit(Segment segment) {
        Insets insets = frame.getInsets();
        graphics.setColor(segment.getColor());
        graphics.drawLine(
                insets.left + segment.getA().getX(),
                insets.top + segment.getA().getY(),
                insets.left + segment.getB().getX(),
                insets.top + segment.getB().getY());

        strategie.show();
    }

    @Override
    public void visit(AnyPolygon other) {
        Insets insets = frame.getInsets();
        ArrayList<Integer> xPoints = new ArrayList<Integer>();
        ArrayList<Integer> yPoints = new ArrayList<Integer>();
        for (Point point : other.getSegments()) {
            xPoints.add(insets.left + point.getX());
            yPoints.add(insets.top + point.getY());
        }
        graphics.setColor(other.getColor());
        graphics.fillPolygon(
                xPoints.stream().mapToInt(i -> i).toArray(),
                yPoints.stream().mapToInt(i -> i).toArray(),
                xPoints.size());

        strategie.show();
    }

    @Override
    public void closeDraw() {
        frame.dispose();
        strategie.dispose();
        graphics.dispose();
    }
}
