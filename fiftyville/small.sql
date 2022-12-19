select * from passengers
    inner join passengers on passengers.passport_number = people.passport_number
    inner join flights on flights.id = passengers.flight_id
    where flights.flight_id = 36;