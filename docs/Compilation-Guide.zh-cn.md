# 编译指南

本指南旨在解决各位的编译问题，如果需要自行编译并运行的话，请按照以下步骤进行操作。

本指南假设各位使用Arduino IDE进行编译，若不使用Arduino IDE，则无需理会本指南。

## 准备工作

1. 安装Arduino IDE，并安装对应开发版的开发工具，本指南以ESP32C3为例。

    1. [Arduino IDE下载地址](https://www.arduino.cc/en/software)，下载并安装它。（如果你位于中国大陆地区，连接太慢的话，可以使用[镜像站](https://arduino.me/download)下载）
    1. 启动 Arduino 应用程序，将 ESP32 板包添加到 Arduino IDE。
        1. 在 Arduino IDE 的工具栏中，选择“文件”>“首选项”（`File` > `Preferences`），然后使用以下 url 填写 “其他开发板管理器地址”（ `Additional Boards Manager URL` ）：[https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)
        ![导入开发板管理器源](/docs/imgs/2.png)
        1. 在 Arduino IDE 的工具栏中，导航到“工具”>“开发板”>“开发板管理器…”（`Tools` > `Board` > `Boards Manager...`） ，在搜索框中输入关键字 `esp32` ，选择最新版本的 `esp32` 并安装它。
        ![安装开发板](/docs/imgs/3.png)
    1. 安装好开发工具后，重启 Arduino IDE。

1. 安装库文件。

    1. 安装 `FastLED` 库。
        在 Arduino IDE 的工具栏中，导航到“工具”>“库管理器…”（`Tools` > `Library Manager...`），搜索 `FastLED` ，然后安装它。
        ![安装FastLED库](/docs/imgs/4.png)
    1. 安装 `PN532` 库。
        1. 前往[我的PN532库分支](https://github.com/tatanakots/PN532)，选择`code`>`download zip`，下载压缩包。
        ![下载PN532库](/docs/imgs/5.png)
        1. 在 Arduino IDE 的工具栏中，导航到“项目”>“导入库”>“添加.ZIP库...”，将刚刚下载的 zip 文件导入到 Arduino IDE 中。
        ![导入PN532库](/docs/imgs/6.png)

## 配置编译参数

如果你的硬件在 [README.md](/README.md) 中的表格上有写“使用CDC”，那么你需要开启“USB CDC on Boot”选项，否则无法正常使用串口通讯。
![USB CDC on Boot](/docs/imgs/1.png)

然后请按照硬件配置开发板参数。

## 开始编译

在Arduino IDE中，编译有两种方法，即编译并烧录和编译并导出，按照自己喜欢的方法编译即可。

### 编译并烧录

选择编译并烧录的话，需要在编译之前插入你的硬件，并且将硬件置于烧录模式。

> `ESP32C3` 进入烧录模式有两种方法：
> 1. 按住BOOT上电。
> 2. 按住ESP32C3的BOOT按键，然后按下RESET按键，松开RESET按键，再松开BOOT按键。

插入硬件后，只需要按下Arduino IDE的“上传”（ `Upload` ）按钮即可。
![编译并烧录](/docs/imgs/7.png)

### 编译并导出

选择编译并导出的话，不需要硬件也可以编译，但是需要在之后手动进行烧录。

在 Arduino IDE 的工具栏中，导航到“项目”>“导出已编译的二进制文件”即可。
![编译并导出](/docs/imgs/8.png)
然后你就可以在项目的 `build` 目录下看到编译好的二进制文件包 `.bin` 了。