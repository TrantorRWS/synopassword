Source : https://wrgms.com/synologys-secret-telnet-password/
Original developper : Gui Ambros

Basically Synology hardcoded a modified login binary within the firmware that accepts an obfuscated password for root, which depends on the current date. 

Compile and run the code in the .c file with gcc

Here's the algorithm:

    1st character = month in hexadecimal, lower case (1=Jan, ... , a=Oct, b=Nov, c=Dec)
    2-3 = month in decimal, zero padded and starting in 1 (01, 02, 03, ..., 11, 12)
    4 = dash
    5-6 = day of the month in hex (01, 02 .., 0A, .., 1F)
    7-8 = greatest common divisor between month and day, zero padded. This is always a number between 01 and 12.

So, let's say today is October 15, the password would be: a10-0f05 where a = month in hex, 10 = month in decimal, 0f = day in hex, 05 = greatest divisor between 10 and 15).
