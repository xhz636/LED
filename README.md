# LED
LED点阵屏显示驱动<br>
使用设备：<br>
1.Arduino Uno R3开发板<br>
2.HUB-08接口的16*64LED点阵显示屏<br>
3.MicroSD Card Adapter模块<br>
4.microSD卡：SanDisk 8GB class4<br>
5.德飞莱LY-BL001 v2.0蓝牙模块<br>
microSD卡内包含内容在Files_in_microSD文件夹内：<br>
LED/ASCII:8*12点阵英文字库<br>
LED/HZK16:16*16点阵GB2312汉字库<br>
正式版实现以下功能：<br>
1.开机界面为“欢迎使用”<br>
2.实现蓝牙输入，最大输入为30byte<br>
3.12*8英文和16*16汉字显示<br>
4.输入不足8byte自动居中，超过8byte则滚动显示<br>
5.蓝牙可传输命令，命令以.字符开头，可用命令包括：<br>
a)stop：停止滚动<br>
b)start：开始滚动<br>
c)slow：慢速滚动<br>
d)fast：快速滚动<br>
e)close：关闭显示<br>
f)open：开启显示