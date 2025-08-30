#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 50
#define MAX_BOOKINGS 100

// ---------------- Flight Structure ----------------
typedef struct {
    int flightNo;
    char flightName[50];     // NEW: Airline/Flight name
    char destination[50];
    int availableSeats;
} Flight;

// ---------------- Booking Structure ----------------
typedef struct {
    int bookingId;
    int flightNo;
    char passengerName[50];
    int seatsBooked;
} Booking;

// ---------------- Global Variables ----------------
Flight flights[MAX_FLIGHTS];
Booking bookings[MAX_BOOKINGS];
int totalFlights = 0, totalBookings = 0;

// ---------------- Function Declarations ----------------
void loadFlights();
void saveFlights();
void loadBookings();
void saveBookings();

void viewFlights();
void bookFlight();
void cancelBooking();
void viewBookings();

// ---------------- Main Function ----------------
int main() {
    int choice;

    loadFlights();
    loadBookings();

    do {
        printf("\n===== Flight Reservation System =====\n");
        printf("1. View Available Flights\n");
        printf("2. Book a Flight\n");
        printf("3. Cancel Reservation\n");
        printf("4. View Current Bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: viewFlights(); break;
            case 2: bookFlight(); break;
            case 3: cancelBooking(); break;
            case 4: viewBookings(); break;
            case 5:
                saveFlights();
                saveBookings();
                printf("Exiting... Data saved!\n");
                break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// ---------------- File Handling ----------------
void loadFlights() {
    FILE *fp = fopen("flights.txt", "r");
    if (fp == NULL) return;

    while (fscanf(fp, "%d %s %s %d",
                  &flights[totalFlights].flightNo,
                  flights[totalFlights].flightName,
                  flights[totalFlights].destination,
                  &flights[totalFlights].availableSeats) != EOF) {
        totalFlights++;
    }
    fclose(fp);
}

void saveFlights() {
    FILE *fp = fopen("flights.txt", "w");
    for (int i = 0; i < totalFlights; i++) {
        fprintf(fp, "%d %s %s %d\n", flights[i].flightNo,
                                     flights[i].flightName,
                                     flights[i].destination,
                                     flights[i].availableSeats);
    }
    fclose(fp);
}

void loadBookings() {
    FILE *fp = fopen("bookings.txt", "r");
    if (fp == NULL) return;

    while (fscanf(fp, "%d %d %s %d",
                  &bookings[totalBookings].bookingId,
                  &bookings[totalBookings].flightNo,
                  bookings[totalBookings].passengerName,
                  &bookings[totalBookings].seatsBooked) != EOF) {
        totalBookings++;
    }
    fclose(fp);
}

void saveBookings() {
    FILE *fp = fopen("bookings.txt", "w");
    for (int i = 0; i < totalBookings; i++) {
        fprintf(fp, "%d %d %s %d\n", bookings[i].bookingId,
                                     bookings[i].flightNo,
                                     bookings[i].passengerName,
                                     bookings[i].seatsBooked);
    }
    fclose(fp);
}

// ---------------- Functionalities ----------------
void viewFlights() {
    printf("\n--- Available Flights ---\n");
    for (int i = 0; i < totalFlights; i++) {
        printf("Flight No: %d | Flight: %s | Destination: %s | Seats: %d\n",
               flights[i].flightNo, flights[i].flightName,
               flights[i].destination, flights[i].availableSeats);
    }
}

void bookFlight() {
    int flightNo, seats;
    char name[50];
    printf("Enter Flight No to book: ");
    scanf("%d", &flightNo);
    printf("Enter passenger name: ");
    scanf("%s", name);
    printf("Enter number of seats: ");
    scanf("%d", &seats);

    for (int i = 0; i < totalFlights; i++) {
        if (flights[i].flightNo == flightNo) {
            if (flights[i].availableSeats >= seats) {
                flights[i].availableSeats -= seats;

                Booking newBooking = { totalBookings+1, flightNo, "", seats };
                strcpy(newBooking.passengerName, name);
                bookings[totalBookings++] = newBooking;

                printf("Booking Successful! Booking ID: %d\n", newBooking.bookingId);
                return;
            } else {
                printf("Not enough seats available!\n");
                return;
            }
        }
    }
    printf("Invalid Flight Number!\n");
}

void cancelBooking() {
    int bookingId;
    printf("Enter Booking ID to cancel: ");
    scanf("%d", &bookingId);

    for (int i = 0; i < totalBookings; i++) {
        if (bookings[i].bookingId == bookingId) {
            for (int j = 0; j < totalFlights; j++) {
                if (flights[j].flightNo == bookings[i].flightNo) {
                    flights[j].availableSeats += bookings[i].seatsBooked;
                    break;
                }
            }
            printf("Booking for %s cancelled.\n", bookings[i].passengerName);

            for (int k = i; k < totalBookings-1; k++) {
                bookings[k] = bookings[k+1];
            }
            totalBookings--;
            return;
        }
    }
    printf("Booking ID not found!\n");
}

void viewBookings() {
    printf("\n--- Current Bookings ---\n");
    for (int i = 0; i < totalBookings; i++) {
        printf("Booking ID: %d | Flight No: %d | Passenger: %s | Seats: %d\n",
               bookings[i].bookingId, bookings[i].flightNo,
               bookings[i].passengerName, bookings[i].seatsBooked);
    }
}
