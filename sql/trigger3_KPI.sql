CREATE TRIGGER trigger3
   ON  tbKPI
   INSTEAD OF insert
AS 
declare @A nvarchar(100)
declare @B FLOAT
declare @C nvarchar(255)
declare @D nvarchar(255)
declare @E NVARCHAR(100)
declare @F FLOAT
declare @G FLOAT
declare @H FLOAT
declare @I FLOAT
declare @J FLOAT
declare @K FLOAT
declare @L FLOAT
declare @M FLOAT
declare @N FLOAT
declare @O FLOAT
declare @P FLOAT
declare @Q FLOAT
declare @R FLOAT
declare @S FLOAT
declare @T FLOAT
declare @U FLOAT
declare @V FLOAT
declare @W FLOAT
declare @X FLOAT
declare @Y FLOAT
declare @Z FLOAT
declare @AA FLOAT
declare @AB FLOAT
declare @AC FLOAT
declare @AD FLOAT
declare @AE FLOAT
declare @AF FLOAT
declare @AG FLOAT
declare @AH FLOAT
declare @AI FLOAT
declare @AJ FLOAT
declare @AK FLOAT
declare @AL FLOAT
declare @AM FLOAT
declare @AN FLOAT
declare @AO FLOAT
declare @AP FLOAT



select @A =起始时间, @B =周期,@C=网元名称, @D=基站,@E=小区, @F =[RRC连接建立完成次数 (无)], @G =[RRC连接请求次数（包括重发） (无)],@H =[RRC建立成功率qf (%)],@I =[E-RAB建立成功总次数 (无)],@J =[E-RAB建立尝试总次数 (无)],@K =[E-RAB建立成功率2 (%)],@L =[eNodeB触发的E-RAB异常释放总次数 (无)],@M =[小区切换出E-RAB异常释放总次数 (无)],@N =[E-RAB掉线率(新) (%)],@O =[无线接通率ay (%)],@P =[eNodeB发起的S1 RESET导致的UE Context释放次数 (无)],@Q =[UE Context异常释放次数 (无)],@R =[UE Context建立成功总次数 (无)],@S =[无线掉线率 (%)],@T =[eNodeB内异频切换出成功次数 (无)],@U =[eNodeB内异频切换出尝试次数 (无)],@V =[eNodeB内同频切换出成功次数 (无)],@W =[eNodeB内同频切换出尝试次数 (无)],@X =[eNodeB间异频切换出成功次数 (无)],@Y =[eNodeB间异频切换出尝试次数 (无)],@Z =[eNodeB间同频切换出成功次数 (无)],@AA =[eNodeB间同频切换出尝试次数 (无)],@AB =[eNB内切换成功率 (%)],@AC =[eNB间切换成功率 (%)],@AD =[同频切换成功率zsp (%)],@AE =[异频切换成功率zsp (%)],@AF =[切换成功率 (%)],@AG =[小区PDCP层所接收到的上行数据的总吞吐量 (比特)],@AH =[小区PDCP层所发送的下行数据的总吞吐量 (比特)],@AI =[RRC重建请求次数 (无)],@AJ =[RRC连接重建比率 (%)],@AK = [通过重建回源小区的eNodeB间同频切换出执行成功次数 (无)],@AL =[通过重建回源小区的eNodeB间异频切换出执行成功次数 (无)], @AM =[通过重建回源小区的eNodeB内同频切换出执行成功次数 (无)],  @AN =[通过重建回源小区的eNodeB内异频切换出执行成功次数 (无)],@AO =[eNB内切换出成功次数 (次)],@AP =[eNB内切换出请求次数 (次)] from inserted
if((select count(*) from tbKPI where 起始时间=@A AND 小区=@E )>0)
begin

       UPDATE tbKPI SET 起始时间 = @A ,周期 =@B,网元名称 = @C,基站 =@D,小区 = @E,[RRC连接建立完成次数 (无)] = @F,[RRC连接请求次数（包括重发） (无)] =@G,[RRC建立成功率qf (%)] =@H,[E-RAB建立成功总次数 (无)] =@I,[E-RAB建立尝试总次数 (无)] =@J,[E-RAB建立成功率2 (%)] =@K,[eNodeB触发的E-RAB异常释放总次数 (无)] =@L,[小区切换出E-RAB异常释放总次数 (无)] =@M,[E-RAB掉线率(新) (%)] =@N,[无线接通率ay (%)] =@O,[eNodeB发起的S1 RESET导致的UE Context释放次数 (无)] =@P,[UE Context异常释放次数 (无)] =@Q,[UE Context建立成功总次数 (无)] =@R,[无线掉线率 (%)] =@S,[eNodeB内异频切换出成功次数 (无)] =@T,[eNodeB内异频切换出尝试次数 (无)] =@U,[eNodeB内同频切换出成功次数 (无)] =@V,[eNodeB内同频切换出尝试次数 (无)] =@W,[eNodeB间异频切换出成功次数 (无)] =@X,[eNodeB间异频切换出尝试次数 (无)] =@Y,[eNodeB间同频切换出成功次数 (无)] =@Z,[eNodeB间同频切换出尝试次数 (无)] =@AA,[eNB内切换成功率 (%)] =@AB,[eNB间切换成功率 (%)] =@AC,[同频切换成功率zsp (%)] =@AD,[异频切换成功率zsp (%)] =@AE,[切换成功率 (%)] =@AF,[小区PDCP层所接收到的上行数据的总吞吐量 (比特)] =@AG,[小区PDCP层所发送的下行数据的总吞吐量 (比特)] =@AH,[RRC重建请求次数 (无)] =@AI,[RRC连接重建比率 (%)] =@AJ, [通过重建回源小区的eNodeB间同频切换出执行成功次数 (无)] =@AK,[通过重建回源小区的eNodeB间异频切换出执行成功次数 (无)] = @AL,[通过重建回源小区的eNodeB内同频切换出执行成功次数 (无)] =  @AM,[通过重建回源小区的eNodeB内异频切换出执行成功次数 (无)] =@AN,[eNB内切换出成功次数 (次)] =@AO,[eNB内切换出请求次数 (次)]=@AP WHERE 起始时间=@A AND 小区=@E
	   PRINT'UPDATE!'
end
ELSE
INSERT INTO tbKPI VALUES (@A ,@B ,@C , @D ,  @E ,  @F ,  @G ,  @H ,  @I ,  @J ,  @K ,  @L ,  @M ,  @N ,  @O ,  @P ,  @Q ,  @R ,  @S ,  @T ,  @U ,  @V ,  @W ,  @X ,  @Y ,  @Z ,  @AA ,  @AB ,  @AC ,  @AD ,  @AE ,  @AF ,  @AG ,  @AH ,  @AI ,@AJ ,  @AK ,  @AL ,  @AM ,  @AN ,  @AO ,  @AP )
print 'success!'
