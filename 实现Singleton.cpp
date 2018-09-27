/*不好的解法一：只适用于单线程环境*/
/*由于要求只能生成个一个实例，因此我们必须把构造函数设为私有函数以禁止他人创建实例。我们可以定义有一个静态的实例，在
需要的时候创建该实例。下面定义类型Singleton1就是基于这个思路的实现：*/
public sealed class Singleton1
{
	private Singleton1(){}
	private static Singleton1 instance=null;
	public static Singleton1 Instance
	{
		get
		{
			if(instance==null)
			{
				instance=new Singleton1();
			}
			return instance;
		}
	}
}

/*上述代码在Singleton1的静态属性Instance中，只有在instance为null的时候才创建一个实例以避免重复创建。同时我们把
构造函数设置为私有函数，这样就能够确保只创建一个实例*/

/*不好的解法二：虽然在多线程环境中能工作，但效率不高*/
/*解法一中的代码在单线程的时候工作正常，但在多线程的情况下就有问题了。设想如果有两个线程同时运行到判断instance是否
为null的if语句，并且instance的确没有创建时，那么两个线程都会创建一个实例，此时类型Singleton1就不再满足单例模型的要求
了。为了保证在多线程环境下我们还是只能得到类型的一个实例，需要加上一个同步锁。把Singleton1稍作修改得到了如下代码*/

public sealed class Singleton2
{
	private Singleton2(){}
	private static readonly object syncObj=new object();
	public static Singleton2 Instance
	{
		get
		{
			lock(syncObj)
			{
				if(instance==null)
				{
					instance=new Singleton2();
				}
			}
			return instance;
		}
	}
}

/*我们还是假设有两个线程同时想创建一个实例。由于在一个时刻只有一个线程能得到同步锁，当第一个线程加上锁时，第二个线程
只能等待。但第一个线程发现实例还没有创建时，它创建一个实例。接着第一个线程释放同步锁，此时第二个线程可以加上同步锁，
并运行接下来的代码。这时候由于实例已经被第一个线程创建出来了，第二个线程就不会重复创建实例了，这样就保证了我们在多线
程环境中也只能得到一个实例。
但是类型Singleton2还不是很完美。我们每次通过属性Instance 得到Singleton2的实例，都会试图加上一个同步锁，而加锁是一个
非常耗时的操作，在没有必要的时候我们应该尽量避免。*/

/*可行的解法：加同步锁前后两次判断实例是否已经存在*/
/*我们只是在实例还没有创建之前需要加锁操作，以保证只有一个线程创建出实例。而当实例已经创建之后，我们已经不再需要执行
加锁操作了。于是我们可以把解决二中的代码再做进一步的改进：*/
public sealed class Singleton3
{
	private Singleton3(){}
	
	private static object syncObj=new object();
	
	private static Singleton3 instance=null;
	
	public static Singleton3 Instance
	{
		get
		{
			if(instance==null)
			{
				lock(syncObj)
				{
					if(instance==null)
					{
						instance=new Singleton3();
					}
				}
			}
			return instance;
		}
	}
}
/*Singleton3中只有当instance为null即没有创建时，需要加锁操作。当instance已经创建出来之后，则无需加锁。因为只有在
第一次的时候instance为null，因此只有在第一次试图创建实例的时候需要加锁。这样Singleton3的时候效率比Singleton2要多
很多
Singleton3用加锁机制来确保在多线程环境下只创建一个实例，并且用两个if判断来提高效率。这样的代码实现起来比较复杂，
容易出错，我们还有更加优秀的解法。*/

/*强烈推荐的解法一：利用静态构造函数*/
/*C#的语法中有一个函数能够确保只调用一次，那就是静态构造函数，我们可以利用C#的这个特征实现单例模型。*/
public sealed class Singleton4
{
	private Singleton4()
	{}
	private static Singleton4 instance=new Singleton4();
	public static Singleton4 Instance
	{
		get
		{
			return instance;
		}
	}
}
/*Singleton4的实现代码非常简洁。我们在初始化静态变量instance的时候创建一个实例。由于C#是在调用静态构造函数时初始化
静态变量，.NET运行时能够确保只调用一次静态构造函数，这样我们就能够保证只初始化一个instance。
C#中调用静态构造函数的时机不是有程序员掌控的，而是当.NET运行时发现第一次使用一个类型的时候自动调用该类型的静态构造
函数。因此在Singleton4中，实例instance并不是在第一次调用属性Singleton4.Instance的时候被创建的，而是在第一次用到
Singleton4的时候就会被创建。假设我们在Singleton4中添加一个静态方法，调用该静态函数是不需要创建一个实例的，但如果
按照Singleton4的方式实现单例模式，则仍然会过早地创建实例，从而降低内存的使用效率。*/

/*强烈推荐的解法三：实现按需创建实例*/
/*最后一个实现Singleton5则很好地解决了Singleton4中的实例创建时机过早的问题。*/
public sealed class Singleton5
{
	Singleton5()
	{}
	
	public static Singleton5 Instance
	{
		get
		{
			return Nested instance;
		}
	}
	class Nested
	{
		static Nested()
		{}
		internal static readonly Singleton5 instance=new Singleton5();
	}
}

/*在上述Singleton5的代码中，我们在内部定义了私有类型Nested。当第一次用到这个嵌套类型的时候，会调用静态构造函数创建
Singleton5的实例instance。类型Nested只在属性Singleton5.Instance中被用到，由于其私有属性，他人无法使用Nested类型。
因此，当我们第一次试图通过属性Singleton5.Instance得到Singleton5的实例时，会自动调用Nested的静态构造函数创建实例
instance。如果我们不调用属性Singleton.Instance，就不会触发.NET运行调用Nested，也不会创建实例，这样就不会真正做到
了按需创建*/

/*解法比较：
在前面的5种实现单例模型的方法中，第一种方法在多线程环境中不能工作，第二种模式虽然能在多线程环境中正常工作，
但时间效率很低，都不是面试官期待的解法。第三种方法中，我们通过两次判断一次加锁确保在多线程环境中能高效地工作。
第四种方法利用C#的静态构造函数的特征，确保只创建一个实例。第五种方法利用私有嵌套类型的特征，做到只有在真正需要
的时候才会创建实例，提高空间使用效率。如果在面试中给出第四种或者第五种解法，则毫无疑问会得到面试官的青睐。*/