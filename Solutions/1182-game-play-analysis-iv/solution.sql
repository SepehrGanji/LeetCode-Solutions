SELECT ROUND(1.0 * COUNT(*) / (SELECT COUNT(DISTINCT player_id) 
FROM Activity) , 2) fraction FROM Activity
WHERE (player_id, event_date) IN (
    SELECT player_id, MIN(event_date) + 1
    FROM Activity
    GROUP BY player_id
)
