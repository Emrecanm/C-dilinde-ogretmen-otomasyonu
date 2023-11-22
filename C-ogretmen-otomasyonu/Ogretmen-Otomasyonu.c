#include <stdio.h>//standart imput output kutuphanesi
#include <math.h>//matematik kutuphanesi
#include <string.h>//karakter dizisi kutuphanesi

#define SINIF_MEVCUDU 10  //sinif mevcudunu tanimlar
#define VIZE_1 0.2  //vize1 in ne kadar etki etti?ini tanimlar
#define VIZE_2 0.3  //vize2 nin ne kadar etki edece?ini tanimlar
#define FINAL 0.5   //final in ne kadar etki etti?ini tanimlar

int sinif_mevcudu=0,basari_notu_hesaplmasi=0;// basmasi gereken komuta basmadiginda uyari vermesi icin
char ad[SINIF_MEVCUDU][50],soyad[SINIF_MEVCUDU];//Ad ve soyadlary depolayan dizi
char harf[9][2] = {{'A', 'A'},{'B', 'A'},{'B', 'B'},{'C', 'B'},{'C', 'C'},{'D', 'C'},{'D', 'D'},{'F', 'D'},{'F', 'F'}};//Harf notlarini depolayan dizi
char durumu[3][15]={{"Gecti"},{"Kaldi"},{"Sorunlu Gecti"}};//Ki?inin kalyp geçmesini depolayan dizi
int vize1[SINIF_MEVCUDU],vize2[SINIF_MEVCUDU],final[SINIF_MEVCUDU];//vie vize 2 ve final notlaryny depolayan dizi
double ort[SINIF_MEVCUDU];//synyftaki ö?rencilerin ortalamasyny depolayan dizi

void MenuyuYaz(void);//menü yazdyran deger döndermeye fonksiyon
void adTakas(char *, char *);//dizi icindeki elemanlari degistiren fonksiyon
double EnYuksekNotHesaplama(double[],double);//en yüksek notu hesaplayan geriye int bir deger donderen fonksiyon
double EnDusukNotHEsaplama(double[],double);//en düsük notu hesaplayan geriye int deger donderen fonksiyon
double SinifOrtalamasiHesapla(double[],double);//sinifin ortalamasini hesaplayan geriye double deger donderen fonksiyon
double StandartSapmaHesaplama(double[],double);//standart sapmayi hesaplayan geriye double deger donderen fonksiyon

