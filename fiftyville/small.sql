select * from people
    inner join bank_accounts on bank_accounts.person_id = people.id
    inner join atm_transactions on bank_accounts.account_number = atm_transactions.account_number
    where year = 2021
    and month = 7
    and day = 28
    and atm_transactions.transaction_type = "withdraw"
    and atm_transactions.atm_location = "Leggett Street";