#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
// 实现类的功能
class ploy{
public:
	int r;
	int g;
	int b;
	string id;
	string shuxing;
	vector<string> groupid;
	ploy(){
		r = 0;
		g = 0;
		b = 0;
	}
	ploy(string i){
		id = i;
		r = 0;
		g = 0;
		b = 0;
	}
	ploy(string i, string s){
		id = i;
		r = 0;
		g = 0;
		b = 0;
		shuxing = s;
	}
	friend ostream& operator << (ostream& o, ploy& p){
		return o << p.id << " " << p.r << " " << p.g << " " << p.b<<endl;
	}
	double getGray(){
	 return r * 0.299 + g * 0.587 + b * 0.114;
	}
	void addGroupID(string s){
		groupid.push_back(s);
	}
	bool isBelonged(const string& groupID) const{
		for (int i = 0; i < groupid.size(); i++){
			if (groupID == groupid[i])
				return true;
		}
		return false;
	}
	void setRGB(int red, int green, int blue){
		if (shuxing == "normal")
		{
			r = red;
			g = green;
			b = blue;
			return;
		}
		
		if (shuxing == "single"){
			r = red;
			g = 0;
			b = 0;
			return;
		}
		if (shuxing == "reverse"){
			r = 255 - red;
			g = 255 - green;
			b = 255 - blue;
		}
	}
	void setID(string s){
		id = s;
	}
};
vector<ploy*> ploys;
vector<string> groupIDS;

//找到对应编号的矩阵的索引
int findIndex(string id){
	for (int i = 0; i < ploys.size(); i++){
		if (id == ploys[i]->id)
			return i;
	}
	return -1;
}

//强行根据字节码比较数字大小
int compareID( const string & id1,const string & id2){
	string i1 = id1.substr(1);
	string i2 = id2.substr(1);
	if (i1.size() > i2.size())
		return -1;
	if (i1.size() < i2.size())
		return 1;
	if (i1 <= i2)
		return 1;
	return -1;
}
//根据灰度排序
void sortByGray(){
	for (int i = 0; i < ploys.size(); i++){
		for (int j = 0; j < ploys.size() - 1; j++){
			if (ploys[j]->getGray() == ploys[j + 1]->getGray()){
				if (compareID(ploys[j]->id, ploys[j + 1]->id) < 0)

				{
					ploy * temple = ploys[j];
					ploys[j] = ploys[j + 1];
					ploys[j + 1] = temple;
				}
			}

			if (ploys[j]->getGray()>ploys[j+1]->getGray()){
				ploy * temple = ploys[j];
				ploys[j] = ploys[j + 1];
				ploys[j + 1] = temple;
			}
		}
	}
}
//根据ID排序
void sortByID(){
	for (int i = 0; i < ploys.size(); i++){
		for (int j = 0; j < ploys.size() - 1; j++){
			int result = compareID(ploys[j]->id, ploys[j + 1]->id);

			if (result < 0){
				ploy * temple =	ploys[j];
				ploys[j] = ploys[j + 1];
				ploys[j + 1] = temple;
			}
		}
	}
}
//根据ID打印出来
void printById(){
		sortByID();
		for (int i = 0; i < ploys.size(); i++){
			cout << *ploys[i];
		}
};
void printByGray(){
	sortByGray();
	for (int i = 0; i < ploys.size(); i++){
		cout << *ploys[i];
	}
}
//判断是否是组编号
bool isGroupID(string & id){
	for (int i = 0; i < groupIDS.size(); i++){
		if (groupIDS[i] == id)
			return true;
	}
	return false;
}
;
int main(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		string ope;
		cin >> ope;
		if (ope == "Add"){
			string option;
			cin >> option;
			
				string id;
				cin >> id;
				ploy * p = new ploy(id,option);
				ploys.push_back(p);
			
			continue;
		}
		if (ope == "Set"){
			string id;
			
			cin >> id;
			
			int r, g, b;
			cin >> r >> g >> b;
			if (isGroupID(id)){
				for (int i = 0; i < ploys.size(); i++){
					if (ploys[i]->isBelonged(id)){
						ploys[i]->setRGB(r, g, b);
					}
				}
				continue;
			}
			
			int index = findIndex(id);
			if (index>=0)
			{
				ploys[index]->setRGB(r, g, b);

			}
			continue;
		}
		if (ope == "Group")
		{
			int number;
			cin >> number;
			vector<string> ids;
			for (int i = 0; i < number; i++){
				string  id;
				cin >> id;
				ids.push_back(id);
			}
			string group;
			cin >> group;
			groupIDS.push_back(group);
			for (int i = 0; i < number; i++){
				int index = findIndex(ids[i]);
				if (index >= 0){
					ploys[index]->addGroupID(group);
				}
			}
		}
		
	
	}
	string print;
	cin >> print;
	if (print == "Normal")
		printById();
	if (print == "Gray")
		printByGray();
}