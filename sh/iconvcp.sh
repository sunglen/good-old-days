#!/bin/bash
#like cp -r, copy old file tree to new one.
#better than cp, this tool can convert filename
#or path which contains gb2312/gbk characters to
#utf-8 encoding as well as convert the content of
#gb2312/gbk files to utf-8 encoding.

case $# in
  1) SRC_DIR=$1; DEST_DIR=utf8 ;;
  2) SRC_DIR=$1; DEST_DIR=$2 ;;
  *) echo 'Usage: iconvcp.sh src_dir [dest_dir]' 1>&2 ; exit 1 ;;
esac

#exclude *~, *.swp, *.H and *,v files
for i in `find "$SRC_DIR" -regex '\(.*~$\|.*\.swp$\|.*\.H$\|.*,v$\)' -o -print`
do
  p=`echo "$i" | iconv -f gbk -t utf8`
  if [ -d "$i" ]
  then
    echo "mkdir -p $DEST_DIR/$p"
    mkdir -p "$DEST_DIR/$p"
  elif [ -f "$i" ]
  then
    echo "iconv -c -f gbk -t utf8" "$i" "-o" "$DEST_DIR/$p"
    iconv -c -f gbk -t utf8 "$i" -o "$DEST_DIR/$p"
  else
    echo omit "$p"
  fi
done
