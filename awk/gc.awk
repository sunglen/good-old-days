#!/bin/awk -f
#gc.awk: 按时间输出 .lrc 格式的歌词。
#算法：
#对每一行：
#	保存“时间-歌词”到关联数组；
#END:
#对每一秒：
#	确定真实流逝时间计数器的值；
#	比较该值与关联数组索引是否相同
#		若相同，输出对应歌词；
#
#核心问题：选择数据结构

BEGIN { FS="]"; inittime=systime() }

/\[[0-9][0-9]:[0-9][0-9]\]/ { for(i=1; i<NF; i++){
	gsub("[\[\{]","",$i)
	#将显示时间换算为秒
	echotime=gensub(":[0-9][0-9]", "", g, $i)*60+gensub("[0-9][0-9]:", "", g, $i)
	statetab[echotime]=$NF
	#获得时间最大值
	if(echotime>maxtime)
		maxtime=echotime
	}	
}

END { 
	for(time=0; time<=maxtime; time++){
		realtime=(systime()-inittime)
		if(statetab[realtime]!="")
			print statetab[realtime]
		system("sleep 1")
	}	
}
