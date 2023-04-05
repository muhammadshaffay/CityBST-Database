#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;


class TreeNode
{
public:
	string country;
	string population;
	string x;
	string y;
	string id;
	string ascii;

public:
	TreeNode* left;
	TreeNode* right;

	TreeNode()
	{
		x = y = id = population = ascii = " ";
		country = " ";
		left = right = NULL;
	}
	TreeNode(string c, string la, string lo, string i, string p, string a)
	{
		x = la;
		y = lo;
		id = i;
		population = p;
		country = c;
		ascii = a;
		left = right = NULL;
	}

	string getcountry()
	{	return country;	}

	void setcountry(string s)
	{	country = s;	}

	string getascii()
	{	return ascii;	}

	void setascii(string a)
	{	ascii = a;	}

	string getx()
	{	return x;	}

	void setx(int la)
	{	x = la;	}

	string gety()
	{	return y;	}

	void sety(int lo)
	{	y = lo;	}

	string getid()
	{	return id;	}

	void setid(int i)
	{	id = i;	}

	string getpopulation()
	{	return population;	}

	void setpopulation(int p)
	{	population = p;	}

	TreeNode* getRight()
	{	return right;	}

	void setLeft(TreeNode* l)
	{	left = l;	}

	TreeNode* getLeft()
	{	return left;	}

	void setRight(TreeNode* r)
	{	right = r;	}
};

class BST
{
	TreeNode* root;

public:
	TreeNode* getroot()
	{	return root;	}

	BST()
	{	root = NULL;	}

	BST(TreeNode* roote)
	{	root = roote;	}

	TreeNode* insertion(TreeNode*& roote, string c, string la, string lo, string i, string p, string a)
	{
		if (roote == NULL)
		{
			TreeNode* temp = new TreeNode(c, la, lo, i, p, a);
			roote = temp;
			return roote;
		}
		if (roote->getascii() > a)
		{
			insertion(roote->left, c, la, lo, i, p, a);
		}
		else if (roote->getascii() < a)
		{
			insertion(roote->right, c, la, lo, i, p, a);
		}
	}

	void insert(string c, string la, string lo, string i, string p, string a)
	{	insertion(root, c, la, lo, i, p, a);	}

	void searchByname(TreeNode* roote, string city)
	{
		if (roote == NULL)
		{	return;	}

		if (roote->getcountry() == city)
		{	cout << "Record Of City : " << city << " Found."<< endl;	return;	}

		searchByname(roote->left, city);
		searchByname(roote->right, city);
	}
	void searchbn(string city)
	{	searchByname(root , city);	}

	void searchBycordinate(TreeNode* roote, string x, string y)
	{
		if (roote == NULL)
		{	return;	}

		if (roote->getx() == x && roote->gety() == y)
		{	cout << "Record Of City : " << roote->getcountry() << " Found."<< endl;	return;	}

		searchBycordinate(roote->left, x, y);
		searchBycordinate(roote->right, x, y);
	}
	void searchbc(string x , string y)
	{	searchBycordinate(root , x , y);	}
	
	void smallcounts(TreeNode* roote, string pop )
	{
		if (roote == NULL)
		{	return;	}

		if (roote->getpopulation() < pop)
		{	cout << roote->getcountry() << " , " ;	}

		smallcounts(roote->left, pop );
		smallcounts(roote->right, pop );
	}
	void smallcount(string pop)
	{	smallcounts(root , pop );	}

	void PrintRanges(TreeNode* roote, string pop1 , string pop2)
	{
		if (roote == NULL)
		{	return;	}
		
		if (roote->getpopulation() >= pop1 && roote->getpopulation() <= pop2)
		{	cout << "Record Of City : " << roote->getcountry() << " Found."<< endl;	return; 	}
		
		PrintRanges(roote->left, pop1 , pop2);
		PrintRanges(roote->right, pop1 , pop2);
	}
	void PrintRange(string pop1 , string pop2)
	{	PrintRanges(root , pop1 , pop2);	}
	
	/*void printallrecords(TreeNode* roote, string pop1 , string pop2)
	{
		if (roote == NULL)
		{	return;	}
		//sqrt(a2 - b2
		if ((roote->getx() >= pop1 && roote->gety() >= pop2) && (roote->getx() <= (pop1*pop1) && roote->gety() <= pop2*pop2))
		{	cout << "Record Of City : " << roote->getcountry() << " Found in range."<< endl;	return; 	}
		
		PrintRanges(roote->left, pop1 , pop2);
		PrintRanges(roote->right, pop1 , pop2);
	}
	void printallrecords(string pop1 , string pop2)
	{
		PrintRanges(root , pop1 , pop2);
	}*/
	
