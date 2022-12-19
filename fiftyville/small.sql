select * from passengers
    inner join passengers on passengers.flight_id = flights.id
    inner join people on passengers.passport_number = people.passport_number
    -- inner join flights on flights.id = passengers.flight_id
    where flights.flight_id = 36;