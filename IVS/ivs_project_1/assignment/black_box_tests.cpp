//======== Copyright (c) 2018, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Radovan Babic <xbabic09@stud.fit.vutbr.cz>
// $Date:       $2018-03-05
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author RADOVAN BABIC
 *
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>
#include "gtest/gtest.h"
#include "red_black_tree.h"

using namespace ::testing;

class NonEmptyTree : public Test
{
protected:
      BinaryTree tree;
      virtual void SetUp() {
          int values[10] = {1,2,3,4,5,6,7,8,9,10};
          for (int i = 0; i < 11; i++) {
            tree.InsertNode(values[i]);
          }
        }

};

class EmptyTree : public Test
{
protected:
      BinaryTree tree;
};

class TreeAxioms : public Test
{
protected:
      BinaryTree tree;
      virtual void SetUp() {
          int values[10] = {1,2,3,4,5,6,7,8,9,10};
          for (int i = 0; i < 11; i++) {
            tree.InsertNode(values[i]);
          }
        }
};


TEST_F(EmptyTree, InsertNode){
      // vlozim do stromu node s hodnotou 42
      std::pair<bool, BinaryTree::Node_t *> insert = tree.InsertNode(42);
      BinaryTree::Node_t *node = insert.second;

      // skontrolujem ci sa node pridal
      ASSERT_FALSE(node == NULL);

      // skontrolujem farbu a hodnotu, mal by mat ciernu farbu a hodnotu 42
      EXPECT_EQ(node->color, BinaryTree::BLACK);
      EXPECT_EQ(node->key, 42);

      // skontrolujem jeho stav a rodica, nemal by mat ziadneho rodica
      EXPECT_FALSE(node->pParent != NULL);

      // nasledne overim jeho laveho potomka
      BinaryTree::Node_t *leftdes = node->pLeft;
      ASSERT_FALSE(leftdes == NULL);
      EXPECT_EQ(leftdes->color, BinaryTree::BLACK);

      // overim jeho stav, potomok by nemal mat potomkov a mal by mat rodica
      // s hodnotou 42
      EXPECT_FALSE(leftdes->pLeft != NULL);
      EXPECT_FALSE(leftdes->pRight != NULL);
      EXPECT_TRUE(leftdes->pParent != NULL);
      EXPECT_EQ(leftdes->pParent->key, 42);

      // rovnaku operaciu vykonam s pravym potomkom
      BinaryTree::Node_t *rightdes = node->pRight;
      ASSERT_FALSE(rightdes == NULL);
      EXPECT_EQ(rightdes->color, BinaryTree::BLACK);
      EXPECT_FALSE(rightdes->pLeft != NULL);
      EXPECT_FALSE(rightdes->pRight != NULL);
      EXPECT_TRUE(rightdes->pParent != NULL);
      EXPECT_EQ(rightdes->pParent->key, 42);
}

TEST_F(NonEmptyTree, InsertNode){
      // do stromu vlozim node s existujucou hodnotou
      std::pair<bool, BinaryTree::Node_t *> insert = tree.InsertNode(42);
      BinaryTree::Node_t *node = insert.second;

      // skontrolujem ci sa node pridal
      ASSERT_FALSE(node == NULL);

      // skontrolujem stav, farbu a hodnotu
      EXPECT_EQ(node->color, BinaryTree::RED);
      EXPECT_EQ(node->key, 42);
      EXPECT_FALSE(tree.FindNode(42) == NULL);

      // skontrolujem stav rodica a potomkov
      ASSERT_FALSE(node->pParent == NULL);
      ASSERT_FALSE(node->pLeft == NULL);
      ASSERT_FALSE(node->pRight == NULL);
}

TEST_F(EmptyTree, DeleteNode){
      // v cykle vyskusam vymazat strom, je prazdny, EXPECT_FALSE
      for (int i = 0; i < 10; i++) {
        EXPECT_FALSE(tree.DeleteNode(i));
      }
}

TEST_F(NonEmptyTree, DeleteNode){
      // v cykle vyskusam vymazat strom, nie je prazdny, EXPECT_TRUE
      for (int i = 1; i < 11; ++i) {
        EXPECT_TRUE(tree.DeleteNode(i));
      }
}

TEST_F(EmptyTree, FindNode){
      // v cykle vyskusam najst nodes v strome, je prazdny, FindNode == NULL
      for (int i = 0; i < 10; i++) {
        EXPECT_TRUE(tree.FindNode(i) == NULL);
      }
}

TEST_F(NonEmptyTree, FindNode){
      // v cykle vyskusam najst nodes v strome, nie je prazdny, FindNode != NULL
      for (int i = 1; i < 10; ++i) {
        EXPECT_FALSE(tree.FindNode(i) == NULL);
      }
}

TEST_F(TreeAxioms, Axiom1){
      // pomocou funkcie GetLeafNodes najdem vsetky listove uzly bez potomka
      std::vector<BinaryTree::Node_t *> LEAF;
      tree.GetLeafNodes(LEAF);

      // v cykle prejdem cely strom a testujem, ci su vsetky leafNodes cierne
      for (BinaryTree::Node_t *leafNode : LEAF) {
        ASSERT_EQ(leafNode->color, BinaryTree::BLACK);
      }
}

TEST_F(TreeAxioms, Axiom2){
    // pomocou funkcie GetAllNodes najdem vsetky uzly s potomkami
    std::vector<BinaryTree::Node_t *> ALL;
    tree.GetAllNodes(ALL);

    // v cykle prejdem cely strom a overim, ci ma kazdy cerveny uzol cierneho potomkami
    for (BinaryTree::Node_t *node : ALL) {
      if (node->color == BinaryTree::RED) {
        ASSERT_EQ(node->pLeft->color, BinaryTree::BLACK);
        ASSERT_EQ(node->pRight->color, BinaryTree::BLACK);
      }
    }
}

TEST_F(TreeAxioms, Axiom3){
    // pomocou funkcie GetLeafNodes najdem vsetky listove uzly
    std::vector<BinaryTree::Node_t *> LEAF;
    tree.GetLeafNodes(LEAF);

    // zadefinujem si pocitadla a uzol ktory budem kontrolovat
    BinaryTree::Node_t *nodeToCheck;
    int totalBlackNodes = 0;
    int countedBlackNodes = 0;

    // v cykle for prejdem vsetky listove uzly
    // na zaciatku vynulujem pocitadlo a zoberiem si jeden listovy uzol na kontrolu
    for (BinaryTree::Node_t *node : LEAF) {
      countedBlackNodes = 0;
      nodeToCheck = node;

      // vnorenym cyklom while budem kotrolovat farbu a inkrementovat pocitadlo
      while (nodeToCheck) {
        if (nodeToCheck->color == BinaryTree::BLACK) {
          countedBlackNodes++;
        }
        // aby sme sa dostali az na vrch stromu, vzdy zoberiem rodica a nastavim
        // ho ako dalsi uzol na testovanie
        // tymto zarucim, ze cyklus while skonci ked pridem na vrch stromu
        nodeToCheck = nodeToCheck->pParent;
      }

      // ziskanu hodnotu ulozim do premennej totalBlackNodes a posuniem sa o jeden
      // uzol vyssie a skontrolujem, ci sa ich pocet rovna
      totalBlackNodes = countedBlackNodes;
      EXPECT_EQ(totalBlackNodes, countedBlackNodes);
    }


}

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

/*** Konec souboru black_box_tests.cpp ***/
