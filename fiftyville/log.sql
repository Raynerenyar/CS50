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

-- find security logs at hour 10
select *
    from bakery_security_logs
    where day = 28
    and month = 7
    and year = 2021
    and hour = 10;

-- linking license plate from security footage
-- and account numbers that withdrew from atm at Leggett Street at hour 10
-- reveals a few names
select * from people
    inner join bank_accounts on bank_accounts.person_id = people.id
    inner join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
    inner join bakery_security_logs on bakery_security_logs.license_plate = people.license_plate
    where atm_transactions.year = 2021
    and atm_transactions.month = 7
    and atm_transactions.day = 28
    and bakery_security_logs.hour = 10
    and atm_transactions.transaction_type = "withdraw"
    and atm_transactions.atm_location = "Leggett Street";

-- call logs on 28/8/2021 duration less than 60 seconds
select * from phone_calls where year = 2021 and day = 28 and month = 7 and duration < 60;

-- narrow down to 3 people
select * from people
    inner join bank_accounts on bank_accounts.person_id = people.id
    inner join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
    inner join bakery_security_logs on bakery_security_logs.license_plate = people.license_plate
    inner join phone_calls on people.phone_number = phone_calls.caller
    where atm_transactions.year = 2021
    and atm_transactions.month = 7
    and atm_transactions.day = 28
    and bakery_security_logs.hour = 10
    and atm_transactions.transaction_type = "withdraw"
    and atm_transactions.atm_location = "Leggett Street"
    and phone_calls.duration < 60
    and phone_calls.day = 28;

-- fiftyville airport id = 8
select * from airports where id = 8;

-- flights
select * from flights
    where day = 29
    order by hour asc, minute asc;

