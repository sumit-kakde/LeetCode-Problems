# Write your MySQL query statement below
SELECT product_id
FROM Products
WHERE low_fats=recyclable AND 
low_fats="Y"
AND recyclable="Y"