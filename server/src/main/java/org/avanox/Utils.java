package org.avanox;

import java.awt.Color;

public class Utils {
    /**
     * Convert a string format #RRGGBBAA to a Color object
     * 
     * @param colorStr
     * @return Color
     */
    public static Color hexToRGBA(String colorStr) {
        return new Color(
                Integer.valueOf(colorStr.substring(1, 3), 16),
                Integer.valueOf(colorStr.substring(3, 5), 16),
                Integer.valueOf(colorStr.substring(5, 7), 16),
                Integer.valueOf(colorStr.substring(7, 9), 16));
    }
}
