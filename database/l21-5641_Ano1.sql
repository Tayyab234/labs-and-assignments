create database assignment1
use assignment1

create table Patients(
 P_ID int primary key,
 P_Name nvarchar(30),
 DOB nvarchar(15),
 Gender nvarchar(8) check(Gender in('Male','Female')),
 contact nvarchar(20) unique,
 P_Address nvarchar(35),
 Email nvarchar(40) unique
);
create table department(
D_name nvarchar(25) not null,
D_ID int primary key
)
create table Medical_Staff(
M_ID int primary key,
M_Name nchar(30) not null,
DOB nvarchar(17),
contact nvarchar(15) unique,
M_address nvarchar(35) not null,
M_Role nvarchar(15) not null,
depart_ID int foreign key references Department(D_id)
);



create table appointments(
P_ID int foreign key references Patients(p_ID),
Staff_ID int foreign key references Medical_Staff(M_ID),
A_date nvarchar(17),
A_time nvarchar(15),
A_status nvarchar(17),
primary key(P_ID,Staff_ID)
);
create table Medication(
Medication_ID int primary key,
Medication_Name nvarchar(25) unique,
Dosage nvarchar(25) not null,
Instruction nvarchar(50) not null
);

create table Test(
Test_ID int primary key ,
Test_Name nvarchar(30) not null,
Test_Description nvarchar(50),
Test_Cost  int
);
create table Medical_Records(
P_ID int foreign key references Patients(P_ID),
Staff_ID int foreign key references Medical_Staff(M_ID),
Service_date nvarchar(17),
Diagnosis nvarchar(25),
Treatment nvarchar(25) ,
Medication_ID int foreign key references Medication(Medication_ID),
Test_id int foreign key references Test(Test_ID),
Precription nvarchar(50),
Test_Result nvarchar(25) NULL,
primary key(P_ID,Staff_ID)

);

create table billing(
P_ID int foreign key references Patients(P_ID),
Staff_ID int foreign key references Medical_Staff(M_ID),
Billing_date nvarchar(17),
total_amount float,
Paid_Status nvarchar(50),
primary key(P_ID,Staff_ID)
);

INSERT INTO Patients (P_ID, P_Name, DOB, Gender, Contact, P_Address, Email)
VALUES
    (1, 'John Doe', '1990-05-15', 'Male', '123-456-7890', '123 Main St, Cityville', 'john.doe@example.com'),
    (2, 'Jane Smith', '1985-08-22', 'Female', '987-654-3210', '456 Elm St, Townsville', 'jane.smith@example.com'),
    (3, 'Chris Johnson', '1998-03-10', 'Male', '555-555-5555', '789 Oak St, Villageton', 'chris.j@example.com'),
    (4, 'Alex Taylor', '1992-11-02', 'Male', '111-222-3333', '101 Pine St, Countryside', 'alex.taylor@example.com'),
    (5, 'Emily Davis', '1980-07-18', 'Female', '777-888-9999', '222 Cedar St, Hamletville', 'emily.d@example.com')
go
INSERT INTO Patients (P_ID, P_Name, DOB, Gender, Contact, P_Address, Email)
VALUES
    
	(6, 'David Brock','1980-07-18', 'Male', '707-808-9999', '22 Pine St, Cityville', 'david.d@example.com')
go

INSERT INTO Department (D_ID, D_Name)
VALUES
    (1, 'Cardiology'),
    (2, 'Orthopedics'),
    (3, 'Pediatrics'),
    (4, 'Neurology'),
    (5, 'Surgery');
go
INSERT INTO Billing (P_ID, Staff_ID, Billing_Date, Total_Amount, Paid_Status)
VALUES
    (1, 1, '2023-09-20', 500.00, 'Paid'),
    (2, 4, '2023-09-21', 750.00, 'Paid'),
    (3, 3, '2023-09-22', 400.00, 'Unpaid'),
    (4, 2, '2023-09-23', 300.00, 'Paid'),
    (5, 1, '2023-09-24', 600.00, 'Unpaid');
go
INSERT INTO Medical_Records (P_ID, Staff_ID, Service_Date, Diagnosis, Treatment, Medication_ID, Test_id, Test_Result, Precription)
VALUES
    (1, 1, '2023-09-20', 'Common Cold', 'Rest and fluids', 1, 1, 'Normal', 'Ibuprofen 200mg, 1 tablet every 4 hours'),
    (2, 4, '2023-09-21', 'Fractured Arm', 'Cast applied', 2, 2, 'Healing', 'Painkillers as needed'),
    (3, 3, '2023-09-22', 'Stomach Flu', 'Antibiotics prescribed', 3, 1, 'Positive for influenza', 'Antibiotics and rest'),
    (4, 2, '2023-09-23', 'Hypertension', 'Lifestyle changes', 4, 3, 'Normal', 'Lisinopril 10mg, once daily'),
    (5, 1, '2023-09-24', 'Headache', 'Rest and hydration', 5, 2, 'No abnormalities', 'Ibuprofen 200mg, as needed');
	go



INSERT INTO Medical_Staff (M_ID, M_Name, DOB, Contact, M_Address, M_Role, Depart_ID)
VALUES
    (1, 'Dr. John Smith', '1980-03-15', '123-456-7890', '789 Elm St, Cityville', 'Physician', 1),
    (2, 'Dr. Sarah Johnson', '1975-08-22', '987-654-3210', '456 Oak St, Townsville', 'Surgeon', 5),
    (3, 'Nurse Emily Davis', '1990-05-10', '555-555-5555', '101 Pine St, Countryside', 'Nurse', 3),
    (4, 'Dr. Michael Brown', '1982-11-02', '111-222-3333', '222 Cedar St, Hamletville', 'Cardiologist', 1),
    (5, 'Dr. Lisa Patel', '1978-07-18', '777-888-9999', '333 Maple St, Villageton', 'Neurologist', 4);
