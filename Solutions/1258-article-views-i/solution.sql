-- Write your PostgreSQL query statement below
select author_id as id from Views
where author_id = viewer_id
group by author_id
ORDER BY author_id
