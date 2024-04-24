
app:split_yuv.c
	gcc -o app split_yuv.c

.PHONY:clean
clean:
	rm -rf app out
# rm -rf 请谨慎使用，避免误删除重要文件
