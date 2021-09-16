public class countPathsMaze{

    public static int countPath(int i,int j,int n, int m){
        if(i == n || j == m){
            return 0;
        }

        if(i == n-1 && j == m-1){
            return 1;
        }
        // move downwords
        int downPaths = countPath(i+1,j,n,m);

        int rightPaths = countPath(i,j+1,n,m);

        return downPaths+rightPaths;
    }
    public static void main(String[] args){
        int n =3,m=3;
        int totalPaths = countPath(0,0,n,m);
        System.out.println(totalPaths);
    }  
};


















