# 机器学习  
## Tree分类回归树
### 离散分类树
1. 特征选择：信息增益、信息增益比、基尼指数
2. 决策树的生成：递归生成 ID3(信息增益)、C4.5(信息增益比)、CART(基尼指数)
3. 剪枝：决策树学习的损失函数 $C_{\alpha}(T) = \\sum_{t=1}^{|T|}N_tH_t(T)+\alpha|T|$ ,其中$|T|$是叶子节点数，$N_t$是该叶子节点的样本数，$H_t$是熵.
对每个叶子节点递归操作，直到不能继续为止.
- 对连续特征使用二分法化成离散特征.
- CART回归树  
选取某个特征$x_j$及其切分点s，将样本二分，求解$min_{j,s}$.

## svm支撑向量机
balabala.

## LR逻辑斯蒂回归
- 二分类  
$P(Y=1|x)=\frac{e^{w\cdot x}}{1+e^{w\cdot x}}$  
$P(Y=0|x)=\frac{1}{1+e^{w\cdot x}}$
- 多分类
$P(Y=k|x)=\frac{e^{w_k \cdot x}}{1+\sum_{k=1}^{K} e^{w_k \cdot x}}, k=1,2,\cdots,K-1$  
$P(Y=K|x)=\frac{1}{1+\sum_{k=1}^{K} e^{w_k \cdot x}}$  
其中$x \in \mathrm{R}^{n+1},w_k \in \mathrm{R}^{n+1}.$
- 使用似然函数求解参数w  
$L(w)=\prod_{i=1}^N P(Y=1|x)^{y_i} P(Y=0|x)^{1-y_i}$  
对数似然函数 $LL(w)=log(L(w)).$  
对w求导可得w的估计值.

## Adaboost
GBDT算法.

# 数据结构
## 排序
balabala.

