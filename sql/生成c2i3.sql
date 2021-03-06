USE [TD-LTE]
GO
/****** Object:  StoredProcedure [dbo].[C2I2]    Script Date: 2018/9/14 20:48:53 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROC [dbo].[C2I2]
@X FLOAT
AS
BEGIN
IF EXISTS(SELECT * FROM sys.Tables WHERE name='tbC2I3')
	DROP TABLE tbC2I3;
create table tbC2I3(
 CELLa NVARCHAR(100) NOT NULL,
 CELLb NVARCHAR(100) NOT NULL,
 CELLc NVARCHAR(100) NOT NULL)
declare @i int=0
declare @j int=0;

WITH TEMP AS(
SELECT  ServingSector, InterferingSector,PrbABS6 FROM tbC2Inew where PrbABS6>@X
),
temp1 as(
SELECT TEMP.PrbABS6, temp.ServingSector as cell1, temp.InterferingSector as cell2,tbC2Inew.ServingSector as cell4,tbC2Inew.InterferingSector as cell3 FROM TEMP left join tbC2Inew on TEMP.InterferingSector=tbC2Inew.ServingSector OR TEMP.ServingSector=tbC2Inew.InterferingSector AND tbC2Inew.PrbABS6>@X
)
select cell1,cell2,cell3,tbC2Inew.ServingSector AS ecell INTO #TEMP2 from temp1 left join tbC2Inew on temp1.cell3=tbC2Inew.ServingSector OR tbC2Inew.InterferingSector=temp1.cell1 and tbC2Inew.PrbABS6>@X
SELECT @i=COUNT(*)FROM #TEMP2
DECLARE @C1 NVARCHAR(50)=NULL
DECLARE @C2 NVARCHAR(50)=NULL
DECLARE @C3 NVARCHAR(50)=NULL
DECLARE @C4 NVARCHAR(50)=NULL
while @j<@i
begin
SELECT TOP(1) @C1=cell1,@C2=cell2,@C3=cell3,@C4=ecell FROM #TEMP2
delete top(1) from #TEMP2
if @C3!=@C1 AND @C4 IS NOT null and not exists (select * from tbC2I3 where (CELLa=@C1 and CELLb=@C2 and CELLc=@C3)or (CELLa=@C1 and CELLb=@C3 and CELLc=@C2)or (CELLa=@C2 and CELLb=@C1 and CELLc=@C3)or (CELLa=@C2 and CELLb=@C3 and CELLc=@C1)or (CELLa=@C3 and CELLb=@C1 and CELLc=@C2)or (CELLa=@C3 and CELLb=@C2 and CELLc=@C1))
BEGIN
print @C1
insert into tbC2I3 values(@C1,@C2,@C3)
END
SET @j+=1
end
drop table #TEMP2
select * from tbC2I3
END