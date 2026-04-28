CREATE TABLE [dbo].[famoso] (
    [ID]        INT          NOT NULL,
    [nombre]    VARCHAR (20) NOT NULL,
    [apellidos] VARCHAR (30) NOT NULL,
    [cumple]    DATETIME     NOT NULL,
    [imagen]    VARCHAR (20) NOT NULL,
    PRIMARY KEY CLUSTERED ([ID] ASC)
);

INSERT famoso VALUES (1, 'Blake', 'Lively', '1987/08/25', 'famoso1.jpg')
INSERT famoso VALUES (2, 'Tom', 'Cruise', '1962/07/03', 'famoso2.jpg')
INSERT famoso VALUES (3, 'Jennifer', 'Lawrence', '1990/08/15', 'famoso3.jpg')
INSERT famoso VALUES (4, 'Kate', 'Hudson', '1979/04/19', 'famoso4.jpg')
INSERT famoso VALUES (5, 'Ryan', 'Lochte', '1984/08/03', 'famoso5.jpg')
INSERT famoso VALUES (6, 'Miranda', 'Kerr', '1983/04/20', 'famoso6.jpg')
INSERT famoso VALUES (7, 'Toni', 'Costa', '1983/08/20', 'famoso7.jpg')
INSERT famoso VALUES (8, 'Gaby', 'Espino', '1976/11/15', 'famoso8.jpg')

