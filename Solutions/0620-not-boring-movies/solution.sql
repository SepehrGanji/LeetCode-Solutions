-- Write your PostgreSQL query statement below
SELECT * FROM Cinema
WHERE description != 'boring'
AND id % 2 = 1
ORDER BY rating DESC
