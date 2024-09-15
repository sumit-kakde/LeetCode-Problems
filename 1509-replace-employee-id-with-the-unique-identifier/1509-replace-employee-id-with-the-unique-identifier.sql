# Write your MySQL query statement below
SELECT E.name ,U.unique_id
FROM Employees E
LEFT JOIN EmployeeUNI U
ON E.id=U.id 