int main(void)//ana fonsiyon
{
	int islem;


		while(1)//ssonsuz döngü
		{
		    MenuyuYaz();

			printf("Bir Islem Seciniz: ");
			scanf("%d",&islem);

			 if(islem==1)//eger islem 1 e esitse komutlari calistir
			{
				int i,j;

				if(sinif_mevcudu==SINIF_MEVCUDU)//sinif mevcudu dolu ise asagidaki uyariyi ver
				{
					printf("\n<<------------------->>\n");
					printf("Sinif Mevcucu Dolu!!");
					printf("\n<<------------------->>\n\n");

				}

				else if(sinif_mevcudu<=SINIF_MEVCUDU)//sinif mevcudu dolu degilse komutlari calistir
				{
					printf("\n<<------------->>\n");
						printf("***Kayit Ekle***");
					printf("\n<<------------->>\n\n");

					for(i=0;i<SINIF_MEVCUDU;i++)//sinif mevcudu kadar ad soyad vize1 vize2 final notlarýný al
					{
						printf("Adi: ");
						scanf("%s",&ad[i]);
						printf("Soyadi: ");
						scanf("%s",&soyad[i]);
						printf("1. Ara Sinavi Giriniz: ");
						scanf("%d",&vize1[i]);
						printf("2. Ara Sinavi Giriniz: ");
						scanf("%d",&vize2[i]);
						printf("Final Notunu Giriniz: ");
						scanf("%d",&final[i]);
						printf("\n");
						sinif_mevcudu++;
					}
					printf("\n<<------------------------------------------------------------------------->>\n\n");

					printf("%s\t\t%s\t\t%s\t\t%s\t\t%s","Ad","Soyad","Vize1","Vize2","Final");
					printf("\n");


					for(j=0;j<SINIF_MEVCUDU;j++)
						printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\n",ad[j],soyad[j],vize1[j],vize2[j],final[j]);

					printf("\n<<---------------------------------------------------------------------------->>\n\n");
				}
			}



			else if(islem==2)//eger islem 2 e esitse asagidaki komutlari calistir
			{
				int i,j,e;
				char gecici[SINIF_MEVCUDU][2];


				if(sinif_mevcudu==0)//sinif mevcudu dolmamissa asagidaki uyariyi ver
				{
					printf("\n<<---------------------------------------------------------------->>\n");
					printf("-Kisi eklemeden basari notu hesaplanamaz.\n-Sinif kayit ekranindan kayit ekleme islemi gerceklestiriniz!");
					printf("\n<<--------------------------------------------------------------->>\n\n");
				}

				else//sinif mevcudu dolu ise asagidaki komutlari calistir
				{
			        printf("\n<<----------------------------------------------------------------------------------------------------------------------->>\n");
					printf("\n\t\t\t\t\t----->Kayitlari Listele<--------\n\n");
					printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n","Ad","Soyad","Vize1","Vize2","Final","Notu","Harf","Durumu");


					for(i=0;i<SINIF_MEVCUDU;i++)//siniftaki ogrencilerin notlari ortalamasini hesaplar
					{
						ort[i]=((vize1[i]*VIZE_1)+(vize2[i]*VIZE_2)+(final[i]*FINAL));
						basari_notu_hesaplmasi++;
					}


				    for(e=0;e<SINIF_MEVCUDU;e++)//ogrencilerin adini soyadini vize1 i vize2 yi finalini ortalamasini harf notini ve durumunu tablo seklinde yazdirir
	    		   	{

	    		    	if(ort[e]>89 && ort[e]<=100){
    				        printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[0][0],harf[0][1],durumu[0]);
    			    	}

        				else if(ort[e]>84 && ort[e]<90){
        				    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[1][0],harf[1][1],durumu[0]);
        				}

        				else if(ort[e]>79 && ort[e]<85){
    					    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[2][0],harf[2][1],durumu[0]);
        				}

        				else if(ort[e]>74 && ort[e]<80){
        				    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[3][0],harf[3][1],durumu[0]);
        				}

    	    			else if(ort[e]>69 && ort[e]<75){
    	    			    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[4][0],harf[4][1],durumu[0]);
    	    			}

    			   		else if(ort[e]>64 && ort[e]<70){
        				    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[5][0],harf[5][1],durumu[0]);
    			   		}

    		    		else if(ort[e]>59 && ort[e]<65){
    			   		    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[6][0],harf[6][1],durumu[0]);
    		   			}

    			        else if(ort[e]>49 && ort[e]<60){
        				    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[7][0],harf[7][1],durumu[2]);
    			        }

    	    			else if(ort[e]<50){
	    	    		    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[8][0],harf[8][1],durumu[1]);
	        			}
			       	}
			        printf("\n<<----------------------------------------------------------------------------------------------------------------------->>\n\n");
				}
			}

			if(islem==3)//eger islem 3 e esitse asagidaki komutlari calistir
			{
				int i,j;

				if(basari_notu_hesaplmasi==0)//islem 2 gerceklesmeden 3 e basilirsa asagidaki uyariyi ver
				{
					printf("\n<<---------------------------------------------------------------->>\n");
					printf("-Sinif Basari Notu Hesaplamadan Listelenemez.\n-Kayitlari listele Menusunden Once Kayitlari listeleyiniz!");
					printf("\n<<--------------------------------------------------------------->>\n\n");
				}


				else////islem 2 gerceklersirse asagidaki komutlari calistir
				{

					for(i=0;i<SINIF_MEVCUDU;i++)
						{
							ort[i]=((vize1[i]*VIZE_1)+(vize2[i]*VIZE_2)+(final[i]*FINAL));
						}

					printf("\n<<------------------------------------------------------------->>\n\n");

                    printf("\n\t----->Sinif Basari Notlarini Hesapla<--------\n\n");
                	printf("%s\t\t%s\t\t%s\n","Ad","Soyad","Notu");

                	for(j=0;j<SINIF_MEVCUDU;j++)
	                	printf("%s\t\t%c.\t\t%d\n",ad[j],soyad[j],(int)round(ort[j]));

	                printf("\n<<------------------------------------------------------------->>\n\n");
				}
			}

			if(islem==4)//eger islem 4 e esitse asagidaki komutlari calistir
			{
			    int tut,gec_o,gec_v1,gec_v2,gec_f,i,j,k,h;
			    char gec_a,gec_s;
			    int e;

			    if(sinif_mevcudu==0)//sinif kaydi yapmadan kullanici 4 e basarsa asagidaki uyariyi ver
				{
					printf("\n<<---------------------------------------------------------------->>\n");
					printf("-Kisi eklemeden basari notu hesaplanamaz.\n-Sinif kayit ekranindan kayit ekleme islemi gerceklestiriniz!");
					printf("\n<<--------------------------------------------------------------->>\n\n");
				}

				else//sinif kaydi yaptiktam sonra 4 e basarsa asagidaki komutlari calistir
			    {
			        printf("\n<<----------------------------------------------------------------------------------------------------------------------->>\n");

				    printf("\n\t\t\t\t----->Kayitlari Basari Notuna Gore Sirala<--------\n\n");

    			    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n","Ad","Soyad","Vize1","Vize2","Final","Notu","Harf","Durumu");

    			    for(h=0;h<SINIF_MEVCUDU;h++)
    				{
	    				ort[h]=((vize1[h]*VIZE_1)+(vize2[h]*VIZE_2)+(final[h]*FINAL));
		    		}

    			    for(tut=0;tut<SINIF_MEVCUDU;tut++)//dizilerde kosula gore yer degistiren dongu
    			    {
    			        for(i=0;i<SINIF_MEVCUDU-1;i++)
    			        {
    			            if(ort[i]<ort[i+1])
    			            {
    			                adTakas(ad[i],ad[i+1]);

	    		                gec_s=soyad[i];
    			                soyad[i]=soyad[i+1];
    			                soyad[i+1]=gec_s;

    			                gec_v1=vize1[i];
    			                vize1[i]=vize1[i+1];
    			                vize1[i+1]=gec_v1;

    			                gec_v2=vize2[i];
    			                vize2[i]=vize2[i+1];
    			                vize2[i+1]=gec_v2;

    			                gec_f=final[i];
    			                final[i]=final[i+1];
    			                final[i+1]=gec_f;

    			                gec_o=ort[i];
    			                ort[i]=ort[i+1];
    			                ort[i+1]=gec_o;
	    		            }
	    		        }
		    	    }


    				for(e=0;e<SINIF_MEVCUDU;e++)//ogrencilerin adini soyadini vize1 i vize2 yi finalini harf notini ve durumunu tablo seklinde ortalama sirasina göre yazdirir
	    		   	{

	    		    	if(ort[e]>89 && ort[e]<=100){
    				        printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[0][0],harf[0][1],durumu[0]);
    			    	}

        				else if(ort[e]>84 && ort[e]<90){
        				    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[1][0],harf[1][1],durumu[0]);
        				}

        				else if(ort[e]>79 && ort[e]<85){
    					    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[2][0],harf[2][1],durumu[0]);
        				}

        				else if(ort[e]>74 && ort[e]<80){
        				    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[3][0],harf[3][1],durumu[0]);
        				}

    	    			else if(ort[e]>69 && ort[e]<75){
    	    			    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[4][0],harf[4][1],durumu[0]);
    	    			}

    			   		else if(ort[e]>64 && ort[e]<70){
        				    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[5][0],harf[5][1],durumu[0]);
    			   		}

    		    		else if(ort[e]>59 && ort[e]<65){
    			   		    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[6][0],harf[6][1],durumu[0]);
    		   			}

    			        else if(ort[e]>49 && ort[e]<60){
        				    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[7][0],harf[7][1],durumu[2]);
    			        }

    	    			else if(ort[e]<50){
	    	    		    printf("%s\t\t%c.\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c%c\t\t%s\n",ad[e],soyad[e],vize1[e],vize2[e],final[e],(int)round(ort[e]),harf[8][0],harf[8][1],durumu[1]);
	        			}
			       	}
				}
			}

			if(islem==5)//eger islem 5 e esitse asagidaki komutlari calistir
			{
			    if(basari_notu_hesaplmasi==0)//basari notu hesaplanmadan kullanici 5 e basarsa asagidaki uyariyi ver
				{
					printf("\n<<---------------------------------------------------------------->>\n");
					printf("-Sinif Basari Notu Hesaplamadan istatistiki bilgiler gosterilemez.\n-Sinif Basari Notlari Hesapla Menusunden Once Basari Notlarini Hesaplayiniz!");
					printf("\n<<--------------------------------------------------------------->>\n\n");
				}

			    else//basari notu hesaplandiktan sonra kullanici 5 e basarsa asagidaki komutlari calistir
			    {

			        int enYuksekNot,enDusukNot,sinifOrtalmasi,ortalamaUstuKisiSayisi,i,kisiSayisi=0;
			        double standartSapma;

			        printf("\n<<-------------------------------------------------------------------->>\n\n");
				    printf("\n\t----->Istatistiki Bilgiler<--------\n\n");

			        enYuksekNot=EnYuksekNotHesaplama(ort,SINIF_MEVCUDU);
			        printf("Sinifin En Yuksek Notu: %d\n",enYuksekNot);

			        enDusukNot=EnDusukNotHEsaplama(ort,SINIF_MEVCUDU);
			        printf("Sinifin En Dsusk Notu: %d\n",enDusukNot);

			        sinifOrtalmasi=SinifOrtalamasiHesapla(ort,SINIF_MEVCUDU);
			        printf("Sinif Ortalamasi: %d\n",sinifOrtalmasi);

			        for(i=0;i<SINIF_MEVCUDU;i++)
		                {
			                if(ort[i]>=sinifOrtalmasi)
			                    kisiSayisi++;
			            }
                    printf("Sinif Ortalasinin Uzerindeki Kisi Sayisi: %d <----> Basari Orani : %d\n",kisiSayisi,(100/SINIF_MEVCUDU)*kisiSayisi);

                    standartSapma=StandartSapmaHesaplama(ort,SINIF_MEVCUDU);
                    printf("Sinifin Standart Sapmasi: %.2f",standartSapma);

                    printf("\n<<-------------------------------------------------------------------->>\n\n");

			    }
			}

			if(islem==6)//eger islem 6 e esitse asagidaki komutlari calistir
			{
			    printf("\n\n<<-------------------------->>\n\n");
			    printf("<Kodu Yazan: EMRECAN DUZENLI>\n");
			    printf("<Kodu Yazanin Numarasi: 210757060>");
			    printf("\n\n<<-------------------------->>");
			    break;
			}
		}

	return 0;
}

