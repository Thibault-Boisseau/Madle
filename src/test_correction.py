from jeu import correction

def test_type_retour():
    """
    vérifie le type de retour de la fonction correction
    """
    assert type(correction("LFEH", "KDKD")) == list

def test_arg_tailles_diffs():
    """
    verifie que la liste est vide si les mots ne sont pas de la même taille
    """
    assert correction("LIHD", "ELDELFHLIEFLEILIH") == []

def test_couleur():
    """
    fait un test simple avec les mots BONJOUR et BONNEEE
    """
    assert correction("BONJOUR", "BONNEEE") == ["V", "V", "V", "N", "N", "N", "N"]

def test_arg_vide():
    """
    vérification avec des mots vides
    """
    assert correction("", "") == []

def test_mot_bon():
    """
    vérification avec un mot bon
    """
    assert correction("BONJOUR", "BONJOUR") == ["V"] * 7

def test_mauvais():
    """
    vérification avec deux mots différents
    """
    assert correction("BONJOUR", "PATATES") == ["N"] * 7

def test_mauvais_sens():
    """
    vérification avec les lettres dans le mauvais ordre
    """
    assert correction("BONJOUR", "RNJBUOO") == ["B"] * 7

def test_premier_occ():
    """
    test de la première occurence
    """
    assert correction("BONJOUR", "BONJUOR") == ["V", "V", "V", "V", "B", "B", "V"]

def test_second_occ():
    """
    test de la seconde occurence
    """
    assert correction("BONJOUR", "BNOJOUR") == ["V", "B", "B", "V", "V", "V", "V"]

def test_particularite1():
    """
    test de la particularité 1
    """
    assert correction("BONJOUR", "JONJOUR") == ["N", "V", "V", "V", "V", "V", "V"]

def test_particularite2():
    """
    test de la particularité 2
    """
    assert correction("BONJOUR", "ONBJOBR") == ["B", "B", "B", "V", "V", "N", "V"]