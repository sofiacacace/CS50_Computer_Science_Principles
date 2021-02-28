-- write a SQL query to list the names of all people who starred in Toy Story.

SELECT name
FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id  --Esta sintaxis y la de abajo dan igual resultado.
--FROM movies JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id
WHERE title = "Toy Story"