void MenuyuYaz(void)
{
    printf("--->MENU<---\n\n");
		printf("1) Kayit Ekle.\n");
		printf("2) Kayitlari Listele.\n");
		printf("3) Sinif basari notlarini hesapla.\n");
		printf("4) Kayitlari basari notuna gore sirala.\n");
		printf("5) Istatistiki bilgiler.\n");
		printf("6) Cikis.");

		printf("\n\n<<--------------------------------------->>\n\n");
}

double EnYuksekNotHesaplama(double dizi[],double a)
{
    int i,gec,enYuksekNot;

    for(i=0;i<SINIF_MEVCUDU-1;i++)
		{
		    if(ort[i]<ort[i+1])
            {
                gec=ort[i];
                ort[i]=ort[i+1];
                ort[i+1]=gec;
            }
        }

    enYuksekNot=ort[0];

    return round(enYuksekNot);
}

double EnDusukNotHEsaplama(double dizi[],double a)
{
    int i,gec,enDusukNot;

    for(i=0;i<SINIF_MEVCUDU-1;i++)
		{
		    if(ort[i]<ort[i+1])
            {
                gec=ort[i];
                ort[i]=ort[i+1];
                ort[i+1]=gec;
            }
        }

    enDusukNot=ort[SINIF_MEVCUDU-1];

    return round(enDusukNot);
}

