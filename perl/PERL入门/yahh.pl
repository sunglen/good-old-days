#!/usr/bin/perl

open(WOUT,"w|");
$time=<WOUT>;
$time=~s/^ *//;
$time=~s/ .*//;
$waste=<WOUT>;
@users=<WOUT>;
close(WOUT);
foreach $user (@users)
{
        $user=~s/ .*//;
}
print("现在时刻: $time");
print("现在登录的用户有:\n");
foreach $user (sort @users)
{
        if($user ne $last)
        {
          print("\t$user");
        }
        $last=$user;
}
