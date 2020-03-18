// VD1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;

#pragma comment(lib, "ws2_32")
char domainname[1024];
int main()
{
	cout << "Nhap tien mien can phan giai :" << endl;
    // Khoi tao thu vien Winsock
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    
	//tao bien de luu du lieu
    addrinfo* info;
    SOCKADDR_IN addr;

	//gia tri nhap vao luu tai domainname
	gets_s(domainname);
	//ret = o neu phan giai duoc ten mien
    int ret = getaddrinfo(domainname, "http", NULL, &info);
		
	if (ret != 0) {
		cout << "Ten mien khong the phan giai";
	}

    if(ret == 0){
		//sao chep vung nho luu gia tri phan giai duoc vao addr
        memcpy(&addr, info->ai_addr, info->ai_addrlen);
        printf("Phan giai ten mien thanh cong\n");
        printf("Dia chi IP: %s", inet_ntoa(addr.sin_addr));
    }
}