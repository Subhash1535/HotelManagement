
# 🏨 Hotel Management System in C

This project is a simple **Hotel Management System** written in the C programming language. It allows **admins** to manage room listings and **customers** to book rooms. It demonstrates basic use of structures, arrays, and functions in C.

---

## ✨ Features

### Admin
- Add new rooms
- View all rooms
- View all bookings

### Customer
- View available rooms
- Book a room

---

## 🧑‍💻 Technologies Used

- Language: **C**
- Compiler: GCC

---

## 🛠️ How to Compile and Run

1. Save the code in a file, e.g., `hotel_management.c`.

2. Open your terminal or command prompt and run:

```bash
gcc hotel_management.c -o hotel
./hotel
```

---

## 📋 Sample Menu

```
Welcome to the Hotel Management System

1. Admin Menu
2. Customer Menu
3. Exit
```

---

## 📄 Project Structure

The project is built using the following data structures:

- `Room`: Contains room ID, type, price, and availability.
- `Booking`: Contains customer name, room ID, days, and total price.

Functions are used to handle admin and customer tasks separately, improving code readability and modularity.

---

## ✅ Sample Booking Flow

1. Customer views available rooms.
2. Customer selects a room ID and enters the number of days.
3. Booking is recorded and availability is updated.

---

## 📌 Notes

- Room availability is updated after booking.
- Data is stored in memory (no file I/O).
- Simple text-based interface.

---

## 📃 License

This project is for educational purposes and is licensed under the MIT License.
