first_list =[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
for i in range (20):
    n = int(input("Enter a number: "))
    first_list.append(n)
m=min(first_list)
n=max(first_list)
l1sum= n + m
print(n,m,l1sum)
odd_count = 0 

for j in range(len(first_list)):
    if first_list[j] % 2 != 0: 
        odd_count = odd_count + 1
print("The number of odd numbers is:", odd_count)

second_list =[]
for k in first_list:
    if k % 5 == 0:
        second_list.append(k)

print("The new list with numbers divisible by 5 is:", second_list)
l2max=max(second_list)
l2avarage=sum(second_list) / len(second_list)
diff = l2max - l2avarage
print("The average of the max and min numbers in the new list is:", diff)

new_element_val = second_list[0] + second_list[-1]
second_list.append(new_element_val)
print("The final list is:", second_list)


class FoodDelivery:
    def __init__(self, order_number, destination, price, delivery_term, order_status):
        self.order_number = order_number
        self.destination = destination
        self.price = price
        self.delivery_term = delivery_term
        self.order_status = order_status

    def order_info(self):
        print(f"Order Number: {self.order_number}")
        print(f"Destination: {self.destination}")
        print(f"Price: {self.price}")
        print(f"Delivery Term: {self.delivery_term}")
        print(f"Status: {self.order_status}")

    def change_term(self):
        new_term = input("Enter new delivery term: ")
        self.delivery_term = new_term

def add_order(order_list, new_order):
    order_list.append(new_order)

def status_info(order_list, num):
    found = False
    for order in order_list:
        if str(order.order_number) == str(num):
            print(f"Found {order.order_status}")
            found = True
            break
    
    if not found:
        print("Not Found")

order_list = []
n = int(input("Enter number of orders: "))

for i in range(n):
    print(f"Enter details for order {i + 1}:")
    num = input("Order Number: ")
    dest = input("Destination: ")
    price = input("Price: ")
    term = input("Delivery Term: ")
    status = input("Order Status: ")

    new_order = FoodDelivery(num, dest, price, term, status)
    add_order(order_list, new_order)

search_num = input("Enter order number to search: ")
status_info(order_list, search_num)