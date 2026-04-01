#include <iostream>
#include <string>
using namespace std;



struct Package{
    string packageID;
    string destinationCity;
    int dimensions[3]; // length,width,height
    Package* next;
};

struct Courier {
    string courierName;
    string vehicleType;
};

// Global değişkenler
Package* ilkPaket = NULL;
Courier kuryeler[5];
int kuryeSayisi = 0;
int siradakiKurye = 0;


void push(string id, string city, int l, int w, int h) {
    Package* newPackage = new Package();
    newPackage->packageID = id;
    newPackage->destinationCity = city;
    newPackage->dimensions[0] = l;
    newPackage->dimensions[1] = w;
    newPackage->dimensions[2] = h;
    newPackage->next = NULL;

    if (ilkPaket == NULL) {
        ilkPaket = newPackage;
    } else {
        Package* temp = ilkPaket;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPackage;
    }
    cout << "paket eklendi: " << id << "\n";
}


void enqueue(string isim, string arac) {
    if (kuryeSayisi == 5) {
        cout << "kurye doldu yer yok!\n";
        return;
    }
    kuryeler[kuryeSayisi].courierName = isim;
    kuryeler[kuryeSayisi].vehicleType = arac;
    kuryeSayisi++;
    cout << isim << " eklendi.\n";
}


void dispatch() {
    if (ilkPaket == NULL) {
        cout << "Hata: Dagitilacak package kalmadi!\n";
        return;
    }

    Package* packageToDeliver = ilkPaket;

    ilkPaket = ilkPaket->next;

    if (siradakiKurye >= kuryeSayisi) {
        cout << "Hata: Bekleyen courier kalmadi!\n";
        return;
    }
    cout << "Courier " << kuryeler[siradakiKurye].courierName
         << " took package " << packageToDeliver->packageID << " and left.\n";

    delete packageToDeliver;
    siradakiKurye++;
    }

void display() {
    cout << "\n--- DURUM ---\n";
    cout << "Paketler:\n";
    Package* temp = ilkPaket;
    while(temp != NULL) {
        cout << temp->packageID << "\n";
        temp = temp->next;
    }

    cout << "Kuryeler:\n";
    for (int i = siradakiKurye; i < kuryeSayisi; i++) {
        cout << kuryeler[i].courierName << "\n";
    }
    cout << "-------------\n";
}

int main() {
    push("A1", "Bursa", 10,10,10);
    push("A2", "Izmir", 20,20,20);

    enqueue("Ali", "Motor");
    enqueue("Ayşe", "Car");


    dispatch();
    display();

    return 0;
}




