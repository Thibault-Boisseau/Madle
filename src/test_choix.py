from jeu import choix
from jeu import MOTS_TAILLE_UN, MOTS_TAILLE_DEUX, MOTS_TAILLE_TROIS, MOTS_TAILLE_QUATRE, MOTS_TAILLE_CINQ, MOTS_TAILLE_SIX, MOTS_TAILLE_SEPT, MOTS_TAILLE_HUIT, MOTS_TAILLE_NEUF, MOTS_TAILLE_DIX, MOTS_TAILLE_ONZE, MOTS_TAILLE_DOUZE, MOTS_TAILLE_TREIZE, MOTS_TAILLE_QUATORZE

MOTS_TOTAL = MOTS_TAILLE_UN + MOTS_TAILLE_DEUX + MOTS_TAILLE_TROIS + MOTS_TAILLE_QUATRE + MOTS_TAILLE_CINQ + MOTS_TAILLE_SIX + MOTS_TAILLE_SEPT + MOTS_TAILLE_HUIT + MOTS_TAILLE_NEUF + MOTS_TAILLE_DIX + MOTS_TAILLE_ONZE + MOTS_TAILLE_DOUZE + MOTS_TAILLE_TREIZE + MOTS_TAILLE_QUATORZE

def test_type_retour():
    """
    vérification du type de retour de la fonction choix
    """
    assert type(choix(7)) == str

def test_mot_dans_dico():
    """
    vérifie qu'un mot au hasard de chaque longueur est bien dans l'ensemble des mots
    """
    for i in range(1, 11):
        assert choix(i) in MOTS_TOTAL

def test_mot_bonne_taille():
    """
    vérifie que le mot retourné est bien de la bonne taille
    """
    for i in range(1, 11):
        assert len(choix(i)) == i

def test_argument_nul():
    """
    verifie qu'un mot de taille 0 renvoie bien le mot vide
    """
    assert choix(0) == ""

def test_argument_negatif():
    """
    une taille négative renvoie un mot vide
    """
    assert choix(-5) == ""

def test_argument_trop_grand():
    """
    si la taille dépasse 15 alors le mot vide est renvoyé
    """
    assert choix(100) == ""

def test_taille():
    """
    vérifie que les mots de taille 1 sont bien l'ensemble de l'alphabet
    """
    assert len(MOTS_TAILLE_UN) == 26