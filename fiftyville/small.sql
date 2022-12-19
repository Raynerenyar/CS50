select * from passengers
    inner join passengers.passport_number = people.passport_number
    where passengers.flight_id = 36;