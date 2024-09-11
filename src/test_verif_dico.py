from jeu import verif_dico

def test_type_retour():
    """
    test du type de retour
    """
    assert type(verif_dico("fl")) == bool

def test_mot_dedans():
    """
    test qu'un mot est bien dedans
    """
    assert verif_dico("A") == True

def test_mot_dedans2():
    """
    test un autre mot
    """
    assert verif_dico("BONJOUR") == True

def test_mot_dehors():
    """
    test un mot qui n'est pas dans le dico
    """
    assert verif_dico("LOL") == False

def test_mot_nul():
    """
    test du mot nul
    """
    assert verif_dico("") == False

def test_mot_trop_long():
    """
    test d'un mot trop long
    """
    assert verif_dico("LHFIERLIHELRIH") == False

