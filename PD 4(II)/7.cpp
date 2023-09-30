#include <iostream>
using namespace std;

void flowerShop(int redRose, int whiteRose, int tulip);

main() 
{
	int redRose, whiteRose, tulip;
	cout << "Red Rose: ";
	cin >> redRose;
	cout << "White Rose: ";
	cin >> whiteRose;
	cout << "Tulips: ";
	cin >> tulip;
flowerShop(redRose, whiteRose, tulip);
}
void flowerShop(int redRose, int whiteRose, int tulip)
{
	float redRosePrice, whiteRosePrice, tulipPrice, originalPrice;
	redRosePrice = redRose * 2.00;
	whiteRosePrice = whiteRose * 4.10; 
	tulipPrice = tulip * 2.50;
	originalPrice = redRosePrice + whiteRosePrice + tulipPrice;
	cout << "Original Price: $" << originalPrice <<endl;
	if(originalPrice > 200){
	cout << "Price after Discount: $";
	cout << originalPrice-(originalPrice*20/100) <<endl;
}
	if(originalPrice <= 200){
	cout << "No discount applied.";
}

}