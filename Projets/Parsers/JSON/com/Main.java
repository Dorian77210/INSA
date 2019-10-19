import com.json.JSONObject;
import com.json.JSONArray;

public class Main {

    public static void testJSONObject() {
        JSONObject json = new JSONObject();
        JSONArray array = new JSONArray();
        
        // json.put("cars", array);
        // System.out.println(json.toString(2));
        JSONObject o = new JSONObject()
            .put("name", "Ford")
            .put("models", new JSONArray()
                .put("Fiesta").put("Focus").put("Mustang")
            );
        
        array.put(o);
        json.put("cars", array);


        System.out.println(json.toString(2));
    }

    public static void testJSONArray() {
        JSONArray array = new JSONArray();

        JSONObject o = new JSONObject().put("toto", "titi").put("tutu", true).put("hhh", 10.0);
        array.put(o);
        array.put(o);
        System.out.println(array.toString(2));

    }

    public static void main(String[] args) {
        testJSONObject();
    }
}