#include<iostream>
#include<vector>
#include<string>
// longlong ��ѧ�ſ���˵�Ǻ�������
using namespace std;

//ָ����
int lengthOfInstructions;
//�ҵ��γ̵�����
int findCourse(string s);
//�ҵ�ѧ�ŵ�����
int findNumber(long long number);
// ��ѧ�š��γ���������ѧ�����пγ̵ķ���
vector<long long> numbers;
vector<string> courses;

//����ѧ����ƽ����
vector<double> avg;
int main(){
	cin >> lengthOfInstructions;
	string name;
	long long number;
	string course;
	double score;
	double allscores[1000][100];
	//�������
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 100; j++)
			allscores[i][j] = 0;

	for (int i = 0; i < lengthOfInstructions; i++){
		cin >> name >> number >> course >> score;
		//cout << name << " " << number << " " << course << " " << score << endl;
		int index = findNumber(number);
		if (-1 == index){
			index = numbers.size();
			numbers.push_back(number);
		}

		int courseIndex = findCourse(course);
		if (-1 == courseIndex){
			courseIndex = courses.size();
			courses.push_back(course);
		}
		allscores[index][courseIndex] = score;
	}


	for (int i = 0; i < numbers.size(); i++){
		double sum = 0;
		for (int j = 0; j < courses.size(); j++){
			sum += allscores[i][j];
		}
		avg.push_back(sum / courses.size());
	}
	double allAvg = 0;
	for (int i = 0; i < avg.size(); i++){
		allAvg += avg.at(i);
	}
	allAvg /= avg.size();
	for (int i = 0; i < numbers.size(); i++)
		for (int j = 0; j < numbers.size() - 1; j++){
			if (avg.at(j) < avg.at(j + 1)){
				double temple = avg.at(j + 1);
				avg.at(j + 1) = avg.at(j);
				avg.at(j) = temple;
				int templeNumber = numbers.at(j + 1);
				numbers.at(j + 1) = numbers.at(j);
				numbers.at(j) = templeNumber;
			}
		}
 
	for (int i = 0; i < numbers.size(); i++)
		for (int j = 0; j < numbers.size() - 1; j++)
	  if (avg.at(j) == avg.at(j + 1)){
		if (numbers.at(j) < numbers.at(j + 1)){
			int templeNumber = numbers.at(j + 1);
			numbers.at(j + 1) = numbers.at(j);
			numbers.at(j) = templeNumber;
			continue;
		}
	}
	for (int i = 0; i < avg.size(); i++){
		if (avg.at(i) <= allAvg){
			cout << numbers.at(i) << endl;
		}
	}
}
int findNumber(long long number){
	for (int i = 0; i < numbers.size(); i++){
		if (numbers.at(i) == number)
			return i;
	}
	return -1;
}
int findCourse(string s){
	for (int i = 0; i < courses.size(); i++){
		if (s == courses.at(i))
			return i;
	}
	return -1;
}