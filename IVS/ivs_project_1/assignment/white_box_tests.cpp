//======== Copyright (c) 2018, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     Radovan Babic <xbabic09@stud.fit.vutbr.cz>
// $Date:       $2018-03-05
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author RADOVAN BABIC
 *
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"


using namespace ::testing;


// zadefinujem si maticu na testovanie, vytvorim si funkcie na tvorenie najcastejsie
// vyuzivanych matic v implementacii
class MatrixToTest : public Test
{
protected:
	Matrix matrix;


	Matrix make1x1Matrix() {
		return Matrix();
	}


	void build1x1Matrix() {
		matrix = make1x1Matrix();
	}


	Matrix make2x3Matrix() {
		Matrix matrix = Matrix(2, 3);
		matrix.set(std::vector<std::vector<double>> {
			{4, 2, 0},
			{1, 1, 0},
		});

		return matrix;
	}


	void build2x3Matrix() {
		matrix = make2x3Matrix();
	}


	Matrix make3x2Matrix() {
		Matrix matrix = Matrix(3, 2);
		matrix.set(std::vector<std::vector<double>> {
			{1, 1},
			{0, 0},
			{0, 1},
		});

		return matrix;
	}


	void build3x2Matrix() {
		matrix = make3x2Matrix();
	}

	Matrix make3x3Matrix() {
		Matrix matrix = Matrix(3, 3);
		matrix.set(std::vector<std::vector<double>> {
			{1, 2, 3},
			{2, 3, 3},
			{1, 2, 2},
		});

		return matrix;
	}


	void build3x3Matrix() {
		matrix = make3x3Matrix();
	}


	Matrix make4x4Matrix() {
		Matrix matrix = Matrix(4, 4);
		matrix.set(std::vector<std::vector<double>> {
			{4, 12, -7, 5},
			{-4, 0, 2, 42},
			{1, 12, -78, 1},
			{-41, 114, -45, 8},
		});

		return matrix;
	}


	void build4x4Matrix() {
		matrix = make4x4Matrix();
	}
};

TEST_F(MatrixToTest, Create)
{
	// otestujem ci sa matica spravne vytvori
	EXPECT_NO_THROW(Matrix());
	EXPECT_NO_THROW(Matrix(1, 1));
	EXPECT_NO_THROW(Matrix(42, 56));
	EXPECT_NO_THROW(Matrix(101, 145));
	EXPECT_NO_THROW(Matrix(420, 690));

	// minimalna velkost vytvorenej matice je 1x1 - nasledujuce testy by nemali prejst
	EXPECT_ANY_THROW(Matrix(0, 0));
	EXPECT_ANY_THROW(Matrix(1, 0));
	EXPECT_ANY_THROW(Matrix(0, 1));
	EXPECT_ANY_THROW(Matrix(25, 0));
}

TEST_F(MatrixToTest, GetValuesFrom1x1Matrix)
{
	build1x1Matrix();

	// otestujem existujuce hodnoty z matice
	EXPECT_DOUBLE_EQ(matrix.get(0, 0), 0);
}

TEST_F(MatrixToTest, SetValuesTo1x1Matrix)
{
	build1x1Matrix();

	// vyskusam do matice pridat hodnoty, testy budu true
	EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{0}}));
	EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {{424242}}));
}

TEST_F(MatrixToTest, SetValueTo1x1Matrix)
{
	build1x1Matrix();

	// neexistujuci index, testy budu false
	EXPECT_FALSE(matrix.set(1, 1, 0));
	EXPECT_FALSE(matrix.set(0, 1, 0));
	EXPECT_FALSE(matrix.set(1, 0, 0));
}

TEST_F(MatrixToTest, SetValueTo4x4Matrix)
{
	build4x4Matrix();

	// existujuce indexy, testy budu true
	EXPECT_TRUE(matrix.set(0, 0, 0));
	EXPECT_TRUE(matrix.set(2, 2, 0));
}

TEST_F(MatrixToTest, SetValuesTo3x2Matrix)
{
	build3x2Matrix();

	/// nastavim spravne hodnoty, testy budu true
	EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {
		{0, 2},
		{0, 0},
		{1, 1},
	}));
}

TEST_F(MatrixToTest, SetValuesTo2x3Matrix)
{
	build2x3Matrix();

	// do matice pridam spravne hodnoty, test bude true
	EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {
		{2, 0, 0},
		{1, 0, 0},
	}));

}

TEST_F(MatrixToTest, SetValuesTo4x4Matrix)
{
	build4x4Matrix();

	/// do matice nastavim spravne hodnoty, testy budu true
	EXPECT_TRUE(matrix.set(std::vector<std::vector<double>> {
		{4, 12, -7, 5},
		{-4, 0, 2, 42},
		{1, 12, -78, 1},
		{-41, 114, -45, 8},
	}));
}

TEST_F(MatrixToTest, GetValuesFrom4x4Matrix)
{
	build4x4Matrix();

	// otestujem existujuce hodnoty
	EXPECT_DOUBLE_EQ(matrix.get(2, 3), 1);
	EXPECT_DOUBLE_EQ(matrix.get(1, 2), 2);
	EXPECT_DOUBLE_EQ(matrix.get(3, 0), -41);
}

