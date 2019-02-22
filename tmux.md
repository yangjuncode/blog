# tmux  使用记录

### 共享使用
```shell
tmux -S /tmp/bfdx
chmod 777 /tmp/bfdx
```



### 共享进入

```shell
tmux -S /tmp/bfdx attach
```

### 保存当前的显示到文件

进入tmux后
像vim一样进入命令行

```
ctrl+b  
:
```

tmux 命令行下复制当前的显示到缓冲

```shell
capture-pane -S -<line number you want to dump>
capture-pane -S -100000
```

tmux 命令行下,保存缓冲到文件

```shell
save-buffer <filepath>
```

