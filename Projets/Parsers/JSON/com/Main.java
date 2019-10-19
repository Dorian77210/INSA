import com.json.JSONObject;
import com.json.JSONArray;

public class Main {

    public static void testJSONObject() {
        JSONObject json = new JSONObject();

        JSONObject person = new JSONObject();
        person.put("lastname", "Terbah");
        person.put("firstname", "Dorian");
        person.put("age", 20);
        json.put("person", person);

        JSONObject o = new JSONObject();
        o.put("hish", "toto");
        o.put("xx", "dldld");
        o.put("x", 10);

        json.put("data", o);

        System.out.println(json);
    }

    public static void testJSONArray() {
        JSONArray array = new JSONArray();
        array.put("toto").put("titi");
        System.out.println(array.toString(2));
    }

    public static void main(String[] args) {
        testJSONArray();
    }
}