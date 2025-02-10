SELECT name, bonus FROM Employee e
LEFT JOIN Bonus b
ON e.empId = b.empId
WHERE bonus IS null or bonus < 1000
