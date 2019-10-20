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
        return this.toString(0);
    }

    @Override
    public String toString(int shift) {
        this.buffer = "[";
        shift *= this.depth;

        // children
        AbstractJSON json;
        int i = 0, limit = this.elements.size() - 1;
        boolean isJSONObject;
        
        for(Map.Entry<String, AbstractJSON> entry : this.elements.entrySet()) {
            json = entry.getValue();
            isJSONObject = json instanceof JSONObject;
            if(isJSONObject) this.buffer += "\n"; 

            this.buffer += json.toString(shift);
            if(i != limit) this.buffer += ",";
            else {
                if(isJSONObject) this.buffer += "\n";
            }

            i++; 
        }

        this.buffer += "]";

        String result = new String(this.buffer);
        this.buffer = ""; // clean the buffer
        return result;
    }
}