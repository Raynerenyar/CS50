select * from passengers
    inner join people on passengers.passport_number = people.passport_number
    inner join flights on flights.id = passengers.flight_id
    inner join passengers on passengers.flight_id = flights.id
    where flights.id = 36;