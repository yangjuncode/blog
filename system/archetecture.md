- etcd 用来存储配置信息，系统的相关参数都在里面，需要权限管理
    - 端口监听配置信息
    - 后台服务地址
    - https 证书
    - 数据库连接配置
    - 测试配置信息
    - 用户系统的配置信息备份
- 数据库
    - 一般用postgresql,pg 12
    - 时序数据库用clickhouse,或者  pg12 +timescaledb，或者pg12+表分区
    - 真的大系统，可考虑tidb,目前没有实验
- 文件存储
    - 小文件 seweedfs, 录音文件，图片
    - groupcache可用作为热门文件缓存
- 消息总线
    - 不存盘 nats server 2.0
    - 如果消息需要存盘(一定不丢失)，考虑 pulsar
- 硬件接口配置
    - 串口配置，相对麻烦,需要连接串口
    - 硬件嵌入webserver网页配置，需要连接网线/wifi
    - 硬件udp组播配置，需要连接网线/wifi
    - 后台+网页webusb，需要连接usb



# 系统模块

- 配置管理
- log,trace系统
- 文件存储
- 定时任务管理
- grpc网关
- 部署系统