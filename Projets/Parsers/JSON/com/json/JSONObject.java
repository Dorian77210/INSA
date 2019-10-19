package com.json;

import java.util.Map;
import java.util.HashMap;

public class JSONObject extends AbstractJSON {

    protected static final int DEFAULT_SHIFT = 1;

    protected Map<String, AbstractJSON> elements;
    protected String buffer;

    /**
     * Create an empty JSONObject
     */
    public JSONObject() {
        this.elements = new HashMap<String, AbstractJSON>();
        this.depth = 0;
        this.buffer = "";
    }

    public JSONObject put(String key, String value) {
        this.elements.put(key, new JSONNode(value));
        return this;
    }

    public JSONObject put(String key, Number value) {
        StringBuffer buffer = new StringBuffer().append(value);
        this.elements.put(key, new JSONNode(buffer.toString()));
        return this;
    }

    public JSONObject put(String key, boolean value) {
        this.elements.put(key, new JSONNode(Boolean.toString(value)));
        return this;
    }

    public JSONObject put(String key, JSONObject json) {
        this.elements.put(key, json);
        this.updateDepth();
        return this;
    }

    public void updateDepth() {
        AbstractJSON json;
        String key;

        for(Map.Entry<String, AbstractJSON> entry : this.elements.entrySet()) {
            json = entry.getValue();
            key = entry.getKey();
            json.updateDepth(this.depth + 1);
        }
    }

    public void updateDepth(int depth) {
        this.depth = depth;
        this.updateDepth();
    }


    public int getDepth() {
        return this.depth;
    }

    @Override
    public String toString() {
        return this.toString(DEFAULT_SHIFT);
    }

    @Override
    public String toString(int shift) {
        int i;
        int shiftLeft = shift * (this.depth + 1);

        for(i = 0; i < this.depth * shift; i++) this.buffer += " ";
        this.buffer += "{\n";

        this.elements.forEach((String key, AbstractJSON value) -> {
            for(int j = 0; j < shiftLeft; j++) {
                this.buffer += " ";
            }

            this.buffer += key + ": " + value.toString(shift) + ",\n";
        });      

        for(i = 0; i < this.depth * shift; i++) this.buffer += " ";
        this.buffer += "}";

        String result = new String(this.buffer);
        this.buffer = ""; // clean the buffer
        
        return result;
    }
}