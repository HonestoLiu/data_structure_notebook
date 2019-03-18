# 机器学习  

## 感知器
二分类的线性模型：$f(x)=sign(w \cdot x+b)$,策略是极小化损失函数：$min_{w,b} L(w,b)=-\sum_{x_i \in M}y_i (w_i \cdot x_i+b)$，M是误分类样本集合，通常采用随机梯度下降法求解.

## k近邻
多数表决分类策略
$$for (x,y),$y=argmax_{c_j}\sum_{x_i \in N_k(x)} I(y_i=c_j)$$

## 朴素贝叶斯
朴素贝叶斯是典型的生成学习方法，目标是学习联合概率分布P(X,Y)，进而求得后验概率分布P(Y|X).其基本假设是属性的条件独立性，即$P(X=x|Y=c_k)=\prod_{j=1}^n P(X^{(j)}=x^{(j)}|Y=c_k).$  
$$P(Y|X)=\frac{P(X,Y)}{P(Y)}=\frac{P(Y)P(X|Y)}{\sum_Y P(Y)P(X|Y)}$$ 预测时$y=argmin_{c_k}P(Y=c_k)\prod_{j=1}^n P(X^{(j)}=x^{(j)}|Y=c_k).$  估计类条件概率时，常使用类条件概率估计假设分布的参数，使用拉普拉斯平滑解决概率为0的情形.

## Tree分类回归树
针对离散特征的分类树：
1. 特征选择：信息增益、信息增益比、基尼指数
2. 决策树的生成：递归生成 ID3(信息增益)、C4.5(信息增益比)、CART(基尼指数)
3. 剪枝：决策树学习的损失函数 $C_{\alpha}(T) = \\sum_{t=1}^{|T|}N_tH_t(T)+\alpha|T|$ ,其中$|T|$是叶子节点数，$N_t$是该叶子节点的样本数，$H_t$是熵.
对每个叶子节点递归操作，直到不能继续为止.
- 对连续特征使用二分法化成离散特征.
- CART回归树  
选取某个特征$x_j$及其切分点s，将样本二分，求解$min_{j,s}$.

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
使用梯度下降法或者拟牛顿法求解w.

## svm支撑向量机
- 最基本模型-最大化间隔
$$min_{w,b} \ \ \frac{1}{2}||w||^2$$
$$s.t. \ \ y_i(w^{T}x_i+b) \geq 1,\ i=1,2,\cdots,m.$$
- 对偶问题
$$max_{\alpha} \ \ \sum_{i=1}^m \alpha_i-\frac{1}{2}\sum_i \sum_j \alpha_i \alpha_j y_i y_j x_i^{T}x_j$$
$$s.t. \ \ \sum_i \alpha_i y_i=0,\ \alpha_i \geq 0,\ i=1,2,\cdots,m.$$
高效算法SMO，其思想每次选取$\alpha_i,\alpha_j$并固定其他参数进行优化.
- 核方法
$$max_{\alpha} \ \ \sum_{i=1}^m \alpha_i-\frac{1}{2}\sum_i \sum_j \alpha_i \alpha_j y_i y_j \mathcal{k}(x_i,x_j)$$
$$s.t. \ \ \sum_i \alpha_i y_i=0,\ \alpha_i \geq 0,\ i=1,2,\cdots,m.$$
- 软间隔
替代$\mathcal{l}_{0/1}$损失函数：hinge损失$max{0,1-z}$、指数损失$e^{-z}$、对率损失$log(1+e^{-z})$.
$$max_{\alpha} \ \ \sum_{i=1}^m \alpha_i-\frac{1}{2}\sum_i \sum_j \alpha_i \alpha_j y_i y_j x_i^{T}x_j$$
$$s.t. \ \ \sum_i \alpha_i y_i=0,\ 0 \geq \alpha_i \leq C,\ i=1,2,\cdots,m.$$

## Adaboost
GBDT算法.

# 数据结构
## 排序
balabala.

