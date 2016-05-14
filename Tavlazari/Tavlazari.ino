/*
* 2 li tavla zarı uygulaması
* 2- buton 1
* PIN5...PIN12 zar ekrani LED ucları 
*/
int ButonPIN=2;
int zar1;
int zar2;
int sayac1=0;

// bu fonksiyon zar bilgisini ledleri kullanarak gosterir
void ZarGoster( int Z1, int Z2)
{
   for(int i=2; i < 13; i++) {
     digitalWrite( i, LOW ); 
   }
   //7856
   switch (Z1){
     case 1:
       digitalWrite( 7, HIGH );
     break;

     case 2:
       digitalWrite( 8, HIGH );
     break;

     case 3:
       digitalWrite( 7, HIGH );
       digitalWrite( 8, HIGH );
     break;
    
     case 4:
       digitalWrite( 5, HIGH );
       digitalWrite( 8, HIGH );
     break;
     
     case 5: 
       digitalWrite( 7, HIGH );
       digitalWrite( 5, HIGH );
       digitalWrite( 8, HIGH );
     break;
     
     case 6:
       digitalWrite( 5, HIGH );
       digitalWrite( 8, HIGH );
       digitalWrite( 6, HIGH );
     break;
   }
   //11-12-9-10
   switch (Z2){
     case 1:
       digitalWrite( 11, HIGH );
     break;

     case 2:
       digitalWrite( 12, HIGH );
     break;

     case 3:
       digitalWrite( 11, HIGH );
       digitalWrite( 12, HIGH );
     break;
    
     case 4:
       digitalWrite( 9, HIGH );
       digitalWrite( 12, HIGH );
     break;
     
     case 5: 
       digitalWrite( 11, HIGH );
       digitalWrite( 9, HIGH );
       digitalWrite( 12, HIGH );
     break;
     
     case 6:
       digitalWrite( 9, HIGH );
       digitalWrite( 12, HIGH );
       digitalWrite( 10, HIGH );
     break;
   }
}



void setup()
{
   //led uclari cikis olarak tanimlanir
   for(int i=2; i < 13; i++) {
      pinMode(i, OUTPUT); 
   }
   //buton ucu giris olarak tanimlanir
   pinMode(ButonPIN, INPUT);
   //kart ilk calistiginda zar atsin
    delay(5);
    zar1 = random(1,7);
    delay(8);
    zar2 = random(1,7);
} 
 
void loop()
{
   int value;
   int B1Durum;
   //butonlar okunur
   B1Durum = digitalRead(ButonPIN);
   //
  if (B1Durum == 0 ) {     
    zar1 = random(1,7);
    zar2 = random(1,7);
    ZarGoster(zar1,zar2);
  }else{
    sayac1++;
    if (sayac1 > 100) {sayac1 = 0;}
    if (sayac1 > 50){
      ZarGoster(zar1,0);
    }else{
      ZarGoster(0,zar2);
    }
  }

  delay(10);
} 

