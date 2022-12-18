SELECT name FROM people
INNER JOIN stars ON stars.person_id = people.id
INNER JOIN movies ON movies.id = stars.movie_id

-- filters
WHERE movies.id IN

-- returns table of id from movies where the 1958 Kevin Bacon starred in
(SELECT movies.id from movies
INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON people.id = stars.person_id
WHERE people.name = "Kevin Bacon"
AND people.birth = 1958)
AND people.name != "Kevin Bacon";