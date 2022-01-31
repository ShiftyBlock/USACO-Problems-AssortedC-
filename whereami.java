import java.util.*;
import java.io.*;
public class whereami{
	public static void main(String[] args)throws Exception{
		Scanner sc= new Scanner(new FileInputStream(new File("name.in")));
		PrintWriter pw= new PrintWriter(new FileOutputStream(new File("name.out")));
		int n= sc.nextInt();
		pw.println(n+1);
		pw.close();
	}
}
