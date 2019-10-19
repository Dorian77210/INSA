package com.json;

import java.util.Map;

public class JSONArray extends JSONObject {

    public JSONArray() {
        super();
    }

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
        StringBuffer buffer = new StringBuffer().append(value);
        String key = this.generateChildrenKey();
        this.elements.put(key, new JSONNode(buffer.toString()));
        this.updateDepth();
        return this;
    }

    public JSONArray put(boolean value) {
        String key = this.generateChildrenKey();
        this.elements.put(key, new JSONNode(Boolean.toString(value)));
        return this;
    }

    private String generateChildrenKey() {
        return Integer.toString(this.elements.size());
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