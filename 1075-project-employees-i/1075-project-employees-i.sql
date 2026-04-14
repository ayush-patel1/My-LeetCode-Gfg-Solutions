# Write your MySQL query statement below
select p.project_id,
ifnull(round(sum(e.experience_years)/count(e.employee_id),2),0) as average_years
from Project p
Left Join Employee e
on p.employee_id=e.employee_id
group by p.project_id
