#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n, m, i, cnt = 0;
long long res = 0;

struct Node
{
	int v = 0;
	int k = 0;
};

struct Edge
{
	int x;
	int y;
	long long w;
	bool operator > (Edge &a) const { return w > a.w; }
	bool operator < (Edge &b) const { return w < b.w; }
};

struct Set
{
	int index;
	Set *parent;
	int rank = 0;
};

bool cmp(Edge a, Edge b) { return a < b; }

void make_set(Set* x, int i) {
	x->index = i;
	x->parent = x;
}

Set* find(Set x) {
	if (x.parent->index != x.index) {
		x.parent = find(*x.parent);
	}
	return x.parent;
}

void join(Set *x, Set *y) {
	Set* x_root = find(*x);
	Set* y_root = find(*y);
	if (x_root->index == y_root->index) {
		return;
	}
	if (x_root->rank < y_root->rank) {
		Set* temp = x_root;
		x_root = y_root;
		y_root = temp;
	}
	y_root->parent = x_root;
	if (x_root->rank == y_root->rank) {
		x_root->rank++;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	Node * nodes = new Node[n + 1];
	for (i = 1; i <= n; i++) {
		scanf("%d", &nodes[i].v);
	}
	Edge *edge = new Edge[m];
	for (i = 0; i < m; i++) {
		scanf("%d%d%lld", &edge[i].x, &edge[i].y, &edge[i].w);
		nodes[edge[i].x].k++;
		nodes[edge[i].y].k++;
	}
	for (i = 0; i < m; i++) {
		edge[i].w =(abs(nodes[edge[i].x].v - nodes[edge[i].y].v) + 1)*edge[i].w
			* (abs(nodes[edge[i].x].k - nodes[edge[i].y].k) + 1);
	}
	sort(edge, edge + m, cmp);
	Set* disjoint = new Set[n + 1];
	for (i = 1; i <= n; i++) {
		make_set(&(disjoint[i]), i);
	}
	for (i = 0; i < m&&cnt < m - 1; i++) {
		Set* a = &disjoint[edge[i].x], *b = &disjoint[edge[i].y];
		if (find(*a)->index != find(*b)->index) {
			join(a, b);
			res += edge[i].w;
			cnt++;
		}
	}
	printf("%lld", res);
	delete nodes;
	delete edge;
	return 0;
}