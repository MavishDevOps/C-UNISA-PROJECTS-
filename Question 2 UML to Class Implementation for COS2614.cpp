#include<iostream>//to be implemented in QtCreator
//#include<QCoreApplication>
//#include<QString>
#include<string>// I will do this in vs since I had trouble doing so in QtCreator


using namespace std;


class Vendor {
	//by default all attributes and methods are private in c++ classes
	//QString m_Name,m_Email;
	string m_Name, m_Email;
	bool isManufacturer;
public:
	Vendor(string name, string email)
	{
		m_Name = name;
		m_Email = email;
	}
	void setDetails(string n,string mail, bool isManufacturer)//QString name,QString mail
	{
		m_Name = n;
		m_Email = mail;
		

	 }
	
	
	string getName(string name)//QString getName (QString name) the getter method for setter method 
	{
		name = m_Name;

		return name;
	
	}

	string toString();//Qstring toString



};

class Product
{
private:
	string m_Name;//QString m_Name
	double m_Price;
	
	string  m_supplier;//Vendor m_Supplier
	
	
public:
	Product(string name ,double price)

	{
		m_Name = name;
		m_Price = price;
		}

	
	void setSupplier(string name,string email,bool isManufacturer)//QString name,QString supplier
	{
		
		name = m_Name;

	}
	
	void setManufacturer(string supply)
	{
		supply = m_supplier;
	}
	string getManufacturer(string supplier)
	{
	
		m_supplier = supplier;
		return supplier;
	}

	string toString(bool supplierDetails)const
	{//QString toString implementation

		string str = "Name of product:" + m_Name + "Price of product: " + to_string(m_Price);

		if (supplierDetails)
		{
			str += "," + m_supplier;

		}

		return str;

}

};





int main()
{
	string  email_address, name_supplier, product_name;
	double cost_product;

	cout << "Enter in the name of the product:" << endl;
	getline(cin, product_name);

	cout << "Enter in the name of the supplier whom you would like to purchase from" << endl;
	getline(cin,name_supplier);

	cout << "Enter in the email address to order this product: " << endl;
	getline(cin, email_address);

	cout << "Enter in the price of this product :" << endl;
	cin >> cost_product;


	std::cout << "Your product,   " << product_name << "   will be delivered to you by tommorrow ,Saturday 27 May 2023,  your total cost for your delivery excluding delivery cost is " << cost_product << endl;

	Vendor ven = Vendor("Alphabet Biscuits", "enquiries@alphabet.biscuits.co.za");
	

	Product prod = Product("Vanilla Berrylicious ", 29.9);

	cout << "Name of Supplier: " << prod.getManufacturer(name_supplier) << endl;
	cout << "Details of Product purchased:" << prod.toString(false)<< endl;
	cout << "Checkout details of your product:" << prod.toString(true) << endl;

	

	return 0;
}