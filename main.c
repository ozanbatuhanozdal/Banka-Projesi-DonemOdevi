#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//struct tanımlandı
 struct Hesaplar {

    int hesapNo;
    float hesapBakiye;
    float hesapLimit;


    };
    struct Tarih {

        int gun;
        int ay;
        int yil;

    };
    struct timeinfo {

        int gun

    };
     struct Musteriler {

    char MusteriIsim[20];
    char MusteriTelNo[20];
    char musteriAdres[20];
    char musteriKimlikNo[20];
    char musteriYas[3];
    int musteriTipi;
    int MusteriNo;

        }Musteriler,MusteriHesap;


          // ANA MENU
    void Menu()
    {
        int secim;
     printf("\n\n\t\t\tBanka Otomasyon Yazilimi");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Ana Menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Yeni Musteri Olustur\n\t\t2.Hesap Acma\n\t\t3.Hesaptan Para Cekme\n\t\t4.Hesaba Para Yatirma\n\t\t5.Baska Hesaba Havale\n\t\t6.Banka Gelir-Gider Raporu\n\t\t7.Hesap Ozeti\n\t\t8.Hesap Kapama\n\t\t0.Cikis\n\n\n\n\n\t\t Seciminizi Yapin:");
    scanf("%d",&secim);

    switch(secim)
    {
        case 1:yeni_Musteri();
        break;
        case 2:yeni_Hesap();
        break;
        case 3:para_Cekme();
        break;
        case 4:para_Yatirma();
        break;
        case 5:havale();
        break;
        case 6:rapor();
        break;
        case 7:hesap_Ozeti();
        break;
        case 8:hesap_Kapat();
        break;
        case 0:exit(0);
        break;
        default:
            {
                printf("1 ile 8 arasi bir sayi giriniz.Cikmak icin 0':");
                system("cls");
                Menu();
            }
    }
    }
