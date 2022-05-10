select distinct a.name from people a
join stars b on a.id = b.person_id
where b.movie_id in(
select distinct movies.id from movies
join stars on movies.id = stars.movie_id
where stars.person_id in (select people.id from people where name = 'Kevin Bacon' and birth = 1958))
and a.name != 'Kevin Bacon';