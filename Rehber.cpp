#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>//Gökhan Yücel Türkhan 
struct bilgiler
{
	char isim[BUFSIZ];
	char soyad[BUFSIZ];
	char evtelefonu[BUFSIZ];
	char cebtelefonu[BUFSIZ];
	char istelefonu[BUFSIZ];
	char eposta[BUFSIZ];
	char dogumtarihi[BUFSIZ];
	char adres[BUFSIZ];
	int kontrol;
}blg[40];
 int menu()
{
	system("cls");
	printf("1-Kisi ekle\n");
	printf("2-Goruntule\n");
	printf("3-Guncelle\n");
	printf("4-Sil\n");
	printf("5-Arama(ad,soyad,adres ve dogum tarihi vb.)\n");	
	printf("6-Cikis ve kayit etme\n");
}
void goruntule(struct bilgiler* kisi)
{
	system("cls");
	printf("Isim\t\tSoyisim\t\tCep Telefonu\t\tEv Telefonu\t\tIs Telefonu\n");
	for(int i=0;i<40;i++)
    {
    if(kisi[i].kontrol==1)
    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",kisi[i].isim,kisi[i].soyad,kisi[i].cebtelefonu,kisi[i].evtelefonu,kisi[i].istelefonu);
    }
    
    return;
}
void guncelle(struct bilgiler* kisi)
{
	system("cls");
	char telefon[50]; int a=0;
	goruntule(blg);
	printf("\n\nGuncellemek istediginiz kisinin CEP TELEFONUNU giriniz:"); scanf("%s",&telefon); 
	for(int i=0;i<40;i++)
	{
		if(strcmp(kisi[i].cebtelefonu,telefon)==0)
		{
		printf("\nGuncellemek istediginiz kisinin:\n");
		printf("Ismini giriniz:"); scanf("%s",&kisi[i].isim); 
		printf("Soyadini giriniz:"); scanf("%s",&kisi[i].soyad);
		printf("Ev telefonunu giriniz:"); scanf("%s",&kisi[i].evtelefonu);
		printf("Cep telefonunu giriniz:"); scanf("%s",&kisi[i].cebtelefonu);
		printf("Is telefonunu giriniz:"); scanf("%s",&kisi[i].istelefonu);
		printf("E-Postasini giriniz:"); scanf("%s",&kisi[i].eposta);
		printf("Dogum tarihini giriniz:"); scanf("%s",&kisi[i].dogumtarihi);
		printf("Adres giriniz:"); scanf("%s",&blg[i].adres); fflush(stdin);
		a++;
		}
	}
	if(a==0)
	{   printf("Kisi bulunamadi..."); getch(); }
	else
	{	printf("Kisi guncellendi..."); getch(); }
	return;
}
char kisisil(struct bilgiler* kisi)
{
	system("cls");
    char secim,emin,isim[50],soyad[50],numara[50],telsecim;
    int sil;
    printf("1-Isim ve soyisme gore sil");
    printf("\n2-Telefon numarasina gore sil\n");
    printf("Hangi islemi yapmak istersiniz[1/2]:"); tsec: secim=getch();
    switch (secim)
    {
    case '1':   
    system("cls"); goruntule(blg);
    printf("\n\nSilmek istediginiz kisinin ismini giriniz :"); scanf("%s",&isim);
	printf("Silmek istediginiz kisinin soyadini giriniz:"); scanf("%s",&soyad);
	break;
    case '2':  	
    system("cls"); goruntule(blg);
    printf("\n\n1-Cep telefonu");
    printf("\n2-Ev telefonu");
    printf("\n3-Is telefonu");
	printf("\nSilmek istediginiz kisinin hangi telefon numarasini gireceksiniz:"); telsecim=getch(); 
	printf("\nNumarayi giriniz:"); scanf("%s",&numara); break;
	}
	for(int i=-1;i<40;)
    {
    	sil2:
    	i++;
    	sil=55;
    	if(kisi[i].kontrol==1)
        {
        if(secim=='1' && strcmp(kisi[i].isim,isim)==0 && strcmp(kisi[i].soyad,soyad)==0) 
        { sil=i; }
        else if(secim=='2' && strcmp(kisi[i].cebtelefonu,numara)==0 && telsecim=='1')
        { sil=i; }
        else if(secim=='2' && strcmp(kisi[i].evtelefonu,numara)==0 && telsecim=='2')
        { sil=i; }
        else if(secim=='2' && strcmp(kisi[i].istelefonu,numara)==0 && telsecim=='3')
        { sil=i; }
		}
		if(sil==i)
        {
        printf("\nAdi\t\tSoyadi\t\tCep Telefonu\n");
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%s",kisi[i].isim,kisi[i].soyad,kisi[i].cebtelefonu,kisi[i].evtelefonu,kisi[i].istelefonu);
        printf("\nBu kayidi silmek istediginize emin misiniz ? (e-h)"); temin: emin=getch();
        if (emin=='e')
        {
        kisi[i].kontrol=0;
        printf("\nKisi Silindi...");
        }
        else if(emin=='h')
        { goto sil2; }
        else
        {
        printf("\nLutfen e(evet) veya h(hayir) tuslarindan birini giriniz!!"); goto temin;
		}
		getch();
        return kisi[i].kontrol;
        }
    }
	 printf("\nKisi Bulunamadi..");
    getch();
   }
