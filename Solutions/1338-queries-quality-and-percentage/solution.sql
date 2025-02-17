SELECT query_name, ROUND(AVG(1.0*q.rating/q.position), 2) quality,
ROUND(AVG(CASE WHEN
    q.rating < 3 THEN 1
    ELSE 0
    END)*100, 2) poor_query_percentage
FROM Queries q
GROUP BY query_name
