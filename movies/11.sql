SELECT title FROM movies
INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN ratings on 