TEST_F(MatrixToTest, EqualityTest)
{
	Matrix matrix3x2 = make3x2Matrix();
	Matrix matrix4x4 = make4x4Matrix();
	Matrix matrix2x3 = make2x3Matrix();

	// porovnavam matice s rovnkou velkostou, testy budu true
	EXPECT_TRUE(matrix2x3 == matrix2x3);
	EXPECT_TRUE(matrix4x4 == matrix4x4);

	// porovnavam matice s roznou velkostou, take matice sa porovnat nedaju
	EXPECT_ANY_THROW(matrix2x3 == matrix3x2);
	EXPECT_ANY_THROW(matrix3x2 == matrix4x4);

}

TEST_F(MatrixToTest, Add)
{
	Matrix matrix1x1 = make1x1Matrix();
	Matrix matrix3x2 = make3x2Matrix();
	Matrix matrix3x3 = make3x3Matrix();

	// nemozem scitat matice s roznou velkostou
	EXPECT_ANY_THROW(matrix3x2 + matrix3x3);
	EXPECT_ANY_THROW(matrix1x1 + matrix3x3);

	// vytvorim si ocakavany vysledok, sucet by sa mali rovnat ocakavanemu vysledku
	Matrix actualResult = matrix3x3 + matrix3x3;
	Matrix expectedResult = Matrix(3, 3);
	expectedResult.set(std::vector<std::vector<double>> {
		{2, 4, 6},
		{4, 6, 6},
		{2, 4, 4},
	});
	EXPECT_TRUE(expectedResult == actualResult);

}

TEST_F(MatrixToTest, MultiplyTest)
{
	Matrix matrix1x1 = make1x1Matrix();
	Matrix matrix3x2 = make3x2Matrix();

	// prva matica musi mat rovnaky pocet stlpcov ako ta druha riadkov
	// test preto neprejde
	EXPECT_ANY_THROW(matrix3x2 * matrix1x1);

	// vytvorim si ocakavany vysledok, sucin by sa mal rovnat
	// pre jednoduchost si zoberiem prazdne 1x1 matice
	Matrix actualResult = matrix1x1 * matrix1x1;
	Matrix expectedResult = Matrix();
	EXPECT_TRUE(actualResult == expectedResult);
}

TEST_F(MatrixToTest, MultiplyMatrixByConstantTest)
{
	Matrix matrix1x1 = make1x1Matrix();
	Matrix matrix3x2 = make3x2Matrix();

	// prva matica musi mat rovnaky pocet stlpcov ako ta druha riadkov
	// test preto neprejde
	EXPECT_ANY_THROW(matrix3x2 * matrix1x1);

	// vytvorim si ocakavany vysledok a maticu vynasobim konstantov, sucin by sa mal rovnat
	// pre jednoduchost si zoberiem prazdne 1x1 matice
	Matrix actualResult = matrix1x1 * 42;
	Matrix expectedResult = Matrix();
	EXPECT_TRUE(actualResult == expectedResult);
}

TEST_F(MatrixToTest, Solve1x1Equation)
{
	build1x1Matrix();
	matrix.set(0, 0, 1);

	// vyskusam vyriesit sustavu rovnic a porovnavam s ocakavanym vysledkom
	EXPECT_TRUE(matrix.solveEquation(std::vector<double> {1}) == (std::vector<double> {1}));
}

TEST_F(MatrixToTest, Solve2x2Equation)
{
	matrix = Matrix(2, 2);
	matrix.set(std::vector<std::vector<double>> {
		{2, -3},
		{1, -2},
	});

	// vyskusam vyriesit sustavu rovnic a porovnavam s ocakavanym vysledkom
	EXPECT_TRUE(matrix.solveEquation(std::vector<double> {5, 1}) == (std::vector<double> {7, 3}));
}

TEST_F(MatrixToTest, Solve3x3Equation)
{
	build3x3Matrix();
	matrix.set(std::vector<std::vector<double>> {
		{1, -1, -2},
		{2, 4, 1},
		{3, -2, -3},
	});

	// vyskusam vyriesit sustavu rovnic a porovnavam s ocakavanym vysledkom
	EXPECT_TRUE(matrix.solveEquation(std::vector<double> {2, 1, -1}) == (std::vector<double> {-2, 2, -3}));
}

TEST_F(MatrixToTest, Solve4x4Equation)
{
	build4x4Matrix();
	matrix.set(std::vector<std::vector<double>> {
		{0, 1, 5, -1},
		{5, 0, -2, 2},
		{-1, 2, -3, 1},
		{3, 0, 1, 2},
	});

	// vyskusam vyriesit sustavu rovnic a porovnavam s ocakavanym vysledkom
	EXPECT_TRUE(matrix.solveEquation(std::vector<double> {-6, 8, 3, -2}) == (std::vector<double>{2, 1, -2, -3}));
}

/*** Konec souboru white_box_tests.cpp ***/
