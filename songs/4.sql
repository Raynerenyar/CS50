SELECT name from songs WHERE danceability > 0.75;
SELECT name from songs WHERE energy > 0.75;
SELECT name from songs WHERE valence > 0.75;
SELECT name from songs WHERE valence > 0.75 IN (SELECT valence FROM songs WHERE energy > 0.75);
SELECT name,danceability,energy,valence from songs WHERE valence IN (SELECT danceability,valence FROM songs WHERE energy > 0.75) > 0.75;
