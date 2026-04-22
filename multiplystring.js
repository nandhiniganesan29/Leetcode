public class Solution {
    public String multiply(String num1, String num2) {
        // If any number is 0
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        int n1 = num1.length();
        int n2 = num2.length();
        
        int[] result = new int[n1 + n2];

        // Multiply from right to left
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int d1 = num1.charAt(i) - '0';
                int d2 = num2.charAt(j) - '0';

                int product = d1 * d2;

                int p1 = i + j;
                int p2 = i + j + 1;

                int sum = product + result[p2];

                result[p2] = sum % 10;     // unit digit
                result[p1] += sum / 10;    // carry
            }
        }

        // Build result string
        StringBuilder sb = new StringBuilder();
        for (int num : result) {
            if (!(sb.length() == 0 && num == 0)) {
                sb.append(num);
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        Solution obj = new Solution();
        System.out.println(obj.multiply("2", "3"));       // 6
        System.out.println(obj.multiply("123", "456"));   // 56088
    }
}
