#!/usr/bin/expect -- 
set CTRLA \001 
set CTRLC \037 
set CTRLZ \032 
set CTRLK \013 
set CTRLO \017 
set CTRLP \020 
set CTRLX \028 
set postbuffer "" 
set POSTFILE "./postfile" 
set TITLE "POST BY EXPECT" 
set BOARD "test" 
set USERNAME "guest" 
set PASSWORD "password" 
set debug_flag 1 
if $argc==0 { 
    send_user "Too few argument\nUSAGE:\n\tbbs POST_FILE_NAME BOARD TITTLE\n\n" 
    exit 
} 
if $argc==1 { 
    send_user "Too few argument\nUSAGE:\n\tbbs POST_FILE_NAME BOARD TITTLE\n\n"  
    exit 
} 
if $argc==2 { 
    send_user "Too few argument\nUSAGE:\n\tbbs POST_FILE_NAME BOARD TITTLE\n\n"  
    exit 
} 
if $argc>3 { 
    send_user "Too many argument\nUSAGE:\n\tbbs POST_FILE_NAME BOARD TITTLE\n\n"  
    exit 
} 
set POSTFILE [lindex $argv 0] 
set BOARD [lindex $argv 1] 
set TITLE [lindex $argv 2] 
if [file exists $POSTFILE] { 
send_user "Start autoposting file..." 
} else { 
send_user "Not find file $POSTFILE !!!\n 
" 
exit 
} 
proc readfile {} { 
global POSTFILE postbuffer 
if [catch {open $POSTFILE} fp] return 
say "reading post file" 
set line 0 
while {[gets $fp postbuffer]!=-1} { 
send " $postbuffer\r" 

incr line 
} 
close $fp 
say "I have success posted $line line " 
} 
proc say {msg} { 
global debug_flag 
if !$debug_flag return 
if [catch {puts "parent: $msg"}] { 
send_log "child: $msg\n" 
} 
} 
spawn /usr/bin/telnet 202.112.58.200 
expect "login" 
send "bbs\r" 

expect "new):" 
send "$USERNAME\r" 

expect "请输入密码:" 
send "$PASSWORD\rq\r\reqqb\r\/$BOARD\r\r" 

expect "刊 登 者" 
send "$CTRLP" 

expect "标题:" 
send "$TITLE\r" 

expect "设定:" 
send "\r" 

expect "时间" 
readfile 
sleep 24 

expect "Ctrl-Z" 
send "$CTRLX" 

expect "编辑" 
send "\r" 

expect "转信" 
sleep 1 
send "\r\r" 
sleep 1 
send "eeg\r\r\r" 
sleep 1 
send "exit\r" 
sleep 1 
close 
send_user "\r\r\r\rPosting file completed.\r\r\r" 
