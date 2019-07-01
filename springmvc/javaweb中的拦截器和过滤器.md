
## javaweb中的过滤器和拦截器
_filter&interceptor_

#### Filter
filter是Servlet的API中提供的Filter接口，在开发中可以自定义Filter接口的实现类，开发者可以通过编写代码，在请求到达某个资源之间进行拦截，进行预处理，比如可以拦截请求校验Cookie，允许部分资源被请求，或者记录请求执行时间；以及设置编码等操作。__filter依赖Servlet，而interceptor依赖于框架__

在Filter中，可以通过filterChain.doFilter(..)来执行请求

开发者需要编写实现类，实现Filter接口，重写必要的方法，在纯servlet的开发中，需要在web.xml中注册实现类，而在依赖框架中，可以通过添加注解等方式来注册实现类。

Filter基于函数回调


#### Interceptor
interceptor依赖于框架，底层实现为AOP，用于方法级别的拦截，在一次http请求中，位于filter流程之后。interceptor主要思想是AOP，关注点在于切点，也就是方法，开发者可以定义一个方法执行前后的代码，比如统计执行时间，记录日志，拦截特定方法等操作。

interceptor基于java的反射机制