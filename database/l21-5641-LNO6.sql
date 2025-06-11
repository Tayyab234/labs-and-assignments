create database l21_5641_LNo6
use l21_5641_LNo6
CREATE TABLE Students (
  studentID INT IDENTITY(1,1) PRIMARY KEY,
  name VARCHAR(50),
  age INT,
  rollNo VARCHAR(50),
  major VARCHAR(50)
);

-- Create the Courses table
CREATE TABLE Courses (
  courseID INT IDENTITY(1,1) PRIMARY KEY ,
  courseName VARCHAR(50),
  instructor VARCHAR(50),
  department VARCHAR(50),
  creditHour INT
);

-- Create the Enrollments table
CREATE TABLE Enrollments (
  enrollmentID INT IDENTITY(1,1) PRIMARY KEY ,
  studentID INT,
  courseID INT,
  FOREIGN KEY (studentID) REFERENCES Students(studentID),
  FOREIGN KEY (courseID) REFERENCES Courses(courseID)
);

-- Create the Grades table
CREATE TABLE Grades (
  gradeID INT IDENTITY(1,1) PRIMARY KEY ,
  enrollmentID INT,
  grade DECIMAL(4,2),
  FOREIGN KEY (enrollmentID) REFERENCES Enrollments(enrollmentID)
);

-- Inserting records into the Students table
INSERT INTO Students (name, age, rollNo, major) VALUES ('Giselle Collette', 20, 'l201234', 'Computer Science');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Emily Davis', 22, 'l212342', 'Data Science');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Kaeya Alberich', 21, 'l203451', 'Mathematics');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Florence Nightingale', 23, 'l203452', 'Data Science');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Waver Velvet', 21, 'l224324', 'Data Science');
INSERT INTO Students (name, age, rollNo, major) VALUES ('Benedict Blue', 21, 'l214984', 'Computer Science');

-- Inserting records into the Courses table
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Database Systems', 'Prof. Smith', 'CS', 4);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Web Development', 'Prof. Jonathan', 'CS', 4);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Theory of Automata', 'Prof. Williams', 'CS', 3);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Machine Learning', 'Prof. Williams', 'CS', 3);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Discrete Structures', 'Prof. Horace', 'CS', 3);
INSERT INTO Courses (courseName, instructor, department, creditHour) VALUES ('Numeric Computing', 'Prof. Sarah', 'MTH', 3);

-- Inserting records into the Enrollments table
INSERT INTO Enrollments (studentID, courseID) VALUES (1, 1); 
INSERT INTO Enrollments (studentID, courseID) VALUES (2, 1); 
INSERT INTO Enrollments (studentID, courseID) VALUES (2, 2); 
INSERT INTO Enrollments (studentID, courseID) VALUES (3, 3); 
INSERT INTO Enrollments (studentID, courseID) VALUES (5, 4); 
INSERT INTO Enrollments (studentID, courseID) VALUES (5, 3); 
INSERT INTO Enrollments (studentID, courseID) VALUES (5, 6); 
INSERT INTO Enrollments (studentID, courseID) VALUES (6, 1); 

-- Inserting records into the Grades table
INSERT INTO Grades (enrollmentID, grade) VALUES (1, 3.3); 
INSERT INTO Grades (enrollmentID, grade) VALUES (2, 2.7); 
INSERT INTO Grades (enrollmentID, grade) VALUES (3, 2.3); 
INSERT INTO Grades (enrollmentID, grade) VALUES (4, 4); 
INSERT INTO Grades (enrollmentID, grade) VALUES (5, 3.3); 
INSERT INTO Grades (enrollmentID, grade) VALUES (6, 3.7); 
INSERT INTO Grades (enrollmentID, grade) VALUES (7, 3); 
INSERT INTO Grades (enrollmentID, grade) VALUES (8, 3.7); 

-------------------------------------------------------------------------------------
select top 1* from Students
select top 1* from Courses
select top 1* from Enrollments
select top 1* from Grades
-----------------------------LAB TASKS----------------------------
--TASK NO 1

create procedure getUnenrolledStudents
as
begin
select studentID from Students
intersect
select studentID from Enrollments
END
GO

Execute getUnenrolledStudents

--Task no 2

create procedure updateStudentAge
@StudentID int,
@newAGE int
as
begin
update Students 
set age=@newAGE
where @StudentID= studentID
END
GO

declare @s_ID int=4,@age  int=25
execute updateStudentAge
@StudentID=@s_ID,@newAGE=@age

select * from students

--Task no 3

create procedure deletestudent
@StudentID int
as
begin
delete from students where studentID=@StudentID
delete from Enrollments where studentID=@StudentID
END
GO

declare @s_ID int=4
execute deletestudent
@StudentID=@s_ID

select * from students
select * from Enrollments

--Task no 4

create procedure GetCourseStudent
@CourseID int
as
begin
select E.courseID,E.studentID,S.name,S.Major from Enrollments E
inner join Students S on S.studentID=E.studentID
where E.courseID=@CourseID
END
GO

declare @C_ID int=1
execute GetCourseStudent
@CourseID=@C_ID


select * from Courses

------------------------------------------------------------------
--Task no 5

create procedure Studentinfo
@StudentID int
as
begin
select S.studentID,S.name,S.age,S.RollNo,S.Major,E.courseID,C.courseName,C.department
from students S
inner join Enrollments E on S.studentID=E.studentID
inner join Courses C on E.courseID=C.courseID
where S.studentID=@StudentID
END
GO

declare @s_ID int=2
execute Studentinfo
@StudentID=@s_ID


----------------------------------------------------------------------
--Task no 6

create procedure GetmostpopularCourse
as
begin
select C.courseID,C.courseName,(select top 1count(studentID) from Enrollments group by courseID order by count(studentID) desc) as NoOFEnrollments
from Courses C
where C.courseID=(select top 1 courseID from Enrollments group by courseID order by count(courseID) desc)
END
GO

execute GetmostpopularCourse

-------------------------------------------------------------
--Task no 7

create procedure CalculateCourseGPA
@courseID int,
@avgGPA float output
as
begin
select @avgGPA=avg(G.grade)from Enrollments E
inner join Grades G on E.enrollmentID=G.enrollmentID
where E.courseID=@courseID

END
GO

declare @C_ID int= 1,@A_G float
execute CalculateCourseGPA
@courseID=@C_ID , @avgGPA=@A_G output
select @A_G as 'average_GPA'

--drop procedure CalculateCourseGPA3
----------------------------------------------------------------
--Task no 8
--drop procedure then create again


-----------------------------------------------------------------
--Task no 9
create procedure getCourseEnrollmentCount
@CourseID int
as
begin
select courseID,count(studentID) as NoOfEnrollments from Enrollments
where courseID=@CourseID
group by courseID
END
GO

declare @c_ID int=1
execute getCourseEnrollmentCount
@courseID=@c_ID

--Task no 10
create procedure getCourseWithoutGrades
as
begin
select C.courseID,C.courseName from courses C
where C.courseID != all(select E.courseID from Enrollments E) or
      C.courseID in (select E.courseID from Enrollments E
	                 where E.enrollmentID !=all(select enrollmentID from Grades)
					 )
END
GO
execute getCourseWithoutGrades































