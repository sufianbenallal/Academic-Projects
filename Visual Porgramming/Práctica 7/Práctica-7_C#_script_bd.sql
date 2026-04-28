Para utilizar con SQL Server Express (sqlcmd):
-----------------------------------------------

USE master

if exists (select * from sysdatabases where name='bd_famosos')
begin
  raiserror('La base de datos existe; eliminándola....',0,1)
  DROP database bd_famosos
end
GO

CHECKPOINT
go

raiserror('Creando base de datos bd_famosos....',0,1)
go


CREATE DATABASE bd_famosos
GO

USE bd_famosos
GO

if db_name() <> 'bd_famosos'
   raiserror('Error, ''USE bd_famosos'' falló!  Killing the SPID now.'
            ,22,127) with log
GO

/*** execute sp_dboption 'bd_famosos' ,'trunc. log on chkpt.' ,'true' ***/
/*** En SQL Server 2012 cambiar la línea anterior por la siguiente ***/
ALTER DATABASE bd_famosos SET RECOVERY SIMPLE
GO

execute sp_addtype id      ,'varchar(11)' ,'NOT NULL'
execute sp_addtype tid     ,'varchar(6)'  ,'NOT NULL'
execute sp_addtype empid   ,'char(9)'     ,'NOT NULL'

raiserror('Creando la tabla famoso....',0,1)

GO

CREATE TABLE famoso
(
  ID int PRIMARY KEY NOT NULL,
  nombre varchar(20) NOT NULL,
  apellidos varchar(30) NOT NULL,
  cumple datetime NOT NULL,
  imagen varchar(20) NOT NULL
)
GO

INSERT famoso VALUES (1, 'Blake', 'Lively', '25/08/1987', 'famoso1.jpg')
INSERT famoso VALUES (2, 'Tom', 'Cruise', '03/07/1962', 'famoso2.jpg')
INSERT famoso VALUES (3, 'Jennifer', 'Lawrence', '15/08/1990', 'famoso3.jpg')
INSERT famoso VALUES (4, 'Kate', 'Hudson', '19/04/1979', 'famoso4.jpg')
INSERT famoso VALUES (5, 'Ryan', 'Lochte', '1984/08/03', 'famoso5.jpg')
INSERT famoso VALUES (6, 'Miranda', 'Kerr', '20/04/1983', 'famoso6.jpg')
INSERT famoso VALUES (7, 'Toni', 'Costa', '20/08/1983', 'famoso7.jpg')
INSERT famoso VALUES (8, 'Gaby', 'Espino', '15/11/1976', 'famoso8.jpg')
GO

UPDATE STATISTICS famoso
GO

CHECKPOINT
GO

USE master
GO

CHECKPOINT
GO

declare @dttm varchar(55)
select  @dttm=convert(varchar,getdate(),113)
raiserror('Editando %s ....',1,1,@dttm) with nowait
GO

quit

===================================================================================

Para utilizar con SQL Server Express LocalDB desde el EDI Visual Studio:
------------------------------------------------------------------------

1.- Para crear la tabla famoso:

CREATE TABLE famoso
(
  ID int PRIMARY KEY NOT NULL,
  nombre varchar(20) NOT NULL,
  apellidos varchar(30) NOT NULL,
  cumple datetime NOT NULL,
  imagen varchar(20) NOT NULL
)

2.- Para añadir datos a la tabla creada:

INSERT famoso VALUES (1, 'Blake', 'Lively', '1987/08/25', 'famoso1.jpg')
INSERT famoso VALUES (2, 'Tom', 'Cruise', '1962/03/07', 'famoso2.jpg')
INSERT famoso VALUES (3, 'Jennifer', 'Lawrence', '1990/08/15', 'famoso3.jpg')
INSERT famoso VALUES (4, 'Kate', 'Hudson', '1979/04/19', 'famoso4.jpg')
INSERT famoso VALUES (5, 'Ryan', 'Lochte', '1984/03/08', 'famoso5.jpg')
INSERT famoso VALUES (6, 'Miranda', 'Kerr', '1983/04/20', 'famoso6.jpg')
INSERT famoso VALUES (7, 'Toni', 'Costa', '1983/08/20', 'famoso7.jpg')
INSERT famoso VALUES (8, 'Gaby', 'Espino', '1976/11/15', 'famoso8.jpg')

