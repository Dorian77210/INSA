package com.json;

interface IJSON {

    /* PUT METHODS */
    IJSON put(String key, String value);
    IJSON put(String key, boolean value);
    IJSON put(String key, int value);
    IJSON put(String key, long value);
    IJSON put(String key, float value);
    IJSON put(String key, double value);

    void updateDepth(int depth);

    /* GET METHODS */
    String getString(String key);
    int getDepth();


    String toString(int shift);
}