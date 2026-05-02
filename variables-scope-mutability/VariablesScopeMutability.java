import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class VariablesScopeMutability {
    private static void mutateList(List<String> items) {
        items.add("new-item");
    }

    public static void main(String[] args) {
        int mutableCount = 1;
        final String immutableName = "Nazmul";

        List<String> items = new ArrayList<>(List.of("a", "b"));
        Map<String, String> config = new HashMap<>();
        config.put("mode", "demo");

        String scopeValue;
        {
            String insideBlock = "inside";
            scopeValue = insideBlock;
        }

        mutateList(items);
        config.put("mode", "updated");
        mutableCount = mutableCount + 1;

        System.out.println("Language: Java");
        System.out.println("immutableName=" + immutableName);
        System.out.println("mutableCount=" + mutableCount);
        System.out.println("scopeValue=" + scopeValue);
        System.out.println("items=" + items);
        System.out.println("config=" + config);
    }
}
