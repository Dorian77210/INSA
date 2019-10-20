package com.json;

import java.util.List;
import java.util.ArrayList;
import java.util.Collection;
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

    /* SETTERS */
    public JSONObject put(String key, String value) {
        this.elements.put(key, new JSONNode(value));
        return this;
    }

    public JSONObject put(String key, Number value) {
        this.elements.put(key, new JSONNode(objectToString(value)));
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

    public JSONObject put(String key, Collection<?> values) {
        JSONArray array = new JSONArray();
        for(Object element : values) {
            array.put(objectToString(element));
        }

        this.elements.put(key, array);
        return this;
    }

    public JSONObject put(String key, Map<?, ?> values) {
        values.forEach((Object mapKey, Object value) -> {
            this.elements.put(mapKey.toString(), new JSONNode(objectToString(value)));
        });

        return this;
    }

    /* UTILS METHODS */ 
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

    public Object remove(String key) {
        AbstractJSON json = this.elements.get(key);
        if(json == null) return null;
        return (json instanceof JSONNode) ? getSanitizedValue(json) : json;        
    }

    protected static String objectToString(Object object) {
        return new StringBuffer().append(object).toString();
    }

    /* ERROR METHODS */
    public static final void generateKeyNotFoundError(String key) {
        throw new JSONException("The object has not object with key \"" + key + "\"");
    }

    public static final void generateFormatViolationError(String key) {
        throw new JSONException("The value for the key \"" + key + "\" don't respect the wanted format");
    }

    /* GETTERS METHODS */
    public String getString(String key) {
        AbstractJSON value = this.elements.get(key);
        if(value == null) generateKeyNotFoundError(key);
        String result = getSanitizedValue(value);
        return result;
    }

    private static String getSanitizedValue(AbstractJSON json) {
        String result = json.toString().replace('"', ' ').trim();
        return result;
    }

    private static String sanitizeKey(String key) {
        return key.replace('"', ' ').replace('\'', ' ').trim();
    }

    public int getInt(String key) {
        AbstractJSON value = this.elements.get(key);
        if(value == null) generateKeyNotFoundError(key);
        
        int result = 0;
        try {
            result = Integer.parseInt(getSanitizedValue(value));
        } catch(Exception exception) {
            generateFormatViolationError(key);
        }

        return result;
    }

    public long getLong(String key) {
        AbstractJSON value = this.elements.get(key);
        if(value == null) generateKeyNotFoundError(key);
        
        long result = 0;
        try {
            result = Long.parseLong(getSanitizedValue(value));
        } catch(Exception exception) {
            generateFormatViolationError(key);
        }

        return result;
    }

    public boolean getBoolean(String key) {
        AbstractJSON value = this.elements.get(key);
        if(value == null) generateKeyNotFoundError(key);
        
        boolean result = false;
        try {
            result = Boolean.parseBoolean(getSanitizedValue(value));
        } catch(Exception exception) {
            generateFormatViolationError(key);
        }

        return result;
    }

    public float getFloat(String key) {
        AbstractJSON value = this.elements.get(key);
        if(value == null) generateKeyNotFoundError(key);
        
        float result = 0.0f;
        try {
            result = Float.parseFloat(getSanitizedValue(value));
        } catch(Exception exception) {
            generateFormatViolationError(key);
        }

        return result;
    }

    public double getDouble(String key) {
        AbstractJSON value = this.elements.get(key);
        if(value == null) generateKeyNotFoundError(key);
        
        double result = 0.0f;
        try {
            result = Double.parseDouble(getSanitizedValue(value));
        } catch(Exception exception) {
            generateFormatViolationError(key);
        }

        return result;
    }

    public List<String> keysList() {
        final List<String> keys = new ArrayList<String>();
        this.elements.forEach((String key, AbstractJSON json) -> {
            keys.add(key);
        });

        return keys;
    }

    public JSONArray keysToJSONArray() {
        final JSONArray array = new JSONArray();
        this.elements.forEach((String key, AbstractJSON json) -> {
            array.put(key);
        });

        return array;
    }

    public boolean has(String key) {
        return this.elements.get(key) != null;
    }

    public boolean isNull(String key) {
        return !this.has(key);
    }


    public JSONObject getJSONObject(String key) {
        AbstractJSON value = this.elements.get(key);
        if(value == null) generateKeyNotFoundError(key);

        try {
            JSONObject object = (JSONObject)value;
            return object;
        } catch(Exception exception) {
            generateFormatViolationError(key);
        }

        return null;
    }

    public JSONArray getJSONArray(String key) {
        AbstractJSON value = this.elements.get(key);
        if(value == null) generateKeyNotFoundError(key);

        try {
            JSONArray object = (JSONArray)value;
            return object;
        } catch(Exception exception) {
            generateFormatViolationError(key);
        }

        return null;
    }

    public int length() {
        return this.elements.size();
    }

    @Override
    public String toString() {
        return this.toString(0).replaceAll(" ", "").replaceAll("\n", "");
    }

    @Override
    public String toString(int shift) {
        int i;
        int shiftLeft = shift * (this.depth + 1);

        for(i = 0; i < this.depth * shift; i++) this.buffer += " ";
        this.buffer += "{\n";

        final int[] tmp = { 0 };
        final int commaLimit = this.elements.size() - 1;
        
        this.elements.forEach((String key, AbstractJSON value) -> {
            for(int j = 0; j < shiftLeft; j++) {
                this.buffer += " ";
            }

            this.buffer += key + ": " + value.toString(shift);
            if(tmp[0] != commaLimit) this.buffer += ",";
            this.buffer += "\n";

            tmp[0]++;
        });      

        for(i = 0; i < this.depth * shift; i++) this.buffer += " ";
        this.buffer += "}";

        String result = new String(this.buffer);
        this.buffer = ""; // clean the buffer
        
        return result;
    }
}