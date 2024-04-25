Logic：逻辑部分

MApp：qt展示相关

config：配置项

# 基本逻辑

logic部分负责读写，读到的数据传递到mapp，mapp上用户修改的数据传给logic写入data。

## logic

采用组件形式，组件由manager管理

## mapp

qt显示、控件重写

# 模块

## 目录模块

目录记录了每本书的编号（唯一，由manager分配）、名字、地址（每本书一个文件夹）
