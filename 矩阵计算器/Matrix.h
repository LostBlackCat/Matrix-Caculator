#ifndef _MATRIX_H
#define _MATRIX_H

#include<cstdlib>
#include<ctime>

template <typename T>
class Matrix
{
private:
	T MatrixArrey[5][5];
	int row;
	int column;
public:
	Matrix(int hang,int lie)
	{
		row=hang;
		column=lie;
		srand((unsigned)time(NULL));
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				MatrixArrey[i][j]=rand()%100+1;
			}
		}

	}
	void change(int hang,int lie)
	{
		row=hang;
		column=lie;
		srand((unsigned)time(NULL));
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				MatrixArrey[i][j]=rand()%100+1;
			}
		}
	}
	void Transpose()
	{
		int var=row;
		row=column;
		column=var;
		for(int i=0;i<5;i++)
		{
			for(int j=i;j<5;j++)
			{
				T tem=MatrixArrey[i][j];
				MatrixArrey[i][j]=MatrixArrey[j][i];
				MatrixArrey[j][i]=tem;
			}
		}
	}
	void Multiply(int number)
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				MatrixArrey[i][j]=number*MatrixArrey[i][j];
			}
		}
	}
	Matrix<T> add(Matrix<T> other)
	{
		Matrix<T> result(row,column);
		if(row==other.row&&column==other.column)
		{
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<column;j++)
				{
					result.MatrixArrey[i][j]=MatrixArrey[i][j]+other.MatrixArrey[i][j];
				}
			}
		}
		else
		{
			result.MatrixArrey[0][0]=-9999;
		}
		return result;
	}
	Matrix<T> subtrct(Matrix<T> other)
	{
		Matrix<T> result(row,column);
		if(row==other.row&&column==other.column)
		{
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<column;j++)
				{
					result.MatrixArrey[i][j]=MatrixArrey[i][j]-other.MatrixArrey[i][j];
				}
			}
		}
		else
		{
			result.MatrixArrey[0][0]=-9999;
		}
		return result;
	}
	Matrix<T> MULTIPLY(Matrix<T> other)
	{
		Matrix<T> result(row,other.column);
		if(column==other.row)
		{
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<other.column;j++)
				{
					int tem=0;
					for(int n=0;n<column;n++)
					{
						tem=tem+MatrixArrey[i][n]*other.MatrixArrey[n][j];
					}
					result.MatrixArrey[i][j]=tem;
				}
			}
		}
		else
			result.MatrixArrey[0][0]=-9999;
		return result;
	}
	void intoCString(CString& into)
	{
		into="";
		if(MatrixArrey[0][0]==-9999)
		{
			into="wrong Matrix";
		}
		else
		{
		    for(int i=0;i<row;i++)
		    {
			    for(int j=0;j<column;j++)
			    {
				    CString tem;
				    tem.Format(_T("%d"),MatrixArrey[i][j]);
				    into=into+" "+tem;
			     }
			    into=into+"\r\n";
		    }
		}
	}

};


#endif
