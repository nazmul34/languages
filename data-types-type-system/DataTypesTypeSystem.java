import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DataTypesTypeSystem {
    public static void main(String[] args) {
        int age = 28;
        double temperature = 36.7;
        String name = "Nazmul";
        boolean isActive = true;
        List<String> tags = List.of("java", "types", "demo");

        Map<String, Integer> scores = new HashMap<>();
        scores.put("math", 90);
        scores.put("science", 88);

        String middleName = null;

        String convertedAge = String.valueOf(age);
        int parsedNumber = Integer.parseInt("42");

        System.out.println("Language: Java");
        System.out.println("age=" + age + " (int)");
        System.out.println("temperature=" + temperature + " (double)");
        System.out.println("name=" + name + " (String)");
        System.out.println("isActive=" + isActive + " (boolean)");
        System.out.println("tags=" + tags + " (List<String>)");
        System.out.println("scores=" + scores + " (Map<String, Integer>)");
        System.out.println("middleName=" + middleName + " (String nullable)");
        System.out.println("convertedAge=" + convertedAge + " (String)");
        System.out.println("parsedNumber=" + parsedNumber + " (int)");
    }
}
