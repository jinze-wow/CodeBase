package com.liu.test;

import java.util.Map;

import com.liu.grammarparse.impl.Mediator;


public class Test {

	public static void main(String[] args) {
/*		Integer [][] a={{2,3,4,5},{6,7,8,9},{10,11,12,13}};
		Integer [][] b={{0,1,1,0,0},{1,0,1,0,1},{0,1,0,0,1},{0,0,0,0,0},{1,0,0,1,0}};
		Integer [][]d={{0,0,1,0,0,0,0,0},
							 {0,0,0,1,1,0,1,0},
							 {0,1,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0}};
		Integer[][] c=MetrixUtil.transitiveClosuresByWarShall(d);
		
		Test.printMetrix(c);
*/		
		
		/*String wenfa="S=> (R) | a | A\nR=> T \n T=> S,T  |  S";
		IParserBootstrap p=new ParseBootStrap();
		Character[] ch=p.parseNTernimal(wenfa);
		Map<String, String[]> map=p.parseWenFaPartors(wenfa);
		
		System.out.println(Arrays.toString(ch));
		System.out.println();
		for(String key:map.keySet()){
			System.out.print("key:"+key+",value:");
			for(int i=0;i<map.get(key).length;i++)
				System.out.print(map.get(key)[i]+"@");
			System.out.println();
		}*/
		
		//String wenfa="S=> (R) | a | ^\nR=> T \n T=> S,T  |  S";
		String wenfa="E=>e \n e=>e+t | t \n t=>T \n T=>T*F | F \n F=>(E) | i";
		Mediator mediator=new Mediator();
		mediator.init(wenfa);
		Character [][] t=mediator.getProcedentTable();

		//Map<String,Object> map=mediator.getValidatorGrammar("((a),a)");
		//Map<String,Object> map=mediator.getValidatorGrammar("(i+i)*i");
		Map<String,Object> map=mediator.getValidatorGrammar("i*i+(i)*i(i)*i+i*i");

		System.out.println(map.get("process"));
		//printMetrix(t);
	}

	public static void printMetrix(Integer [][] r){			
		for(int i=0;i<r.length;i++){
			for(int j=0;j<r[i].length;j++)
				System.out.print(r[i][j]+" ");
			
			System.out.println();
		}	
		System.out.println();
	}
	
	public static void printMetrix(Character [][] r){			
		for(int i=0;i<r.length;i++){
			for(int j=0;j<r[i].length;j++)
				System.out.print(String.format("%3c", r[i][j]));
			
			System.out.println();
		}	
		System.out.println();
	}

}
