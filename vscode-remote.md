# vscode remote 开发记录

vscode  1.35已经正式支持remote 开发,以前尝试vscode不多,不过刚好有个硬件的项目是工具安装在一台远程机器上,这回来特别试了下,感觉还是很强大的,真正地remote,比clion的感觉还舒服,代码提示OK,clion从cmake项目中找的include dir还是有问题,导致无法自动完成和语法老是出错提示,基本用不了.



- ssh 远程到机器上,vscode只支持证书登录,这个需要配置下,也不难,也可以用container的方式
- vscode连接上远程机器后,需要继续在远程窗口安装相应的插件,否则只是一个文本编辑器,它只提示本地已经安装过的,所以要先在本地安装,目前用到 cmake,cmake-tools,c/c++,cmake-tools helper,git相关的几个插件
- 打开相应的工程,cmake-tools会有相应的提示,基本点Ok即可,如果用container的方式,因为没有执行bashrc,cmake tools可能找不到工具链,需要自己配置一下, F1 命令行下 *Edit CMake Kits*,根据格式自己添加一个就ok



