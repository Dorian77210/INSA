package com.json;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class JSONArray extends JSONObject {

    private List<Object> elements;

    public JSONArray() {
        super();
        this.elements = new ArrayList<Object>();
    }

    public JSONArray put(String value) {
        String key = this.generateSiblingsKey();
        this.siblings.add(new JSONNode(this.depth, key, value, false));
        return this;
    }

    public JSONArray put(Object value) {
        String key = this.generateSiblingsKey();
        String str = new StringBuilder().append(value).toString();
        this.siblings.add(new JSONNode(this.depth, key, str, false));
        System.out.println("ok");
        return this;
    }

    public JSONArray put(boolean value) {
        String key = this.generateSiblingsKey();
        this.siblings.add(new JSONNode(this.depth, key, Boolean.toString(value), false));
        return this;
    }

    public JSONArray put(float value) {
        String key = this.generateSiblingsKey();
        this.siblings.add(new JSONNode(this.depth, key, Float.toString(value), false));
        return this;
    }

    public JSONArray put(double value) {
        String key = this.generateSiblingsKey();
        this.siblings.add(new JSONNode(this.depth, key, Double.toString(value), false));
        return this;
    }

    public JSONArray put(long value) {
        String key = this.generateSiblingsKey();
        this.siblings.add(new JSONNode(this.depth, key, Long.toString(value), false));
        return this;
    }

    public JSONArray put(int value) {
        String key = this.generateSiblingsKey();
        this.siblings.add(new JSONNode(this.depth, key, Integer.toString(value), false));
        return this;
    }

    public JSONArray put(JSONObject value) {
        String key = this.generateChildrenKey();
        this.children.put(key, value);
        return this;
    }

    private String generateSiblingsKey() {
        return Integer.toString(this.siblings.size());
    }

    private String generateChildrenKey() {
        return Integer.toString(this.children.size());
    }


    @Override
    public String toString() {
        return this.toString(0);
    }

    @Override
    public String toString(int shift) {
        String result = "[";
        int i, size;

        // children
        JSONObject json;
        for(Map.Entry<String, JSONObject> entry : this.children.entrySet()) {
            json = entry.getValue();
            result += json.toString(shift) + ",\n";            
        }

        // siblings
        IJSON node;
        size = this.siblings.size();
        for(i = 0; i < size; i++) {
            node = this.siblings.get(i);
            result += node.toString();
            if(i != (size - 1)) result += ",";
        }

        result += "]";
        return result;
    }
}