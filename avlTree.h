/*
 * AVLTree.h
 *
 *  Created on: Nov 27, 2016
 *      Author: user
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <iostream>


template<class keyType,class dataType>
class AVLNode {
public:
	AVLNode<keyType,dataType>* father;
	AVLNode<keyType,dataType>* rightSon;
	AVLNode<keyType,dataType>* leftSon;
	keyType key;
	dataType value;
	int height;
	int balanceFactor;

	AVLNode():
			father(NULL),
			rightSon(NULL),
			leftSon(NULL),
			key(0),
			height(0),
			balanceFactor(0)
	{}

	AVLNode(keyType iKey, dataType tData):
			father(NULL),
			rightSon(NULL),
			leftSon(NULL),
			key(iKey),
			value(tData),
			height(0),
			balanceFactor(0)
	{}

	AVLNode(keyType iKey, dataType tData, int iBalanceFactor, AVLNode* nLeftSon, AVLNode* nRightSon, AVLNode* nPrev, int iHeight): // a "full" node
			key(iKey),
			value(tData),
			balanceFactor(iBalanceFactor),
			height(iHeight),
			father(nPrev),
			rightSon(nRightSon),
			leftSon(nLeftSon)
	{}

	AVLNode(keyType iKey, dataType tData, int iBalanceFactor, AVLNode* nLeftSon, AVLNode* nRightSon, int iHeight):
			father(NULL),
			rightSon(nRightSon),
			leftSon(nLeftSon),
			key(iKey),
			value(tData),
			height(iHeight),
			balanceFactor(iBalanceFactor)
	{}

	AVLNode(const AVLNode<keyType,dataType>& nNode):
		father(nNode.father),
		rightSon(nNode.rightSon),
		leftSon(nNode.leftSon),
		key(nNode.key),
		value(nNode.value),
		height(nNode.height),
		balanceFactor(nNode.balanceFactor)
	{}

	int getAndSetHeight() {
		if (NULL != leftSon && NULL != rightSon) {
			if (leftSon->getAndSetHeight() > rightSon->getAndSetHeight()) {
				height = leftSon->getAndSetHeight() + 1;
			}
			else {
				height = rightSon->getAndSetHeight() + 1;
			}
		}
		else if (NULL != leftSon) {
			height = leftSon->getAndSetHeight() + 1;
		}
		else if (NULL != rightSon) {
			height = rightSon->getAndSetHeight() + 1;
		}
		else {
			height = 0;
		}
		return height;
	}

	int getBalanceFactor() {
		this->updateBalanceFactor();
		return balanceFactor;
	}
	void updateBalanceFactor() {
		AVLNode<keyType,dataType>* tmpNode = this;
		if (NULL != leftSon && NULL != rightSon) {
			tmpNode->balanceFactor = (tmpNode->leftSon->getAndSetHeight()) - (tmpNode->rightSon->getAndSetHeight());
		}
		else if (NULL != leftSon) {
			tmpNode->balanceFactor = (tmpNode->leftSon->getAndSetHeight()) + 1;
		}
		else if (NULL != rightSon) {
			tmpNode->balanceFactor = (-1) * (tmpNode->rightSon->getAndSetHeight() + 1);
		}
		else {
			tmpNode->balanceFactor = 0;
		}
	}


	AVLNode<keyType,dataType>* setLeftSon(AVLNode<keyType,dataType>* newLeftNode) {
		if (NULL != newLeftNode) {
			newLeftNode->father = this;
		}
		leftSon = newLeftNode;
		getAndSetHeight();
		return leftSon;
	}

	AVLNode<keyType,dataType>* setRightSon(AVLNode<keyType,dataType>* newRightNode) {
		if (newRightNode) {
			newRightNode->father = this;
		}
		rightSon = newRightNode;
		getAndSetHeight();
		return rightSon;
	}

	bool findByKey(keyType& iKey) {
		if (this->key == iKey) {
			return true;
		}
		if (this->key > iKey) {
			if (NULL == leftSon) {
				return false;
			}
			return leftSon->findByKey(iKey);
		}
		if (NULL == rightSon) {
			return false;
		}
		return rightSon->findByKey(iKey);
	}

	AVLNode<keyType,dataType>* returnNode(keyType iKey) {
		if (this->key == iKey) {
			return this;
		}
		if (this->key > iKey) {
			if (NULL == leftSon) {
				return NULL;
			}
			return leftSon->returnNode(iKey);
		}
		if (NULL ==rightSon) {
			return NULL;
		}
		return rightSon->returnNode(iKey);
	}

	void swap(AVLNode<keyType,dataType>* nNode) {
		if (!nNode) {
			return;
		}
		keyType tmpKey = nNode->key;
		nNode->key = key;
		key = tmpKey;
		dataType tmpValue = nNode->value;
		nNode->value = value;
		value = tmpValue;
	}

	void emptySubTree(AVLNode<keyType,dataType>* nNode){
		if(!nNode){
			return;
		}

		emptySubTree(nNode->leftSon);
		emptySubTree(nNode->rightSon);
		delete  nNode;
		nNode=NULL;



	}



};



typedef enum {
	AVLTREE_SUCCESS, AVLTREE_ALLOCATION_ERROR, AVLTREE_NODE_ALREADY_EXISTS, AVLTREE_NODE_NOT_FOUND
} TreeResult;

template<class keyType,class dataType>
class AVLTree {
public:
	AVLNode<keyType,dataType>* rootNode;
	int size;

	static AVLNode<keyType,dataType>* copyNodes(AVLNode<keyType,dataType>* nNode) {
		if (nNode != NULL) {
			AVLNode<keyType,dataType>* left = copyNodes(nNode->leftSon);
			AVLNode<keyType,dataType>* right = copyNodes(nNode->rightSon);
			return new AVLNode<keyType,dataType>(nNode->key, nNode->value, nNode->balanceFactor, left, right, nNode->height);
		}
		else {
			return NULL;
		}
	}

	static void updatePrevNode(AVLNode<keyType,dataType>* nNode) {
		if (nNode == NULL) {
			return;
		}
		if (nNode->rightSon != NULL) {
			AVLNode<keyType,dataType>* tmp = nNode->rightSon;
			tmp->father = nNode;
			updatePrevNode(nNode->rightSon);
		}
		if (nNode->leftSon != NULL) {
			AVLNode<keyType,dataType>* tmp = nNode->leftSon;
			tmp->father = nNode;
			updatePrevNode(nNode->leftSon);
		}
	}

	AVLTree(const AVLTree& tTree) { // copy cTor
		this->size = tTree.size;
		this->rootNode = copyNodes(tTree.rootNode);
		updatePrevNode(this->rootNode);

		if (this->rootNode != NULL) {
			this->rootNode->father = NULL;
		}
	}

	AVLTree(const AVLTree* tTree) { // copy cTor
		this->size = tTree->size;
		this->rootNode = copyNodes(tTree->rootNode);
		updatePrevNode(this->rootNode);

		if (this->rootNode != NULL) {
			this->rootNode->father = NULL;
		}
	}

	const AVLTree<keyType,dataType>& operator=(const AVLTree& tree) {
		if (this == &tree) {
			return *this;
		}

		this->emptyTree();

		this->size = tree.size;
		this->rootNode = copyNodes(tree.rootNode);

		updatePrevNode(this->rootNode);

		if (this->rootNode != NULL) {
			this->rootNode->father = NULL;
		}

		return *this;
	}

	AVLTree(){
			rootNode = NULL;
			size = 0;
	}

	inline bool operator==(const AVLTree<keyType,dataType>& tTree) {
		return this->rootNode == tTree.rootNode;
	}

	void rotateRight(AVLNode<keyType,dataType>* nNode) {
		AVLNode<keyType,dataType>* parent = nNode->father;
		int flag;
		if (NULL != parent) {
			flag = parent->leftSon == nNode ? 1 : 2;
		}
		AVLNode<keyType,dataType>* tmpNode = nNode->leftSon;
		nNode->setLeftSon(tmpNode->rightSon);
		tmpNode->setRightSon(nNode);
		if (NULL != parent) {
			if (flag == 1) {
				parent->leftSon = tmpNode;
			} else {
				parent->rightSon = tmpNode;
			}
		} else {
			rootNode = tmpNode;
			if (rootNode) {
				rootNode->father = NULL;
				return;
			}
		}
		tmpNode->father = parent;
	}

	void rotateLeft(AVLNode<keyType,dataType>* nNode) {
		AVLNode<keyType,dataType>* parent = nNode->father;
		int flag;
		if (NULL != parent) {
			flag = parent->leftSon == nNode ? 1 : 2;
		}
		AVLNode<keyType,dataType>* tmp = nNode->rightSon;
		nNode->setRightSon(tmp->leftSon);
		tmp->setLeftSon(nNode);
		if (NULL != parent) {
			if (flag == 1) {
				parent->setLeftSon(tmp);
			} else {
				parent->setRightSon(tmp);
			}
		} else {
			rootNode = tmp;
			if (rootNode) {
				rootNode->father = NULL;
			}
		}
		tmp->father = parent;
	}

	void checkBalance(AVLNode<keyType,dataType>* nNode) {
		int balanceFactor = nNode->getBalanceFactor();
		if (balanceFactor > 1) {
			if (nNode->leftSon->getBalanceFactor() < 0) {
				rotateLeft(nNode->leftSon);
			}
			rotateRight(nNode);
		}
		else if (balanceFactor < -1) {
			if (nNode->rightSon->getBalanceFactor() > 0) {
				rotateRight(nNode->rightSon);
			}
			rotateLeft(nNode);
		}
	}

	template<class Function>
	void inorder(AVLNode<keyType,dataType>* node, Function f) {
		if (!node) {
			return;
		}
		inorder(node->leftSon, f);
		f(node);
		inorder(node->rightSon, f);
	}





	dataType* findMax() {
		if (NULL == rootNode) {
			return NULL;
		}
		AVLNode<keyType,dataType>* node = rootNode;
		while(node->rightSon){
			node = node->rightSon;
		}
		return &(node->value);
	}
	dataType* findMin() {
		if (NULL == rootNode) {
			return NULL;
		}
		AVLNode<keyType,dataType>* node = rootNode;
		while(node->leftSon){
			node = node->leftSon;
		}
		return &(node->value);
	}

	AVLNode<keyType,dataType>* returnNextNode(AVLNode<keyType,dataType>* node) { // returns the following node by order (according to the key)
		if (!node) {
			return NULL;
		}
		AVLNode<keyType,dataType>* tmp = node;
		if (!node->father) {
			if (!tmp->rightSon) {
				return NULL;
			}
			tmp = tmp->rightSon;
			while (tmp->leftSon) {
				tmp = tmp->leftSon;
			}
			return tmp;
		}
		else if (!tmp->rightSon && (tmp->key < node->father->key)) {
			return tmp->father;
		}
		else if (tmp->rightSon) {
			tmp = tmp->rightSon;
			while (tmp->leftSon) {
				tmp = tmp->leftSon;
			}
			return tmp;
		}
		else if (!tmp->rightSon && (tmp->key > node->father->key)) {
			while (tmp->father) {
				if (tmp->key > tmp->father->key) {
					tmp = tmp->father;
				} else {
					return tmp->father;
				}
			}
		}
		return tmp->key > node->key ? tmp : NULL;
	}

	void emptyTree();
	~AVLTree() {
		emptyTree();
	}

	bool findIfValueExists(keyType& iKey);
	TreeResult insertData(const keyType& iKey,const dataType& data);
	TreeResult removeValue(keyType& iKey);
	AVLNode<keyType,dataType>* returnRoot();
	AVLNode<keyType,dataType>* getNodeByKey(keyType& iKey);
	dataType* getValue(keyType& iKey);

};

template<class keyType,class dataType>
bool AVLTree<keyType,dataType>::findIfValueExists(keyType& iKey) {
	if (!rootNode) { //nothing in the tree
		return false;
	}
	return rootNode->findByKey(iKey);
}

template<class keyType,class dataType>
AVLNode<keyType,dataType>* AVLTree<keyType,dataType>::getNodeByKey(keyType& iKey) {
	if (NULL == rootNode) {
		return NULL;
	}
	return rootNode->returnNode(iKey);
}

template<class keyType,class dataType>
dataType* AVLTree<keyType,dataType>::getValue(keyType& iKey) {
	if (!this->findIfValueExists(iKey))
	{
		return NULL;
	}
	return &(rootNode->returnNode(iKey)->value);
}

template<class keyType,class dataType>
TreeResult AVLTree<keyType,dataType>::insertData(const keyType& iKey,const dataType& data) {
	if (NULL == rootNode) {
		try {
			rootNode = new AVLNode<keyType,dataType>(iKey, data);
		}
		catch (std::bad_alloc&) {
			return AVLTREE_ALLOCATION_ERROR;
		}
		size++;
		return AVLTREE_SUCCESS;
	}
	AVLNode<keyType,dataType>* tmpNode = rootNode;
	AVLNode<keyType,dataType>* newNode;
	while (true) {
		if (tmpNode->key > iKey) {
			if (!tmpNode->leftSon) {
				newNode = new AVLNode<keyType,dataType>(iKey, data);
				tmpNode->setLeftSon(newNode);
				break;
			} else {
				tmpNode = tmpNode->leftSon;
			}
		}
		else if (tmpNode->key < iKey) {
			if (!tmpNode->rightSon) {
				newNode = new AVLNode<keyType,dataType>(iKey, data);
				tmpNode->setRightSon(newNode);
				break;
			} else {
				tmpNode = tmpNode->rightSon;
			}
		}
		else {
			return AVLTREE_NODE_ALREADY_EXISTS;
			break;
		}
	}
	tmpNode = newNode;
	while (tmpNode) { //updating the node ruined path
		tmpNode->getAndSetHeight(); //Updating the height
		tmpNode->updateBalanceFactor();
		checkBalance(tmpNode);
		tmpNode = tmpNode->father;
	}
	size++;
	return AVLTREE_SUCCESS;
}

template<class keyType,class dataType>
TreeResult AVLTree<keyType,dataType>::removeValue(keyType& iKey) {
	if (!rootNode || !findIfValueExists(iKey)) {
		return AVLTREE_NODE_NOT_FOUND;
	}
	else if (size == 1) {
		delete rootNode;
		size--;
		rootNode = NULL;
		return AVLTREE_SUCCESS;
	}
	AVLNode<keyType,dataType>* parent = NULL;
	AVLNode<keyType,dataType>* tmp = rootNode->returnNode(iKey);
	if (tmp->father) {
		parent = tmp->father;
	}
	if (!tmp->leftSon && !tmp->rightSon) { //if this node is a leaf
		if (parent) {
			if (parent->key < tmp->key) { //then tmp is a right son.
				parent->rightSon = NULL;
			}
			else {
				parent->leftSon = NULL;
			}
			delete tmp;
			while (parent) {
				parent->getAndSetHeight();
				parent->updateBalanceFactor();
				checkBalance(parent);
				parent = parent->father;
			}
		}
		else { //then this one is the root.
			rootNode = NULL;
			delete tmp;
		}
	}
	else if (!tmp->rightSon) {
		if (parent) {
			if (parent->key < tmp->key) { //then tmp is a right son.
				parent->setRightSon(tmp->leftSon);
			} else {
				parent->setLeftSon(tmp->leftSon);
			}
			delete tmp;
			while (parent) {
				parent->getAndSetHeight();
				parent->updateBalanceFactor();
				checkBalance(parent);
				parent = parent->father;
			}
		}
		else {
			rootNode = tmp->leftSon;
			tmp->leftSon->father = NULL;
			delete tmp;
		}
	}
	else if (!tmp->leftSon) {
		if (parent) {
			if (parent->key < tmp->key) { //then tmp is a right son.
				parent->setRightSon(tmp->rightSon);
			}
			else {
				parent->setLeftSon(tmp->rightSon);
			}
			delete tmp;
			while (parent) {
				parent->getAndSetHeight();
				parent->updateBalanceFactor();
				checkBalance(parent);
				parent = parent->father;
			}
		}
		else {
			rootNode = tmp->rightSon;
			tmp->rightSon->father = NULL;
			delete tmp;
		}
	}
	else {
		AVLNode<keyType,dataType>* replace = tmp->rightSon;
		while (replace->leftSon) {
			replace = replace->leftSon;
		}
		tmp->swap(replace);
		parent = replace->father;
		if (parent->rightSon) {
			if (parent->rightSon->key == replace->key) {
				parent->setRightSon(replace->rightSon);
			}
			else {
				parent->setLeftSon(replace->rightSon);
			}
		}
		else {
			parent->setLeftSon(replace->rightSon);
		}
		delete replace;
		while (parent) {
			parent->getAndSetHeight();
			parent->updateBalanceFactor();
			checkBalance(parent);
			parent = parent->father;
		}
	}
	size--;
	return AVLTREE_SUCCESS;
}


template<class keyType,class dataType>
void inOrderToArray(AVLNode<keyType,dataType>* nNode, dataType* array, int* i) {
	if (!nNode) {
		return;
	}
	inOrderToArray(nNode->leftSon, array, i);
	array[(*i)++] = nNode->value;
	inOrderToArray(nNode->rightSon, array, i);
}







#endif /* AVLTREE_H_ */
