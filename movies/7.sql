SELECT rating FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2010);
SELECT title,id FROM movies WHERE year = 2010;

SELECT ratings.rating, movies.title
from movies
inner join ratings on movies.id = ratings.movie_id