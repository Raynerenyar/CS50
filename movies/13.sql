SELECT name FROM people
INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON people.id = stars.person_id
WHERE movies.id IN
(SELECT id from movies
INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON people.id = stars.person_id
WHERE people.name = "Kevin Bacon"
AND people.birth = 1958);