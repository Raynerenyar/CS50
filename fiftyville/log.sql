-- Keep a log of any SQL queries you execute as you solve the mystery.
-- interview about thief, 3 accounts on 28/7/2021
select * from interviews where transcript like "%thief%";
select * from bakery_security_logs where day = 28 and month = 7 and year = 2021;