void arama(struct bilgiler* kisi)
{
	system("cls");
	char sec,isim[30],soyad[30],dogumtarihi[20],eposta[50],adres[BUFSIZ];
	printf("1)Isim");
	printf("\n2)Soyisim");
	printf("\n3)Dogum Gunu");
	printf("\n4)E-posta");
	printf("\n5)Adres");
	printf("\nHangi yontemle arama yapmak istersiniz:");  sec=getch();
	switch(sec)
	{
		case '1':
		printf("\nAramak istediginiz ismi giriniz:"); scanf("%s",&isim);
		system("cls");
		printf("Isim\t\tSoyisim\t\tCep Telefonu\t\tEv Telefonu\t\tIs Telefonu\n");
		for(int i=0;i<40;i++)
		{
			if(strcmp(kisi[i].isim,isim)==0 && kisi[i].kontrol==1)
			{
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",kisi[i].isim,kisi[i].soyad,kisi[i].cebtelefonu,kisi[i].evtelefonu,kisi[i].istelefonu);
			}
		} break;
		case '2':
		printf("\nAramak istediginiz soyadi giriniz:"); scanf("%s",&soyad);
		system("cls");
		printf("Isim\t\tSoyisim\t\tCep Telefonu\t\tEv Telefonu\t\tIs Telefonu\n");
		for(int i=0;i<40;i++)
		{
			if(strcmp(kisi[i].soyad,soyad)==0 && kisi[i].kontrol==1)
			{
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",kisi[i].isim,kisi[i].soyad,kisi[i].cebtelefonu,kisi[i].evtelefonu,kisi[i].istelefonu);
			}
		} break;
		case '3':
		printf("\nAramak istediginiz kisinin dogum gununu giriniz:"); scanf("%s",&dogumtarihi);
		system("cls");
		printf("Isim\t\tSoyisim\t\tCep Telefonu\t\tEv Telefonu\t\tIs Telefonu\n");
		for(int i=0;i<40;i++)
		{
			if(strcmp(kisi[i].dogumtarihi,dogumtarihi)==0 && kisi[i].kontrol==1)
			{
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",kisi[i].isim,kisi[i].soyad,kisi[i].cebtelefonu,kisi[i].evtelefonu,kisi[i].istelefonu);
			}
		} break;
		case '4':
		printf("\nAramak istediginiz e-postayi giriniz:"); scanf("%s",&eposta);
		system("cls");
		printf("Isim\t\tSoyisim\t\tCep Telefonu\t\tEv Telefonu\t\tIs Telefonu\n");
		for(int i=0;i<40;i++)
		{
			if(strcmp(kisi[i].eposta,eposta)==0 && kisi[i].kontrol==1)
			{
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",kisi[i].isim,kisi[i].soyad,kisi[i].cebtelefonu,kisi[i].evtelefonu,kisi[i].istelefonu);
			}
		} break;
		case '5':
		system("cls");
		printf("\nAramak istediginiz adresi giriniz:"); scanf("%s",&adres); fflush(stdin);
		printf("Isim\t\tSoyisim\t\tCep Telefonu\t\tEv Telefonu\t\tIs Telefonu\n");
			for(int i=0;i<40;i++)
		{
			if(strcmp(kisi[i].adres,adres)==0 && kisi[i].kontrol==1)
			{
			printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",kisi[i].isim,kisi[i].soyad,kisi[i].cebtelefonu,kisi[i].evtelefonu,kisi[i].istelefonu);
			}
		} break;
	}
	getch();
	return;
}

