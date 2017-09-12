#!/usr/bin/perl -w
use Tk;
my $mw = MainWindow->new;
$mw->Button(-text => "你好！", -command =>sub{exit})->pack;
MainLoop;
