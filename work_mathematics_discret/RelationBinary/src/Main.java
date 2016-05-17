import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	ArrayList<Simetricos> colectionPars;
	ArrayList<Integer> colectionInterval, colA, colB;
	ArrayList<Simetricos> colectionNotSimetrics;
	static Scanner scannerA;
	static Scanner scannerB;
	static Scanner scannerq;
	static Integer A, B, q;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Digite o numero A: ");
		scannerA = new Scanner(System.in);
		A = scannerA.nextInt();

		System.out.println("Digite o numero B: ");
		scannerB = new Scanner(System.in);
		B = scannerB.nextInt();

		System.out.println("Digite o numero q: ");
		scannerq = new Scanner(System.in);
		q = scannerB.nextInt();

		Main n = new Main();
		n.InsertionArray();
		n.PrintArray();
		n.IsSimetric();
		// n.PrintArray();
		if (n.IsSimetric() > 0) {
			System.out.println(" nao simetrico : " + 0);
			// n.InsertArrayNotSimetric();
			n.InsertArrayNewSimetrics();
			n.PrintNotSimetric();			
		} else {
			System.out.println("simetrico : " + 1);
		}

	}

	/*
	 * public void InsertionArray() { colectionPars = new
	 * ArrayList<Simetricos>(); colectionInterval = new ArrayList<Integer>();
	 * for (int i = 0; i < q; i++) { // separados por ,
	 * System.out.println("Digite os simetricos [" + i + "]"); Scanner scan =
	 * new Scanner(System.in); String vector = scan.nextLine(); String[] parts =
	 * vector.split(","); //
	 * System.out.println("colection : {"+parts[0]+","+parts[1]+"}"); Simetricos
	 * sim = new Simetricos(); sim.setA(Integer.parseInt(parts[0]));
	 * sim.setB(Integer.parseInt(parts[1])); colectionPars.add(sim); }
	 * 
	 * for (int i = A; i <= B; i++) { colectionInterval.add(i); }
	 * 
	 * }
	 */

	public void InsertArrayNewSimetrics() {
		colectionNotSimetrics = new ArrayList<Simetricos>();
		for (int i = 0; i < colectionPars.size(); i++) {
			if (colectionPars.get(i).A == colectionPars.get(i).B) {
				Simetricos simetricos = new Simetricos();
				simetricos.setA(colectionPars.get(i).A);
				simetricos.setB(colectionPars.get(i).B);
				colectionNotSimetrics.add(simetricos);
			} else {
				Simetricos simetricos = new Simetricos();
				if (IsParSimetric(colectionPars.get(i).A,
						colectionPars.get(i).B)) {
					simetricos.setA(colectionPars.get(i).A);
					simetricos.setB(colectionPars.get(i).B);
				} else {
					simetricos.setA(colectionPars.get(i).A);
					simetricos.setB(colectionPars.get(i).B);

					Simetricos simetricosn = new Simetricos();

					simetricosn.setA(colectionPars.get(i).B);
					simetricosn.setB(colectionPars.get(i).A);
					colectionNotSimetrics.add(simetricosn);
				}
				colectionNotSimetrics.add(simetricos);
			}
		}
		
		Collections.sort(colectionNotSimetrics);

	}

	public void InsertionArray() {
		colectionPars = new ArrayList<Simetricos>();
		colectionInterval = new ArrayList<Integer>();
		int randA, randB, j = 0;
		/*
		 * for(int i=0; i < q; i++){ randA = rand(A,B); randB = rand(A,B);
		 * 
		 * }
		 */
		while (j < q) {
			randA = rand(A, B);
			randB = rand(A, B);
			if (!IsExists(randA, randB)) {
				Simetricos simetricos = new Simetricos();
				simetricos.setA(randA);
				simetricos.setB(randB);
				colectionPars.add(simetricos);
				j++;
			}

		}
	}

	static int rand(int Str, int End) {
		return (int) Math.ceil(Math.random() * (End - Str + 1)) - 1 + Str;
	}

	/**
	 * Metodo para verificar se o par gerado randomicamente já existe no Array
	 * 
	 * @param vA
	 * @param vB
	 * @return
	 */
	public boolean IsExists(int vA, int vB) {
		for (int i = 0; i < colectionPars.size(); i++) {
			if ((vA == colectionPars.get(i).A)
					&& (vB == colectionPars.get(i).B)) {
				return true;
			}
		}
		return false;
	}

	public void PrintNotSimetric() {
		for (int i = colectionNotSimetrics.size() -1; i > -1; i--) {
			System.out.println(colectionNotSimetrics.get(i).A + ","
					+ colectionNotSimetrics.get(i).B + "\n");
		}
	}

	public void InsertArrayNotSimetric() {
		colectionNotSimetrics = new ArrayList<Simetricos>();
		for (int i = A; i <= B; i++) {
			for (int k = 0; k <= B; k++) {
				Simetricos simetricos = new Simetricos();
				simetricos.setA(i);
				simetricos.setB(k);
				colectionNotSimetrics.add(simetricos);
			}
		}
	}

	public int IsSimetric() {
		int cont = 0;
		for (int i = 0; i < colectionPars.size(); i++) {
			if (colectionPars.get(i).A != colectionPars.get(i).B) {
				if (!IsParSimetric(colectionPars.get(i).A,
						colectionPars.get(i).B)) {
					cont++;
				}
			}
		}
		return cont;
	}

	public boolean IsParSimetric(Integer A, Integer B) {
		for (int i = 0; i < colectionPars.size(); i++) {
			if ((colectionPars.get(i).A == B) && (colectionPars.get(i).B == A)) {
				return true;
			}
		}
		return false;
	}

	public void PrintArray() {
		for (int i = 0; i < colectionPars.size(); i++) {
			System.out.println(" v :" + colectionPars.get(i).A + ","
					+ colectionPars.get(i).B);
		}
	}

	public void ScannerOrderPars() {

	}

}
