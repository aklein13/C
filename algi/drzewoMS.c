#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *parent;
	struct node *left;
	struct node *right;
	int key;
};

//wstawia wezel z do drzewa t
void treeInsert(struct node *t,struct node *z){
	struct node *x= t;
	struct node *y= NULL; //y jest ojcem 
	
	while(x!=NULL){
		y=x;
		if(z->key<x->key)
			x=x->left;

			
			else 
			x=x->right;
	}
	z->parent=y;
	if(y==NULL)
		t->parent=z;
	else if(z->key<y->key)
		y->left=z;
	else 
		y->right=z;
}


//tworzenie nowego wezla
struct node *nodeNew(int k){
	struct node *z;
	z=malloc(sizeof(struct node));
	z->parent=NULL;
	z->left=NULL;
	z->right=NULL;
	z->key=k;
	return z;
}

//drukowanie drzewa w porzadku in-order
void treePrint(struct node *t){
	struct node *z=t;
	if(z==NULL)
		return;
	else{
	
	
		treePrint(z->left);
		printf(" %d",z->key);
		treePrint(z->right);
}
}


//wyszukiwanie najmniejszego wezla w drzewie 

struct node *treeMinimum(struct node *x){
	while(x->left!=NULL){
		x=x->left;
	}
	return x;
}

//wyszukiwanie klucza k w poddrzewie o korzeniu x
struct node *treeSearch(int k,struct node *x){
	while(x!=NULL && k!=x->key){
		if(k<x->key)
			x=x->left;
		else 
			x=x->right;
	}
	return x; //zwraca NULL, gdy nie ma klucza 
}

//usuwanie drzewa w kolejnosci in-order
/*
void treeDeleteALL(struct node *t){
	struct node *z=t;
	if(z==NULL)
		return;
	else{
		treeDeleteALL(z->left);
		treeDeleteALL(z->right);
		free(z);

	} 
}
*/
//usuwanie wezla n z drzewa t (wedlug starszych wydan Cromera)

struct node *treeDelete(struct node *t, struct node *z)
{
	struct node *x;
	struct node *y;

	if(z->left==NULL || z->right==NULL)
		y = z;
	else
		y=treeMinimum(z->right);	// Usuwamy y z co najwyzej jednym synem
	if(y->left!=NULL)
		x = y->left;
	else					// x to jedyny syn y lub null
		x = y->right;
	if(x!=NULL)
		x->parent = y->parent;
	if(y->parent==NULL)			// jesli y byl korzeniem
		t = x;
	else
	{
		if(y==y->parent->left)		// Jesli y byl lewym synem
			y->parent->left = x;
		else				// Jesli y byl prawym synem
			y->parent->right = x;
	}
	if(y!=z)				// Jesli n mial dwoch synow 
		z->key = y->key;
	free(z);
	
	return t;
}


int main(){
	struct node *z,*tree;
	
	tree=nodeNew(7);
	z=nodeNew(15);
	treeInsert(tree, z);
	z = nodeNew(12);
	treeInsert(tree, z);
	z = nodeNew(13);
	treeInsert(tree,z);
	z = nodeNew(9);
	treeInsert(tree, z);
	printf("drzewo: ");
	treePrint(tree);
	
	struct node *s = treeSearch(9, tree);
	printf("\nSzukany: %d\n", s->key);

	tree = treeDelete(tree, s);
	printf("Drzewo po usunieciu: %d \n",s->key);
	treePrint(tree);

	//treeDeleteALL(tree);
	
	

	printf("\n");
	return 0;
}
/*
	7
	 \
	 15
	/
       12
      /	 \	
     9   13
*/


//7 9 12 13 15 


