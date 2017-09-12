#!/usr/bin/expect
#only a test.
#donwload a file through ftp.
spawn ftp

while {1} {
    expect "ftp>"
    send "o 127.0.0.1\r"
    expect {
	"no connections result" { sleep 10 }
	"refused" { sleep 10 }
	"Connected" { break }
    }
}

expect "Name"
send "anonymous\r" 

expect "Password:"
send "sunge@etang.com\r"

expect "apply"
send "cd /pub\r"

expect "successful"
send "bin\r"

expect "set to I"
send "get ftp.sites\r"

expect "complete"
send "bye\r"
