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
        + (OutputColorConfig)outColor: 用于配置控制台字体颜色
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
    + #### Private Member
        + ##### Functions
            + (bool)input():用于录入有效的人脸信息
            + (bool)remove():用于删除无效的人脸信息
            + (bool)clear(int&):用于清空人脸信息库
            + (bool)print():用于打印人脸信息库中的所有信息
        + ##### Variables
            + (enum)opNameEnum: 枚举类型，用于操作选择
            + (vectof<int>)faceIdList: 利用向量存储人脸信息
            + (OutputColorConfig)outColor: 用于配置控制台字体颜色
+ CardManager
    #### 其功能与FaceManager相同，只是某些变量名与输出不同，此处不细表
+ OutputColorConfig
    + #### Class Introduction
        OutputColorConfig是为了丰富命令行的输出效果，而创建的输出配置类
    + #### Public Member
        + ##### Functions
            + ###### void print(string, ColorEnum)
                该函数可被调用，可根据调用时的传入参数ColorEnum中定义的颜色对传入的字符串进行输出
        + ##### Variables
            + ###### (enum)ColorEnum 
                定义了```WHITE RED GREEN```三种颜色，可在调用print函数时，作为传入参数，配置输出颜色
    + #### Private Member Function
        + ##### void setForeGround(ColorEnum)
            可根据输入的颜色，更改命令行字体颜色，在print函数中调用
+ Simulate
    + #### Class Introduction 
        用于在信息录入完毕后，根据输入的信息，进行模拟并输出模拟结果，
    + #### Public Member Functions
        + ##### void doSimulate(InOutInfo, FaceManager, CardManager)
            该函数实现了模拟输出的功能，根据时间顺序，利用faceManager中的人脸信息判断是否能够刷脸，利用cardManager中的身份卡信息判断是否能够刷卡。
    + #### Private Member Variables
        + ##### (string)teacher
        + ##### (string)student
            两个变量用于确定当前要进出系楼的人的身份，判断是否采取刷脸的方式
        + ##### (OutputColorConfig)outColor
            用于配置控制台字体颜色