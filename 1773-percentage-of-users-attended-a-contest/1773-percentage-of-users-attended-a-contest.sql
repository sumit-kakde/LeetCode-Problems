# Write your MySQL query statement below
SELECT r.contest_id, round(Count(distinct r.user_id)/(SELECT COUNT(*) FROM Users)*100 ,2)as percentage
FROM Users u
join Register r
ON u.user_id=r.user_id
GRoup by r.contest_id
order by percentage desc,r.contest_id ASC


