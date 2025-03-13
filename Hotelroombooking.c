#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int room_id;
    char room_type[20];
    float price_per_night;
    int is_available;
} Room;
typedef struct {
    char customer_name[50];
    int room_id;
    int days;
    float total_price;
} Booking;
void admin_menu();
void customer_menu();
void add_room(Room rooms[], int *room_count);
void view_rooms(Room rooms[], int room_count);
void book_room(Room rooms[], int room_count, Booking bookings[], int *booking_count);
void view_bookings(Booking bookings[], int booking_count);

int main() {
    Room rooms[100];
    Booking bookings[100];
    int room_count = 0, booking_count = 0;
    int choice;
    printf("Welcome to the Hotel Management System\n");
    do {
        printf("\n1. Admin Menu\n2. Customer Menu\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                admin_menu(rooms, &room_count, bookings, &booking_count);
                break;
            case 2:
                customer_menu(rooms, room_count, bookings, &booking_count);
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void admin_menu(Room rooms[], int *room_count, Booking bookings[], int *booking_count) {
    int choice;
    do {
        printf("\nAdmin Menu:\n");
        printf("1. Add Room\n");
        printf("2. View Rooms\n");
        printf("3. View Bookings\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room(rooms, room_count);
                break;
            case 2:
                view_rooms(rooms, *room_count);
                break;
            case 3:
                view_bookings(bookings, *booking_count);
                break;
            case 4:
                printf("Exiting Admin Menu.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}
void customer_menu(Room rooms[], int room_count, Booking bookings[], int *booking_count) {
    int choice;
    do {
        printf("\nCustomer Menu:\n");
        printf("1. View Available Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_rooms(rooms, room_count);
                break;
            case 2:
                book_room(rooms, room_count, bookings, booking_count);
                break;
            case 3:
                printf("Exiting Customer Menu.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}
void add_room(Room rooms[], int *room_count) {
    Room new_room;
    printf("\nEnter Room ID: ");
    scanf("%d", &new_room.room_id);
    printf("Enter Room Type (Single/Double/Suite): ");
    scanf("%s", new_room.room_type);
    printf("Enter Price per Night: ");
    scanf("%f", &new_room.price_per_night);
    new_room.is_available = 1; // Room is initially available

    rooms[*room_count] = new_room;
    (*room_count)++;
    printf("Room added successfully!\n");
}

void view_rooms(Room rooms[], int room_count) {
    printf("\nRoom ID | Room Type | Price per Night | Availability\n");
    for (int i = 0; i < room_count; i++) {
        printf("%d\t  %s\t    %.2f\t   %s\n", rooms[i].room_id, rooms[i].room_type,
               rooms[i].price_per_night, rooms[i].is_available ? "Available" : "Not Available");
    }
}

void book_room(Room rooms[], int room_count, Booking bookings[], int *booking_count) {
    int room_id, days, found = 0;
    char customer_name[50];
    printf("Enter your name: ");
    scanf("%s", customer_name);
    view_rooms(rooms, room_count); 
    printf("Enter the Room ID to book: ");
    scanf("%d", &room_id);
    for (int i = 0; i < room_count; i++) {
        if (rooms[i].room_id == room_id && rooms[i].is_available) {
            printf("Enter number of days: ");
            scanf("%d", &days);
            Booking new_booking;
            strcpy(new_booking.customer_name, customer_name);
            new_booking.room_id = room_id;
            new_booking.days = days;
            new_booking.total_price = rooms[i].price_per_night * days;
            bookings[*booking_count] = new_booking;
            (*booking_count)++;
            rooms[i].is_available = 0;
            printf("Room booked successfully! Total price: %.2f\n", new_booking.total_price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Room not available or invalid room ID!\n");
    }
}

void view_bookings(Booking bookings[], int booking_count) {
    printf("\nCustomer Name | Room ID | Days | Total Price\n");
    for (int i = 0; i < booking_count; i++) {
        printf("%s\t     %d\t   %d\t %.2f\n", bookings[i].customer_name, bookings[i].room_id,
               bookings[i].days, bookings[i].total_price);
    }
}