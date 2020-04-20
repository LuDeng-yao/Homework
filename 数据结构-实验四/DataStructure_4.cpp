#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> P;
int m,n;
struct edge {
	int u,v,cost;
};
bool cmp(edge& a,edge& b) {
	return a.cost < b.cost;
}

class Graphm {
	private:
		int numvertex,numedge,flag = 0;
		int **matrix;
		int *mark,*rank,*par;
		edge *es;
		int loop = 0;
	public:
		Graphm(int numvert,int numedge) {
			init(numvert,numedge);
		}
		~Graphm() {
			delete []mark;
			for(int i=1; i<=numvertex; i++)
				delete []matrix[i];
			delete []matrix;
			delete []es;
			delete []rank;
			delete []par;
		}
		void init(int n,int m) {
			numvertex = n;
			numedge = 0;
			mark = new int [n+1];
			es = new edge [m+2];
			for(int i=0;i<m+2;i++){
				es[i].cost = 0;
				es[i].u = 0;
				es[i].v = 0;
			}
			
			par = new int [n+1];
			rank = new int [n+1];
			for(int i=1; i<=numvertex; i++)
				mark[i] = 0;
			matrix =  new int*[numvertex+1];
			for(int i=1; i<=numvertex; i++)
				matrix[i] = new int[numvertex+1];
			for(int i=1; i<=numvertex; i++)
				for(int j=1; j<=numvertex; j++)
					matrix[i][j] = INF;
		}
		
		void setes(int s,int from,int to,int weight){
			es[s].u = from;//�������еıߵ���Ϣ����洢�ߵ�һά���� 
			es[s].v = to;
			es[s].cost = weight;
		}
		
		void setegde(int v1,int v2,int w) {//���ߵ���Ϣ�����ڽӾ����� 
			if(matrix[v1][v2] == INF) numedge++;
			matrix[v1][v2] = w;
			matrix[v2][v1] = w;
		}

		int first(int v) {//���ص�����v�ڵ��ڽӵĵ�һ���ڵ� 
			for(int i=1; i<=numvertex; i++)
				if(matrix[v][i] != INF) return i;
			return numvertex+1;
		}

		int next(int v,int w) {//��w��Ϊ��v�ڽӵ���һ���ڵ㣬
								//Ѱ����v�ڽӵ���һ���ڵ� 
			for(int i=w+1; i<=numvertex; i++)
				if(matrix[v][i] != INF )
					return i;
			return numvertex+1;
		}
		
		void reset(){//reset��������������ÿ��ִ��dfs��bfs����ʱ��mark�����е�ֵ���ã�Ҳ���ǽ����е㶼���Ϊδ���� 
			flag = 0;
			for(int i=1;i<=numvertex;i++)
				mark[i] = 0;
		}
		
		void dfs(int v) {
			if(flag == 0) flag = 1;//flag����������ӡ��һ��Ԫ��ǰ�Ŀո� 
			else cout<<" ";//���ڸýڵ��previsit 
			cout<<v;
			mark[v] = 1;//���ýڵ���Ϊ�ѷ��� 
			for(int w = first(v); w<=numvertex; w = next(v,w)) {
				if(mark[w] == 0)//��v��ÿһ���ڽӵ㶼���б���
								//�����ǰ�ڽӵ�wδ�����ʣ�
								//�����w��ݹ����dfs���� 
					dfs(w);
			}
			return;//���� 
		}
		
		void bfs(int start) {
			int v,w;
			queue<int> que;
			que.push(start);//��ʼ�����в������ѹ������� 
			mark[start] = 1;//�������Ϊ�ѷ��� 
			while(!que.empty()) {//����������Ԫ��ʱ�㲻��ִ�в��� 
				v = que.front();
				que.pop();//������ͷԪ�� 
				if(flag == 0) flag = 1;
				else cout<<" ";
				cout<<v;// ���ڶ�ͷԪ�ؽ���previsit 
				for(w = first(v); w <= numvertex; w = next(v,w)) {
					if(mark[w] == 0) { //��ǰv�ڵ�ĸ����ڽӵ�Ҳ��Ҫ������ 
						mark[w] = 1;//���Ա㽫���Ǳ��Ϊ�ѷ��ʲ��Ҷ�ѹ����� 
						que.push(w);
					}
				}
			}
		}

