create proc [dbo].[enodeProc]
@ename nvarchar(100),
@eid   int
as
begin
select * from tbcell where ENODEB_NAME=@ename or ENODEBID=@eid
end
