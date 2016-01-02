#ifndef __MATRIX__
#define __MATRIX__

#include "Common.h"

class Matrix
{
	friend istream& operator >> (istream&, Matrix&);        //��������
	friend ostream& operator << (ostream&, const Matrix&);  //�������
	friend Matrix dotMul(const Matrix &, const Matrix &);
	friend Matrix dotDiv(const Matrix &, const Matrix &);
	friend Matrix operator + (const Matrix &, const Matrix &); 
	friend Matrix operator - (const Matrix &, const Matrix &);
	friend Matrix operator * (const Matrix &, const Matrix &);

public:
	//���캯��
	Matrix() : data(NULL), use(NULL), row(0), col(0)  //Ĭ�Ϲ��캯��
	{
	}
	Matrix(int r, int c, double va = 0);
	Matrix(string s);

	//���ƿ���
	Matrix(const Matrix &);   //���ƹ��캯��
	Matrix& operator = (Matrix &);   //���ظ�ֵ
	~Matrix();   //��������

	//���ظ��ϸ�ֵ
	Matrix& operator += (const Matrix &);
	Matrix& operator -= (const Matrix &);

	//��ͨ��Ա����
	Matrix T() const;
	void copyTo(Matrix &) const;
	int get_row() const
	{
		return row;
	}
	int get_col() const
	{
		return col;
	}
	double get_val(int r, int c) const;
	void set_val(int r, int c, double va);
	double get_sum() const;

private:
	int row, col;
	double *data;
	int *use;

};


Matrix dotMul(const Matrix &, const Matrix &);
Matrix dotDiv(const Matrix &, const Matrix &);
Matrix operator + (const Matrix &, const Matrix &);
Matrix operator - (const Matrix &, const Matrix &);
Matrix operator * (const Matrix &, const Matrix &);


#endif 
