### 技术交流QQ群:1027579432，欢迎你的加入！
#### 1.从封建角度变化对23种设计模式分类
- 组件协作：Template Method、Strategy、Observer/Event
- 单一职责：Decorator、Bridge
- 对象创建：Factory Method、Abstract Factory、Prototype、Builder
- 对象性能：Singleton、Flyweight
- 接口隔离：Facade、Proxy、Mediator、Adapter
- 状态变化：Memento、State
- 数据结构：Composite、Iterator、Chain of、Responsibility
- 行为变化：Command、Visitor
- 领域问题：Interpreter
#### 2.重构获得模式 Refactoring to Patterns
- 面向对象设计模式是“好的面向对象设计”，所谓好的面向对象设计指的是那些可以满足“应对变化，提高复用”的设计。
- 现代软件设计的特点是“需求的频繁变化”。设计模式的要点是“寻找变化点，然后在变化点处应用设计模式。从而来更好的应对需求的变化”，“什么时候、什么地点应用设计模式”比“理解设计模式代码结构本身”更加重要。
- 设计模式的应用不宜先入为主，一上来就使用设计模式对设计模式的最大误用。没有一步到位的设计模式。敏捷软件开发实践所提倡的"Refactoring to Patterns"是目前普遍公认的最好的使用设计模式的方法。
#### 3.代码重构的关键方法
- 静态 → 动态
- 早绑定 → 晚绑定
- 继承 → 组合
- 编译时依赖 → 运行时依赖
- 紧耦合 → 松耦合
#### 4.组件协作模式
- 现代软件专业化分工之后的第一个结果是“框架与应用程序的划分”，“组件协作”模式通过晚绑定来实现框架与应用程序之间的松耦合，是二者之间协作时常用的模式。
- 典型代表模式：
    - Template Method
    - Strategy
    - Observe/Event
#### 5.Template Method模式的动机
- 在软件构建过程中，对于某一项任务，它常常有**稳定的**整体操作结构，但各个子步骤却有很多**改变的**需求，或者由于固有的原因（比如框架与应用程序之间的关系）而无法和任务的整体结构同时实现。
- 如何在确定**稳定操作**结构的前提下，来灵活应对各个子步骤的**变化或者晚期实现**需求？
- Template Method模式定义：定义一个操作中的算法骨架(**稳定**)，而将一些步骤延迟(**变化**)到子类中。Template Method模式使得子类可以不改变(**复用**)一个算法的结构即可重定义(**override重写**)该算法的某些特定步骤。
![Template Method模式示例程序UML类图，红色方框部分表示稳定的，蓝色方框部分表示变化的.png](https://upload-images.jianshu.io/upload_images/13407176-4012e5acc046a68b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
#### 6.Template Method模式总结
- Template Method模式是一种**非常基础性的**设计模式，在面向对象系统中有着大量的应用。它用最简洁的机制(**虚函数的多态性**)为很多应用程序框架提供了**灵活的扩展点**，是代码复用方面的基本实现结构。
- 除了可以灵活应对子步骤的变化外，“不要调用我，让我来调用你”的反向控制结构是Template Method模式的典型应用。
- 在具体实现方面，被Template Method模式调用的虚方法可以具体实现，也可以没有任何具体实现(如抽象方法，纯虚方法)，但一般推荐将它们设置为protected方法。
#### 7.资料下载
- [笔记，欢迎star,follow,fork......](https://github.com/cdlwhm1217096231/cpp_ws/tree/master/C%2B%2B%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F)