CREATE DATABASE L215641_Lno8
use L215641_Lno8
create table products(
P_ID int primary key,
P_name nvarchar(25),
price int,
quantity nvarchar(10)
);

CREATE TRIGGER before_products_insert
ON products 
for insert 
as
BEGIN
    IF exists(select 1 from inserted where price < 0 OR price > 1000 )
	Begin
        print 'Price value must be between 0 and 1000';
		rollback Transaction;
    END 
END;

insert into products(P_ID,P_name,price,quantity)
values (1,'product1',600,13)

insert into products(P_ID,P_name,price,quantity)
values (2,'product2',2000,14)



--------------------------------QUESTION NO 2

CREATE TABLE Orders(
	OrderNo int primary key,
	CustomerNo int foreign key references Customers(CustomerNo) on delete cascade,
	O_Date date NULL,
	Total_Items_Ordered int NULL
);

CREATE TABLE Customers(
	CustomerNo int primary key,
	C_Name nvarchar(30) NULL,
	City nvarchar(20) NULL,
	Phone nvarchar(15) NULL unique
);

drop trigger BeforeDeletedFromCustomer
------------------------------------------------------------------
CREATE TRIGGER BeforeDeletedFromCustomer
ON Customers
for DELETE 
AS
BEGIN
    IF EXISTS (SELECT 1 FROM deleted d WHERE d.CustomerNo IN (SELECT CustomerNo FROM Orders))
    BEGIN
        PRINT 'Row cannot be deleted; customer is associated with the order table.';
        ROLLBACK;
        RETURN;
    END 
END;
CREATE TRIGGER BeforeDeletedFromCustomer
ON Customers
for DELETE 
AS
BEGIN
        SELECT 1 FROM deleted 
        PRINT 'Row cannot be deleted; customer is associated with the order table.';
        ROLLBACK;
        RETURN;
END;

--------------------------------------------------------------------
INSERT INTO Customers (CustomerNo, C_Name, City, Phone) VALUES
(1, 'John Doe', 'New York', '123-456-7890'),
(2, 'Jane Smith', 'Los Angeles', '987-654-3210'),
(5, 'Michael Khurram', 'Austria', '134-557-3993');

INSERT INTO Orders (OrderNo, CustomerNo, O_Date, Total_Items_Ordered) VALUES
(101, 1, '2023-10-15', 5),
(102, 2, '2023-10-18', 8);


delete from Customers where CustomerNo =2
select * from Customers
select * from Orders

--Task 4
create table order1(
column_id int, 
customer_id int,
total int,
discount int,
primary key(column_id,customer_id)
);
drop trigger checkdiscount
create trigger checkdiscount on  order1  instead of update , insert
as 
begin
   declare @total int
   declare @discount int
   declare @customer_id int
   declare @column_id int
   select   @total=total,@discount=discount, @customer_id=customer_id , @column_id =column_id from inserted;
   if 0.10 * @total < @discount
   print 'cannot execute the operation'
   else
   insert into order1  values(@column_id,@customer_id,@total,@discount);


end;
select * from order1
 insert into order1  values(1,1,100,9);


