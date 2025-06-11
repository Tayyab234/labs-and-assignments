create database Lab2_21l_5641
use Lab2_21l_5641
create table Books
(
  BookID int primary key,
  Title varchar(50) not null,
  Author varchar(50) not null,
  Pyear int not null,
  ISBN varchar(50) not null
);
insert into [Books] 
values (1,'To kill a bird','Harper Lee',1960,'97846585'),
       (2,'1984','George Orwell',1949,'758375'),
	   (3,'The Great Gatsby','F.Scott',1925,'254854');
insert into [Books]
	 values  (4,'The Catcher in the Rye','J.D.Salinger',1951,'3853628');
       select *from Books
update Books set Title='Catcher in the Rye' where ISBN='3853628'
      delete from Books where ISBN='3853628'
	  select *from Books
--Question no 2
create table Products
(
   ProductID int primary key,Pname varchar(50) not null,category varchar(50), price float not null
);
insert into [Products] 
values (1,'Laptop','Electronics',800.00),(2,'Desk Chair','Furniture',120.00),(3,'SmartPhone','Electronics',500.00),(4,'Office Desk','Furniture',250.00);
select * from Products where Pname like '%Chair%'
update Products set category='Electronics' where ProductID=1
select * from Products where category='Electronics'
select * from Products where price<200
select Pname,category from Products where Pname like '%Desk%'

--Question no 3
create table Orders(
 order_id int primary key, customer_id int not null, order_date date not null, total_amount decimal not null
 );
 insert into Orders 
 values (1,101,'2023-10-10',150.50),(2,102,'2022-02-09',750.75),(3,103,'2023-09-08',200.00),(4,104,'2022-12-09',800.75),(5,105,'2021-09-07',300.30);
 select sum(total_amount) as Revenue, avg(total_amount) as Average from Orders
 update Orders set total_amount=total_amount*1.10
 select * from Orders where total_amount>500
select sum(total_amount) as Revenue_in_2023 from Orders where datediff(year,order_date,'2023')=0

create table departments( department_id int primary key, department_name varchar(50));
insert into departments
values (101,'Sales'),(102,'Marketing'),(103,'Finance'),(104,'Human Resources'),(105,'Research')
create table employess(employee_id int primary key, first_name varchar(50) not null,last_name varchar(50) not null,department_id int foreign key references departments(department_id));
insert into employess
values (1,'John','Smith',101),(2,'Sarah','Johnson',102),(3,'Michael','Williams',103),(4,'Emily','Davis',104),(5,'David','Lee',105)
select e.first_name,e.last_name,d.department_name from employess e join departments d on e.department_id=d.department_id
select d.department_name, COUNT(e.employee_id) AS num_employees
FROM departments d
LEFT JOIN employess e on d.department_id = e.department_id
GROUP BY d.department_name;
update employess set department_id=105 where employee_id=5
select * from employess
select d.department_name from departments d left join employess e on e.department_id=d.department_id where e.employee_id is null

--Question no 4

create table Products(
  product_id int primary key,
  product_name nvarchar(50) ,
  Pro_Description nvarchar(100),
  Price int NULL,
  Manufacturer_date nvarchar(30)
);
insert into [Products] ([product_id],[product_name],[Pro_Description],[Price],[Manufacturer_date])
values
(1 ,'Laptop',' High-performance laptop',900,'2023-05-15'),
(2,' Smartphone',' Latest smartphone model',699,'2023-06-20'),
(3,'Headphones','Noise-canceling headphones',949 ,'2023-07-10'),
(4,'Tablet','10-inch touchscreen tablet',299,'2023-06-05'),
(5,'Camera','DSLR camerawith zoom lens',799,'2023-08-12')
go
--1
select top 3* from Products

--2 calculate age of each product

select datediff(day,Manufacturer_date,'2023-09-8')as ProductAge from Products

--3 : product name with description display
update Products
set Pro_Description='Latest premium smartphone model'
where product_id=2
select product_name,Pro_description from Products
where Pro_Description like '%premium%'

--4: create new column

alter table Products add Discounted_price int  null
update Products
set Discounted_price = price-(price*10/100)
select* from Products

--5:Earliest manufacturer data
select min(Manufacturer_date) as earliest_product from Products

--6: total price of all products

select sum(Price) as priceOfallProducts from Products

--7:display product assending order

select * from Products
order by Price desc

--8:

select count(price) as count_of_Products_greater_than_900 from products
where price>900  
 
--9:
select P.product_name,P.Pro_Description from Products P 
inner join Products U
on len(P.Pro_Description)>len(U.Pro_Description) and P.product_id!=U.product_id

--10:
update Products
set Pro_Description='Budget Product'
where Price>799
select*from products