double SinifOrtalamasiHesapla(double dizi[],double a)
{
    int i,toplam=0;
    double ortalama;

    for(i=0;i<SINIF_MEVCUDU;i++)
        toplam+=dizi[i];

    ortalama=(float)toplam/(float)SINIF_MEVCUDU;

    return round(ortalama);
}

void adTakas(char *dizi1, char *dizi2)
{
    char gec[SINIF_MEVCUDU];
    strcpy(gec, dizi1);
    strcpy(dizi1, dizi2);
    strcpy(dizi2, gec);
}

double StandartSapmaHesaplama(double dizi[],double a)
{
    int i,j,k;
    float toplam;
    float standartToplam=0.0,standartSapma=0.0;
    float ortalama,sapma[SINIF_MEVCUDU];

    for(i=0;i<SINIF_MEVCUDU;i++)
        toplam+=dizi[i];

    ortalama=(float)toplam/(float)SINIF_MEVCUDU;

    for(j=0;j<SINIF_MEVCUDU;j++)
    {
        sapma[j]=(ortalama-dizi[j])*(ortalama-dizi[j]);
    }

    for(k=0;k<SINIF_MEVCUDU;k++)
    {
        standartToplam+=sapma[k];
    }

    standartSapma=sqrt(standartToplam/(SINIF_MEVCUDU-1));

    return standartSapma;

}
