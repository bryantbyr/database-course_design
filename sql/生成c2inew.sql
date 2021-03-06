
ALTER PROCEDURE [dbo].[c2i]
@n int
AS

BEGIN
IF EXISTS(SELECT * FROM sys.Tables WHERE name='tbC2Inew')
	DROP TABLE tbC2Inew;

with temp as(
select count(TimeStamp) as t,ServingSector as s,InterferingSector as i from tbMROData group by ServingSector,InterferingSector having count(TimeStamp)>@n),
TEMP1 AS(select TOP(9000) ServingSector,InterferingSector, avg(LteScRSRP-LteNcRSRP) AS MEAN,STDEV(LteScRSRP-LteNcRSRP)AS STD from tbMROData GROUP BY ServingSector,InterferingSector having count(TimeStamp)in(select t from temp) order by ServingSector,InterferingSector)
SELECT ServingSector,InterferingSector,MEAN,STD,dbo.dist((9-MEAN)/STD)as PrC2I9,dbo.dist((6-MEAN)/STD)-dbo.dist((-6-MEAN)/STD)as PrbABS6 into tbC2Inew FROM TEMP1
alter table tbC2Inew
add constraint PK_c2i
primary key (ServingSector,InterferingSector)
end