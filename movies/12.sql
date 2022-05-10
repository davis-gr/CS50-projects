select

select title, count(*) from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where people.name in ('Johnny Depp','Helena Bonham Carter')
group by title
having count(*) > 1;