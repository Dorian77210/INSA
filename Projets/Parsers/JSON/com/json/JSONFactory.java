package com.json;

import java.util.Stack;

public class JSONFactory {

    private static final char RIGHT_ACCOLADE = '}';
    private static final char LEFT_ACCOLADE = '{';
    private static final char RIGHT_BRACKET = ']';
    private static final char LEFT_BRACKET = '[';
    private static final char SIMPLE_QUOTE = '\'';
    private static final char DOUBLE_QUOTE = '"';
    private static final char COMMA = ',';

    public JSONFactory() {

    }

    public static JSONObject parse(String json) {
        JSONObject object = new JSONObject();
        String[] buffer;
        String key, value;
        char currentChar = ' ', separator;
        int index;
        json = json.replaceAll(" ", "");

        while (json.charAt(0) != RIGHT_ACCOLADE && !json.isEmpty()) {
            // we are in json object
            json = json.substring(1);
            index = json.indexOf(':');
            if (index == -1) {
                break;
            }

            buffer = json.split(":", 2);
            key = sanitizeKey(buffer[0]);
            json = buffer[1];

            currentChar = json.charAt(0);
            // it is a string
            if (currentChar == DOUBLE_QUOTE || currentChar == SIMPLE_QUOTE) {
                separator = currentChar;
                json = json.substring(1);
                index = json.indexOf(separator);
                value = json.substring(0, index);
                object.put(key, value);
                json = json.substring(index + 1);
                if(json.charAt(0) != RIGHT_ACCOLADE && json.charAt(0) != COMMA) throw new JSONException("JSON bad formed");
            } else if (currentChar == LEFT_ACCOLADE) {
                String copy = json;
                JSONObject obj = parse(json);
                String tmp = obj.toString();
                object.put(key, obj);
                json = copy.substring(tmp.length());
                if(json.charAt(0) != RIGHT_ACCOLADE && json.charAt(0) != COMMA) throw new JSONException("JSON bad formed");
            } else if (currentChar == LEFT_BRACKET) {
                String copy = json;
                JSONArray array = parseJSONArray(json);
                object.put(key, array);
                String tmp = array.toString();
                json = copy.substring(tmp.length());
                if(json.charAt(0) != RIGHT_ACCOLADE && json.charAt(0) != COMMA) throw new JSONException("JSON bad formed");
            } else {
                // maybe it is a number
                index = json.indexOf(COMMA);
                if(index == -1) index = json.indexOf(COMMA);
                try {
                    // the number is like "key":number}
                    value = json.substring(0, index);
                    long number = Long.parseLong(value);
                    object.put(key, number);
                } catch(Exception exception) {
                    // the number is like "key":number
                    try {
                        value = json.substring(0, index);
                        double number = Double.parseDouble(value);
                        object.put(key, number);
                    } catch(Exception ex) {
                        throw new JSONException("JSON bad formed");
                    }
                }
                
                json = json.substring(0, index + 1);
            }
        }

        return object;
    }

    public static String sanitizeKey(String key) {
        return key.replaceAll("\"", "").replaceAll("\'", "");
    }

    private static final JSONArray parseJSONArray(String json) {
        JSONArray array = new JSONArray();
        String value;
        char currentChar, separator;
        int index;
        while(json.charAt(0) != RIGHT_BRACKET && !json.isEmpty()) {
            json = json.substring(1);
            currentChar = json.charAt(0);
            if(currentChar == DOUBLE_QUOTE || currentChar == SIMPLE_QUOTE) {
                separator = currentChar;
                json = json.substring(1);
                index = json.indexOf(separator);
                value = json.substring(0, index);
                array.put(value);
                json = json.substring(index + 1);
                if(json.charAt(0) != RIGHT_BRACKET && json.charAt(0) != COMMA) throw new JSONException("JSON bad formed");
            } else if(currentChar == LEFT_ACCOLADE) {
                String copy = json;
                JSONObject object = parse(json);
                String tmp = object.toString();
                array.put(object);
                json = copy.substring(tmp.length());
            } else if(currentChar == LEFT_BRACKET) {
                String copy = json;
                JSONArray obj = parseJSONArray(copy);
                String tmp = obj.toString();
                array.put(obj);
                json = json.substring(tmp.length());
            } else {
                // maybe it is a number
                index = json.indexOf(COMMA);
                if(index == -1) index = json.indexOf(RIGHT_BRACKET);
                value = json.substring(0, index);
                try {
                    long number = Long.parseLong(value);
                    array.put(number);
                } catch(Exception exception) {
                    try {
                        double number = Double.parseDouble(value);
                        array.put(number);
                    } catch(Exception ex) {
                        throw new JSONException("JSON bad formed");
                    }
                }
                
                json = json.substring(index);
            }
        }

        return array;
    }

    public static final boolean isCorrectJSON(String json) {
        if (json.charAt(0) != LEFT_ACCOLADE || json.charAt(json.length() - 1) != RIGHT_ACCOLADE)
            return false;
        Stack<Character> stack = new Stack<Character>();
        char currentChar, buffer;
        int length = json.length();

        for (int i = 0; i < length; i++) {
            currentChar = json.charAt(i);
            // state machine
            if ((currentChar == LEFT_ACCOLADE) || (currentChar == LEFT_BRACKET)) {
                stack.push(currentChar);
            } else {
                if (currentChar == RIGHT_ACCOLADE) {
                    if (stack.isEmpty())
                        return false;
                    buffer = stack.pop();
                    if (buffer != LEFT_ACCOLADE)
                        return false;
                } else if (currentChar == RIGHT_BRACKET) {
                    if (stack.isEmpty())
                        return false;
                    buffer = stack.pop();
                    if (buffer != LEFT_BRACKET)
                        return false;
                }
            }
        }

        return true;
    }
}