# GateVerify
  
161220131 王志邦  

## Introduce

GateVerify 是一个用于管理门禁系统的模拟程序，其中包含对身份卡、人脸信息以及进出信息的管理，并根据输入的信息，对进出结果进行模拟。

## MyLibs
  
+ GateManager
    + #### Class Introduction
        GateManager 是整个模拟系统的主要部分，在整个模拟系统中，主要功能有：身份卡管理系统、人脸信息管理系统、进出信息管理系统、模拟系统，所以在这个类中，实现了对各个部分的调用。
    + #### Public Member Functions
        + ##### void manage()
            进行各部分系统的调用管理
    + #### Private Member
        + ##### Objects
            +  (OutColor)outColor: 用于配置控制台字体颜色
            + (CardManager)cardManager: 用于身份卡管理
            + (FaceManager)faceManager: 用于人脸信息管理
            + (InOutInfo)inOutInfo: 用于进出信息管理
            + (Simulate)simulate: 用于模拟，并输出结果
            + (enum)opNameEnum: 枚举类型，用于操作选择
+ FaceManager
    + #### Class Introduction
        FaceManager 是人脸信息管理系统，其中提供了管理函数和确认函数。在此类中，可以实现对有效人脸信息的增删查，既方便管理者的信息录入，又方便在使用时的调用
    + #### Public Member Functions
        + ##### void manage()
            进行人脸信息管理系统的管理，提供录入、删除、清空、打印的功能，可对人脸信息库进行管理
        + ##### bool OK(int)
            查询人脸信息库，当传入的人脸存在信息库中时，返回true，否则返回false
+ CardManager
+ OutputColorConfig
+ Simulate