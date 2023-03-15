# **8-1 Roll Your Own Mini Search Engine**

### Description:

In this project, you are supposed to create your own mini search engine which can handle inquiries over “The Complete Works of William Shakespeare” (http://shakespeare.mit.edu/).

You may download the functions for handling stop words and stemming from the Internet, as long as you add the source in your reference list.

Your tasks are:

- (1) Run a word count over the Shakespeare set and try to identify the stop words (also called the **noisy** words) – How and where do you draw the line between “interesting” and “noisy” words?
- (2) Create your inverted index over the Shakespeare set with word stemming. The stop words identified in part (1) must not be included.
- (3) Write a query program on top of your inverted file index, which will accept a user-specified word (or phrase) and return the IDs of the documents that contain that word.
- (4) Run tests to show how the thresholds on query may affect the results.

### Grading Policy:

**Programming:** Write the programs for word counting (1 pt.), index generation (5 pts.) and query processing (3 pts.) with sufficient comments.

**Testing:** Design tests for the correctness of the inverted index (2 pts.) and thresholding for query (2 pts.). Write analysis and comments (3 pts.). **Bonus: What if you have 500 000 files and 400 000 000 distinct words? Will your program still work? (+2 pts.)**

**Documentation:** Chapter 1 (1 pt.), Chapter 2 (2 pts.), and finally a complete report (1 point for overall style of documentation).

**Note:** Anyone who does excellent job on answering the Bonus question will gain extra points.



---



# **8-1制作自己的迷你搜索引擎**

### 描述:

在这个项目中，你应该创建自己的迷你搜索引擎，可以处理对《[威廉·莎士比亚全集](http://shakespeare.mit.edu/)》的查询。

你可以下载处理停止词stop words和词干stemming的函数，只要你在你的参考列表中添加源代码。

你的任务是:

1. 对莎士比亚的单词集进行单词计数，并试着识别停顿词stop words(也被称为**嘈杂的**词) - 你如何以及在哪里在“有趣的”和“嘈杂的”单词之间划清界限?

2. 创建你的倒索引inverted file indexing莎士比亚集词干。第(1)部分识别的停止词不得包括在内。
3. 在反向文件索引上编写一个查询程序，该程序将接受用户指定的单词(或短语)，并返回包含该单词的文档的id。
4. 运行测试，以显示查询的阈值如何影响结果。

### 评分策略:

**编程: **编写单词计数(1分)，索引生成(5分)和查询处理(3分)的程序，并提供足够的注释。

**测试:** 设计测试倒排索引(2分)和查询阈值(2分)的正确性。写分析和评论(3分)。**奖励:如果你有50万个文件和40亿个不同的单词怎么办?你的程序还能工作吗?(+ 2分)* *

**文档: **第一章(1分)，第二章(2分)，最后是一份完整的报告(1分是文档的整体风格)。

**注:**任何在奖金问题上表现出色的人将获得额外的分数。
