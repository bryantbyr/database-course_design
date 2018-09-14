alter function dist( @x float)
returns float
as
begin
declare @t table(id float)
insert into @t values(0.196854)
insert into @t values(0.115194)
insert into @t values(0.000344)
insert into @t values(0.019527)
 declare @x0  float=@x
 if @x0<0
 begin
 set @x0=-@x0
 end
 declare @erf float(8) =0
declare @i int =0
while @i<4
begin
set @i+=1
select top(@i+1) @erf += id * Power(@x0, @i) from @t


end
set @erf = 1 - Power(1.0 + @erf, -4)


  declare @phi float(8)= 0.5 * (1 + @erf)  
  if @x<0
  begin
  set @phi=0.5 * (1-@erf)
  end

  return @phi*100



end