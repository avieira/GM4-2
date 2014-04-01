--Insertion dans les Sous-Sections des Sujets, puis des posts

INSERT INTO Sous-Section VALUES ("Premiers pas", "Règles", "À lire avant toute inscription !");
	INSERT INTO Sujet VALUES (1, "Règles du forum");
		INSERT INTO Post VALUES (1, NULL, 26-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Admin");

	INSERT INTO Sujet VALUES ("Règles", "Règles du site");
		INSERT INTO Post VALUES (1, NULL, 25-03-2014, "Suspendisse rhoncus lectus nec tortor porta, ut viverra nisl malesuada. Suspendisse eget euismod dui. Duis id enim id nibh euismod lobortis amet.", "Admin");


INSERT INTO Sous-Section VALUES ("Premiers pas", "Présentation", "La politesse veut qu'on se présente après l'inscription, histoire qu'on ne vous considère pas comme un inconnu !");
	INSERT INTO Sujet VALUES (2, "Premier nouveau");
		INSERT INTO Post VALUES (2, NULL, 25-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo1");
		INSERT INTO Post VALUES (2, NULL, 25-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo2");
	INSERT INTO Sujet VALUES (3, "Deuxième arrivé");
		INSERT INTO Post VALUES (3, NULL, 26-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo3");
		INSERT INTO Post VALUES (3, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo1");


INSERT INTO Sous-Section VALUES ("Informations", "Annonces globales", "Seuls les administrateurs et modérateurs peuvent poster ici. Cette section sert à communiquer avec le bas-peuple.");
	INSERT INTO Sujet VALUES (4, "Mise à jour site");
		INSERT INTO Post VALUES (4, NULL, 01-04-2014, "Suspendisse rhoncus lectus nec tortor porta, ut viverra nisl malesuada. Suspendisse eget euismod dui. Duis id enim id nibh euismod lobortis amet.", "Admin");
	INSERT INTO Sujet VALUES (5, "Mise à jour forum");
		INSERT INTO Post VALUES (5, NULL, 02-04-2014, "Suspendisse rhoncus lectus nec tortor porta, ut viverra nisl malesuada. Suspendisse eget euismod dui. Duis id enim id nibh euismod lobortis amet.", "Admin");
	INSERT INTO Sujet VALUES (6, "Petite mise au point");
		INSERT INTO Post VALUES (6, NULL, 28-02-2014, " Morbi rhoncus sem massa, ut malesuada mauris viverra quis. Nulla sem libero, malesuada a posuere nec, aliquet eget lectus. Pellentesque ut consectetur nibh. Aliquam vel augue non nisl fermentum tempus. Suspendisse potenti. Vivamus eu velit nunc. Pellentesque volutpat rhoncus nibh eget feugiat.

Integer eros orci, iaculis viverra ornare quis, aliquet at velit. Cras condimentum augue eu odio adipiscing aliquet non vel lectus. Ut aliquam tempor rhoncus. In vitae tincidunt eros. Vestibulum leo lorem, lacinia eu ullamcorper ac, malesuada eget lorem. Donec consequat leo sed eleifend vulputate. Cras a nisl viverra purus ultricies rutrum. Mauris fringilla velit sed nulla laoreet varius. Nullam lobortis, velit molestie egestas vestibulum, purus nisl dictum nisi, at mollis massa tortor in velit.

Etiam rutrum risus ultricies, cursus nunc eget, eleifend quam. Sed ut nisl lorem. Mauris non vulputate ipsum. Aliquam auctor, urna ac vehicula rutrum, justo neque luctus diam, at eleifend ante nulla id felis. Donec semper velit nisl, id imperdiet diam viverra et. Sed quis iaculis ligula. Proin condimentum faucibus dapibus. Aenean mattis ac ligula id pharetra. Integer non adipiscing erat. Praesent et augue vitae ligula consequat tincidunt. Pellentesque malesuada, tortor a faucibus scelerisque, arcu diam semper turpis, eu fermentum velit ligula sed massa. Maecenas quis malesuada magna. Nunc nec faucibus sapien. Nunc et nisi dolor. Donec in orci eget tellus venenatis posuere eu eget orci. ", "Moderateur1");
		INSERT INTO Post VALUES (6, NULL, 01-03-2014, "Suspendisse rhoncus lectus nec tortor porta, ut viverra nisl malesuada. Suspendisse eget euismod dui. Duis id enim id nibh euismod lobortis amet.", "Moderateur2");


INSERT INTO Sous-Section VALUES ("Informations", "Problèmes sur le site", "Un problème ou une coquille sur le site ? Venez en parler ici.");
	INSERT INTO Sujet VALUES (7, "Problème d'affichage sous IE7");
		INSERT INTO Post VALUES (7, NULL, 15-03-2014, "Suspendisse rhoncus lectus nec tortor porta, ut viverra nisl malesuada. Suspendisse eget euismod dui. Duis id enim id nibh euismod lobortis amet.", "Pseudo7");
		INSERT INTO Post VALUES (7, NULL, 15-03-2014, "Mais laisse tomber IE, sérieusement. C'est quoi ce noobie ?", "Pseudo4");
		INSERT INTO Post VALUES (7, NULL, 15-03-2014, "Hé, on se calme ici, hein.", "Moderateur3");


INSERT INTO Sous-Section VALUES ("Informations", "Problèmes sur le forum", "Un problème ou une coquille sur le forum ? Venez en parler ici.");
	INSERT INTO Sujet VALUES (8, "Problème d'affichage sous IE7");
		INSERT INTO Post VALUES (8, NULL, 15-03-2014, "Suspendisse rhoncus lectus nec tortor porta, ut viverra nisl malesuada. Suspendisse eget euismod dui. Duis id enim id nibh euismod lobortis amet.", "Pseudo7");
		INSERT INTO Post VALUES (8, NULL, 15-03-2014, "Encore lui..?", "Moderateur3");
	INSERT INTO Sujet VALUES (9, "Proposition d'amélioration");
		INSERT INTO Post VALUES (9, NULL, 8-05-2014, " Pellentesque aliquam ipsum a mauris volutpat egestas. Morbi feugiat, nulla vitae rhoncus facilisis, purus nisi laoreet eros, eget tincidunt sem lorem quis ante. Maecenas imperdiet nibh quis fermentum egestas. Duis posuere mi vel sapien aliquam, ut ultricies dolor dignissim. Vivamus justo velit, suscipit et elementum vitae, euismod vel nisl. Praesent eu turpis in est scelerisque molestie sit amet nec sem. Nunc varius hendrerit massa. Vivamus vehicula dolor vitae vulputate rutrum. Maecenas convallis velit sit amet lacinia imperdiet. Donec sodales eget diam ut eleifend. Suspendisse quam tellus, aliquet et mattis in, interdum sed leo. Vivamus ullamcorper a risus quis vestibulum. Ut ut felis nec enim ultricies facilisis. Praesent malesuada, enim vitae semper elementum, orci erat consectetur lacus, non lobortis purus urna sit amet dui. ", "Pseudo1");


INSERT INTO Sous-Section VALUES ("Informations", "News", "Envie de revenir sur une de nos news ? Vous pouvez en discuter avec tous les membres ici !");
	INSERT INTO Sujet VALUES (10, "News01");
		INSERT INTO Post VALUES (10, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo5");
		INSERT INTO Post VALUES (10, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");
		INSERT INTO Post VALUES (10, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo4");
	INSERT INTO Sujet VALUES (11, "News02");
		INSERT INTO Post VALUES (11, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo5");
		INSERT INTO Post VALUES (11, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");
		INSERT INTO Post VALUES (11, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo4");
	INSERT INTO Sujet VALUES (12, "News03");
		INSERT INTO Post VALUES (12, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo5");
		INSERT INTO Post VALUES (12, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");
		INSERT INTO Post VALUES (12, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo5");


INSERT INTO Sous-Section VALUES ("Discussion", "Loisirs et bons plans", "Un loisir à partager ou un bon plan pour les membres ? C'est ici que ça se passe !");
	INSERT INTO Sujet VALUES (13, "Ciné du moment");
		INSERT INTO Post VALUES (13, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo5");
		INSERT INTO Post VALUES (13, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");
		INSERT INTO Post VALUES (13, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo4");
		INSERT INTO Post VALUES (13, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo7");
		INSERT INTO Post VALUES (13, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo3");
		INSERT INTO Post VALUES (13, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");
	INSERT INTO Sujet VALUES (14, "Sortie au musée");
		INSERT INTO Post VALUES (14, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo3");
		INSERT INTO Post VALUES (14, NULL, 28-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");


INSERT INTO Sous-Section VALUES ("Discussion", "Petits jeux", "Parce qu'on ne doit parler que de sujets sérieux ici, les petits jeux servent à se détendre.");
	INSERT INTO Sujet VALUES (15, "Pendu");
		INSERT INTO Post VALUES (15, NULL, 27-03-2014, "P _ _ _ _ _ _ E", "Pseudo4");
		INSERT INTO Post VALUES (15, NULL, 28-03-2014, "Un L !", "Pseudo3");
		INSERT INTO Post VALUES (15, NULL, 28-03-2014, "P _ _ _ _ LLE", "Pseudo4");
		INSERT INTO Post VALUES (15, NULL, 28-03-2014, "Un O !", "Pseudo3");
		INSERT INTO Post VALUES (15, NULL, 29-03-2014, "PO _ _ _ LLE", "Pseudo4");
		INSERT INTO Post VALUES (15, NULL, 28-03-2014, "Poubelle !", "Pseudo5");
		INSERT INTO Post VALUES (15, NULL, 28-03-2014, "... Tu l'as eu avant moi.", "Pseudo3");


INSERT INTO Sous-Section VALUES ("Discussion", "Blabla et boîte à flood", "Si vous ne savez pas où poster, ou que ce n'est pas très sérieux... C'est par ici !");
	INSERT INTO Sujet VALUES (16, "Super/Naze");
		INSERT INTO Post VALUES (16, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo5");
		INSERT INTO Post VALUES (16, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");
		INSERT INTO Post VALUES (16, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo4");
		INSERT INTO Post VALUES (16, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo7");
		INSERT INTO Post VALUES (16, NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo3");
		INSERT INTO Post VALUES (16, NULL, 28-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");
		INSERT INTO Post VALUES (16, NULL, 28-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo5");
		INSERT INTO Post VALUES (16, NULL, 28-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");
		INSERT INTO Post VALUES (16, NULL, 28-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo4");
		INSERT INTO Post VALUES (16, NULL, 28-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo7");
		INSERT INTO Post VALUES (16, NULL, 30-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo3");
		INSERT INTO Post VALUES (16, NULL, 30-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo8");


INSERT INTO Sous-Section VALUES ("Administration", "Page d'admin", "Page reservée aux administrateurs.");
	INSERT INTO Sujet VALUES (17, "Alertes sur le forum");
		INSERT INTO Post VALUES (16, NULL, 27-03-2014, "... Bon, on n'est pas obligés de toujours être sérieux non plus ;)", "Admin");
