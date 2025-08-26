#include <stdio.h>
#include <stdlib.h>

//트리 노드 정의
typedef struct Node{
	int data; //노드에 저장할 데이터
	struct Node* left;	//왼쪽 자식 노드의 주소
	struct Node* right;	//오른쪽 자식 노드의 주소
}Node;

//노드 생성 함수
Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		puts("메모리 할당 실패");
		exit(1);
	}
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//트리에 노드 삽입
Node* insert(Node* root, int data) {
	//( 찾아간 곳이 NULL이면 그 자리에 넣기 )
	if (root == NULL) { //최상위 루트 노드
		return createNode(data);
	}

	//재귀 함수 호출
	if (data < root->data)
		root->left = insert(root->left, data); //왼쪽 서브루트에 삽입
	else
		root->right = insert(root->right, data); //오른쪽 서브루트에 삽입
	return root; //변경된 루트 반환
}

//전위 순회
void preOrder(Node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}

}

//중위 순회(왼쪽 - 루트 - 오른쪽)
void inOrder(Node* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

//후위 순회(왼쪽 - 오른쪽 - 루트)
void postOrder(Node* root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

//메모리 해제
void freeTree(Node* root) {
	if (root != NULL) {
		freeTree(root->left); //제일 왼쪽으로
		freeTree(root->right);//왼쪽으로 다 갔으면, 제일 오른쪽으로
		free(root); //해당 노드 삭제
	}
}

int main()
{
	Node* root = NULL;

	//트리에 데이터 삽입
	int values[] = { 50, 30, 70, 20, 40, 60, 80, 90 };
	int size = sizeof(values) / sizeof(values[0]);

	for (int i = 0;i < size;i++) {
		root = insert(root, values[i]);
	}

	//출력
	printf("중위 순회(오름차순 정렬): ");
	inOrder(root);
	printf("\n");

	printf("전위 순회: ");
	preOrder(root);
	printf("\n");

	printf("후위 순회: ");
	postOrder(root);
	printf("\n");

	//메모리 해제
	freeTree(root);

	return 0;
}