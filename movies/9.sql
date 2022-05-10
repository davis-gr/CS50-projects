select distinct name from people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
where movies.year = 2004
and people.birth is not null
order by people.birth;