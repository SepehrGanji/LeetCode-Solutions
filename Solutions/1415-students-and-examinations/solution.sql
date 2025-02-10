SELECT s.student_id, s.student_name, su.subject_name,
COALESCE(gg.attended_exams, 0) attended_exams FROM Students s 
CROSS JOIN Subjects su
LEFT JOIN (
    SELECT student_id, subject_name, COUNT(*) AS attended_exams
    FROM Examinations
    GROUP BY student_id, subject_name 
) gg
ON s.student_id = gg.student_id AND su.subject_name = gg.subject_name
ORDER BY s.student_id, su.subject_name
