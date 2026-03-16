# ; съдайте функоя която према като аргумент  число, ако числото не цяло и  положително да върне грешка value error ako e clqo i polojetlno. da printira koren dvadqen ot towa chislo i vinagi da prinira nadpiz goodbye vuv vqrnata chast na funkciqta
def koren_dvadqten(chislo):
    try:
        if not isinstance(chislo, int) or chislo <= 0:
            raise ValueError("Грешка: Числото трябва да е цяло и положително.")
            
        rezultat = chislo ** 0.5
        print(f"Коренът е: {rezultat}")
        
    except ValueError as e:
        print(e)
        
    finally:
        print("Goodbye")
        print("-" * 20) 

koren_dvadqten(16)
koren_dvadqten(-4)
koren_dvadqten(2.5)

def koren_dvadqten(chislo):
    try:
        if not isinstance(chislo, int) or chislo <= 0:
            raise ValueError
            rezultat = chislo ** 0.5
            stepen = chislo ** 2

        print(f"Коренът е: {rezultat}")
        print(f"Stepen: {stepen}")
        
    except ValueError :
        print("Грешка: Числото трябва да е цяло и положително.")
        
    finally:
        print("Goodbye")
        print("-" * 20) 

koren_dvadqten(16)
koren_dvadqten(-4)
koren_dvadqten(2.5)