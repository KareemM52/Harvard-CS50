import time
def vend():

    a = {'item': 'Nacho Cheese Doritos', 'Price': 1.50, 'stock': 1}
    b = {'item': 'BBQ Limited Doritos', 'Price': 1.75, 'stock': 2}
    c = {'item': 'Mars Bar', 'Price': 0.50, 'stock': 2}
    d = {'item': 'Healthy snack bar', 'Price': 0.75, 'stock': 2}
    e = {'item': 'Coca Cola', 'Price': 0.50, 'stock': 3}
    f = {'item': 'Regular chips', 'Price': 1.50, 'stock': 1}
    g = {'item': 'Ketchup chips', 'Price': 1.75, 'stock': 2}
    h = {'item': 'Sour Cream & Onion chips', 'Price': 1.75, 'stock': 2}
    i = {'item': 'Milk chocolate bar', 'Price': 0.50, 'stock': 1}
    j = {'item': 'Mint Milk chocolate bar', 'Price': 0.75, 'stock': 2}
    items = [a, b, c, d, e, f, g, h, i, j]
    MIV = 0 
    # money in vending ^

    print('Welcome to the vending machine! \n')
    time.sleep(0.5)
    print('All prices are in CAD \n')
    # display items
    
    def show(items):
        time.sleep(1)
        print('\nHere are your items:\n')

        for item in items:      
            if item.get('stock') == 0:
                items.remove(item)
                time.sleep(1)
        for item in items:
            time.sleep(1)
            print(item.get('item'), item.get('Price'))

        print('\n')
    # choosen item
    
    while True:
        show(items)
        selected = input('Select item: ')
        for item in items:
            if selected == item.get('item'):
                selected = item               
                Price = selected.get('Price')
                while MIV < Price:
                    MIV = float(input('Insert ' + str(Price - MIV) + ': '))   
                else:
                    time.sleep(1)
                    print('You now have ' + selected.get('item'))
                    selected['stock'] -= 1
                    MIV -= Price
                    time.sleep(1)
                    print('Change: ' + str(MIV))
                    x = input('Would you like to buy something else?')
                    if x == 'no':
                        if MIV != 0:
                            print(' Your money back: ' + str(MIV))
                            MIV = 0
                        print('Thank you for your business!\n')
                        return 0                      
                    else:
                        continue



vend()