package com.json;

interface IJSON {

    /* PUT METHODS */
    void put(String key, String value);
    void put(String key, boolean value);
    void put(String key, int value);
    void put(String key, long value);
    void put(String key, float value);
    void put(String key, double value);

    void updateDepth(int depth);

    /* GET METHODS */
    String getString(String key);
    int getDepth();


    String toString(int shift);
}