import funcs

funcs.make_product_list("product_list_py.dat")  # make first file with product list
funcs.read_file("product_list_py.dat")  # to read first file
print("Finding products")
# find products to the rule (10% of the time it can be used)
funcs.transfer_data_expiration("product_list_py.dat", "almost_expired_py.dat")
print("NEW FILE:")
# making new file with these products
funcs.read_file("almost_expired_py.dat")
# products that have less than 10 days
funcs.info_ten_days("product_list_py.dat")
funcs.dopys()  # do you want to re-run the file
