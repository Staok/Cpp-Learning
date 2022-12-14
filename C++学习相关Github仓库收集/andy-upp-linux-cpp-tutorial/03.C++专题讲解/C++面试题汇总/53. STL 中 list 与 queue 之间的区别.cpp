//https://blog.csdn.net/gogokongyin/article/details/51178378

/*
	1) list 不再能够像 vector 一样以普通指针作为迭代器，因为其节点不保证在存储空间中 
	    连续存在； 
	2) list 插入操作和结合操作都不会造成原有的 list 迭代器失效; 
	3) list 不仅是一个双向链表，而且还是一个环状双向链表，所以它只需要一个指针； 
	4) list 不像 vector 那样有可能在空间不足时做重新配置、数据移动的操作，所以插入前 
	   的所有迭代器在插入操作之后都仍然有效； 
	5) deque 是一种双向开口的连续线性空间，所谓双向开口，意思是可以在头尾两端分别做 
	元素的插入和删除操作；
	6) deque 和 vector 最大的差异，一在于 deque 允许常数时间内对起头端进行元素的插入 
	或移除操作，二在于 deque 没有所谓容量概念，因为它是动态地以分段连续空间组合而 
    成，随时可以增加一段新的空间并链接起来，deque 没有所谓的空间保留功能。
*/