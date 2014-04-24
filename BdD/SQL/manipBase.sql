USE forumSite;

-- Nombre de posts dans chaque sujet de la base de données ?
SELECT idSuj, COUNT(noPost) FROM Post
GROUP BY idSuj;

-- Vue donnant les personnes ayant déjà écrit une news
CREATE VIEW redacteurEffectifNews (pseudo)
AS	SELECT pseudo FROM Concoit;


-- Liste des newseurs n'ayant jamais posté de News ?
SELECT pseudo FROM Appartient
WHERE nomGroupe="Newseur"
AND pseudo NOT IN (SELECT * FROM redacteurEffectifNews);

-- Noms des sujets dont le nom est utlisé deux fois mais dans 2 sous-sections différentes ?
SELECT DISTINCT nomSujet FROM Sujet s1
WHERE EXISTS (SELECT *
FROM Sujet s2
WHERE s1.nomSsSection<>s2.nomSsSection
AND s1.nomSujet=s2.nomSujet);

-- Liste des sujets de MP où 2 personnes (pseudo1 et pseudo5) apparaissent obligatoirement ?
SELECT noSujetMP FROM RecoitMP r1
WHERE EXISTS(SELECT pseudo 
FROM RecoitMP r2
WHERE r1.pseudo="Pseudo1"
AND r2.pseudo="Pseudo5");

-- Vue donnant les news conçues par deux personnes différentes mais utilisant une même source ?
CREATE VIEW news2Personnes1Source (noNews, pseudo, nomSource, ref)
AS	SELECT * FROM Concoit c1
WHERE EXISTS (SELECT * FROM Concoit c2
	WHERE c1.nomSource=c2.nomSource
	AND c1.pseudo<>c2.pseudo);

--  Liste des news où une même source a été utilisée par deux personnes différentes ?
SELECT noNews, titre FROM News
WHERE noNews IN (SELECT noNews FROM news2Personnes1Source);

--  Quelle news ont été postées à une date donnée ? Et qui les a posté ?
SELECT n1.noNews, titre, jour, pseudo FROM News n1, Concoit c1
WHERE jour="2014-04-12"
AND n1.noNews=c1.noNews;

--  Quand telle source a-t-elle été utilisée ?
SELECT jour FROM News
WHERE noNews IN(SELECT noNews FROM Concoit
WHERE nomSource="Vivamus justo");

--  Combien de commentaire a écrit une personne, toute news confondues ?
SELECT COUNT(noCom) FROM Commentaire
WHERE pseudo="Pseudo3";

--  Combien de commentaire a écrit toutes les personnes inscrites, toutes news confondues ?
SELECT pseudo, COUNT(noCom) FROM Commentaire
GROUP BY pseudo
ORDER BY COUNT(noCom) DESC;

--  Vue donnant le nombre de posts par personne
CREATE VIEW nbPostParPersonne (pseudo, nb)
AS SELECT pseudo, COUNT(noPost) FROM Post
GROUP BY pseudo;

--  Quelle est la personne ayant le plus posté sur le forum ? Et combien de posts a-t-il créé ?
SELECT pseudo, nb FROM nbPostParPersonne
WHERE nb=(SELECT MAX(nb) FROM nbPostParPersonne);

--  A quel groupe appartiennent les différentes personnes participant à une conversation par message privé ?
SELECT pseudo, nomGroupe FROM Appartient
WHERE pseudo IN (SELECT pseudo FROM RecoitMP
WHERE noSujetMP=2)
GROUP BY pseudo;

--  Parmi les personnes ayant écrit un message dans ce sujet, lesquels sont modérateurs ou administrateur ?
SELECT pseudo, nomGroupe FROM Appartient
WHERE (nomGroupe="Moderateur"
OR nomGroupe="Administrateur")
AND pseudo IN (SELECT pseudo FROM Post
WHERE idSuj=2)
GROUP BY pseudo;

--  Liste des posts inclus dans une sous-section donnée ?
SELECT idSuj, noPost, pseudo FROM Post
WHERE idSuj IN (SELECT idSuj FROM Sujet
WHERE nomSsSection="Petits jeux");
