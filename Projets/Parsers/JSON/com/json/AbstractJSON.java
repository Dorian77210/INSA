package com.json;

public abstract class AbstractJSON {

    protected int depth;

    public AbstractJSON() {
        this.depth = 1;
    }

    abstract String toString(int shift);
    abstract void updateDepth(int depth);

    public boolean equals(AbstractJSON json) {
        return this.toString().equals(json.toString());
    }
}