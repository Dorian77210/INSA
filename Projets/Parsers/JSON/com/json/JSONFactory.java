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
            key = buffer[0];
            json = buffer[1];

            currentChar = json.charAt(0);
            // it is a string
            if (currentChar == DOUBLE_QUOTE || currentChar == SIMPLE_QUOTE) {
                separator = (currentChar == DOUBLE_QUOTE) ? DOUBLE_QUOTE : SIMPLE_QUOTE;
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
                JSONArray tmp = new JSONArray();
                index = parseJSONArray(tmp, json);
                object.put(key, tmp);
                json = json.substring(0, index);
            }
        }

        return object;
    }

    private static final int parseJSONArray(JSONArray buffer, String json) {
        return 0;
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