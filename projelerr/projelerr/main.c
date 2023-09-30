#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
//Gloabal değişken olarak bakiyeyi tanımladık
int bakiye;
//Fonksiyonlaı oluşturduk
int menu(void);
void paraCek(void);
void paraYatir(void);
void faturaOde(void);
void havaleEFT(void);

int main(void){
    int sifre;
    int sayac=0;
    int secim;
    //Şifre'yi başta sormakta doğruyasa işlemleri yapar fakat 3 kere üst üste girildiğinde programdan çıkar
    printf("Şifreniz : ");
    scanf("%d",&sifre);
    
    while (sifre != 3791) {
        printf("Hatalı şifre girdiniz!!");
        printf("Şirenizi giriniz : ");
        scanf("%d",&sifre);
        sayac++;
        if(sayac==3){
            printf("Kartınız kilitlenmiştir\n");
            printf("Lütfen müşteri hizmetleri ile iletişime geçiniz.\n");
            return 0;
        }
    }
    printf("Giriş başarılı!\n");
    //Hr program çalıştığında bakiyeye farklı bir değer atar
    srand(time(NULL));
    // bakiye her çalıştığında 100-999 arasında rastgele bir sayı üretir
    bakiye=rand()%900+100;
    sleep(2);
    //Programda 5 rakamına basmadığın sürece kod devam etmekte
    while (1) {
        
        secim=menu();
        switch (secim) {
            case 1:
                paraCek();
                break;
            case 2:
                paraYatir();
                break;
            case 3:
                faturaOde();
                break;
            case 4:
                havaleEFT();
                break;
            case 5:
                printf("Karınızı almayı unutmayınız..\n");
                return 0;
            default:
                printf("Hatalı seçim yaptınız\n");
                sleep(2);
        }
    }
    return 0;
}
//menu işlemi burada gerçekleşmekte
int menu(void){
    
    int secim;
    
    printf("Kullanılanilir bakiyeniz : %d\n\n",bakiye);
    printf("\t1-Para Çek\n");
    printf("\t2-Para Yatır\n");
    printf("\t3-Fatura Öde\n");
    printf("\t4-Havale/EFT\n");
    printf("\t5-Çıkış\n");
    
    //Kullanıcının seçimi alınır
    printf("Seçiniz : ");
    scanf("%d",&secim);
    
    return secim;
}
//Para çekme işlemi burada gerçekleşmekte
void paraCek(void){
    int miktar;
    
    printf("Çekeceğiniz para miktarını giriniz : ");
    scanf("%d",&miktar);
    
    printf("İşleminiz gerçekleştiriliyor...\n");
    sleep(2);
    
    if(bakiye<miktar){
        printf("Bakiyeniz yetersiz!\n");
    }
    else{
        //Genel bakiyeden çekilecek miktar çıkarılır
        bakiye-=miktar;
        printf("Para çekme işleminiz başarılı!\n");
        sleep(2);
        printf("Paranızı almayı unutmayınız!\n");
        sleep(2);
    }
    printf("Ana menüye yönlendiriliyorsunuz..\n");
    sleep(2);
}
//Para yatırma işlemi burada gerçekleşmekte
void paraYatir(void){
    int miktar;
    
    printf("Yatıracağınız miktarı girin : ");
    scanf("%d",&miktar);
    printf("İşleminiz gerçekleştiriliyor...\n");
    sleep(2);
    //Genel bakiye ile yatırlacak miktar toplanır
    bakiye+=miktar;
    printf("Para yatırma işlemi başarıyla gerçekleştirildi!\n");
    sleep(2);
    printf("Ana menüye yönlendiriliyorsunuz..\n");
    sleep(2);
}
//Fatura ödeme işlemi burada gerçekleşmekte
void faturaOde(void){
    int secim,no,fatura;
    
    //Ödemek istediğini faturalar kullanıcıya gösterilmekte
    printf("1-Elektrik\n");
    printf("2-Su\n");
    printf("3-Doğalgaz\n");
    printf("4-Telefon\n");
    
    printf("Seçiniz : ");
    scanf("%d",&secim);
    
    if(secim<1 || secim>4){
        printf("Hatalı bir seçim!\n");
    }
    else{
        
        printf("Fatura no : ");
        scanf("%d",&no);
        sleep(2);
        //Fatura'ya 20-119 arasında rastgele bir sayı atar
        fatura=rand()%100+20;
        
        printf("A....S kişisine ait fatura bedeli %d\n",fatura);
        printf("Ödemeyi onaylıyorum (1'e basınız yoksa harici bir rakama) : ");
        scanf("%d",&secim);
        if(secim !=1){
            printf("İşlem iptal edildi\n");
        }
        else{
            if(fatura>bakiye){
                printf("Yetersiz bakiye!\n");
                sleep(2);
            }
            else{
                //Genel bakiyeden fatura miktarı çıkarılır
                bakiye-=fatura;
                printf("Fatura ödeme işlemi başarıyla gerçekleştirildi\n");
                sleep(2);
            }
        }
    }
    printf("Ana menüye yönlendiriliyorsunuz..\n");
    sleep(2);
}
//Havale EFT işlemi burada gerçekleşmekte
void havaleEFT(void){
    int ibanNo,ibanMiktar;
    
    printf("Havale yapılacak kişinin IBAN no : ");
    scanf("%d",&ibanNo);
    printf("Havale yapılacak miktar (TL) : ");
    scanf("%d",&ibanMiktar);
    
    printf("İşleminiz gerçekleştiriliyor...\n");
    
    if(bakiye<ibanMiktar){
        printf("İşlem başarız!!\n");
    }
    else{
        //Genel bakiyeden havale/EFT edilecek miktar çıkarılır
        bakiye-=ibanMiktar;
        printf("Havale/EFT işlemi başarıyla gerçekleştirildi\n");
        sleep(2);
        
    }
    printf("Ana menüye yönlendiriliyorsunuz..\n");
    sleep(2);
}
