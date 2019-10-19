package com.json;

class JSONNode extends AbstractJSON {

    private String value;

    JSONNode(String value) {
        this.value = value;
        this.depth = 1;
    }

    JSONNode(int depth, String value) {
        this.depth = depth;
        this.value = value;
    }

    @Override
    public String toString() {
        return this.toString(0);
    }

    @Override
    public void updateDepth(int depth) {
        this.depth = depth;
    }

    @Override
    public String toString(int shift) {
        return "\"" + this.value + "\""; 
    }
}