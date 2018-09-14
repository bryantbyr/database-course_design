CREATE TRIGGER trigger2
   ON  tbCell
   INSTEAD OF insert
AS 
declare @C nvarchar(255)
declare @ID nvarchar(50)
declare @SN nvarchar(255)
declare @EID INT
declare @EN NVARCHAR(255)
declare @EA INT
declare @PCI INT
declare @PSS INT
declare @SSS INT
declare @TAC INT
declare @VD NVARCHAR(255)
declare @LO REAL
declare @LA REAL
declare @SY NVARCHAR(255)
declare @AZ FLOAT
declare @HE FLOAT
declare @EL FLOAT
declare @ME FLOAT
declare @TO FLOAT



select @C=CITY, @ID=SECTOR_ID, @SN=SECTOR_NAME,@EID =ENODEBID, @EN =ENODEB_NAME,@EA =EARFCN, @PCI =PCI,@PSS =PSS,@SSS=SSS, @TAC=TAC,@VD =VENDOR,@LO=LONGITUDE,@LA =LATITUDE,@SY =STYLE,@AZ =AZIMUTH, @HE =HEIGHT, @EL =ELECTTILT,@ME =MECHTILT,@TO=TOTLETILT from inserted
if((select count(*) from tbCell where SECTOR_ID=@ID )>0)
begin

       UPDATE tbCell SET CITY=@C, SECTOR_ID=@ID, SECTOR_NAME=@SN,ENODEBID=@EID , ENODEB_NAME=@EN ,EARFCN=@EA, PCI =@PCI,PSS =@PSS,SSS=@SSS, TAC=@TAC,VENDOR=@VD ,LONGITUDE=@LO,LATITUDE=@LA ,STYLE=@SY ,AZIMUTH=@AZ ,HEIGHT= @HE , ELECTTILT=@EL,MECHTILT=@ME,TOTLETILT=@TO  WHERE SECTOR_ID=@ID
	   PRINT'UPDATE!'
end
ELSE
INSERT INTO tbCell VALUES (@C ,@ID ,@SN ,@EID , @EN ,@EA ,@PCI ,@PSS ,@SSS ,@TAC ,@VD ,@LO , @LA ,@SY , @AZ , @HE ,@EL ,@ME ,@TO)
print 'success!'
