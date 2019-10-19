package com.json;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;

public class JSONObject implements IJSON {

    protected static final int DEFAULT_SHIFT = 1;

    protected Map<String, JSONObject> children;
    protected List<JSONNode> siblings;
    protected int depth;

    /**
     * Create an empty JSONObject
     */
    public JSONObject() {
        this.children = new HashMap<String, JSONObject>();
        this.siblings = new ArrayList<JSONNode>();
        this.depth = 1;
    }

    @Override
    public JSONObject put(String key, String value) {
        JSONNode node = new JSONNode(this.depth + 1);
        node.put(key, value);
        this.siblings.add(node);
        return this;
    }

    @Override
    public JSONObject put(String key, int value) {
        JSONNode node = new JSONNode(this.depth + 1);
        node.put(key, value);
        this.siblings.add(node);
        return this;
    }

    @Override
    public JSONObject put(String key, long value) {
        JSONNode node = new JSONNode(this.depth + 1);
        node.put(key, value);
        this.siblings.add(node);
        return this;
    }

    @Override
    public JSONObject put(String key, boolean value) {
        JSONNode node = new JSONNode(this.depth + 1);
        node.put(key, value);
        this.siblings.add(node);
        return this;
    }

    @Override
    public JSONObject put(String key, float value) {
        JSONNode node = new JSONNode(this.depth + 1);
        node.put(key, value);
        this.siblings.add(node);
        return this;
    }

    @Override
    public JSONObject put(String key, double value) {
        JSONNode node = new JSONNode(this.depth + 1);
        node.put(key, value);
        this.siblings.add(node);
        return this;
    }

    

    public JSONObject put(String key, JSONObject json) {
        this.children.put(key, json);
        this.updateDepth();
        return this;
    }


    public void updateDepth() {
        for(IJSON json : this.siblings) {
            json.updateDepth(this.depth);
        }

        JSONObject json;
        String key;

        for(Map.Entry<String, JSONObject> entry : this.children.entrySet()) {
            json = entry.getValue();
            key = entry.getKey();
            json.updateDepth(this.depth + 1);
        }
    }

    public void updateDepth(int depth) {
        this.depth = depth;
        this.updateDepth();
    }


    @Override
    public String getString(String key) {
        String result;
        // check the siblings

        for(IJSON json : this.siblings) {
            result = json.getString(key);
            if(!result.isEmpty()) {
                return result;
            }
        }

        // check the children
        JSONObject json;
        String jsonKey;
        for(Map.Entry<String, JSONObject> entry : this.children.entrySet()) {
            json = entry.getValue();
            result = json.getString(key);
            if(!result.isEmpty()) {
                return result;
            }
        }

        return "";
    }

    @Override
    public int getDepth() {
        return this.depth;
    }

    @Override
    public String toString() {
        return this.toString(DEFAULT_SHIFT);
    }

    @Override
    public String toString(int shift) {
        String result = "";
        int i, size;
        IJSON json;
        int shiftLeft = shift * this.depth;

        for(i = 0; i < (shift * this.depth); i++) result += " ";
        result += "{\n";


        Set<Map.Entry<String, JSONObject>> set = this.children.entrySet();
        size = this.children.size();
        i = 0;

        for(Map.Entry<String, JSONObject> entry : set) {
            JSONObject object = entry.getValue();
            String key = entry.getKey();
            for(i = 0; i < shiftLeft; i++) {
                result += " ";
            }

            result += key + ": " + object.toString(shift) + ",\n";
            i++;
        }

        size = this.siblings.size();
        for(i = 0; i < size; i++) {
            json = this.siblings.get(i);
            result += json.toString(shift);
            if(i != (size - 1)) result += ",\n";
        }

        result += "\n";
        for(i = 0; i < (this.depth * shift); i++) result += " ";
        result += "}";
        return result;
    }
}