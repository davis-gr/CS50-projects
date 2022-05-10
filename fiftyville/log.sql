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

-- find all car exits that happened between 10:15am and 10:25am
select license_plate from bakery_security_logs
where year = 2021
and month = 7
and day = 28
and activity = 'exit'
and hour = 10
and minute between 15 and 25;

-- find all persons who withdrew money from this day at Leggett Street
select person_id from bank_accounts
where account_number in (select account_number from atm_transactions
                            where year = 2021
                            and month = 7
                            and day = 28
                            and atm_location = 'Leggett Street'
                            and transaction_type = 'withdraw');

-- find all callers with outgoing phone calls with duration < 1 minute on the same day
select caller from phone_calls
where year = 2021
and month = 7
and day = 28
and duration < 60;

-- find the passenger passport numbers of the earliest flight out of fiftyville tomorrow

select passport_number from passengers
where flight_id in (select flights.id from flights
                    join airports on flights.origin_airport_id = airports.id
                    where year = 2021
                    and month = 7
                    and day = 29
                    and airports.city = 'Fiftyville'
                    order by hour, minute
                    limit 1);

-- find out who the suspect is
select * from people
where phone_number in (select caller from phone_calls
                        where year = 2021
                        and month = 7
                        and day = 28
                        and duration < 60)
and license_plate in (select license_plate from bakery_security_logs
                        where year = 2021
                        and month = 7
                        and day = 28
                        and activity = 'exit'
                        and hour = 10
                        and minute between 15 and 25)
and passport_number in (select passport_number from passengers
                        where flight_id in (select flights.id from flights
                                            join airports on flights.origin_airport_id = airports.id
                                            where year = 2021
                                            and month = 7
                                            and day = 29
                                            and airports.city = 'Fiftyville'
                                            order by hour, minute
                                            limit 1))
and people.id in (select person_id from bank_accounts
                    where account_number in (select account_number from atm_transactions
                                                where year = 2021
                                                and month = 7
                                                and day = 28
                                                and atm_location = 'Leggett Street'
                                                and transaction_type = 'withdraw'));

-- find out where Bruce escaped to
select city from airports a
join flights b on a.id = b.destination_airport_id
where b.id in (select flights.id from flights
                join airports on flights.origin_airport_id = airports.id
                where year = 2021
                and month = 7
                and day = 29
                and airports.city = 'Fiftyville'
                order by hour, minute
                limit 1);

-- find out who the accomplice is
select name from people
where phone_number = (select receiver from phone_calls
                        where year = 2021
                        and month = 7
                        and day = 28
                        and duration < 60
                        and caller = '(367) 555-5533') -- we just use Batman's phone number from before
                        ;