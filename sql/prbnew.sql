USE [tdlte]
GO
/****** Object:  StoredProcedure [dbo].[PRB1]    Script Date: 2018/9/9 14:58:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[PRB1]
AS
declare @i int =0
declare @1 nvarchar(100)
declare @2 FLOAT=1
declare @3 nvarchar(255)
declare @4 nvarchar(255)
declare @5 NVARCHAR(100)
declare @6 float=0
declare @7 float=0
declare @8 float=0
declare @9 float=0
declare @10 float=0
declare @11 float=0
declare @12 float=0
declare @13 float=0
declare @14 float=0
declare @15 float=0
declare @16 float=0
declare @17 float=0
declare @18 float=0
declare @19 float=0
declare @20 float=0
declare @21 float=0
declare @22 float=0
declare @23 float=0
declare @24 float=0
declare @25 float=0
declare @26 float=0
declare @27 float=0
declare @28 float=0
declare @29 float=0
declare @30 float=0
declare @31 float=0
declare @32 float=0
declare @33 float=0
declare @34 float=0
declare @35 float=0
declare @36 float=0
declare @37 float=0
declare @38 float=0
declare @39 float=0
declare @40 float=0
declare @41 float=0
declare @42 float=0
declare @43 float=0
declare @44 float=0
declare @45 float=0
declare @46 float=0
declare @47 float=0
declare @48 float=0
declare @49 float=0
declare @50 float=0
declare @51 float=0
declare @52 float=0
declare @53 float=0
declare @54 float=0
declare @55 float=0
declare @56 float=0
declare @57 float=0
declare @58 float=0
declare @59 float=0
declare @60 float=0
declare @61 float=0
declare @62 float=0
declare @63 float=0
declare @64 float=0
declare @65 float=0
declare @66 float=0
declare @67 float=0
declare @68 float=0
declare @69 float=0
declare @70 float=0
declare @71 float=0
declare @72 float=0
declare @73 float=0
declare @74 float=0
declare @75 float=0
declare @76 float=0
declare @77 float=0
declare @78 float=0
declare @79 float=0
declare @80 float=0
declare @81 float=0
declare @82 float=0
declare @83 float=0
declare @84 float=0
declare @85 float=0
declare @86 float=0
declare @87 float=0
declare @88 float=0
declare @89 float=0
declare @90 float=0
declare @91 float=0
declare @92 float=0
declare @93 float=0
declare @94 float=0
declare @95 float=0
declare @96 float=0
declare @97 float=0
declare @98 float=0
declare @99 float=0
declare @100 float=0
declare @101 float=0
declare @102 float=0
declare @103 float=0
declare @104 float=0
declare @105 float=0
BEGIN
select @i=count(*)from tbPRB;
IF EXISTS(SELECT * FROM sys.Tables WHERE name='tbPRBnew')
	DROP TABLE tbPRBnew
create table tbPRBnew(
	 [起始时间] nvarchar(100) not null,
     [周期(h)] float not null,
     [网元名称] nvarchar(255) not null,
     [小区] nvarchar(255) not null,
     [小区名] nvarchar(100) not null,
     [第0个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第1个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第2个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第3个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第4个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第5个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第6个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第7个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第8个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第9个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第10个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第11个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第12个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第13个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第14个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第15个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第16个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第17个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第18个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第19个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第20个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第21个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第22个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第23个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第24个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第25个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第26个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第27个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第28个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第29个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第30个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第31个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第32个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第33个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第34个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第35个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第36个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第37个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第38个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第39个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第40个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第41个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第42个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第43个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第44个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第45个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第46个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第47个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第48个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第49个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第50个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第51个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第52个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第53个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第54个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第55个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第56个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第57个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第58个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第59个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第60个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第61个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第62个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第63个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第64个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第65个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第66个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第67个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第68个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第69个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第70个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第71个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第72个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第73个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第74个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第75个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第76个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第77个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第78个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第79个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第80个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第81个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第82个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第83个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第84个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第85个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第86个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第87个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第88个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第89个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第90个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第91个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第92个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第93个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第94个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第95个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第96个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第97个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第98个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第99个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
	  primary key(小区名,起始时间)
	 )
declare @t table([起始时间] nvarchar(100) not null,
     [周期(h)] float not null,
     [网元名称] nvarchar(255) not null,
     [小区] nvarchar(255) not null,
     [小区名] nvarchar(100) not null,
     [第0个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第1个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第2个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第3个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第4个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第5个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第6个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第7个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第8个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第9个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第10个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第11个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第12个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第13个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第14个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第15个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第16个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第17个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第18个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第19个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第20个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第21个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第22个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第23个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第24个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第25个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第26个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第27个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第28个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第29个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第30个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第31个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第32个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第33个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第34个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第35个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第36个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第37个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第38个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第39个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第40个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第41个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第42个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第43个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第44个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第45个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第46个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第47个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第48个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第49个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第50个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第51个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第52个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第53个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第54个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第55个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第56个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第57个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第58个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第59个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第60个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第61个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第62个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第63个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第64个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第65个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第66个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第67个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第68个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第69个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第70个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第71个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第72个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第73个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第74个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第75个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第76个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第77个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第78个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第79个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第80个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第81个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第82个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第83个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第84个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第85个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第86个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第87个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第88个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第89个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第90个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第91个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第92个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第93个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第94个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第95个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第96个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第97个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第98个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null,
     [第99个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] float not null
	 primary key(小区名,起始时间))
insert into @t select * from tbPRB order by 小区名,起始时间
declare @j int=0
declare @time nvarchar (100)
while @j<=@i
begin
 select top(1) @time=起始时间, @3=网元名称,  @4=小区,   @5=小区名,  @6 +=[第0个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @7 +=[第1个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @8 +=[第2个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @9 +=[第3个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @10 +=[第4个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @11 +=[第5个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @12 +=[第6个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @13 +=[第7个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @14 +=[第8个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @15 +=[第9个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @16 +=[第10个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @17 +=[第11个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @18 +=[第12个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @19 +=[第13个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @20 +=[第14个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @21 +=[第15个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @22 +=[第16个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @23 +=[第17个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @24 +=[第18个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @25 +=[第19个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @26 +=[第20个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @27 +=[第21个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @28 +=[第22个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @29 +=[第23个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @30 +=[第24个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @31 +=[第25个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @32 +=[第26个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @33 +=[第27个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @34 +=[第28个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @35 +=[第29个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @36 +=[第30个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @37 +=[第31个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @38 +=[第32个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @39 +=[第33个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @40 +=[第34个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @41 +=[第35个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @42 +=[第36个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @43 +=[第37个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @44 +=[第38个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @45 +=[第39个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @46 +=[第40个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @47 +=[第41个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @48 +=[第42个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @49 +=[第43个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @50 +=[第44个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @51 +=[第45个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @52 +=[第46个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @53 +=[第47个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @54 +=[第48个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @55 +=[第49个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @56 +=[第50个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @57 +=[第51个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @58 +=[第52个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @59 +=[第53个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @60 +=[第54个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @61 +=[第55个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @62 +=[第56个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @63 +=[第57个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @64 +=[第58个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @65 +=[第59个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @66 +=[第60个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @67 +=[第61个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @68 +=[第62个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @69 +=[第63个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @70 +=[第64个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @71 +=[第65个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @72 +=[第66个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @73 +=[第67个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @74 +=[第68个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @75 +=[第69个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @76 +=[第70个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @77 +=[第71个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @78 +=[第72个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @79 +=[第73个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @80 +=[第74个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @81 +=[第75个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @82+=[第76个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @83 +=[第77个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @84 +=[第78个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @85 +=[第79个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @86 +=[第80个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @87 +=[第81个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @88 +=[第82个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @89 +=[第83个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @90 +=[第84个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @91 +=[第85个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @92 +=[第86个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @93 +=[第87个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @94 +=[第88个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @95 +=[第89个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @96 +=[第90个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @97 +=[第91个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @98 +=[第92个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @99 +=[第93个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @100 +=[第94个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @101+=[第95个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @102 +=[第96个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @103 +=[第97个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)],  @104 +=[第98个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)], @105 +=[第99个PRB上检测到的干扰噪声的平均值 (毫瓦分贝)] from @t order by 小区名,起始时间
 print 0
 if @j%4=0
 begin
 set @1=@time
 print @1
 end
 delete top(1) from @t
 print @82
 set @j=@j+1
 if @j%4=0
 begin
 print @j
 INSERT INTO tbPRBnew VALUES (@1,  @2,  @3,  @4,  @5,  @6/4,  @7/4,  @8/4,  @9/4,  @10/4,  @11/4,  @12/4,  @13/4,  @14/4,  @15/4,  @16/4,  @17/4,  @18/4,  @19/4,  @20/4,  @21/4,  @22/4,  @23/4,  @24/4,  @25/4,  @26/4,  @27/4,  @28/4,  @29/4,  @30/4,  @31/4,  @32/4,  @33/4,  @34/4,  @35/4,  @36/4,  @37/4,  @38/4,  @39/4,  @40/4,  @41/4, @42/4,  @43/4,  @44/4,  @45/4,  @46/4,  @47/4,  @48/4,  @49/4,  @50/4,  @51/4,  @52/4,  @53/4,  @54/4,  @55/4,  @56/4,  @57/4,  @58/4,  @59/4,  @60/4,  @61/4,  @62/4,  @63/4,  @64/4,  @65/4,  @66/4,  @67/4,  @68/4,  @69/4,  @70/4,  @71/4,  @72/4,  @73/4,  @74/4,  @75/4,  @76/4,  @77/4,  @78/4,  @79/4,  @80/4,  @81/4,  @82/4,  @83/4,  @84/4,  @85/4,  @86/4,  @87/4,  @88/4,  @89/4,  @90/4,  @91/4,  @92/4,  @93/4,  @94/4,  @95/4,  @96/4,  @97/4,  @98/4,  @99/4,  @100/4,  @101/4,  @102/4,  @103/4,  @104/4,  @105/4 )
print @82/4
set @1 =null 
set @3 =null
set @4 =null
set @5 =null
set @6 =0
set @7 =0 
set @8 =0 
set @9 =0 
set @10 =0 
set @11 =0 
set @12 =0 
set @13 =0 
set @14 =0 
set @15 =0 
set @16 =0 
set @17 =0 
set @18 =0 
set @19 =0 
set @20 =0 
set @21 =0 
set @22 =0 
set @23 =0 
set @24 =0 
set @25 =0 
set @26 =0 
set @27 =0 
set @28 =0 
set @29 =0 
set @30 =0 
set @31 =0 
set @32 =0 
set @33 =0 
set @34 =0 
set @35 =0 
set @36 =0 
set @37 =0 
set @38 =0 
set @39 =0 
set @40 =0 
set @41 =0 
set @42 =0 
set @43 =0 
set @44 =0 
set @45 =0 
set @46 =0 
set @47 =0 
set @48 =0 
set @49 =0 
set @50 =0 
set @51 =0 
set @52 =0 
set @53 =0 
set @54 =0 
set @55 =0 
set @56 =0 
set @57 =0 
set @58 =0 
set @59 =0 
set @60 =0 
set @61 =0 
set @62 =0 
set @63 =0 
set @64 =0 
set @65 =0 
set @66 =0 
set @67 =0 
set @68 =0 
set @69 =0 
set @70 =0 
set @71 =0 
set @72 =0
set @73 =0 
set @74 =0 
set @75 =0 
set @76 =0 
set @77 =0 
set @78 =0 
set @79 =0 
set @80 =0 
set @81 =0 
set @82 =0 
set @83 =0 
set @84 =0 
set @85 =0 
set @86 =0 
set @87 =0 
set @88 =0 
set @89 =0 
set @90 =0 
set @91 =0 
set @92 =0 
set @93 =0 
set @94 =0 
set @95 =0 
set @96 =0 
set @97 =0 
set @98 =0 
set @99 =0 
set @100 =0 
set @101 =0 
set @102 =0 
set @103 =0 
set @104 =0 
set @105 =0 
 end
 end
 select * from tbPRBnew
end