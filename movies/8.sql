SELECT people.name
FROM people
INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON stars.person_id = people.id
WHERE movies.title = "Toy Story";