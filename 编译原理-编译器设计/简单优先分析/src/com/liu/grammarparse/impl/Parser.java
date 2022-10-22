package com.liu.grammarparse.impl;

/**
 * 
 * 项目名称：grammarparser<br>     
 *  
 * 类描述：实现接口和抽象方法来解析相关矩阵  <br> 
 * 类名称：com.liu.grammarparse.impl.Parser<br>        
 * 创建人：流沙<br> 
 * 创建时间：2016年5月8日 下午7:28:05<br>      
 * 修改人： 无<br>  
 * 修改时间：2016年5月8日 下午7:28:05<br>      
 * 修改备注：无<br>      
 * @version   V1.0
 */
public class Parser extends AbstractParser {
	
	@Override
	public Integer[][] parseFirstMetrix() {
		
		int n=super.NTernimal.length;
		Integer[][] first=new Integer[n][n];
		
		//初始化first矩阵为0
		for(int i=0;i<first.length;i++)
			for(int j=0;j<first[i].length;j++)
				first[i][j]=0;
		
		//将产生式右边第一个字符对应的在表中设置为1
		for(String LPartor:super.LRpartors.keySet()){
			int row=super.charIndex.get(LPartor);
			String[] RPartor=super.LRpartors.get(LPartor);
			for(String r:RPartor){
				int col=super.charIndex.get(r.charAt(0)+"");
				first[row][col]=1;
			}
		}
		
		return first;
	}

	@Override
	public Integer[][] parseLastMetrix() {
		int n=super.NTernimal.length;
		Integer[][] last=new Integer[n][n];
		
		//初始化last矩阵为0
		for(int i=0;i<last.length;i++)
			for(int j=0;j<last[i].length;j++)
				last[i][j]=0;
		
		//将产生式右边第一个字符对应的在表中设置为1
		for(String LPartor:super.LRpartors.keySet()){
			int row=super.charIndex.get(LPartor);
			String[] RPartor=super.LRpartors.get(LPartor);
			for(String r:RPartor){
				int col=super.charIndex.get(r.charAt(r.length()-1)+"");
				last[row][col]=1;
			}
		}
		
		return last;
	}

	@Override
	public Integer[][] parseEqualProcedent() {
		int n=super.NTernimal.length;
		Integer[][] equal=new Integer[n][n];

		//初始化last矩阵为0
		for(int i=0;i<equal.length;i++)
			for(int j=0;j<equal[i].length;j++)
				equal[i][j]=0;

		for(char ch:super.NTernimal){
			int row=super.charIndex.get(ch+"");
			
			for(String LPartor:super.LRpartors.keySet()){
				for(String s:super.LRpartors.get(LPartor)){
					int index;
					if((index=s.indexOf(ch))>-1 && index<s.length()-1){
						int col=super.charIndex.get(s.charAt(index+1)+"");
						equal[row][col]=1;
					}
				}
			}
		}
		
		return equal;
	}

	@Override
	public Integer[][] parseGreaterProcedent() {return null;}

	@Override
	public Integer[][] parseLesserProcedent() {return null;}

	@Override
	protected Integer[][] combineThreeProcedentToProcedentTable(
			Integer[][] equal, Integer[][] less, Integer[][] great) {
		int n=super.NTernimal.length;
		Integer[][] table=new Integer[n][n];
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				table[i][j]=9;
				if(equal[i][j]!=0)
					table[i][j]=0;
				if(less[i][j]!=0)
					table[i][j]=-1;
				if(great[i][j]!=0)
					table[i][j]=1;
			}
		}
		
		return table;
	}

}
