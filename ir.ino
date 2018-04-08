
#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;
String s = "";

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("---------");
  
}

void loop() {
  if (irrecv.decode(&results)) {
    //if (100000000>results.value){
    //  Serial.println(results.value);
    //}
    
    switch(results.value){
      case 16738455: {s = s+"0"; Serial.print("0"); break;}
      case 16724175: {s = s+"1"; Serial.print("1");break;}
      case 16718055: {s = s+"2"; Serial.print("2");break;}
      case 16743045: {s = s+"3"; Serial.print("3");break;}
      case 16716015: {s = s+"4"; Serial.print("4");break;}
      case 16726215: {s = s+"5"; Serial.print("5");break;}
      case 16734885: {s = s+"6"; Serial.print("6");break;}
      case 16728765: {s = s+"7"; Serial.print("7");break;}
      case 16730805: {s = s+"8"; Serial.print("8");break;}
      case 16732845: {s = s+"9"; Serial.print("9");break;}
      case 16769055: {s = s+"-"; Serial.print("-");break;}
      case 16754775: {s = s+"+"; Serial.print("+");break;}
      case 16720605: {s = s+"/"; Serial.print("/");break;}
      case 16712445: {s = s+"*"; Serial.print("*");break;}
      case 16748655: {
        //s="10+2*3";
        //Serial.println(s);
        int l=0;
        for (int i = 0; i < s.length(); i++) {
           // if ((s.charAt(i)=='+')||(s.charAt(i)=='-')||(s.charAt(i)=='*')||(s.charAt(i)=='/')) l++;
           if (!isDigit(s.charAt(i))) l++;
        }
        int a[l+1]={};

        int j=0;
        for (int i = 0; i < s.length() ; i++) {
            if (isDigit(s.charAt(i))){
                a[j]=a[j]*10+int(s.charAt(i))-48;
                
            }else{
                j++;
            }
        }

        char c[l]={};
        j=0;
        for (int i = 0; i < s.length(); i++) {
            if (!isDigit(s.charAt(i))) {
                c[j]=s.charAt(i);
                j++;
            }
        }
        double n=a[0];
        for (int i = 0; i < sizeof(c); i++) {
            if (c[i]=='+') n=n+a[i+1];
            if (c[i]=='-') n=n-a[i+1];
            if (c[i]=='*') n=n*a[i+1];
            if (c[i]=='/') n=n/a[i+1];
        }
    Serial.print("=");
    Serial.println(n); 
    s="";
    break;
    }
    default:   break; 
  }
    irrecv.resume(); // Receive the next value
  }
  //delay(5);
}

