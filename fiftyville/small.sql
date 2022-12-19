select * from people
    inner join bank_accounts on bank_accounts.person_id = people.id
    inner join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
    inner join bakery_security_logs on bakery_security_logs.license_plate = people.license_plate
    where atm_transactions.year = 2021
    and atm_transactions.month = 7
    and atm_transactions.day = 28
    and atm_transactions.hour = 10
    and atm_transactions.transaction_type = "withdraw"
    and atm_transactions.atm_location = "Leggett Street";