-- Write your PostgreSQL query statement below
SELECT p.firstName, p.lastname, a.city, a.state FROM Person as p
LEFT JOIN Address as a
On p.personId = a.personId

