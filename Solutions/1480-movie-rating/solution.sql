SELECT MIN(name) AS results FROM (
    SELECT name FROM Users JOIN MovieRating
    USING (user_id) GROUP BY (name) HAVING COUNT(*) = (SELECT MAX(cnt) FROM (
        SELECT COUNT(*) cnt FROM Users JOIN MovieRating
        USING (user_id)
        GROUP BY (name)
    ))
)
UNION ALL
SELECT MIN(title) AS results FROM Movies
WHERE movie_id IN (
    SELECT movie_id FROM Movies 
    JOIN MovieRating USING (movie_id) 
    WHERE created_at >= '2020-02-01' AND created_at <= '2020-02-28'
    GROUP BY movie_id HAVING AVG(rating) = (
        SELECT MAX(avg) FROM (
            SELECT AVG(rating) FROM Movies 
            JOIN MovieRating USING (movie_id) 
            WHERE created_at >= '2020-02-01' AND created_at <= '2020-02-28'
            GROUP BY movie_id
        )
    )
)
