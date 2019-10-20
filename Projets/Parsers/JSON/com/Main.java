import com.json.JSONObject;
import com.json.JSONArray;
import com.json.JSONFactory;

public class Main {

    public static void testJSONObject() {
        JSONObject json = new JSONObject();
        json.put("toto", "titi");
        System.out.println(json.getString("toto"));
    }

    public static void testGetter() {
        JSONObject o = new JSONObject().put("titi", 10);
        System.out.println(o.getInt("titi"));

        o.put("toto", new JSONObject().put("titi", 100));
        System.out.println(o.getJSONObject("toto").toString(2));

        System.out.println(o.keysList().toString());
        System.out.println(o.keysToJSONArray().toString());
    }

    public static void testJSONArray() {
        JSONArray array = new JSONArray();

        JSONObject o = new JSONObject().put("toto", "titi").put("tutu", true).put("hhh", 10.0);
        array.put(o);
        array.put(o);
        System.out.println(array.toString(2));

    }

    public static void testValidJSON() {
        String json = new StringBuilder()
            .append("{")
            .append("'car':{'type':'SUV'}, 'lastname':'Terbah','firstname':'Dorian'")
            .append("}")
            .toString();

            JSONObject o = JSONFactory.parse(json);
            System.out.println(o.toString());
    }

    public static void main(String[] args) {
        testValidJSON();
    }
}