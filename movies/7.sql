SELECT rating FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2010);
SELECT title,id FROM movies WHERE year = 2010;