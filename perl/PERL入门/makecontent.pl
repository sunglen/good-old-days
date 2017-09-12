#!/usr/bin/perl
open(INDEX,">>index.html")||die "对不起,不能打开index.html\n";
for($i=0;$i<($number=@ARGV);$i++)
{
   if($ARGV[$i]=~/.+\.(htm|html)$/i)
   {
     $index_list[$j]=$ARGV[$i];
     $j++;
   }
}

for($i=0;$i<$j;$i++)
{
   open(HTML_FILE,"$index_list[$i]");
   while(<HTML_FILE>)
   {
      if(/<title>(.*)<\/title>/i)
         {
            $title[$i]=$1;
         }
   }
}
for($i=0;$i<$j;$i++)
{
   $show_list[$i]="<LI><A HREF=\"$index_list[$i]\">$title[$i]</A></LI>\n";
}

select(INDEX);
$~="HTML_INDEX_FIRST";
write;

print @show_list;

$~="HTML_INDEX_LAST";
write;
#over

format HTML_INDEX_FIRST=
<HTML> 
<HEAD><TITLE>Index created by sunge</TITLE><style type="text/css"> 
<!-- 
a:link {  font-family: "仿宋_GB2312"; font-size: 14pt; font-style: normal; line-height: normal; text-decoration: none} 
a:hover {  font-family: "仿宋_GB2312"; font-size: 14pt; font-style: normal; line-height: normal; color: #66FFFF; text-decoration: none} 
a:visited {  font-family: "仿宋_GB2312"; font-size: 14pt; font-style: normal; line-height: normal; color: #33FF33; text-decoration: none} 
--> 
</style></HEAD> 
<BODY> 
<h1> <font face="仿宋_GB2312" color="#FF66FF">这是网页教程的索引。</font></h1> 
<hr> 
<UL>
.

format HTML_INDEX_LAST=
</UL>
<HR>
<FONT SIZE=-2 FACE="Arial, Helvetica">索引制作:  <A HREF="mailto:sunge@363.net">孙舸</A></FONT>
"@"
</BODY>
</HTML>
.
