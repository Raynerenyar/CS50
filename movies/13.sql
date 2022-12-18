SELECT name FROM people
INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON people.id = stars.person_id