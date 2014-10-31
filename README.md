FarmHeroes
==========

Introduction
-----
Le jeu que nous vous proposons cette année comme projet informatique est inspiré du jeu "FarmHeroes" que vous trouvez gratuitement sur smartphone. Ceux qui auront la curiosité de tester ce jeu comprendront le nom de ce projet.  
Adapté pour convenir au mode console, le jeu garde malgré tout l'esprit du jeu d'origine dans son principe : aligner des items pour les faire disparaître (on retrouve également ce principe dans le célèbre CandyCrush).
Cahier des charges
--

Configuration du jeu
--

Le plateau de jeu se présente comme une matrice de caractères 20 lignes x 40 colonnes (ou autre dimensionnement permettant de tenir dans un écran) contenant aléatoirement les lettres "S" pour soleil, "F" pour fraise, "P" pour pomme, "O" pour oignon, et "M" pour mandarine.  
Le joueur a pour objectif de remplir un contrat qui lui est annoncé au début du tableau. Il correspond à un nombre préfixé d'items à "manger" en un nombre préfixé de coups. Le contrat est différent sur chaque tableau et la difficulté est croissante.  
Exemple de contrat
-	tableau 1 - 10 fraises, 20 oignons et 10 mandarines en 40 coups
-	Tableau 2 - 25 soleils, 15 pommes, 10 fraises et 15 oignons en 50 coups
-	...

Début du jeu
---
Le tableau de caractères 20x40 aléatoirement initialisé est affiché à l’écran et les règles de suppression des items s’appliquent immédiatement.
Tout groupe consécutif en ligne verticale ou horizontale de 3 items ou plus disparait et rapporte des « points contrat » au joueur si l’item correspond. En cas de figure spéciale (croix ou L…) une bonification s’applique comme décrit ci-dessous.  
Les items « mangés » créent des trous qui seront comblés par gravité en faisant tomber les caractères au dessus. Les trous qui se forment en haut de colonne sont comblés aléatoirement par de nouveau items.  
Une fois les trous comblés, les règles de suppression d’appliquent de nouveau automatiquement et les trous sont de nouveau comblés… jusqu’à stabilisation.
Le joueur récupère alors la main sur un tableau qui ne contient plus aucun groupe d’items consécutifs de 3.  
Pour "manger" les items, plusieurs possibilités s'offrent au joueur.  
Le joueur doit maintenant constituer des groupes pour remplir son contrat. Pour cela, il doit permuter les items pour les réarranger et former des groupes sur lesquels les règles de suppression s’appliqueront.  
Il peut déplacer le curseur à l’aide des touches 2, 4, 6 et 8 du pavé numérique jusqu'à un item et appuyer sur la barre d'espace. L’item est alors sélectionné et mis en évidence (en passant le caractère en minuscule par exemple).  (Un second appui sur la barre d’espace désélectionne l’item). Il appuie ensuite de nouveau sur une des touches 2, 4, 6 ou 8 pour permuter l’item sélectionné avec l’item choisi à gauche, à droite, au–dessus ou en-dessous (attention aux limites du tableau qui rendent impossible les permutations vers l’extérieur des items en bordure par exemple).  
Si l’item nouvellement positionné forme un groupe consécutif de 3 minimum ou une figure, les règles de suppression s’appliquent. Si la permutation ne forme aucun groupe, le joueur peut de nouveau déplacer le curseur pour effectuer une autre permutation. (dans cette version de jeu, il peut donc permuter des items isolés). Les règles s’appliquent, si possible, après chaque permutation.
Calcul des points contrat
-	Si la permutation du joueur forme un groupe de 3, la règle "mange" le groupe et cumule 3 points dans le contrat sur l'item correspondant.
-	S’il peut former un groupe de 4 items en ligne ou en colonne, la règle fait disparaître les 4 items et rapporte le double, soit 8 points items.
-	Sur le même principe, faire disparaître un groupe en croix ou en L (voir illustration ci-dessous) rapporte alors ((3+3)x2) soit 12 points ou ((4+3)x2) soit 14 points.
-	Dernière possibilité, on mange une ligne verticale ou horizontale de 5 items (y compris incluse dans une figure), on fait alors disparaître tous les items identiques présents sur le tableau, même s'ils sont isolés, et remporte autant de points que d'items disparus.  
OOMPP  
OOOFF  
FFMSF  
3 oignons à récupérer ici, qui valent 3 oignons  
OMPSP  
OOOPF  
OFFMP  
5 oignons mangeables ici, mais en croix, donc ils rapportent (3+3)x2 soit 12 points oignons !  
SMMPO  
SMOPP  
SSSOF  
Idem ici en L qui rapportent 12 points soleil.  
MPFFM  
OFFFM  
SMFOS  
Et ici 12 points fraise.  
FFFFP  
SFSFP  
SOFSS  
Et hop, 8 points fraise.  
MFSOSFM  
MMFSOSF  
OSFFPSM  
MOSOSPF  
OSSOPMF  
MPMMMMM  
Cette configuration rapporte au joueur 13 points mandarine.  
Lorsque des items sont mangés, les items présents au-dessus tombent pour prendre leur place. Les vides qui sont laissés au sommet de chaque colonne sont comblés par de nouveaux items aléatoires qui tombent eux aussi pour combler les trous.
Si le joueur rempli son contrat dans le nombre de coups préfixé, le jeu lui propose de passer au tableau suivant ou de quitter le jeu. En cas d'échec, le joueur consomme une vie et le jeu lui propose de recommencer le même niveau ou de quitter le jeu.  
Au bout de 5 vies, le joueur a perdu et le jeu s'arrête. Le programme enregistre dans un fichier le nom du joueur et les niveaux accomplis pour que la prochaine partie commence sur le prochain tableau à accomplir. Le fait d'accomplir un tableau ou de quitter le jeu remet à cinq le compteur de vie.
