#include "header.cpp"

int main() {
    // flag to add something to the program
    int again = 0;
    // amount of products
    int am_prods = 0;
    // array of products
    vector<Product> prods;
    do {
        int to_end;
        do {
            Product good;
            // get data from user
            good.setProduct();
            // cout total cost for each position (used later for displaying)
            good.countTotal();
            // flag to check if the same product with the same price was before
            int check = check_same(prods, good);
            if (check == -1) // if it wasn't before
                prods.push_back(good);
            else {
                prods[check].amount += good.amount;
                prods[check].total = prods[check].price * prods[check].amount;// re-count total
                cout<<"You've already entered this product with the same price. The amount is added."<< endl;
                am_prods--; // this doesn't add any position to list
            }
            // user can input as much products as they want
            cout << "Print 0 to end input: ";
            cin >> to_end;
            cin.ignore();
            am_prods++;
        } while (to_end != 0);
        // sort an array by names
        sort_by_name(prods);
        cout << endl <<"Your input: " << endl;
        output_arr(prods); // output array
        // create trees
        cout <<endl << "Trees: " << endl;
        make_trees(prods, am_prods);
        // get total of a product
        cout<<"Which product's total cost do you want?"<< endl;
        string total_prod;
        getline(cin, total_prod);
        // check if the total exists
        int total_cost = find_total(prods, total_prod);
        if(total_cost!=0)
            cout <<"The total cost is "<< total_cost << endl;
        else
            cout <<"You haven't entered this product!"<< endl;
        // user can add more products to the same program
        cout << "Do you want to add something?(print '1' if yes) ";
        cin >> again;
        cin.ignore();
    }while(again==1);
}
