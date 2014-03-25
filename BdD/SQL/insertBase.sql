--Insertion dans la Sous-Section, des Sujets, puis des posts
INSERT INTO Sous-Section VALUES ("Premiers pas", "Règles", "À lire avant toute inscription !");
	INSERT INTO Sujet VALUES ("Règles", "Règles du forum");
		INSERT INTO Post VALUES ("Règles du forum", NULL, 25-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Admin");

	INSERT INTO Sujet VALUES ("Règles", "Règles du site");
		INSERT INTO Post VALUES ("Règles du site", NULL, 25-03-2014, "Suspendisse rhoncus lectus nec tortor porta, ut viverra nisl malesuada. Suspendisse eget euismod dui. Duis id enim id nibh euismod lobortis amet.", "Admin");


INSERT INTO Sous-Section VALUES ("Premiers pas", "Présentation", "La politesse veut qu'on se présente après l'inscription, histoire qu'on ne vous considère pas comme un inconnu !");
	INSERT INTO Sujet VALUES ("Présentation", "Premier nouveau");
		INSERT INTO Post VALUES ("Premier Nouveau", NULL, 25-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo1");
		INSERT INTO Post VALUES ("Premier Nouveau", NULL, 25-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo2");
	INSERT INTO Sujet VALUES ("Présentation", "Deuxième arrivé");
		INSERT INTO Post VALUES ("Deuxième arrivé", NULL, 26-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo3");
		INSERT INTO Post VALUES ("Deuxième arrivé", NULL, 27-03-2014, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce porta lacinia eleifend. Vivamus fermentum ultricies ante consectetur rutrum massa nunc.", "Pseudo1");



INSERT INTO Sous-Section VALUES ("Informations", "Annonces globales", "Seuls les administrateurs et modérateurs peuvent poster ici. Cette section sert à communiquer avec le bas-peuple.");
INSERT INTO Sous-Section VALUES ("Informations", "Problèmes sur le site", "Un problème ou une coquille sur le site ? Venez en parler ici.");
INSERT INTO Sous-Section VALUES ("Informations", "Problèmes sur le forum", "Un problème ou une coquille sur le forum ? Venez en parler ici.");
INSERT INTO Sous-Section VALUES ("Informations", "News", "Envie de revenir sur une de nos news ? Vous pouvez en discuter avec tous les membres ici !");

INSERT INTO Sous-Section VALUES ("Discussion", "Loisirs et bons plans", "Un loisir à partager ou un bon plan pour les membres ? C'est ici que ça se passe !");
INSERT INTO Sous-Section VALUES ("Discussion", "Petits jeux", "Parce qu'on ne doit parler que de sujets sérieux ici, les petits jeux servent à se détendre.");
INSERT INTO Sous-Section VALUES ("Discussion", "Blabla et boîte à flood", "Si vous ne savez pas où poster, ou que ce n'est pas très sérieux... C'est par ici !");

INSERT INTO Sous-Section VALUES ("Administration", "Page d'admin", "Page reservée aux administrateurs.");
