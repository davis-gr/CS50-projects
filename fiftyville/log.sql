-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Understand what was the crime that happened.
select description from crime_scene_reports
where year = 2021
and month = 7
and day = 28
and street = 'Humphrey Street';

-- Get the interview transcripts that mention bakery from that day
select * from interviews
where year = 2021
and month = 7
and day = 28
and transcript like '%bakery%';

-- find all car exits that happened after 10:15am
select * from bakery_security_logs
where year = 2021
and month = 7
and day = 28;