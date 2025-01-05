TRAWELL

**CONTENTS:**

1) Introduction
1) Working
1) Description of the data types

**INTRODUCTION:**
This project is done as a grouo of 3.

In this project we have coded the cab hailing process using C language. Through this code we wish to execute the driver details, user details and the process which takes place in the interface.

In this Cab Hailing process we have 3 interfaces namely

1) user
1) driver and
1) Trawell interface

Here there are certain modules especially for certain interfaces.

We have also included various files, structures and arrays in our code which are explained in detail below.

**OVERVIEW OF THE CODE:**

First they have a choice whether they are the user or driver and next they can either select login or register.Once the user has registered their part ,the ticket booking starts ,In the ticket booking we get location and destination as input and the maps will be open for them and **URL** will be provided for them.,They give distance ,meredian,promo code(if they have),time as input . Based on this their driver will be alloted.

We will ask choice to driver if they want to take the offer or not ,if they accept that offer,the driver details will be displayed to the customer along the driver's phone number,cab number and the otp.If not the recursion part runs until the customer gets the driver .The bill will be estimated based on conditions like time they chose to travel and their mode of the vehicle and based on traffic conditions.

Next they can either proceed or cancel the ticket( if they booked advance).If they proceeded to travel,the bill will be displayed on the console screen.The user can pay the bill either on cash or online payments.Once they paid the bill they can tell otp to the driver,and proceed

their travel.During their travel the emergency service portal will be open where the different kinds of services are provided they can also change their driver if they are discomfort with current driver.Once they reached their destination they can press exit button.

Once they pressed their exit button the feedback page will be open for them in which they can give the rating and feedback about the driver.

And at last the salary of the driver is computed based on the number of passengers he took in the month.

**WORKING:**

How our code works:-

In this code we have several modules:-

**USER LOGIN / USER REGISTRATION:**

We receive the user's name and the password for the user login in this section.Additionally, when a person registers, we collect their basic information and, if they are enrolling for the first time, we also produce a promol code for them.In the user data.txt file, we keep the user's fundamental information for future reference

**DRIVER LOGIN/DRIVER REGISTRATION:**

In the same way that we developed a page for users, we have also created one for drivers, where they may sign up or log in.

**TICKET BOOKING:**

This module deals with the booking of the cab by the customers. Here inputs like location,destination,distance, number of people, number of vehicles,vehicles, time, meridiam, advance booking,cancellation,promo code are read from the customer.

Then from this module google maps,driver allocation,otp, bill estimation, paying,emergency services,ticket cancellation modules are called and then this finally prints the bill.

**MAP:**

This module is the one which shows the maps for the customer. In this module, a map showing different routes between the location and the destination of the customer is shown. The customer is asked to select the route and to enter the distance of the selected route.Then the url for the map is also provided for the customer for future reference.

**DRIVER ALLOTMENT:**

In this module, the file containing driver details (driver.txt) is opened. Here each driver is asked whether they would like to take the given offer from the given location tho the destination mentioned by the customer.

**OTP:**

In this module the otp, a four digit random number is generated for the customer. This otp will be asked by the driver before the ride begins.

**BILL ESTIMATION:**

This module deals with the estimation of the bill. In this module, inputs like distance,number of people, number of vehicles, type of vehicles, time,meridian,advance booking,cancellation,promo code are passed as arguments. Then it does some mathematical calculations to produce the estimated bill.

**TICKET CANCELLATION:**

In this module, after estimating the bill, the customer is asked whether they want to proceed with ticket booking or cancel the ticket. If they opt for ticket cancellation, the ticket is cancelled accordingly otherwise it skips the steps of cancellation and moves to payment.

**PAY:**

This is the module where the payment is done. It provides two modes of payment for the customer. If the customer chooses to pay using cash, then they are asked to pay it directly to the driver. If the customer chooses to pay online, then many facilities have been provided. They can choose their app of payment and their bank. Then they are asked to enter their password. Then they can proceed to pay by entering the amount and their pi number. Then a message to confirm the payment.

**EMERGENCY SERVICES:**

In this module, the customer, if not satisfied by the services or punctuality of the driver, can change the driver. Through this module, the customer can change the driver. Through this module we also keep track of whether the customer has reached the destination, as this module will be live throughout the code and the customer can press ‘exit’ once they have reached the required destination.

**FEEDBACK SYSTEM:**

Users can provide feedback for the driver via the feedback system in addition to evaluating the driver.

**SALARY:**

The driver's salary is fixed and is increased dependent on the number of passengers they carry each month.We use the formula **"fixed amount+fixed amount\*no of passengers he took in a month**" to determine salaries.

**DESCRIPTION OF THE DATA TYPES: 1.FILES USED IN THE CODE:**

**Driver.txt:**

In this text file, the driver details are present in the following order:-

1) Driver name
1) Driver ID
1) Driver gmail id
1) Driver’s preference 1
1) Driver’s preference 2
1) Driver’s preference 3
7) Years of experience

(viii) Driver’s licence expiry data

9) Driver phone number
9) Driver Vehicle number

**ticket.txt:**

This text file holds the records of the booked cabs and the cancelled ones. The data is stored in the following order:

1) Ticket number
1) Location
1) Destination
1) Distance
1) Vehicle (number of vehicles vary depending on the number of people)
1) Number of people
1) Time

(viii) Advance booking

9) Promocode
9) Bill amount

**STRUCTURES:**

- We have used structures for storing the feedback and rating of the driver.
- For providing salary for the drivers, structure have been used.

The structures used are:

1. feedback
1. salary

**2.ARRAYS:**

Arrays have been used for storing various details.

- 1D arrays have been used for storing the vehicle base fares and vehicles booked.
- 2D arrays have been used for storing payment apps and bank names which are strings.
1. vehicles (1D)
1. vehicle (1D)
1. pay (2D)
1. bank (2D)

**Conclusion:**

It can be only implemented in DEVC++ as we have included some features which can be only used in developer c++.
