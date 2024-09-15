
SELECT S.user_id,IFNULL(ROUND(COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END) / COUNT(c.user_id), 2), 0.00) AS confirmation_rate
FROM Signups S
 LEFT join Confirmations C
ON S.user_id=C.user_id
Group by S.user_id 