	void display(TreeNode* roote)
	{
		if (roote != NULL)
		{
			display(roote->left);
			cout << roote->getcountry() << " ";
			display(roote->right);
		}
	}
	
	void deletionsbyname(TreeNode*& roote , string name)
	{
		if (roote == NULL)
		{	return;	}
		
		else if(roote->getcountry() == name)
		{
			deletingbn(roote);
			cout << "Deletion done" << endl;
		}	
		deletionsbyname(roote->left, name);
		deletionsbyname(roote->right, name);
	}
	void deletingbn(TreeNode*& roote) 
	{
		TreeNode* tempy;

		if (roote->right == NULL)
		{
			tempy = roote;
			roote = roote->left;
			delete tempy;
		}

		else if (roote->left == NULL)
		{
			tempy = roote;
			roote = roote->right;
			delete tempy;
		}

		else
		{
			tempy = roote->right;
			while (tempy->left)
			{	tempy = tempy->left;	}

			tempy->left = roote->left;
			tempy = roote;
			roote = roote->right;
			delete tempy;
		}
	}
	void deletionbn(string name)
	{	deletionsbyname(root , name);
	}
	
	/*void display(TreeNode* roote)
	{
		if (roote != NULL)
		{
			display(roote->left);
			cout << roote->getcountry() << " ";
			display(roote->right);
		}
	}*/
	
	void deletionsbycordinate(TreeNode*& roote , string c1 , string c2)
	{
		if (roote == NULL)
		{	return;	}
		
		else if(roote->getx() == c1 && roote->gety() == c2)
		{
			deletingbc(roote);
			cout << "Deletion done" << endl;
		}	
		deletionsbycordinate(roote->left, c1, c2);
		deletionsbycordinate(roote->right, c1 , c2);
	}
	void deletingbc(TreeNode*& roote) 
	{
		TreeNode* tempy;

		if (roote->right == NULL)
		{
			tempy = roote;
			roote = roote->left;
			delete tempy;
		}

		else if (roote->left == NULL)
		{
			tempy = roote;
			roote = roote->right;
			delete tempy;
		}

		else
		{
			tempy = roote->right;
			while (tempy->left)
			{	tempy = tempy->left;	}

			tempy->left = roote->left;
			tempy = roote;
			roote = roote->right;
			delete tempy;
		}
	}
	void deletionbc(string c1 , string c2)
	{	deletionsbycordinate(root , c1 , c2);	}
	
};
	
struct holder
{
	string latitude = " ";
	string longitude = " ";
	string city = " ";
	string population = " ";
	string id = " ";
	string city_ascii = " ";
};

int main()
{
	int counter = 0;
	holder data[1000];
	BST object;

	ifstream MyFile;

	MyFile.open("dataworldcities.CSV");

	if (!MyFile)
	{
		cout << "Error: file could not be opened" << endl;
		return 0;
	}
	else
	{
		getline(MyFile, data[counter].latitude, ',');
		getline(MyFile, data[counter].longitude, ',');
		getline(MyFile, data[counter].population, ',');
		getline(MyFile, data[counter].id, ',');
		getline(MyFile, data[counter].city_ascii, ',');
		getline(MyFile, data[counter].city, '\n');

		while (!MyFile.eof() && counter < 1000)
		{
			getline(MyFile, data[counter].latitude, ',');
			getline(MyFile, data[counter].longitude, ',');
			getline(MyFile, data[counter].population, ',');
			getline(MyFile, data[counter].id, ',');
			getline(MyFile, data[counter].city_ascii, ',');
			getline(MyFile, data[counter].city, '\n');

			counter += 1;
		}
		MyFile.close();
	}

	for (int i = 0; i < 1000; i++)
	{
		object.insert(data[i].city, data[i].latitude, data[i].longitude, data[i].population, data[i].id, data[i].city_ascii);
	}

	cout << "\n\nTesting small count." << endl;
	object.smallcount("833276");
	cout << "\n\nTesting search by name." << endl;
	object.searchbn("Tokyo");
	cout << "\n\nTesting search by cordinates." << endl;
	object.searchbc("18.9667" , "72.8333");
	cout << "\n\nTesting countries between population range." << endl;
	object.PrintRange("17125000" , "3797700");
	cout << "\n\nTesting deletion by name." << endl;
	object.deletionbn("Tokyo");
	cout << "\n\nTesting deletion by cordinates." << endl;
	object.deletionbc("28.66" , "77.23");
	
	//object.display(object.getroot());
	//object.display(object.getroot());

	return 0;
}
