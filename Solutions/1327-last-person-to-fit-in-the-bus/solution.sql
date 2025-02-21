WITH temp AS (
    SELECT *, SUM(weight) OVER (ORDER BY turn) as ww
    FROM queue
)

SELECT person_name from temp WHERE ww <= 1000
ORDER BY turn DESC LIMIT 1
