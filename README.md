# Flight-reservation-system
flight reservation system
Project Brief: Flight Reservation System

Objective: The Flight Reservation System is designed to manage flight schedules, ticket bookings, cancellations, and provide a seamless experience for users interacting with the system. The system aims to facilitate efficient booking and management of flight reservations for travellers.

Functionalities:

View Available Flights:

Description: Users can view a list of available flights with details such as flight number, destination, and the number of available seats.

Implementation: The system reads flight information from a file or an array and displays it to the user.


Book a Flight:

Description: Users can book tickets for a specific flight by providing the flight number. The system checks seat availability and confirms the booking if seats are available.

Implementation: The system updates the number of available seats for the selected flight and records the booking information.


Cancel Reservation:

Description: Users can cancel their flight reservations by providing the flight number. The system verifies the reservation and updates the available seats accordingly.

Implementation: The system searches for the booking based on the flight number and cancels the reservation, releasing the booked seats.


View Current Bookings:

Description: Users can check their current bookings, including details like flight number, destination, and the number of booked seats.

Implementation: The system displays the current bookings by reading the reservation data from the file or array and presenting it to the user.

Features:

File Handling: The system uses file handling to store and retrieve flight information and bookings, ensuring data persistence.

Menu-Driven Interface: Users interact with the system through a menu-driven interface, making it user-friendly and easy to navigate.

Data Validation: The system incorporates data validation to handle invalid inputs and provide informative error messages to users.

Efficient Booking and Cancellation: Booking and cancellation processes are designed to efficiently update the available seats and maintain accurate booking records.
