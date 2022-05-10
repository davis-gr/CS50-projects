-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Understand what was the crime that happened
select description from crime_scene_reports
where year = 2021
and month = 7
and day = 28
and street = 'Humphrey Street';

select * from interviews
where year = 2021
and month = 7
and day = 28
and transcript like '%bakery%