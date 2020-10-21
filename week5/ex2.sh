touch f.txt
while true
do
    if ln f.txt f.lock
    then
        n=$(tail -n 1 f.txt)
        echo $(($n + 1))>>f.txt
        rm f.lock
    fi
done

#Before modifying:
#touch f.txt
#while true
#do
#    n=$(tail -n 1 f.txt)
#    echo $(($n + 1))>>f.txt
#done

#A race condition occurs when two processes
#try to write and read the same numbers from
#the same file at the same time. At this time,
#we can see two identical recorded numbers.
#The critical region is the part of the program
#where we read and write from the file.


