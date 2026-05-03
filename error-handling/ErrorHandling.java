class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

class ConfigException extends RuntimeException {
    public ConfigException(String message) {
        super(message);
    }
}

public class ErrorHandling {
    // Checked exception: must be declared or handled.
    static int parseAge(String text) throws InvalidAgeException {
        int age;
        try {
            age = Integer.parseInt(text);
        } catch (NumberFormatException ex) {
            throw new InvalidAgeException("Age must be a number: " + text);
        }

        if (age < 0) {
            throw new InvalidAgeException("Age cannot be negative");
        }
        return age;
    }

    // Unchecked exception: RuntimeException subclass.
    static String loadConfig(java.util.Map<String, String> data) {
        if (!data.containsKey("mode")) {
            throw new ConfigException("Missing 'mode' in config");
        }
        return data.get("mode");
    }

    static void checkedVsUncheckedNote() {
        System.out.println("Java note: checked exceptions are compiler-enforced; unchecked are not.");
    }

    public static void main(String[] args) {
        System.out.println("Language: Java");

        try {
            System.out.println("Parsed age: " + parseAge("21"));
            System.out.println("Parsed age: " + parseAge("oops"));
        } catch (InvalidAgeException ex) {
            System.out.println("Caught checked custom exception: " + ex.getMessage());
        } finally {
            System.out.println("Finally block: cleanup/logging runs always");
        }

        try {
            String mode = loadConfig(new java.util.HashMap<>());
            System.out.println("Mode: " + mode);
        } catch (ConfigException ex) {
            System.out.println("Caught unchecked custom exception: " + ex.getMessage());
        }

        checkedVsUncheckedNote();
    }
}
