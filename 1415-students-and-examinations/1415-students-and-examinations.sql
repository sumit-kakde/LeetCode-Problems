SELECT S.student_id ,S.student_name ,ss.subject_name,COUNT(E.subject_name) AS attended_exams
FROM Students S
CROSS JOIN Subjects ss
LEFT JOIN Examinations E
ON S.student_id=E.student_id AND ss.subject_name = E.subject_name
GROUP BY S.student_id , S.student_name,ss.subject_name
ORDER BY S.student_id , ss.subject_name

