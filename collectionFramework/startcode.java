import java.util.*;


public class startcode{
    public static void main(String[] args) {
        // creating Arraylist collection
        ArrayList<Integer> arraylist = new ArrayList<Integer>();

        
        arraylist.add(10);
        arraylist.add(20);
        arraylist.add(30);
        arraylist.add(40);
        
        // System.out.println(arraylist);
        // System.out.println(arraylist.size());
        // System.out.println(arraylist.contains(10));
        

        // create vector
        Vector<Integer> vector = new Vector<Integer>();
        vector.addAll(arraylist);
        // System.out.println(vector);

        HashSet<Double> nums = new HashSet<Double>();
        System.out.println("---------------------------------------------------------------------------");

        nums.add(10.30);
        nums.add(15.30);
        nums.add(12.30);
        nums.add(13.30);
        nums.add(14.30);
        nums.add(14.30);
        // System.out.println(nums);
        
        TreeSet<Double> tset = new TreeSet<Double>();
        tset.addAll(nums);
        // System.out.println(tset);

        // iterator

        // for(int ele:arraylist){
        //     System.out.println(ele);
        // }

         
        // traversing forward
        Iterator it = arraylist.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }

        // traversing backword
        ListIterator lt = arraylist.listIterator(arraylist.size());

        while(lt.hasPrevious()){
            System.out.println(lt.previous());
        }

        arraylist.forEach(e -> {
            System.out.println(e);
        });

    }
}


















