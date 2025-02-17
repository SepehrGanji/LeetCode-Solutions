SELECT contest_id, ROUND((100.0*COUNT(user_id))/
(SELECT COUNT(user_id) FROM Users),2) percentage
FROM Register
JOIN Users
USING (user_id)
GROUP BY contest_id
ORDER BY percentage DESC, contest_id
