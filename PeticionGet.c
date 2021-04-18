#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>



int main(){
   int socked_id = 0;
   int conection = 0 ;
   char msm[] = "GET\r\n";
   char buffer[30] = {0};

   // Establesco la estructura de conexion 


   struct sockaddr_in Server_http;
   Server_http.sin_family = AF_INET;
   Server_http.sin_addr.s_addr = inet_addr("142.250.78.142");
   Server_http.sin_port = htons(80);

   //creo el socket 
   socked_id = socket(AF_INET,SOCK_STREAM, 0);

   //Esteblesco la coneccion 

   conection = connect(socked_id,(struct Socketaddr*)&Server_http, sizeof(Server_http));
   

   if(conection < 0){
        
        printf("Coneccion Fallida\n\r");

        return(-1);   
   }
       
       printf("Coneccion Exitosa\n\r");
       send(socked_id, msm , sizeof(msm),0);
       while(recv(socked_id,buffer,sizeof(buffer),0) > 0){
                printf("%s",buffer);
       }
       
       close(socked_id);
       return(0);

}