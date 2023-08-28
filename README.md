{#mainpage}
=========
# Partie CPP
## Task 4 | Photos et Videos
`Comment appelle-t'on ce type de méthode et comment faut-il les déclarer?` 

**Réponse**:

Ce type de méthode s'appelle méthode pure virtuelle. Il fait déclarer avec le mot clé `virtual` et `=0`(pure specifier) à la fin.
Par example `virtual f()=0;`

`Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?`

**Réponse**:

Non, il n'est plus possible parce que on ne peut pas instancer d'un abstract class (au moin un de ses méthod virtual n'est pas implémenté).

## Task 5 | Traitement uniforme

`Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ?  Comparer à Java.`

**Réponse**:

- Elle s'appelle polymorphism qui veut dire qu'on peut choisir le point de vue le plus approprié selon les besoins. Il faut déclarer ce type de méthode avec le mot clé `virtual` afin d'activer polymorphism **dynamique**, et `override` quand on veut reinplémenter la méthode.
- Le tableau doit contenir des pointers vers ces objets parce qu'un tableau ne peux contenir qu'un seul type d'objet.
- Il n'y a pas de notion de pointer en Java mais on a la notion de référance. D'où il n'y a pas de choix. On ne peut créer un tableau de référence. 

## Task 7 | Destruction et copie des objets
`Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?  Modifiez le code de manière à l'éviter.`

**Réponse**:

- On vuet avoir la propriété de polymorphisme sur le méthode descruteur. Par conséquence, on ajoute le mot clé `virtual` devant le desctructeur de `class Base`.
- On modifie également the descructor of Film en ajoutant 
  `delete[] chapiter_duration_table;`

`La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?`

**Réponse**:

- Si on ne fait pas la modification, le copy operator copie juste la valeur de pointer. A la fin de opération, on a deux l'objets film dont leur chapiter_duration_table pointe au même tableau dans le mémoire. 
  Par exemple: 
  ```
  film film1 = film();
  film film2 = film1;
  ``` 
  on a finalement `film1.chapiter_duration_table = film.chapiter_duration_table`  
- On doit reimplémenter le copy constructeur et `=` operator. 

## Task 8 | Créer des groupes
`On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.`

**Réponse**:

C'est déjà répondu dans la question de Task5. 

## Task 11 | client/serveur 
Les commandes sont:
- GET <filename>  : Search the `filename` object in the data base
- PLAY <filename> : Play the `filename` object on the side server. 

Pour tester, 3 objets multimédia sont mis dans le dossier /cpp/media aussi le database de serveur. Les 3 objets sont 
- imag1.jpg
- imag2.jpg
- film1.mp4

# Partie Java Swing

## Task 3: 
Exemple d'utilisation: 
- SEARCH : écrire le nom de l'objet Multimedia à rechercher dans le "JTextArea"
- PLAY : écrire le nom de l'objet Multimedia qu'on veut "jouer". Il sera lancé côté serveur.
- CLOSE : Fermer le client swing

