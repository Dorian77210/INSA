package com.json;

class JSONNode implements IJSON {

    private String key;
    private String value;
    private int depth;

    JSONNode(int depth) {
        this.key = "";
        this.value = "";
        this.depth = depth;
    }

    @Override
    public void put(String key, String value) {
        this.key = key;
        this.value = value;
    }

    @Override
    public void put(String key, boolean value) {
        this.key = key;
        this.value = Boolean.toString(value);
    }

    @Override
    public void put(String key, int value) {
        this.key = key;
        this.value = Integer.toString(value);
    }

    @Override
    public void put(String key, long value) {
        this.key = key;
        this.value = Long.toString(value);
    }

    @Override
    public void put(String key, float value) {
        this.key = key;
        this.value = Float.toString(value);
    }

    @Override
    public void put(String key, double value) {
        this.key = key;
        this.value = Double.toString(value);
    }


    @Override
    public void updateDepth(int depth) {
        this.depth = depth;
    }



    @Override
    public String getString(String key) {
        String result = this.key.equals(key) ? this.value : "";
        return result;
    }

    @Override
    public int getDepth() {
        return this.depth;
    }

    @Override
    public String toString() {
        return this.toString(0);
    }

    @Override
    public String toString(int shift) {
        String result = "";
        int i;
        shift *= this.depth;

        for(i = 0; i < shift; i++) {
            result += " ";
        }

        result += "\"" + this.key + "\"" + ": " + this.value;
        return result;
    }
}