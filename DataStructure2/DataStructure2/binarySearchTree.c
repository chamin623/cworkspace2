#include <stdio.h>
#include <stdlib.h>

//트리 노드 정의
typedef struct Node {
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

//노드 검색
Node* search(Node* root, int key) {
	//root 값이 없거나 그 값이 찾는 값이면 root 반환(종료 조건)
	if (root == NULL || root->data == key)
		return root;
	if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

//최소값 찾기
Node* findMin(Node* root) {
	while (root->left != NULL)
		root = root->left; //왼쪽 노드값을 찾아서 root에 저장
	return root;
}

//노드 삭제
Node* delete(Node* root, int key) {
	if (root == NULL)
		return root; //트리가 비어있으면 그대로 반환

	if (key < root->data) //찾는 값이 루트보다 작으면 왼쪽으로
		root->left = delete(root->left, key);
	else if(key>root->data) //찾는 값이 루트보다 크면 오른쪽으로
		root->right = delete(root->right, key);

	else {
		//1. 자식이 없는 경우
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		//2. 자식이 하나만 있는 경우
		else if (root->left == NULL) { //왼쪽 자식이 없음
			Node* temp = root->right; //오른쪽 자식을 임시 노드에 저장
			free(root); //현재 노드 삭제
			return temp; //오른쪽 자식을 반환(부모와 연결)
		}
		else if (root->right == NULL) { //오른쪽 자식이 없음
			Node* temp = root->left; //왼쪽 자식을 임시 노드에 저장
			free(root); //현재 노드 삭제
			return temp; //왼쪽 자식을 반환(부모와 연결)
		}
		//3. 자식이 둘 다 있는 경우
		else {
			Node* temp = findMin(root->right); //오른쪽 최소값 찾기
			root->data = temp->data; //현재 루트 노드값을 임시 노드와 교체
			root->right = delete(root->right, temp->data); //최소값 노드 삭제
		}
	}
	return root;
}

//중위 순회(왼쪽 - 루트 - 오른쪽)
void inOrder(Node* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

//메모리 해제
void freeTree(Node* root) {
	if (root != NULL) {
		freeTree(root->left); 
		freeTree(root->right);
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

	//노드 검색
	int key = 60;
	Node* found = search(root, key);
	if (found)
		printf("%d을 찾았습니다.\n", key);
	else
		printf("%d은 트리에 없습니다.\n", key);

	//노드 삭제
	puts("20 삭제 후");
	root = delete(root, 20);

	//출력
	printf("중위 순회(오름차순 정렬): ");
	inOrder(root);
	printf("\n");

	//메모리 해제
	freeTree(root);

	return 0;
}