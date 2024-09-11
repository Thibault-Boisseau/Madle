from jeu import occurrence

def test_type_retour():
    """
    test du type de retour
    """
    assert type(occurrence("FMLFK")) == tuple

def test_premiere_liste():
    """
    test de la première liste
    """
    assert occurrence("BONJOUR")[0] == ["B", "O", "N", "J", "U", "R"]

def test_deuxieme_liste():
    """
    test de la deuxième liste
    """
    assert occurrence("BONJOUR")[1] == [1, 2, 1, 1, 1, 1]

def test_mot_vide():
    """
    test du mot vide
    """
    assert occurrence("") == ([], [])

def test_mot_sans_doublon():
    """
    test d'un mot sans doublon
    """
    assert occurrence("SALUT") == (["S", "A", "L", "U", "T"], [1, 1, 1, 1, 1])

def test_mot_que_doublon():
    """
    test mot avec que doublon
    """
    assert occurrence("GGGGG") == (["G"], [5])

def test_quasi_que_doublon():
    """
    test mot avec quasi que des doublons
    """
    assert occurrence("GGGGGA") == (["G", "A"], [5, 1])