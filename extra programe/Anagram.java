import java.util.Arrays;

public class Main
{
	public static void main(String[] args) {
	    String a = "aba";
	    String b = "baha";
	    boolean ana = false;
	    int alen = a.length();
	    int blen = b.length();
	    if(alen != blen){
	        ana = false;
	    }else{
	       char[] anagram1 = a.toCharArray();
	       char[] anagram2 = b.toCharArray();
	       Arrays.sort(anagram1);
	       Arrays.sort(anagram2);
	       ana = Arrays.equals(anagram1,anagram2);
	    }
	    if(ana){
	        System.out.println("Anagram");
	    }else{
	        System.out.println("not");
	    }
	}
}