main()
{
	int i=0;
	for(int i=0;i<40;i++)
    {
        blg[i].kontrol=0;
	}
	FILE *oku;
	oku=fopen("rehber.txt","r");
	fscanf(oku,"Isim\t\tSoyisim\t\tCep Telefonu\t\tEv Telefonu\t\tIs Telefonu\n");
	if(oku!=NULL)
	{
	while(!feof(oku))
	{
	fscanf(oku,"%s %s %s %s %s",blg[i].isim,blg[i].soyad,blg[i].cebtelefonu,blg[i].evtelefonu,blg[i].istelefonu);
	blg[i].kontrol=1;
	i++;
	}}
	blg[i-1].kontrol=0;
	bura:
	char secim;
	menu();
	printf("Yapmak istediginiz islemi seciniz:"); secim=getch();	
	switch(secim)
	{
		case '1': 
	buraya:
	
	for(int i=0;i<40;i++)
	{
	system("cls");
	if(blg[i].kontrol==0)
	{
	printf("Lutfen telefon numaralarini 11 haneli giriniz....\n");
	printf("Isim giriniz:"); scanf("%s",&blg[i].isim); fflush(stdin);
	printf("Soyad giriniz:"); scanf("%s",&blg[i].soyad);
	printf("Ev telefonu giriniz:"); scanf("%s",&blg[i].evtelefonu);
	printf("Cep telefonu giriniz:"); scanf("%s",&blg[i].cebtelefonu);
	printf("Is telefonu giriniz:"); scanf("%s",&blg[i].istelefonu);
	printf("E-Posta giriniz:"); scanf("%s",&blg[i].eposta);
	printf("Dogum tarihi giriniz:"); scanf("%s",&blg[i].dogumtarihi);
	printf("Adres giriniz:"); scanf("%s",&blg[i].adres); fflush(stdin);

	blg[i].kontrol=1;
	printf("\nKisi eklendi...");
    printf("\nTekrar ekleme isi yapmak istermisiniz:[e/h]?"); 
	tsec:
	char sec; sec=getch();
	if(sec=='e' || sec=='E')
	{printf("\n");}
	else if(sec=='h' || sec=='H')
	{
		break;
	}
	else
	{
		printf("\ne veya h ye basiniz!!");
		goto tsec;
	}
	}
	}	break;
	case '2': goruntule(blg); getch(); break;
	case '3': guncelle(blg); break;
	case '4': kisisil(blg); break;
	case '5': arama(blg); break;
	case '6': goto cikis; 
	default : ;
	}
	goto bura;
	cikis: 
	FILE *dosya;
	dosya=fopen("rehber.txt","w");
	fprintf(dosya,"Isim\t\tSoyisim\t\tCep Telefonu\t\tEv Telefonu\t\tIs Telefonu\n");
	for(int i=0;i<40;i++)
    {
    if(blg[i].kontrol==1)
    fprintf(dosya,"%s\t\t%s\t\t%s\t\t%s\t\t%s\n",blg[i].isim,blg[i].soyad,blg[i].cebtelefonu,blg[i].evtelefonu,blg[i].istelefonu);
    }
	
}
