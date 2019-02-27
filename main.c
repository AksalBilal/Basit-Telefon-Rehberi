#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct  telephone
{
    char isim[50];
    char kod[15];
   char numara[11];
};
void menuHazirla();
int telefonEkle();
int telefonlariListele();
int isimaramasiYap(char *);
int numaraaramasiYap(char *);
void menuHazirla(){
    printf("\t\t--------------------------------------\n");
    printf("\t\t*   *   *   *   *   *   *   *   *   *   *\n");
    printf("\t\t                                         \n");
    printf("\t\t*           TELEFON REHBERÝ     v1.2    *\n");
    printf("\t\t         PROGRAMINA HOÞGELDÝNÝZ!         \n");
    printf("\t\t*                                       *\n");
    printf("\t\t                                         \n");
    printf("\t\t*          1. YENÝ KAYIT                *\n");
    printf("\t\t           2. TELEFONLARI LÝSTELE        \n");
    printf("\t\t*          3. KAYDI DÜZENLE             *\n");
    printf("\t\t           4. NUMARA ÝLE KAYDI BUL       \n");
    printf("\t\t*          5. ÝSÝM ÝLE KAYDI BUL        *\n");
    printf("\t\t           6. KAYIT SÝL                  \n");
    printf("\t\t*          0. CIKIÞ                     *\n");
    printf("\t\t                                         \n");
    printf("\t\t*   *   *   *   *   *   *   *   *   *   *\n");
    printf("\t\t--------------------------------------\n");}
int telefonEkle()
{    printf("\n\n\t\t*           TELEFON EKLEME          *\n\n");
    struct  telephone yeniKayit;
    FILE *ptVeritabani;
    // dosyaya ac:
    if((ptVeritabani = fopen("TelefonRehber.txt","a"))==NULL)    {
        return -1;    }
    printf("\n\n");
    printf("Ýsim giriniz(max 15 karakter): ");
    scanf("%s",yeniKayit.isim);
    printf("Kod giriniz(max 100 e kadar): ");
    scanf("%s",yeniKayit.kod);
    printf("Telefon numarasini giriniz: ");
    scanf("%s",yeniKayit.numara);
    if(fwrite(&yeniKayit,sizeof(yeniKayit),1,ptVeritabani)!=1){
        printf("Yazma hatasi!\n");
        exit(1);
    }
    printf("\n");
    fclose(ptVeritabani);
    return 0;}
int telefonlariListele(){
    printf("\n\n\t\t*         TELEFON LÝSTELEME         *\n\n");
    // dosyadaki tum telefonlari listele
    // dosyaya ac:
    FILE *ptVeritabani;
    struct  telephone aktifKayit;
    if((ptVeritabani = fopen("TelefonRehber.txt","r"))==NULL)    {
        return -1;    }
    printf("\n\nÝSÝM\t\t\tKOD\t\t      TELEFON NO\n");
    printf("----\t\t\t----\t\t\t----\n");
    // dosya sonuna kadar tum verileri oku:
    while(!feof(ptVeritabani))    {
if(fread(&aktifKayit,sizeof(aktifKayit),1,ptVeritabani)!=1){
        continue;
    }
        printf("%s\t\t      ",aktifKayit.isim);
        printf("%s\t\t     ",aktifKayit.kod);
        printf("%s\n",aktifKayit.numara);    }
    fclose(ptVeritabani);
    return 0;}
 void duzenleme()
{
	int i=0,p,l;
	FILE *ptVeritabani;
	FILE *tp;///temporary-geçici i?aretçi
	tp=fopen("TelefonRehber-2.txt", "wb+");
	ptVeritabani=fopen("TelefonRehber.txt", "rb+");
	struct telephone aktifKayit;
	char dtel[15];
		printf("\nDüzeltilecek kiþinin numarasýný giriniz:");
	scanf("%s", dtel);
	while(!feof(ptVeritabani))
	{
		i++;
		fread(&aktifKayit, sizeof(aktifKayit), 1, ptVeritabani);
		if(strcmp(aktifKayit.numara,dtel)==0){
		    p=10;
           printf("Yeni isim:");
			scanf("%s", aktifKayit.isim);
         printf("Yeni kod:");
			scanf("%s", aktifKayit.kod);
			 printf("Yeni numara:");
			scanf("%s", aktifKayit.numara);         }
if(feof(ptVeritabani)){
    break;
}
		fseek(tp,(i-1)*sizeof(aktifKayit),0);
		fwrite(&aktifKayit,sizeof(aktifKayit),1,tp);}
		if(p!=10){
            printf("Kayýt bulunamadý\n");
            printf("Tekrar kayýt düzenleme yapmak için 1 e basýnýz:\n");
            printf("Ana menüye dönmek için 2 ye basýnýz:\t");
            scanf("%d",&l);
            if(l==1)
                duzenleme();
            if(l==2)
                main();
		}

	fclose(ptVeritabani);
	remove("TelefonRehber.txt");
	fclose(tp);
	rename("TelefonRehber-2.txt","TelefonRehber.txt");
}
int isimaramasiYap(char *arananIsim){
    printf("\n\n\t\t*         ÝSÝM ARAMA          *\n\n");
    // dosyadaki tum telefonlarini ara
    // dosyaya ac:
    FILE *ptVeritabani;
    struct  telephone aktifKayit;
    int bulunan=0;
    if((ptVeritabani=fopen("TelefonRehber.txt","r"))==NULL)    {
        return -1;    }
    // dosya sonuna kadar tum verileri oku:
    while(!feof(ptVeritabani))    {
       if(fread(&aktifKayit,sizeof(aktifKayit),1,ptVeritabani)!=1){
        continue;
    }
        if(!strcmp(arananIsim, aktifKayit.isim))        { // bulundu!
            printf("%s\t\t\t", aktifKayit.isim);
            printf("%s\t\t\t", aktifKayit.kod);
            printf("%s\n", aktifKayit.numara);
        bulunan++;        }    }
    fclose(ptVeritabani);
    return bulunan;}
