#include <iostream>
#include <string>

using namespace std;



    struct Song{
        string title;
        string artist;
        int ratings[3];
        Song* next;
        Song* prev;
    };

    Song* head = NULL;
    Song* current = NULL;

    void addSong(string t, string a, int r1, int r2, int r3){
        Song* newSong = new Song;
        newSong->title = t;
        newSong->artist = a;
        newSong->ratings[0] = r1;
        newSong->ratings[1] = r2;
        newSong->ratings[3] = r3;
        newSong->next = NULL;
        newSong->prev = NULL;

        if (head == NULL) {
        head = newSong;
        current = newSong;
    }
    else {
        Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
        newSong->prev = temp;
    }

    }
    void nextSong(){
        if(current != NULL && current->next != NULL){
            current = current->next;
            cout<<"sonraki sarkiya gecildi"<<current->title;
        }
        else{
            cout<<"HATA:zaten ilk sarkidasiniz veya liste bos!\n\n";
        }
    }
    void preSong(){
        if(current != NULL && current->prev !=NULL){
            current = current->prev;
            cout<<"onceki sarkiya gecildi"<<current->title;
        }
        else{
            cout<<"HATA:zaten ilk sarkidasiniz veya liste bos!\n\n";
        }
    }
    void removeCurrent(){
        if(current == NULL){
            cout<<"silinecek sarki yok!!\n\n";
            return;
        }
        Song* toDelete = current;

        if(current->prev == NULL && current->next == NULL){
            head = NULL;
            current = NULL;
        }
        else if(current->prev == NULL){
            head = current->next;
            head->prev = NULL;
            current = head;
        }
        else if(current->next == NULL){
            current = current->prev;
            current->next = NULL;
        }
        else{
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
        }
        cout<<"sarki basariyla silindi"<<toDelete->title;
        delete toDelete;
    }
    void display(){
        cout<<"---OYNATMA LISTESI---\n";
        if(head == NULL){
            cout<<"liste bos!!!\n";
            return;
        }
        Song* temp = head;
        while(temp != NULL){
            if(temp == current){
                cout<<"->";
            }
            cout << temp->title << " - " << temp->artist << " Puanlar";

            for(int i=0;i<3;i++){
                cout << temp->ratings[i] << " ";
            }
            temp = temp->next;
        }
    }
    int main(){
        int secim;

        while(true){
            display();

            cout<<"MENU:\n";
            cout<<"1. Yeni Sarki Ekle\n";
            cout<<"2. Sonraki Sarkiya Gec\n";
            cout<<"3. Onceki Sarkiya Gec\n";
            cout<<"4. Gecerli Sarkiyi Sil\n";
            cout<<"5. Cikis\n";
            cin>> secim;

            switch (secim){
                case 1: {
                    string t, a;
                    int r1, r2, r3;

                    cout<<"Sarki adi: ";
                    getline(cin, t);

                    cout<<"Sanatci adi: ";
                    getline(cin, a);

                    cout<<"3 farkli elestirmen puani girin: ";
                    cin >> r1 >> r2 >> r3;

                    addSong(t, a, r1, r2, r3);
                    cout << "Sarki basariyla eklendi";
                    break;
                }
                case 2:
                    nextSong();
                    break;
                case 3:
                    preSong();
                    break;
                case 4:
                    removeCurrent();
                    break;
                case 5:
                    cout << "Programdan cikiliyor...";
                    return 0;
                default:
                    cout<<"Gecersiz Secim!!!";
                    break;
            }
        }
     return 0;
    }


