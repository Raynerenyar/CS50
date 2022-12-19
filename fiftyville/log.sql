-- Keep a log of any SQL queries you execute as you solve the mystery.

-- interview about thief, 3 accounts on 28/7/2021
select *
    from interviews
    where transcript like "%thief%";

-- shows license plate of cars on the date. not filtered by activity yet. Thief exited
-- can get name from license plate number
select *
    from bakery_security_logs
    where day = 28
    and month = 7
    and year = 2021;

-- shows account numbers that transacted on atm at Leggett Street on the date. Thief withdrew.
-- transactions have no timestamp
-- could get name from account number
select *
    from atm_transactions
    where day = 28
    and month = 7
    and year = 2021
    and atm_location = "Leggett Street"
    and transaction_type = "withdraw";

-- crime report on the date at Humphrey Street Bakery
-- crime is roughly at 10:15 am
select *
    from crime_scene_reports
    where year = 2021
    and month = 7
    and day =28
    and description like "%cs50%";
