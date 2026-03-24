import tkinter as tk
from tkinter import messagebox

# --- 1. The Logic (Your Account Class) ---
# I modified this slightly to RETURN strings instead of printing them,
# so the GUI can decide how to show the text.
class Account:
    def __init__(self, account_number, balance, pin):
        self.account_number = account_number
        self.balance = float(balance)
        self.pin = pin

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            return True, f"Успешно депозирахте {amount:.2f} лв."
        else:
            return False, "Сумата трябва да е положителна."

    def withdraw(self, amount, pin_attempt):
        if pin_attempt != self.pin:
            return False, "Грешен ПИН код!"
        
        if amount <= 0:
            return False, "Сумата трябва да е положителна."

        if self.balance - amount < 0:
            return False, "Недостатъчна наличност!"
        else:
            self.balance -= amount
            return True, f"Успешно изтеглихте {amount:.2f} лв."

# --- 2. The Graphical Interface ---
class BankApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Банкова Система")
        self.root.geometry("400x450")

        # Initialize the account (Hardcoded for simplicity, or you could add a login screen)
        self.my_account = Account("BG123456", 100.00, "1234")

        # --- UI Elements ---
        
        # Title
        self.label_title = tk.Label(root, text="Банкомат", font=("Arial", 20, "bold"))
        self.label_title.pack(pady=10)

        # Display Balance
        self.var_balance = tk.StringVar()
        self.var_balance.set(f"Баланс: {self.my_account.balance:.2f} лв.")
        self.label_balance = tk.Label(root, textvariable=self.var_balance, font=("Arial", 14), fg="green")
        self.label_balance.pack(pady=10)

        # Input: Amount
        tk.Label(root, text="Сума:").pack()
        self.entry_amount = tk.Entry(root)
        self.entry_amount.pack(pady=5)

        # Input: PIN
        tk.Label(root, text="Въведете ПИН (за теглене):").pack()
        self.entry_pin = tk.Entry(root, show="*") # show="*" hides the password
        self.entry_pin.pack(pady=5)

        # Buttons Frame
        btn_frame = tk.Frame(root)
        btn_frame.pack(pady=20)

        # Button: Deposit
        btn_deposit = tk.Button(btn_frame, text="Депозит", command=self.make_deposit, width=15, bg="lightblue")
        btn_deposit.grid(row=0, column=0, padx=5, pady=5)

        # Button: Withdraw
        btn_withdraw = tk.Button(btn_frame, text="Теглене", command=self.make_withdraw, width=15, bg="salmon")
        btn_withdraw.grid(row=1, column=0, padx=5, pady=5)

        # Button: Info
        btn_info = tk.Button(btn_frame, text="Инфо за сметката", command=self.show_info, width=15)
        btn_info.grid(row=2, column=0, padx=5, pady=5)

        # Button: Exit
        btn_exit = tk.Button(root, text="Изход", command=root.quit, width=10)
        btn_exit.pack(pady=20)

    # --- Button Functions ---
    
    def update_balance_label(self):
        self.var_balance.set(f"Баланс: {self.my_account.balance:.2f} лв.")
        self.entry_amount.delete(0, tk.END) # Clear the input field
        self.entry_pin.delete(0, tk.END)    # Clear the PIN field

    def make_deposit(self):
        try:
            amount = float(self.entry_amount.get())
            success, message = self.my_account.deposit(amount)
            if success:
                messagebox.showinfo("Успех", message)
                self.update_balance_label()
            else:
                messagebox.showwarning("Грешка", message)
        except ValueError:
            messagebox.showerror("Грешка", "Моля въведете валидно число.")

    def make_withdraw(self):
        try:
            amount = float(self.entry_amount.get())
            pin = self.entry_pin.get()
            
            success, message = self.my_account.withdraw(amount, pin)
            
            if success:
                messagebox.showinfo("Успех", message)
                self.update_balance_label()
            else:
                messagebox.showerror("Грешка", message)
        except ValueError:
            messagebox.showerror("Грешка", "Моля въведете валидно число.")

    def show_info(self):
        info_text = f"Номер на сметката: {self.my_account.account_number}\nБаланс: {self.my_account.balance:.2f} лв."
        messagebox.showinfo("Информация", info_text)

# --- Main Execution ---
if __name__ == "__main__":
    root = tk.Tk()
    app = BankApp(root)
    root.mainloop()