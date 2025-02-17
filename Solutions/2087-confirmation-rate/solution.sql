-- Write your PostgreSQL query statement below
SELECT user_id, ROUND(AVG(COALESCE(action_type, 0)), 2) confirmation_rate
FROM Signups s
LEFT JOIN(
    SELECT user_id, case when action = 'timeout' then 0
    else 1 end as action_type
    FROM confirmations
) as t1
USING (user_id)
GROUP BY user_id