//yeni musteri
    void yeni_Musteri()
    {
        struct Musteriler *pMusteri,sMusteriler;
        struct Hesaplar  *pHesap,sHesap;
        struct Tarih *pTarih,sTarih;
        memset(&sMusteriler, 0, sizeof(sMusteriler));
        memset(&sHesap, 0, sizeof(sHesap));
        memset(&sTarih, 0, sizeof(sTarih));



        pMusteri = &sMusteriler;
        pHesap  =&sHesap;
        pTarih = &sTarih;

        int cikis;
        system("cls");
        int secim,RmusteriNo,RhesapNo;
        //tarih ve random sayı
        time_t rawtime;
        struct tm *timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        FILE *Musteri,*hesapFile,*yatirilanFile;
        Musteri= fopen("Musteriler.txt","a+");
        hesapFile = fopen("Hesaplar.txt","a+");
        yatirilanFile = fopen("YatirilanPara.txt","a+");
        srand(time(NULL));
        RmusteriNo =  rand() % 100;
        RhesapNo =  rand() % 1000;
        printf("MusteriIlk:%d\n",RmusteriNo);
          printf("HesapIlk:%d\n",RhesapNo);
          while(fscanf(Musteri,"%d %d %s %s %s %s %s %d %f %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,pMusteri->MusteriIsim,pMusteri->musteriKimlikNo,pMusteri->musteriYas,pMusteri->musteriAdres,pMusteri->MusteriTelNo,&pMusteri->musteriTipi,&pHesap->hesapBakiye,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
       {

            while(RmusteriNo == pMusteri->MusteriNo)
            {
                    srand(time(0));
                    RmusteriNo =  rand() % 100;
                    printf("Musteri:%d\n",RmusteriNo);
                    rewind(Musteri);

            }
        }

        while(fscanf(hesapFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
                while(RhesapNo == pHesap->hesapNo)
            {
                     srand(time(0));
                     RhesapNo =  rand() % 1000;
                     printf("Hesap:%d\n",RhesapNo);
                     rewind(hesapFile);
            }
        }

        pMusteri->MusteriNo = RmusteriNo;
        pHesap->hesapNo = RhesapNo;
        printf("%Olusan Musteri Numaraniz:%d\n",pMusteri->MusteriNo);
        printf("%Olusan Hesap Numaraniz:%d\n",pHesap->hesapNo);
        printf("\nMusterinin ismini giriniz:");
        scanf("%s",pMusteri->MusteriIsim);
        printf("\nMusterinin kimlik Numarasini giriniz:");
        scanf("%s",pMusteri->musteriKimlikNo);
        printf("\nMusterinin Yasini giriniz:");
        scanf("%s",pMusteri->musteriYas);
        printf("\nMusterinin Adresini giriniz:");
        scanf("%s",pMusteri->musteriAdres);
        printf("\nMusterinin telefon Numarasini giriniz:");
        scanf("%s",pMusteri->MusteriTelNo);
        printf("\nMusteri Tipini Giriniz Bireysel:1/Ticari:2:");
        scanf("%d",&pMusteri->musteriTipi);
        printf("\nHesap Baslangic Bakiyesini Giriniz:");
        scanf("%f",&pHesap->hesapBakiye);
        pHesap->hesapLimit = 0;

        fprintf(Musteri,"%d %d %s %s %s %s %s %d %f %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pMusteri->MusteriIsim,pMusteri->musteriKimlikNo,pMusteri->musteriYas,pMusteri->musteriAdres,pMusteri->MusteriTelNo,pMusteri->musteriTipi,pHesap->hesapBakiye,timeinfo ->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
        fclose(Musteri);
        fprintf(hesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
        fclose(hesapFile);
        fprintf(yatirilanFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
        fclose(yatirilanFile);
        FILE *ticariFile,*bireyselFile;
        ticariFile= fopen("ticariHesaplar.txt","a+");
        bireyselFile= fopen("bireyselHesaplar.txt","a+");
        if(pMusteri->musteriTipi==1)
        {
            fprintf(bireyselFile,"%d %d %s %s %s %s %s %d %f %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pMusteri->MusteriIsim,pMusteri->musteriKimlikNo,pMusteri->musteriYas,pMusteri->musteriAdres,pMusteri->MusteriTelNo,pMusteri->musteriTipi,pHesap->hesapBakiye,timeinfo ->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);

        }
        if(pMusteri->musteriTipi==2)
        {
            fprintf(ticariFile,"%d %d %s %s %s %s %s %d %f %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pMusteri->MusteriIsim,pMusteri->musteriKimlikNo,pMusteri->musteriYas,pMusteri->musteriAdres,pMusteri->MusteriTelNo,pMusteri->musteriTipi,pHesap->hesapBakiye,timeinfo ->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
        }
        fclose(ticariFile);
        fclose(bireyselFile);
        system("cls");
        printf("\nMusteri Basariyla Olusturuldu!");

        printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
        scanf("%d",&cikis);
        system("cls");
        if (cikis==1)
        Menu();
        else if(cikis==0)
            close();

    }
    //yeni hesap olusturma

     yeni_Hesap()
    {
        struct Musteriler *pMusteri,sMusteriler;
        struct Hesaplar  *pHesap,sHesap;
        struct Tarih *pTarih,sTarih;
        memset(&sMusteriler, 0, sizeof(sMusteriler));
        memset(&sHesap, 0, sizeof(sHesap));
        memset(&sTarih, 0, sizeof(sTarih));

        pMusteri = &sMusteriler;
        pHesap  =&sHesap;
        pTarih = &sTarih;


        system("cls");
        int musteriNo;
        int RhesapNo;
        int kontrol=0;
        int cikis;
        int musteriT;
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        printf("\n \n \tYeni Hesap Acmak Istediginiz Musterinin Numarasini Girin:");
        scanf("%d",&musteriNo);
        FILE *hesapFile,*yatirilanFile;
        hesapFile = fopen("Hesaplar.txt","a+");
        yatirilanFile = fopen("YatirilanPara.txt","a+");
        srand(time(NULL));
        RhesapNo =  rand() % 1000;
        printf("HesapIlk:%d\n",RhesapNo);
         while(fscanf(hesapFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
            if(musteriNo==pMusteri->MusteriNo)
            {
                kontrol++;
                musteriT = pMusteri->MusteriNo;

            }
               while(RhesapNo == pHesap->hesapNo)
            {
                     srand(time(0));
                     RhesapNo =  rand() % 1000;
                     printf("Hesap:%d\n",RhesapNo);
                     rewind(hesapFile);
            }
        }

        if(kontrol == 0)
        {
            printf("\tGirdiginiz Musteri Numarasi Sistemde Bulunmamaktadir...\n");
            printf("\n\n\n\t\tAna menuye donmek icin:1");
        scanf("%d",&cikis);
        system("cls");
        if (cikis==1)
        Menu();

        }
        pHesap->hesapLimit = 0;
        pHesap->hesapNo = RhesapNo;
        pMusteri->MusteriNo= musteriNo;
        printf("Baslangic Bakiyesini Giriniz:");
        scanf("%f",&pHesap->hesapBakiye);
       fprintf(hesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
        fclose(hesapFile);
        fprintf(yatirilanFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
        fclose(yatirilanFile);
        system("cls");
        printf("Hesabiniz Basariyla olusturuldu");
         printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
        scanf("%d",&cikis);
        system("cls");
        if (cikis==1)
        Menu();
        else if(cikis==0)
            close();

    }
//para cekme

     para_Cekme()
    {
        struct Musteriler *pMusteri,sMusteriler;
        struct Hesaplar  *pHesap,sHesap;
        struct Tarih *pTarih,sTarih;
        memset(&sMusteriler, 0, sizeof(sMusteriler));
        memset(&sHesap, 0, sizeof(sHesap));
        memset(&sTarih, 0, sizeof(sTarih));



        pMusteri = &sMusteriler;
        pHesap  =&sHesap;
        pTarih = &sTarih;



        system("cls");
        remove("hesap.txt");
        int hesapNo2,hesapNo1,MusteriNo,cikis,kontrol=0,kontrol2=0;
        float cekMiktar,yeniBakiye,ilkBakiye,kalanPara,hesapLimiti,kontrolLimit;
        float toplamBakiye=0;
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        printf("\tMusteri Numaranizi Giriniz:");
        scanf("%d",&MusteriNo);
        FILE *hesapFile,*yeniHesapFile,*hesapFile2,*hesapFile3,*yeniHesapFile2,*cekilenHesap;
        hesapFile = fopen("Hesaplar.txt","a+");
        hesapFile2 = fopen("Hesaplar.txt","r+");
        yeniHesapFile = fopen("hesap.txt","a+");
        cekilenHesap = fopen("CekilenPara.txt","a+");

         while(fscanf(hesapFile2,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
                if(MusteriNo == pMusteri->MusteriNo)
                                {
                                printf("Hesaplariniz: \t%d %d %f %f \n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit);
                                toplamBakiye += pHesap->hesapBakiye;
                                kontrol++;
                                }

         }
         if(kontrol ==0)
         {
                printf("Girdiginiz Musteri numarasi sistemde bulunmamaktadir...");
                printf("\n\n\n\t\tTekrardan Para Cekmek Icin:2-Ana menuye donmek icin:1 - Cikis icin 0'a Basiniz:");
                scanf("%d",&cikis);
                system("cls");
                if (cikis==1)
                Menu();
                else if(cikis==2)
                para_Cekme();
                else if(cikis==0)
                exit(0);

         }
                printf("Hesaplarinizdaki Toplam Para:%f\n",toplamBakiye);
                printf("Cekmek istediginiz miktari giriniz:");
                scanf("%f",&cekMiktar);

          printf("\tPara Cekmek Istediginiz Hesap Numarasini Giriniz:");
            scanf("%d",&hesapNo2);




                   if(cekMiktar>toplamBakiye)
                {
                    printf("Hesaplardaki Miktardan Fazla Deger Girdiniz.../");
                     printf("\n\n\n\t\tTekrardan Para Cekmek Icin:2-Ana menuye donmek icin:1 - Cikis icin 0'a Basiniz:");
                    scanf("%d",&cikis);
                    system("cls");
                    if (cikis==1)
                    Menu();
                    else if(cikis==2)
                    para_Cekme();
                    else if(cikis==0)
                    exit(0);

                }


          while(fscanf(hesapFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
             if(hesapNo2==pHesap->hesapNo)
                {

                     if(cekMiktar>pHesap->hesapBakiye)
                   {
                        printf("Para cekmek istediginiz ek hesabinizi giriniz:");
                        scanf("%d",&hesapNo1);
                        kontrol2 = 1 ;

                   }



                  //tarihe göre günlük para çekme limiti kontrol edildi
                    if(timeinfo ->tm_mday == pTarih->gun && timeinfo->tm_mon + 1 == pTarih->ay && timeinfo->tm_year + 1900 == pTarih->yil)
                    {

                    }
                    else
                    {
                        pHesap->hesapLimit = 0;
                    }

                    pHesap->hesapLimit += cekMiktar;

                    if(pMusteri->musteriTipi == 1)
                    {

                        if(cekMiktar>750)
                        {

                            printf("Günlük para cekme limitimiz bireysel musteriler icin 750'TL...\n");
                            printf("\n\n\n\t\tTekrardan Para Cekmek Icin:2-Ana menuye donmek icin:1 - Cikis icin 0'a Basiniz:");
                            scanf("%d",&cikis);
                            system("cls");
                            if (cikis==1)
                            Menu();
                            else if(cikis==2)
                            para_Cekme();
                            else if(cikis==0)
                            exit(0);
                        }


                        if(pHesap->hesapLimit>750)
                        {
                            float cekUcret;
                            pHesap->hesapLimit -= cekMiktar;
                            printf("Gunluk para çekme limitini astiniz Limitiniz:750'TL\n");
                            printf("Sizin Bugün Cektiginiz Miktar:%f\n",pHesap->hesapLimit);

                            printf("Gunluk para cekme limitimiz bireysel musteriler icin 750'TL...");
                            printf("\n\n\n\t\tTekrardan Para Cekmek Icin:2-Ana menuye donmek icin:1 - Cikis icin 0'a Basiniz:");
                            scanf("%d",&cikis);
                            system("cls");
                            if (cikis==1)
                            Menu();
                            else if(cikis==2)
                            para_Cekme();
                            else if(cikis==0)
                            exit(0);

                        }

                    }
                        if(pMusteri->musteriTipi == 2)
                    {
                        if(cekMiktar>1500)
                        {
                            printf("Gunluk para cekme limitimiz Ticari musteriler icin 1500'TL...");

                              printf("\n\n\n\t\tTekrardan Para Cekmek Icin:2-Ana menuye donmek icin:1 - Cikis icin 0'a Basiniz:");
                                scanf("%d",&cikis);
                                system("cls");
                                if (cikis==1)
                                Menu();
                                else if(cikis==2)
                                para_Cekme();
                                else if(cikis==0)
                                exit(0);
                        }

                        if(pHesap->hesapLimit>1500)
                        {
                            printf("Gunluk para cekme limitimiz Ticari musteriler icin 1500'TL...\n");
                            printf("Sizin Bugun Cektiginiz Miktar:%f",pHesap->hesapLimit-cekMiktar);


                             printf("\n\n\n\t\tTekrardan Para Cekmek Icin:2-Ana menuye donmek icin:1 - Cikis icin 0'a Basiniz:");
                            scanf("%d",&cikis);
                            system("cls");
                            if (cikis==1)
                            Menu();
                            else if(cikis==2)
                            para_Cekme();
                            else if(cikis==0)
                            exit(0);
                        }

                    }



                if(cekMiktar<=pHesap->hesapBakiye)
                {

                    printf("%f: Para Cektiniz\n",cekMiktar);
                    pHesap->hesapBakiye -= cekMiktar;
                     printf("%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
                    fprintf(yeniHesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
                    printf("Para Cekme Islemi Basarili\n");
                    printf("Hesabinizdaki Yeni Para:%f",pHesap->hesapBakiye);

                     fprintf(cekilenHesap,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,cekMiktar,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);

                }
                else
                {



                        printf("girdi");

                        ilkBakiye = pHesap->hesapBakiye;
                        printf("%f: Para Cektiniz\n",pHesap->hesapBakiye);
                        pHesap->hesapBakiye = 0;
                        printf("%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
                        fprintf(yeniHesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,ilkBakiye,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
                        fprintf(cekilenHesap,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,ilkBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);

                }
            }
            else
                    {
                    fprintf(yeniHesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                    }
        }



        fclose(hesapFile);
        fclose(yeniHesapFile);
        fclose(hesapFile2);
        remove("Hesaplar.txt");
        rename("hesap.txt","Hesaplar.txt");


    if(kontrol2 == 1)
    {





         yeniHesapFile2 = fopen("hesap.txt","a+");
         hesapFile3 = fopen("Hesaplar.txt","a+");

           while(fscanf(hesapFile3,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
                    if(hesapNo1==pHesap->hesapNo)
                        {

                             if(timeinfo ->tm_mday == pTarih->gun && timeinfo->tm_mon + 1 == pTarih->ay && timeinfo->tm_year + 1900 == pTarih->yil)
                                {

                                }
                                else
                                {
                                    pHesap->hesapLimit = 0;
                                }


                            kalanPara = cekMiktar - ilkBakiye;
                            pHesap->hesapBakiye -= kalanPara;
                            pHesap->hesapLimit += kalanPara;

                              if(pMusteri->musteriTipi == 1)
                    {
                        printf("tip2 kontrole girdi\n");

                        if(pHesap->hesapLimit>750)
                        {
                            printf("Gunluk para çekme limitini astiniz Limitiniz:750'TL\n");
                            printf("Sizin Bugün Cektiginiz Miktar:%f",pHesap->hesapLimit );



                        }

                    }
                        if(pMusteri->musteriTipi == 2)
                    {

                        if(pHesap->hesapLimit>1500)
                        {
                            printf("Günlük para cekme limitimiz Ticari müsteriler icin 1500'TL...");
                            printf("Sizin Bugün Cektiginiz Miktar:%f",pHesap->hesapLimit );
                             printf("\n\n\n\t\tTekrardan Para Cekmek Icin:2-Ana menuye donmek icin:1 - Cikis icin 0'a Basiniz:");
                            scanf("%d",&cikis);
                            system("cls");
                            if (cikis==1)
                            Menu();
                            else if(cikis==2)
                            para_Cekme();
                            else if(cikis==2)
                            exit(0);

                        }

                    }


                            printf("%f: Para Cektiniz\n",kalanPara);
                            printf("%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
                            fprintf(yeniHesapFile2,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);
                            printf("Para Cekme Islemi Basarili\n");
                            printf("Hesabinizdaki Yeni Para:%f",pHesap->hesapBakiye);
                             fprintf(cekilenHesap,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,kalanPara,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);

                         }
                       else
                    {

                    fprintf(yeniHesapFile2,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                    }


        }
            fclose(hesapFile3);
                fclose(yeniHesapFile2);
                    fclose(cekilenHesap);


                remove("Hesaplar.txt");
                rename("hesap.txt","Hesaplar.txt");





    }



                          printf("\n\n\n\t\tTekrardan Para Cekmek Icin:2 - Ana menuye donmek icin:1 - Cikis icin 0'a Basiniz:son");
                    scanf("%d",&cikis);
                    system("cls");
                    if (cikis==1)
                    Menu();
                    else if(cikis==2)
                    para_Cekme();
                    else if(cikis==0)
                    exit(0);


    }
    //para yatırma

     para_Yatirma()
    {
        struct Musteriler *pMusteri,sMusteriler;
        struct Hesaplar  *pHesap,sHesap;
        struct Tarih *pTarih,sTarih;
        memset(&sMusteriler, 0, sizeof(sMusteriler));
        memset(&sHesap, 0, sizeof(sHesap));
        memset(&sTarih, 0, sizeof(sTarih));



        pMusteri = &sMusteriler;
        pHesap  =&sHesap;
        pTarih = &sTarih;



        system("cls");
        int hesapNo,cikis,kontrol=0;
        float paraYatir;
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        FILE *hesapFile,*yeniHesapFile,*yatirilanHesap;
        hesapFile = fopen("Hesaplar.txt","a+");
        yeniHesapFile = fopen("hesap.txt","a+");
        yatirilanHesap = fopen("YatirilanPara.txt","a+");
        printf("Para yatirmak istediginiz hesap numarasini giriniz:");
        scanf("%d",&hesapNo);



          while(fscanf(hesapFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {

             if(hesapNo==pHesap->hesapNo)
             {
                 printf("Yatiracaginiz miktari giriniz:");
                scanf("%f",&paraYatir);

                printf("Hesabinizdaki Eski Para:%f\n",pHesap->hesapBakiye);


                 pHesap->hesapBakiye += paraYatir;

                fprintf(yeniHesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                printf("Para Yatirma Islemi Basarili\n");
                printf("Hesabinizdaki Yeni Para:%f",pHesap->hesapBakiye);
                kontrol++;
                 fprintf(yatirilanHesap,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,paraYatir,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);


             }

             else{
                    fprintf(yeniHesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
             }
         }
         if(kontrol ==0)
         {
            printf("Girdiginiz hesap numarasinda hesap yoktur...");
            printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();

         }


        fclose(hesapFile);
        fclose(yeniHesapFile);


        remove("Hesaplar.txt");
        rename("hesap.txt","Hesaplar.txt");

            printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();
            else if(cikis==0)
            exit(0);



    }

//havale
    havale()
    {

         struct Musteriler *pMusteri,sMusteriler;
        struct Hesaplar  *pHesap,sHesap;
        struct Tarih *pTarih,sTarih;
        memset(&sMusteriler, 0, sizeof(sMusteriler));
        memset(&sHesap, 0, sizeof(sHesap));
        memset(&sTarih, 0, sizeof(sTarih));



        pMusteri = &sMusteriler;
        pHesap  =&sHesap;
        pTarih = &sTarih;

         system("cls");
        int hesapNo,havaleHesapNo,cikis,kontrol=0,musteriT;
        float paraYatir,havalePara;
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        FILE *hesapFile,*yeniHesapFile,*hesapFile2,*yeniHesapFile2,*havaleHesap;
        hesapFile = fopen("Hesaplar.txt","a+");
        yeniHesapFile = fopen("hesap.txt","a+");
        printf("Kendi Hesap Numaranizi Giriniz:");
        scanf("%d",&hesapNo);


          while(fscanf(hesapFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
                if(hesapNo == pHesap->hesapNo)
                                {
                                    kontrol++;
                                    musteriT= pMusteri->musteriTipi;
                                printf("Hesabiniz: \t%d %d %f\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye);
                                printf("Yatiracaginiz miktari giriniz:");
                                scanf("%f",&paraYatir);

                                havalePara = paraYatir;

                                if(musteriT == 1)
                                {
                                    paraYatir += (paraYatir / 100) * 2 ;
                                }

                                if(paraYatir>pHesap->hesapBakiye)
                                {
                                    printf("Hesabinizda Bulunan miktardan fazla bir deger girdiniz...");
                                    printf("\n\n\n\t\tAna menuye donmek icin:1");
                                    scanf("%d",&cikis);
                                    system("cls");
                                    if (cikis==1)
                                    Menu();


                                }
                                else
                                {
                                    pHesap->hesapBakiye -= paraYatir;
                                }

                                fprintf(yeniHesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);




                                }
                                else
                                {
                                    fprintf(yeniHesapFile,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                                }

         }

         if(kontrol ==0)
         {
             printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();
            else if(cikis==0)
            close();

         }



        fclose(hesapFile);
        fclose(yeniHesapFile);

        remove("Hesaplar.txt");
        rename("hesap.txt","Hesaplar.txt");

        printf("Havale Yapmak istediginiz hesabin numarasini giriniz:");
        scanf("%d",&havaleHesapNo);
        hesapFile2 = fopen("Hesaplar.txt","a+");
        yeniHesapFile2 = fopen("hesap.txt","a+");
        havaleHesap= fopen("yapilanHavale.txt","a+");


          while(fscanf(hesapFile2,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
                if(havaleHesapNo == pHesap->hesapNo)
                                {
                                    kontrol++;
                                printf("Eski Hesabiniz: \t%d %d %f\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye);
                                pHesap->hesapBakiye += havalePara;
                                  printf("Yeni Hesabiniz: \t%d %d %f\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye);

                                fprintf(yeniHesapFile2,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                                fprintf(havaleHesap,"%d %d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,hesapNo,havaleHesapNo,havalePara,pHesap->hesapLimit,pMusteri->musteriTipi,timeinfo ->tm_mday,timeinfo->tm_mon + 1,timeinfo->tm_year + 1900);

                                }
                                else
                                {
                                    fprintf(yeniHesapFile2,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                                }

         }
         if(kontrol ==1)
         {
             printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();
            else if(cikis==0)
            close();

         }

         fclose(hesapFile2);
        fclose(yeniHesapFile2);
        fclose(havaleHesap);

        remove("Hesaplar.txt");
        rename("hesap.txt","Hesaplar.txt");

         printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();
            else if(cikis==0)
            close();

    }

//rapor
    rapor()
    {
          struct Musteriler *pMusteri,sMusteriler;
        struct Hesaplar  *pHesap,sHesap;
        struct Tarih *pTarih,sTarih;
        memset(&sMusteriler, 0, sizeof(sMusteriler));
        memset(&sHesap, 0, sizeof(sHesap));
        memset(&sTarih, 0, sizeof(sTarih));



        pMusteri = &sMusteriler;
        pHesap  =&sHesap;
        pTarih = &sTarih;


        FILE *raporFile,*yatirilanFile,*cekilenFile,*hesapFile;
        int cikis;
        raporFile = fopen("rapor.txt","w+");
        yatirilanFile = fopen("YatirilanPara.txt","r+");
        cekilenFile = fopen("CekilenPara.txt","r+");
        hesapFile = fopen("Hesaplar.txt","r+");

        float toplamPara=0,cekilen=0,Yatirilan=0;

          while(fscanf(cekilenFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
             cekilen += pHesap->hesapBakiye;
         }

      while(fscanf(yatirilanFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
             Yatirilan += pHesap->hesapBakiye;
         }

         while(fscanf(hesapFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
             toplamPara += pHesap->hesapBakiye;
         }
         system("cls");


        printf("Bankadan cekilen toplam para:%f\n",cekilen);
        printf("Bankaya yatirilan toplam para:%f\n",Yatirilan);
        printf("Bankadaki toplam para:%f\n",toplamPara);

        fprintf(raporFile,"Bankadan cekilen toplam para:%f\n",cekilen);
        fprintf(raporFile,"Bankaya yatirilan toplam para:%f\n",Yatirilan);
        fprintf(raporFile,"Bankadaki toplam para:%f\n",toplamPara);

         fclose(raporFile);
         fclose(yatirilanFile);
         fclose(cekilenFile);
         fclose(hesapFile);

           printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();
            else if(cikis==0)
            close();
    }
    //hesap ozeti
      hesap_Ozeti()
    {
        struct Musteriler *pMusteri,sMusteriler;
        struct Hesaplar  *pHesap,sHesap;
        struct Tarih *pTarih,sTarih;
        memset(&sMusteriler, 0, sizeof(sMusteriler));
        memset(&sHesap, 0, sizeof(sHesap));
        memset(&sTarih, 0, sizeof(sTarih));

        pMusteri = &sMusteriler;
        pHesap  =&sHesap;
        pTarih = &sTarih;

        system("cls");

        FILE *raporFile,*yatirilanFile,*cekilenFile,*hesapFile,*hesapFile2,*havaleHesap,*musteriFile,*dekont;
        int cikis,havaleHesapNo,kontrol=0;
        int gun1,ay1,yil1,gun2,ay2,yil2;
        int tarihHesap1,tarihHesap2,tarihHesap3;
        havaleHesap = fopen("yapilanHavale.txt","r+");
        yatirilanFile = fopen("YatirilanPara.txt","r+");
        cekilenFile = fopen("CekilenPara.txt","r+");
        hesapFile2 = fopen("Hesaplar.txt","r+");
        musteriFile = fopen("Musteriler.txt","r+");
        dekont = fopen("dekont.txt","w+");

        int hesapNo5;

        printf("Hesap ozetini gormek istediginiz hesabin numarasini giriniz:");
        scanf("%d",&hesapNo5);

          while(fscanf(hesapFile2,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
             if(hesapNo5==pHesap->hesapNo)
             {
                 kontrol++;
             }

         }



              if(kontrol ==0)
        {
                printf("Girdiginiz Hesap Numarasi sistemde bulunmamaktadir..\n");
                printf("\n\n\n\t\tAna menuye donmek icin:1 Tekrardan Ozet Goruntulemek icin:0'a Basiniz:");
                scanf("%d",&cikis);
                system("cls");
                if (cikis==1)
                Menu();
                else if(cikis==0)
                hesap_Ozeti();
        }


//hangi tarih aralığında işlem yapldığı
        printf("Tarih Araligini seciniz:(YY/YY/YYYY)\n");
        printf("Gun:");
        scanf("%d",&gun1);
        printf("Ay:");
        scanf("%d",&ay1);
        printf("Yil:");
        scanf("%d",&yil1);
        printf("Gun:");
        scanf("%d",&gun2);
        printf("Ay:");
        scanf("%d",&ay2);
        printf("Yil:");
        scanf("%d",&yil2);

        tarihHesap1= gun1 + ay1*30 + yil1;
        tarihHesap2 = gun2 + ay2*30 + yil2;


            printf("Cekilen Paralar:\n");
            fprintf(dekont,"Cekilen Paralar:\n");
         while(fscanf(cekilenFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
              if(pHesap->hesapNo == hesapNo5)
             {
                 kontrol++;
                 tarihHesap3 =  pTarih->gun + pTarih->ay*30 + pTarih->yil;
                 if(tarihHesap1<=tarihHesap3 && tarihHesap2>=tarihHesap3)
                 {
                        printf("%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                        fprintf(dekont,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);


                 }


             }
         }
         printf("Yatirilan Paralar:\n");
         fprintf(dekont,"Yatirilan Paralar:\n");

         while(fscanf(yatirilanFile,"%d %d %f %f %d %d %d %d\n",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
         {
             if(pHesap->hesapNo == hesapNo5)
             {
                 kontrol++;

                    tarihHesap3 =  pTarih->gun + pTarih->ay*30 + pTarih->yil;
                 if(tarihHesap1<=tarihHesap3 && tarihHesap2>=tarihHesap3)
                 {
                        printf("%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                        fprintf(dekont,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                 }

             }
         }
        printf("Yapilan Havaleler\n");
        fprintf(dekont,"Yapilan Havaleler\n");
         while(fscanf(havaleHesap,"%d %d %d %f %f %d %d %d %d\n",&pMusteri->MusteriNo,&pHesap->hesapNo,&havaleHesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
         {

             if(pHesap->hesapNo == hesapNo5)
             {
                 kontrol++;
                 tarihHesap3 =  pTarih->gun + pTarih->ay*30 + pTarih->yil;
                 if(tarihHesap1<=tarihHesap3 && tarihHesap2>=tarihHesap3)
                 {

                 printf("%d %d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,havaleHesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);


                fprintf(dekont,"%d %d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,havaleHesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                 }
             }
         }

         fclose(cekilenFile);
         fclose(yatirilanFile);
         fclose(havaleHesap);
         fclose(dekont);

             if(kontrol ==0)
        {
                printf("Girdiginiz Hesap Numarasi sistemde bulunmamaktadir..\n");
                printf("\n\n\n\t\tAna menuye donmek icin:1 Tekrardan Ozet Goruntulemek icin:0'a Basiniz:");
                scanf("%d",&cikis);
                system("cls");
                if (cikis==1)
                Menu();
                else if(cikis==0)
                hesap_Ozeti();
        }


           printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:son");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();
            else if(cikis==0)
            close();
    }
//hesap kapat
      hesap_Kapat()
    {
        struct Musteriler *pMusteri,sMusteriler;
        struct Hesaplar  *pHesap,sHesap;
        struct Tarih *pTarih,sTarih;
        memset(&sMusteriler, 0, sizeof(sMusteriler));
        memset(&sHesap, 0, sizeof(sHesap));
        memset(&sTarih, 0, sizeof(sTarih));



        pMusteri = &sMusteriler;
        pHesap  =&sHesap;
        pTarih = &sTarih;


        system("cls");
        int hesapNo6,secim,cikis,kontrol=0;
        printf("Kapatmak Istediginiz hesabin numarasini giriniz:");
        scanf("%d",&hesapNo6);

        FILE *hesapFile,*hesapFile2;
        hesapFile = fopen("Hesaplar.txt","a+");
        hesapFile2 = fopen("hesap.txt","a+");

           while(fscanf(hesapFile,"%d %d %f %f %d %d %d %d",&pMusteri->MusteriNo,&pHesap->hesapNo,&pHesap->hesapBakiye,&pHesap->hesapLimit,&pMusteri->musteriTipi,&pTarih->gun,&pTarih->ay,&pTarih->yil)!=EOF)
        {
             if(hesapNo6==pHesap->hesapNo)
             {
                 kontrol++;
                 if(pHesap->hesapBakiye>0)
                 {
                     printf("Hesabinizda %f kadar miktar bulunmaktadir..\nParanizi cekmeden hesabinizi kapatamassiniz paranizi cekmek istiyor musunuz?\n Evet/1 Ana Menuye donmek icin 2/....:",pHesap->hesapBakiye);
                     scanf("%d",&secim);

                     if(secim==1)
                     {
                         printf("%f'kadar para cektiniz",pHesap->hesapBakiye);
                     }
                     else if(secim ==2)
                     {
                         Menu();
                     }
                     }
             }
              else
                {
                          fprintf(hesapFile2,"%d %d %f %f %d %d %d %d\n",pMusteri->MusteriNo,pHesap->hesapNo,pHesap->hesapBakiye,pHesap->hesapLimit,pMusteri->musteriTipi,pTarih->gun,pTarih->ay,pTarih->yil);
                            }
         }
          if(kontrol ==0)
         {
             printf("Girdiginiz Hesap Bulunamamistir\n");
             printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();
            else if(cikis==0)
            close();

         }
         fclose(hesapFile);
         fclose(hesapFile2);

        remove("Hesaplar.txt");
        rename("hesap.txt","Hesaplar.txt");

            printf("\n\n\n\t\tAna menuye donmek icin:1 Sistemden cikmak icin:0'a Basiniz:");
            scanf("%d",&cikis);
            system("cls");
            if (cikis==1)
            Menu();
            else if(cikis==0)
            close();

    }

int main()
{

    Menu();
    return 0;
}
