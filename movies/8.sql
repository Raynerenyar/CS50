SELECT name
FROM people
INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN movies ON movies.id = stars.movie_id
WHERE movies.title = "Toy Story";