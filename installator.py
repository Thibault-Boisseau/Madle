#!/usr/bin/python

import os

def main():
    print("Si vous voulez installer le jeu, tapez INSTALLATION")
    print("Si vous voulez jouer au jeu, tapez JEU")
    print("Si vous voulez installer et jouer au jeu, tapez IJ")

    choix = input("")

    if choix == "INSTALLATION":
        os.system("pip3 install -r src/requirement.txt")
        print("L'installation est maintenant terminée ! Relancez l'installateur si vous voulez jouer !")

    elif choix == "JEU":
        os.chdir("src/")
        os.system("flask run &")
        os.system("xdg-open http://127.0.0.1:5000/")
    
    elif choix == "IJ":
        os.system("pip3 install -r src/requirement.txt")
        os.chdir("src/")
        os.system("flask run &")
        os.system("xdg-open http://127.0.0.1:5000/")

    else:
        print("Entrée invalide, voulez vous réessayez ?")
        confirm = input("OUI ou NON \n")

        if confirm == 'NON':
            return None
        else:
            main()



main()