		void dijkstra(int start,int end) {
			int dis[numvertex+1],prev[numvertex+1];
			stack<int> stk;
			fill(dis+1,dis+1+numvertex,INF);
			cout<<endl;
			fill(prev,prev + numvertex+1,-1);
			dis[start] = 0; 
			priority_queue<P,vector<P>,greater<P> > q;
			//�����P����������ǰ���Լ�����ģ�����second����
			//��ʾĳ����v����first������ʾ�Ѿ�ȷ���˵���㵽��v����С���� 
			q.push(P(0,start));//�������ȶ��в��ѵ����ľ���Ϊ0�����1ѹ�����ȶ��� 
			while(!q.empty()) {
				P temp = q.top();//ȡ�����ȶ��еĶ�ͷԪ����Ϊv�� 
				q.pop();
				int v = temp.second;// 
				int d = temp.first;//��㵽���v���Ѿ�ȷ���˵���С����Ϊd 
				for(int i=1; i<=numvertex; i++) {
					int e = matrix[v][i];//�������ڵ����v����ڽӵ� 
					if( e + d < dis[i]) { //�������㾭v���ٵ�i��ľ��� 
						dis[i] = e + d;   //������dis�����д�Ĵ���㵽i�� 
										//�ľ��뻹ҪС�Ļ����ǾͿ��Ը���dis[i]
						prev[i] = v;//���¹����¼i���ǰ���ڵ�Ϊv 
							   
						q.push(P((e+d),i));//Ȼ��Ҫ�ٰѸ��º��P(e+d,i)��������С� 
					}
				}
			}
			for(int i=end; ;i = prev[i]){//��ǰ���¼��ǰ���ڵ����� 
				if(i == -1) break;		//����������·������ѹ��ջ 
				stk.push(i);
			}
			while(!stk.empty()){
				cout<<stk.top()<<" "; //��ջ��Ԫ�ط������ 
				stk.pop();
			}
			cout<<dis[end]; //��������㵽�յ�����·������ 
		}
		
		
		//�����initial  find  unite ��same ���ǲ��鼯�ĳ�ʼ��
		//Ϊ����kruskal�㷨�в��ʱ�ж��������Ƿ�����ͬһ����С������ 
		void initial(int n) {
			for(int i=1; i<=n; i++) {
				rank[i] = 0;
				par[i] = i;
			}
		}
		
		int find(int a) {
			if(par[a] == a) return a;
			else return par[a] = find(par[a]);
		}

		void unite(int a,int b) {
			int ar = find(a);
			int br = find(b);
			if (ar == br)return;
			if(rank[ar] < rank[br])
				par[ar] = br;
			else {
				par[br] = ar;
				if(rank[ar] == rank[br])rank[ar]++;
			}
		}

		bool same(int a,int b) {
			return find(a) == find(b);
		}

		void kruskal() {
			initial(numedge);//���鼯�ĳ�ʼ�� 
			int count = 0;
			int use[numedge+1];
			fill(use+1,use+1+numedge,0);//����Щ�߶����Ϊδʹ�� 
			sort(es+1,es+1+numedge,cmp);//����Щ�߰���Ȩ�ش�С�������� 
			
			for(int i=1; i<=numedge; i++) {
				if(count >= numvertex-1) break;//����numvertex-1���߼�������ѭ�� 
				edge e = es[i];
				if(!same(e.u,e.v)) { // �������㲻��ͬһ����������������� 
					unite(e.u,e.v); //����������Ϊ��ͬһ������ 
					use[i] = 1;		//�������߱��Ϊ��ʹ�� 
					count++;		//����+1��������� 
				}
			}
			for(int i=1;i<=numedge;i++){
				if(use[i] == 1)
				cout<<es[i].u<<" "<<es[i].v<<" "<<es[i].cost<<endl;
			}//�����ɵ���С�������ıߴ�ӡ���� 
		}

		void existloop(int v) { //��dfs����Ϊ������ִ���л����� 
			mark[v] = 1;
			for(int w = first(v); w<=numvertex; w = next(v,w)) {
				if(mark[w] == 0)
					existloop(w);
				else if(mark[w] == 1) //�����dfs�������жϵ�ǰ�ڵ����һ�� 
									  //�ڽӵ��Ѿ������ʹ�����֤��ͼ���л� 
				loop = 1;	//��ͼ���������е�loop������Ϊ1 
			}
			return;
		} 
		
		void showloop(){//�ж�ͼ�Ƿ���ڻ��ı���loop�ķ��ʽӿ� 
			if(loop == 1) cout<<"YES"<<endl;//�л������YES�� 
			else cout<<"NO"<<endl;//�޻������NO�� 
		}
};

int main() {
	scanf("%d%d",&n,&m);
	Graphm a1(n,m);  //ʵ����һ��ͼ����a1 
	for(int i=1; i<=m; i++) { //ѭ��m�β���m���� 
		int from,to,weight;
		scanf("%d%d%d",&from,&to,&weight);
		edge temp;
		temp.u = from;
		temp.v = to;
		temp.cost = weight;
		a1.setegde(from,to,weight);
		a1.setes(i,from,to,weight);
	}
	a1.reset();
	a1.bfs(1);
	cout<<endl;
	a1.reset();
	a1.dfs(1);
	for(int i=2;i<=n;i++){
		a1.dijkstra(1,i);
	}
	cout<<endl;
	a1.kruskal();
	a1.existloop(1);
	a1.showloop();
	return 0;
}
