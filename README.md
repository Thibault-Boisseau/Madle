# Installation de MADLE

## Préliminaires
* Votre machine dispose d' UBUNTU 20.04 LTS ou une version plus récente.  
* Vous avez soit les droits de superutilisateur sur votre marchine soit les packages 'python3-pip' et 'python3-venv' sont déjà installés.  

## Installation 

### Méthodes 1 : La facilité

Clonez le répertoire avec la commande   
```sh
git clone https://gitlab.telecomnancy.univ-lorraine.fr/ppii2k22/project2-E22.git
```

Ensuite vous devez aller dans le répertoire cloné à l'aide de la commande suivante :
```sh
cd project2-E22
```

Utilisez un environnement virtuel pour éviter tout problème avec votre machine. Pour cela utilisez les commandes suivantes :
```sh
python3 -m venv env
source env/bin/activate
```

Puis vous pouvez enfin lancer l'installateur avec cette commande :
```sh
python3 installator.py
```
Vous pouvez suivre les différentes étapes de l'installateur. Si l'installation ne fonctionne pas correctement utilisez la deuxième méthode qui marche à coup sûr ! 

NB : Vous devez avoir déjà téléchargé le jeu dans l'installateur avant de le lancer avec l'installateur.

### Méthodes 2 : Une Méthode qui marche à coup sûr !

Clonez le répertoire avec la commande   
```sh
git clone https://gitlab.telecomnancy.univ-lorraine.fr/ppii2k22/project2-E22.git
```

Ensuite vous devez aller dans le répertoire cloné à l'aide de la commande suivante :
```sh
cd project2-E22
```

Utilisez un environnement virtuel pour éviter tout problème avec votre machine. Pour cela utilisez les commandes suivantes :
```sh
python3 -m venv env
source env/bin/activate
```

Dirigez vous dans le répertoire où le code source du jeu se situe :
```sh
cd src/
```

Puis installez toutes les dépendances nécessaires pour le jeu :
```sh
pip3 install -r requirement.txt
```

Vous pouvez enfin lancer le jeu en utilisant une dernière commande : 
```sh
flask run
```
Il ne vous reste plus qu'à cliquer sur le lien qui apparait à savoir :
http://127.0.0.1:5000/

Vous pouvez maintenant jouer !