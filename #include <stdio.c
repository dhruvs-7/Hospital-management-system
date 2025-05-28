#include <stdio.h>
#include <string.h>

// Define maximum limits for arrays
#define MAX_PATIENTS 100
#define MAX_APPOINTMENTS 100
#define MAX_DOCTORS 50
#define MAX_DEPARTMENTS 10

// Structure for patient
typedef struct {
    int id;
    char name[50];
    int age;
    char medical_condition[100];
} Patient;

// Structure for doctor
typedef struct {
    int id;
    char name[50];
    char department[50];
} Doctor;

// Structure for appointment
typedef struct {
    int patient_id;
    int doctor_id;
    char date[20];
    char time[20];
} Appointment;

// Global arrays to store data
Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Appointment appointments[MAX_APPOINTMENTS];

int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;

// Function prototypes
void addPatient();
void addDoctor();
void scheduleAppointment();
void displayPatients();
void displayDoctors();
void displayAppointments();

int main() {
    int choice;

    // Main menu loop
    do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Schedule Appointment\n");
        printf("4. Display Patients\n");
        printf("5. Display Doctors\n");
        printf("6. Display Appointments\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
                break;
            case 3:
                scheduleAppointment();
                break;
            case 4:
                displayPatients();
                break;
            case 5:
                displayDoctors();
                break;
            case 6:
                displayAppointments();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}

// Function to add a new patient
void addPatient() {
    if (patientCount < MAX_PATIENTS) {
        printf("\nEnter patient details:\n");
        printf("ID: ");
        scanf("%d", &patients[patientCount].id);
        printf("Name: ");
        scanf("%s", patients[patientCount].name);
        printf("Age: ");
        scanf("%d", &patients[patientCount].age);
        printf("Medical Condition: ");
        scanf("%s", patients[patientCount].medical_condition);
        patientCount++;
        printf("Patient added successfully.\n");
    } else {
        printf("Patient database is full.\n");
    }
}

// Function to add a new doctor
void addDoctor() {
    if (doctorCount < MAX_DOCTORS) {
        printf("\nEnter doctor details:\n");
        printf("ID: ");
        scanf("%d", &doctors[doctorCount].id);
        printf("Name: ");
        scanf("%s", doctors[doctorCount].name);
        printf("Department: ");
        scanf("%s", doctors[doctorCount].department);
        doctorCount++;
        printf("Doctor added successfully.\n");
    } else {
        printf("Doctor database is full.\n");
    }
}

// Function to schedule a new appointment
void scheduleAppointment() {
    if (appointmentCount < MAX_APPOINTMENTS) {
        printf("\nEnter appointment details:\n");
        printf("Patient ID: ");
        scanf("%d", &appointments[appointmentCount].patient_id);
        printf("Doctor ID: ");
        scanf("%d", &appointments[appointmentCount].doctor_id);
        printf("Date (dd/mm/yyyy): ");
        scanf("%s", appointments[appointmentCount].date);
        printf("Time (hh:mm): ");
        scanf("%s", appointments[appointmentCount].time);
        appointmentCount++;
        printf("Appointment scheduled successfully.\n");
    } else {
        printf("Appointment schedule is full.\n");
    }
}

// Function to display all patients
void displayPatients() {
    printf("\nPatient Records:\n");
    printf("ID\tName\tAge\tMedical Condition\n");
    for (int i = 0; i < patientCount; i++) {
        printf("%d\t%s\t%d\t%s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].medical_condition);
    }
}

// Function to display all doctors
void displayDoctors() {
    printf("\nDoctor Records:\n");
    printf("ID\tName\tDepartment\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("%d\t%s\t%s\n", doctors[i].id, doctors[i].name, doctors[i].department);
    }
}

// Function to display all appointments
void displayAppointments() {
    printf("\nAppointment Schedule:\n");
    printf("Patient ID\tDoctor ID\tDate\tTime\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d\t\t%d\t\t%s\t%s\n", appointments[i].patient_id, appointments[i].doctor_id, appointments[i].date, appointments[i].time);
    }
}