#!/bin/bash
# **********************************************************
# * Author        : Shaco
# * Create time   : 2022-02-10 09:24
# * Last modified : 2022-02-10 09:24
# * Filename      : clear.sh
# * Description   : 
# **********************************************************

#进到每个目录内,查找有没有build文件夹,有就删除,然后等待输入commit信息,然后上传

DIR=$(pwd)

function readDir()
{
	for file in `ls $DIR`
	do
		if [ -d $DIR"/"$file ]
		then
			echo "Judge dir:"$file
			if [ -d $DIR"/"$file"/build" ]
			then
				echo $file "Had build dir!"
				#删除这个文件夹
				`/bin/rm $DIR"/"$file"/build" -rf`
			fi
		fi
	done
}

git pull
wait
readDir
wait
read -p "Please input commit Info:" commit_info
wait
echo $commit_info
wait
git add $DIR
wait
git commit -m "$commit_info"
wait
git push
wait