int numaraaramasiYap(char *arananNumara){
    printf("\n\n\t\t*         NUMARA ARAMA         *\n\n");
    // dosyadaki tum telefonlarini ara
    // dosyaya ac:
    FILE *ptVeritabani;
    struct  telephone aktifKayit;
    int bulunan2=0;
    if((ptVeritabani=fopen("TelefonRehber.txt","r"))==NULL)    {
        return -1;    }
    // dosya sonuna kadar tum verileri oku:
    while(!feof(ptVeritabani))    {
        if(fread(&aktifKayit,sizeof(aktifKayit),1,ptVeritabani)!=1){
        continue;
    }
        if(!strcmp(arananNumara, aktifKayit.numara))        { // bbulundu!
            printf("%s\t\t\t", aktifKayit.isim);
            printf("%s\t\t\t", aktifKayit.kod);
            printf("%s\n", aktifKayit.numara);
        bulunan2++;
        }    }
    fclose(ptVeritabani);
    return bulunan2;}
void KayitSil()
{
    printf("\n\n\t\t*         KAYIT SÝLME          *\n\n");
int e=0,v,a;
	FILE *ptVeritabani;
	FILE *gecicibellek;///temporary-geçici i?aretçi
	gecicibellek=fopen("TelefonRehber-3.txt", "wb+");
	ptVeritabani=fopen("TelefonRehber.txt", "rb+");
	struct telephone aktifKayit;
	char kod2[15];
		printf("\nSilinecek kisinin kodunu giriniz:");
	scanf("%s", &kod2);
	while(!feof(ptVeritabani))	{
		e++;
		fread(&aktifKayit, sizeof(aktifKayit), 1, ptVeritabani);
		if(strcmp(aktifKayit.kod,kod2)==0)
         {
v=100;
continue;
}
            if(feof(ptVeritabani)){
    break;
    }
                if(feof(ptVeritabani)){
    continue;}
		fseek(gecicibellek,(e-1)*sizeof(aktifKayit),0);
		fwrite(&aktifKayit,sizeof(aktifKayit),1,gecicibellek);}
		if(v!=100){
            printf("kayýt bulunamadý\n");
            printf("tekrar kayýt silme yapmak için 1 e basýnýz:\n");
            printf("Ana menüye dönmek için 2 ye basýnýz:\t");
            scanf("%d",&a);
            if(a==1)
                KayitSil();
            if(a==2)
                main();
		}
        fclose(ptVeritabani);
     // Dosya silinir.
     remove("TelefonRehber.txt");
       fclose(gecicibellek);
     // geçici dosyanyn ismi asyl dosya ismi de?i?tirilir.
     rename("TelefonRehber-3.txt","TelefonRehber.txt");}
int main()
{
    setlocale(LC_ALL,"Turkish");
    char arananNumara[11];
    char secim='0';
    char aranacakIsim[16];
    int numaraAra=-1;
    int numaraAra2=-1;
    struct  telephone aktifKayit;
    struct  telephone yeniKayit;
    // menu hazirla:
    menuHazirla();
    do    {
        printf("\n\nseciminiz: ");
        secim = putch(getch());
        switch (secim)        {
            case '1':
                if (telefonEkle()==0)  // geri bildirim:
                    {
                    printf("\ntelefon numarasi basariyla eklendi.");
                }
                else{
                    printf("\nHATA: telefon numarasi eklenemedi!");                }
                break;
            case '2':
                if (telefonlariListele()==0) // geri bildirim:
                    {printf("\ntelefonlar basariyla listelendi.");}
                else{
                    printf("\nHATA: telefon numaralari listelenemedi!");                }
                break;
            case '3':
                duzenleme();
                break;
            case '4':
                printf("\naranacak numarayi giriniz(max 10 karakter):");
                scanf("%s",arananNumara);
                numaraAra2= numaraaramasiYap(arananNumara); // geri bildirim:
                if (numaraAra2 == 0)                {
                    printf("\naranan numara kayitlarda bulunamadi.");
                }else {
                    if(numaraAra2 > 0)
                    printf("\ntoplam %d kayit bulundu.",numaraAra2);
                else
                    printf("\nHATA: numara aranamadi!");                }
                break;
            case '5':
                printf("\naranacak ismi giriniz(max 15 karakter):");
                gets(aranacakIsim);
                numaraAra = isimaramasiYap(aranacakIsim); // geri bildirim:
                if (numaraAra == 0)                {
                    printf("\naranan isim kayitlarda bulunamadi.");
                }else {
                    if(numaraAra > 0)
                    printf("\ntoplam %d kayit bulundu.",numaraAra);
                else
                    printf("\nHATA: isim aranamadi!");}
                break;
            case '6':
               KayitSil();
               printf("Kayýt baþarýyla silindi!\n");
                break;
            case '0':
                printf("\nprogrami kullandiginiz icin tesekkurler.");
                return 0;
                break;
            default:
                printf("\nLutfen 1-6 arasinda bir secim yapiniz.");        }
    }while(secim!=6);
    return 0;
}
