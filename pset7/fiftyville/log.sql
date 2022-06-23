-- The following query reveals an important report ID#295.
SELECT * FROM crime_scene_reports
WHERE month = 7
AND day = 28;
-- Theft took place at 10h15. Interviews were conducted with witnesses.

-- The following is to query interviews.
SELECT * FROM interviews
WHERE month = 7
AND day = 28;
-- Interview clue id# 161 footage within 10 minutes of the theft (For thief)
-- Interview clue id# 162 ATM in morning on Leggett Street withdraw money (For thief)
-- Interview clue id# 163 Thief placed call that lasted less than a minute (For thief and accomplice)
-- Interview clue id# 163 Thief book plane for day = 29 earliest (For thief)


-- GET THE NAME OF THE THIEF
SELECT name FROM people
-- Using clue id# 161 from bakery security logs
WHERE license_plate IN
	(SELECT license_plate FROM bakery_security_logs
	WHERE year = 2021
	AND month = 7
	AND day = 28
    -- We know that the thef got into and drove a car within 10 minutes of the theft and the theft occured at 10h15
	AND hour = 10
	AND minute > 15
	AND minute < 25)
-- Using clue id# 162 from the atm withdrawal
AND id IN
	(SELECT person_id FROM atm_transactions
	JOIN bank_accounts
	ON atm_transactions.account_number = bank_accounts.account_number
	WHERE year = 2021
	AND month = 7
	AND day = 28
    -- We know that the thief withdrew money from Legget Street
	AND atm_location = "Leggett Street"
	AND transaction_type = "withdraw")
-- Using clue id# 163
AND phone_number IN
	(SELECT caller FROM phone_calls
	WHERE year = 2021
	AND month = 7
	AND day = 28
    -- We know that the thief placed a call for less than a minute before leaving
	AND duration < 60)
-- Using clue id# 163
AND passport_number IN
	(SELECT passport_number FROM passengers
	JOIN flights ON flights.id = passengers.flight_id
	JOIN airports ON airports.id = flights.origin_airport_id
	WHERE year = 2021
	AND month = 7
	AND day = 29
    -- We know that the thief flew from Fiftyville with the first flight on 29th
	AND airports.city = "Fiftyville"
	AND flight_id IN
        -- Getting the flight number of the first flight on the 29th
		(SELECT flight_id FROM passengers
		JOIN flights ON flights.id = passengers.flight_id
		JOIN airports ON airports.id = flights.origin_airport_id
		WHERE year = 2021
		AND month = 7
		AND day = 29
		AND airports.city = "Fiftyville"
		ORDER BY hour, minute
		LIMIT 1));

-- GET THE NAME OF THE ACCOMPLICE
SELECT name FROM people
WHERE phone_number IN
	(SELECT receiver FROM phone_calls
	JOIN people ON people.phone_number = phone_calls.caller
	WHERE year = 2021
	AND month = 7
	AND day = 28
    -- We know that the accomplice recieved a phone call from bruce just after the theft
	AND duration < 60
	AND name = "Bruce");

-- GET THE NAME OF THE CITY
SELECT city FROM airports
WHERE id IN
	(SELECT destination_airport_id FROM flights
	WHERE id IN
        -- Get the destination city from the first flight info that flew on the 29th
		(SELECT flight_id FROM passengers
		JOIN flights ON flights.id = passengers.flight_id
		JOIN airports ON airports.id = flights.origin_airport_id
		WHERE year = 2021
		AND month = 7
		AND day = 29
		AND airports.city = "Fiftyville"
		ORDER BY hour, minute
		LIMIT 1));