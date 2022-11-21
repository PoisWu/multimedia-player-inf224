{#mainpage}
=========
# Task 4 | Photos et Videos
## Comment appelle-t'on ce type de méthode et comment faut-il les déclarer? 

Virtual void run() const=0; 
("=0") is called pure specifier. 

## Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ? 

Non, il n'est plus possible parce que on ne peut pas instancer d'un abstract class (au moin un de ses méthod virtual n'est pas implémenté).

# Task 5 | Traitement uniforme

## Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
elle s'appelle polymorphism qui veut dire qu'on peut choisir le point de vue le plus approprié selon les besoins 

## Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?


## Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ?  Comparer à Java.

# Task 6 | Films et tableaux

# Task 7 | Destruction et copie des objets

## Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?  Modifiez le code de manière à l'éviter.
- Virtual descturceur dans la class Base
- Modify the descructor of Film, delete[] chapiter_duration_table




## La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?
copy constructeur, operator=

# Task 8 | Créer des groupes
## On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.
Pour être polymorphisme, parce que \texttt{list<T>} prend un type fixe. 





# Task 9 | Gestion automatique de la mémoire 
## Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ? 
# Task 10 | Gestion cohérente des données
# Task 11 | Client/serveur

