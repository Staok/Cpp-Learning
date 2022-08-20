$(CC) = gcc
.PHONY:clean
all:hello test
hello :hello.c
	$(CC) -o $@ $<
test :hello.c
	$(CC) -o $@ $<
clean:
	rm hello

//为了解决问题，我们将目标clean定义成伪目标。也就是添加：.PHONY:clean
//当一个目标被声明为伪目标后，make在执行规则时不会去试图去查找隐含规则来创建它。
//这样就提高了make的执行效率，也不用担心由于目标和文件名重名了