go

INSERT INTO Appointments (P_ID, Staff_ID, A_Date, A_Time, A_Status)
VALUES
    (1, 1, '2023-09-20', '10:00:00', 'Scheduled'),
    (2, 4, '2023-09-21', '14:30:00', 'Scheduled'),
    (3, 3, '2023-09-22', '11:15:00', 'Complete'),
    (4, 2, '2023-09-23', '09:45:00', 'Scheduled'),
    (5, 1, '2023-09-24', '16:00:00', 'Complete');
go
INSERT INTO Appointments (P_ID, Staff_ID, A_Date, A_Time, A_Status)
VALUES
    (6, 1, '2023-10-24', '17:00:00', 'Scheduled');
go
INSERT INTO Medication (Medication_ID,Medication_Name, Dosage, Instruction)
VALUES
    (1,'Aspirin', '500 mg', 'Take with food.'),
    (2,'Amoxicillin', '250 mg', 'Take every 8 hours.'),
    (3,'Ibuprofen', '200 mg', 'Take with plenty of water.'),
    (4,'Lisinopril', '10 mg', 'Take once daily.'),
    (5,'Atorvastatin', '20 mg', 'Take before bedtime.');
go

INSERT INTO Test (Test_ID,Test_Name, Test_Description, Test_Cost)
VALUES
    (1,'Blood Test', 'Measures various blood parameters.', 100.00),
    (2,'X-Ray', 'Radiographic imaging of bones and tissues.', 250.00),
    (3,'MRI Scan', 'Magnetic resonance imaging for detailed imaging.', 500.00),
    (4,'Ultrasound', 'Uses sound waves to create images of the body.', 150.00),
    (5,'ECG', 'Records electrical activity of the heart.', 75.00);
go

--Query no 1

select P.P_ID,P.P_Name,P.contact,M.M_Name as Doctor
from Patients P
inner join Medical_Records Md
on P.P_ID=Md.P_ID and P.Gender='Female'
inner join Medical_Staff M
on M.M_ID=Md.Staff_ID and M.M_Name='dr.sarah'
where P.contact like '%6'or P.contact like '%5' 

--Query no 2
select M_Name, datediff(year,DOB,getdate())  AS age
from Medical_Staff
where datediff(year,DOB,getdate()) >30 and M_Role='Nurse'

--Query no 3
select P.P_Name,P.Gender,A.A_date,A.A_status from appointments A
inner join Patients P
on P.P_ID=A.P_ID and P.Gender='Male'
order by A.A_date asc

--Query no 4
select top 3* from Test
order by Test_Cost desc

--Query no 5
select * from appointments
where A_status='Scheduled'

--Query no 6
select P_Name as Patient_Name,M_Name as Medical_Staff_Name
from Patients
inner join Medical_Staff
on P_Name = M_Name

--Query no 7

Select P.P_ID from Patients P
except
select B.P_ID from billing B

--Query no 8
select * from Medication

--Query no 9

select P.P_ID ,P.P_Name from patients P
where P.P_ID != all(select B.P_ID from billing B)

--Query no 10
select P.P_ID,P.P_Name from Patients P
inner join appointments A on A.P_ID=P.P_ID
where P.P_ID != all(select K.P_ID from Medical_Records K)

--Query no 11
Select P.P_ID,P.P_Name from Patients P,Medical_Records M,billing B,appointments A
where P.P_ID in (M.P_ID,A.P_ID,B.P_ID)

--Query no 12
Select P.P_ID,P.P_Name,M.M_Name as Doctor ,D.D_name as Department
from Patients P
inner join appointments A on A.P_ID=P.P_ID
inner join Medical_Staff M on A.Staff_ID=M.M_ID
inner join department D on M.depart_ID=D.D_ID
where D.D_name='Cardiology'

--Query no 13
select D.M_ID as Doctor_ID,D.M_Name as Doctor_NAME ,P.P_ID as Patient_ID,P.DOB Patient_DateOfBirth
from Medical_Staff D
inner join Medical_Records M on M.Staff_ID=D.M_ID
inner join Patients P on M.P_ID=P.P_ID
where datediff(year,P.DOB,getdate())<33

--Query no 14
Select P.P_ID,P.P_Name,A.A_status as Appointment
from Patients P
inner join appointments A on P.P_ID=A.P_ID

--Query no 15
Select P.P_ID,P.P_Name from Patients P
inner join Medical_Records M on M.P_ID=P.P_ID
inner join billing B on B.P_ID=P.P_ID 
--Query no 16
Select P.P_ID,P.P_Name,D.M_Name as Doctor,T.Test_Name
from Patients P
inner join Medical_Records M on M.P_ID=P.P_ID
inner join Medical_Staff D on M.Staff_ID=D.M_ID
inner join Test T on M.Test_id=T.Test_ID
where T.Test_Name='X-ray' and D.M_Name='Dr. Michael Brown'

--Query no 19

Select P.P_ID,P.P_Name,A.A_time as appointment_time,A.A_status,D.D_name
from Patients P
inner join appointments A on P.P_ID=A.P_ID
inner join Medical_Staff M on A.Staff_ID=M.M_ID
inner join department D on M.depart_ID=D.D_ID
where A.A_status='Scheduled'
--Query no 20
Select P.P_ID,P.P_Name,M.Service_date,M.diagnosis,M.Treatment,D.M_name as doctor
from Patients P
inner join Medical_Records M on M.P_ID=P.P_ID
inner join Medical_Staff D on M.Staff_ID=D.M_ID

--select * from Medical_Records
--select * from Patients
--select * from appointments
--select* from billing
