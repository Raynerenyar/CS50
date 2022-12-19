select * from people
    inner join bank_accounts.account_number = transactions.account_number
    inner join bank_accounts.person_id = people.id
    where year = 2021
    and month = 7
    and day = 28
    and hour = 10;
