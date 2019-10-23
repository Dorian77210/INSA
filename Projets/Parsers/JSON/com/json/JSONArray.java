package com.json;

import java.util.Map;

public class JSONArray extends JSONObject {

    public JSONArray() {
        super();
    }

    /* SETTER METHODS */
    public JSONArray put(String value) {
        String key = this.generateChildrenKey();
        this.elements.put(key, new JSONNode(value));
        return this;
    }

    public JSONArray put(JSONObject value) {
        String key = this.generateChildrenKey();
        this.elements.put(key, value);
        value.updateDepth(this.depth + 1);
        return this;
    }

    public JSONArray put(Number value) {
        String key = this.generateChildrenKey();
        this.elements.put(key, new JSONNode(objectToString(value)));
        this.updateDepth();
        return this;
    }

    public JSONArray put(boolean value) {
        String key = this.generateChildrenKey();
        this.elements.put(key, new JSONNode(objectToString(value)));
        return this;
    }

    /* UTILS METHODS */
    private String generateChildrenKey() {
        return Integer.toString(this.elements.size());
    }

    private static String indexToString(int index) {
        return Integer.toString(index);
    }

    /* GETTER METHODS */ 
    public String getString(int index) {
        return super.getString(indexToString(index));
    }

    public int getInt(int index) {
        return super.getInt(indexToString(index));
    }

    public long getLong(int index) {
        return super.getLong(indexToString(index));
    }

    public boolean getBoolean(int index) {
        return super.getBoolean(indexToString(index));
    }

    public float getFloat(int index) {
        return super.getFloat(indexToString(index));
    }

    public double getDouble(int index) {
        return super.getDouble(indexToString(index));
    }

    public JSONObject getJSONObject(int index) {
        return super.getJSONObject(indexToString(index));
    }

    public JSONArray getJSONArray(int index) {
        return super.getJSONArray(indexToString(index));
    }

    public boolean has(int index) {
        return super.has(indexToString(index));
    }

    public boolean isNull(int index) {
        return super.isNull(indexToString(index));
    }

    public Object remove(int index) {
        return super.remove(indexToString(index));
    }

    @Override
    public String toString() {
        return this.toString(0).replaceAll(" ", "").replaceAll("\n", "");
    }

    @Override
    public String toString(int shift) {
        this.buffer = "[";
        shift *= this.depth;

        // variable for the forEach method
        final int[] tmp = { 0 };
        final int commaLimit = this.elements.size() - 1;

        this.elements.forEach((String key, AbstractJSON value) -> {
            boolean isJSONObject = value instanceof JSONObject;
            if(isJSONObject) this.buffer += "\n";
            try {
                String str = value.toString().replaceAll("\"", ""); 
                Double.parseDouble(str);
                this.buffer += str;
            } catch(Exception exception) {
                this.buffer += value.toString();
            }


            if(tmp[0] != commaLimit) this.buffer += ",";
            else {
                if(isJSONObject) this.buffer += "\n";
            } 

            tmp[0]++;
        });  

        this.buffer += "]";

        String result = new String(this.buffer);
        this.buffer = ""; // clean the buffer
        return result;
    }
}