#include <iostream>
#include <fstream>
#include <map>

int varibl_types(std::string str);
void var_types(std::string data ,int i);
void  howtypes(std::string data );
void itypes_func(std::string data,int count);
void var_stypes(std::string data,int i);
void  stypes_func(std::string data,int count);
void ftypes_func(std::string data,int count);
void  var_ftypes(std::string data,int i);
void btypes_func(std::string data,int count);
void  var_btypes(std::string data,int i);
void pr(std::string data ,int count);
void var_pr(std::string ,int i);
void loop_f(std::string data ,int count);
void loop_name(std::string data,int i );
void mode_f(std::string data ,int count);
void mode_name(std::string data,int i);
void tpich_f(std::string data ,int count);
void tpich_name(std::string ,int i);
int  matem_oper(int number,int number2,char c);


std::map<std::string,int> imp;
std::map<std::string ,std::string>smp;




int main(){

	char data[1000];
	std::fstream read;
	std::string types ="";
	read.open("interpreter.txt");
        while(!read.eof()){
        
		read.getline(data,10000);
 	  howtypes(data);
 
        }
       
}
void howtypes (std::string data){
	std::string itypes ="itype";
	std::string stypes = "stype";
	std::string ftypes = "ftype";
	std::string btypes = "btype";
	std::string pr = "std::cout";
	std::string loop = "loop";
	std::string mode = "mode";
	std::string tpich = "tpich";
 	
	
	int j=0;
	int count=0;
	for(int i = 0; i<data.length();++i){
   while(data[i] == itypes[j]){
	   ++i;
	   ++j;
	   ++count;
   }
   if(count == itypes.length()){
      itypes_func(data, count);
return;
      }
   while(data[i] == stypes[j]){
   ++i;
   ++j;
   ++count;
   }
   if(count  == stypes.length()){
      stypes_func(data,count);
      return;
   }
   while(data[i] == ftypes[j]){

	   ++i;
	   ++j;
	   ++count;
   }
   if(count  ==  ftypes.length()){
     ftypes_func(data,count);
     return;
   }
    while(data[i] == btypes[j]){

	   ++i;
	   ++j;
	   ++count;
   }
   if(count  ==  btypes.length()){
     btypes_func(data,count);
     return;
   }
    while(data[i] == loop[j]){
	   ++i;
	   ++j;
	   ++count;
   }
   if(count == loop.length()){
      loop_f(data, count);
     return;
      }
      while(data[i] == mode[j]){
	   ++i;
	   ++j;
	   ++count;
   }
   if(count == mode.length()){
      mode_f(data, count);  // im  ifn a
     return;
      }
      while(data[i] == tpich[j]){
	   ++i;
	   ++j;
	   ++count;
   }
   if(count == tpich.length()){
      tpich_f(data, count);
     return;
      }
   else{
    std::cout << "! error types " <<std::endl;
    exit(0);
              }
	}
}

void tpich_f(std::string data,int count){
 std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(data[i] != ' '){ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(data[i] == ' '){
		++i;

	}	
		tpich_name(data,i);
	
return;     
}

void tpich_name(std::string data,int i ){
    
std::string str1 = "";
    	while(data[i] == ' '){
		++i;
	}

            
        if(data[i] != '^'){
            std::cout << "error chka 1-in";
            exit(0);
        }
        ++i;

	    if(data[i] != '^'){
		std::cout <<"error chka 2-rd";
	}

	   
	    ++i;
	    while(data[i] == ' '){
		++i;
	}
	   if(data[i] >= 97 && data[i] <= 122){
	       
	   }
	   else{
	       std::cout << "error cout" << std::endl;
	       exit(0);
	   }
	   while(data[i] >= 97 && data[i] <= 122 ){
	       str1 += data[i];
	       ++i;
	   }
	   
	int thekkre  = varibl_types(str1);
      
     
      if(thekkre == 1){
          std::cout <<smp[str1]<<std::endl;
		}
		if(thekkre == 1){
          std::cout <<imp[str1]<<std::endl;
		}
		
		if(thekkre == 0){
	std::cout <<"error no varibale"<<std::endl;
	exit(0);
		}
         str1 = "";
         while(data[i] == ' '){
             ++i;
         }
     if(data[i] != ';' ){
	     std::cout << "error ; piti dnes " << std::endl;
	     exit(0);
     }
     
   
    return; 
    
}

void mode_f(std::string data,int count){
    std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(data[i] != ' '){ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(data[i] == ' '){
		++i;

	}	
		mode_name(data,i);
	
return;  
}

void loop_f(std::string data ,int count){
    std::string str1 ="";
   std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(data[i] != ' '){ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(data[i] == ' '){
		++i;

	}	
		loop_name(data,i);
	
return;  
}

void mode_name(std::string data ,int i){
    
    std::string str1 = "";
    	while(data[i] == ' '){
		++i;
	}

            
        if(data[i] != '^'){
            std::cout << "errrrrr";
            exit(0);
        }
        ++i;

	    while(data[i] == ' '){
		++i;
	}
	  if(data[i] >= 97 && data[i] <= 122){
	       
	   }
	   else{
	       std::cout << "error cout" << std::endl;
	       exit(0);
	   }
	   while(data[i] >= 97 && data[i] <= 122 ){
	       str1 += data[i];
	       ++i;
	   }
         	int thekkre  = varibl_types(str1);

		if(thekkre == 1){
         std::cout <<imp[str1]<<std::endl;
		}
		if(thekkre == 0){
	std::cout <<"error no varibale"<<std::endl;
	exit(0);
		}
       
         while(data[i] == ' '){
             ++i;
         }
	   
	    while(data[i] != '^'){
	        std::cout << "error '^4'" << std::endl;
	        exit(0);
	    }
	    ++i;
	    while(data[i] == ' '){
		++i;
	}
	   while(data[i] != '`'){
	        std::cout << "error '`'"<<std::endl;
	        exit(0);
	    }
	       ++i;
	    while(data[i] == ' '){
		++i;
	}
	std::cout <<imp[str1]<<" Mode ";
	if(imp[str1] == 1 ){
	tpich_name(data, i );
	}
	else{
	    std::cout << "error  0 a ";
	} 
     while(data[i] == ' '){
		++i;
	}
	

    return; 
    
}
 void loop_name(std::string data,int i ){


    std::string str1 = "";
    	while(data[i] == ' '){
		++i;
	}

            
        if(data[i] != '^'){
            std::cout << "errrrrr";
            exit(0);
        }
        ++i;

	    while(data[i] == ' '){
		++i;
	}
	  if(data[i] >= 97 && data[i] <= 122){
	       
	   }
	   else{
	       std::cout << "error cout" << std::endl;
	       exit(0);
	   }
	   while(data[i] >= 97 && data[i] <= 122 ){
	       str1 += data[i];
	       ++i;
	   }
         	int thekkre  = varibl_types(str1);

		if(thekkre == 1){
         std::cout <<imp[str1]<<std::endl;
		}
		if(thekkre == 0){
	std::cout <<"error no varibale"<<std::endl;
	exit(0);
		}
     
         while(data[i] == ' '){
             ++i;
         }
	   
	    while(data[i] != '^'){
	        std::cout << "error '^4'" << std::endl;
	        exit(0);
	    }
	    ++i;
	    while(data[i] == ' '){
		++i;
	}
	   while(data[i] != '`'){
	        std::cout << "error '`'"<<std::endl;
	        exit(0);
	    }
	       ++i;
	    while(data[i] == ' '){
		++i;
	}
	std::cout <<imp[str1]<<"  LOOP ";
	if(imp[str1] == 1 ){
	tpich_name(data, i );
	}
	else{
	    std::cout << "error  0 a ";
	} 
     while(data[i] == ' '){
		++i;
	}
	

    return; 
 }

void btypes_func(std::string data,int count){
    std::string var_name = "";
    bool x =true;
	int j =count;
	int i = count;
	int count1 = 0;
	if(data[i] != ' '){ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(data[i] == ' '){
		++i;

	}	
		var_btypes(data,i);
	
return;
}

void var_btypes(std::string data,int i){
	std::string varibb_name ="";
	int count = 0;
	int number  = 0;
	while(data[i] >= 97 && data[i] <= 122){
          varibb_name += data[i];
          
	     
		++i;
		++count;
	}
	if(count < 2 ){
        std::cout <<" error tpyes" <<std::endl;
	exit(0);
	}
	count = 0;

	while(data[i] == ' '){
		++i;
	}
	if(data[i] == ';'){
		
		return;
	}
	if(data[i] != '='){
		std::cout << "error  = :"<<std::endl;
	
	exit(0);
	}
        ++i;
     while(data[i] == ' '){
               ++i;
            }
     while(data[i] >= 48 && data[i] <= 57 ){
	     number = number *10;
	     number += (data[i] - 48);
	     ++i;
	     ++count;
	
	    }
	    if(number != 0){
	        
	        number =   1;
	    }
	    else{
	        number = 0;
	    }
	    int j =0;
	    std::string fa = "false";
	    std::string tr = "true";
	     while(data[i] == fa[j]){
	         ++j;
	         ++i;
	         ++count;
	       if(count == fa.length()){
	         number = 0;
	         
	     }
	     }
	     
	      while (data[i] == tr[j]){
	         ++j;
	         ++i;
	  
	         ++count;
	         if(count == tr.length()){
	         number= 1;
	     }
	     }
	     

     if(count == 0){
	     std::cout << "error valddue "<<std::endl;
	     exit(0);
     }
     count = 0;
     while(data[i] == ' ' ){
	     ++i;
     }
     if(data[i] != ';' ){
	     std::cout << "error ; piti dnes " << std::endl;
	     exit(0);
     }
     int theref  = varibl_types(varibb_name);

		if(theref == 1){
                std::cout << "error there is  same from name";
		exit(0);
		}
	
		if(theref == 0){
	
		imp[varibb_name] = number;

		}
         varibb_name = "";
         
	 number = 0;
    return;
 
}

void ftypes_func(std::string data,int count){
    std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(data[i] != ' '){ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(data[i] == ' '){
		++i;

	}	
		var_ftypes(data,i);
	
return;
}


void var_ftypes(std::string data ,int i ){
    	std::string varib_name ="";
	int count = 0;
	int number  = 0;
	while(data[i] >= 97 && data[i] <= 122){
          varib_name += data[i];
          
	     
		++i;
		++count;
	}
	if(count < 2 ){
        std::cout <<" error tpyes" <<std::endl;
	exit(0);
	}
	count = 0;

	while(data[i] == ' '){
		++i;
	}
	if(data[i] == ';'){
		
		return;
	}
	if(data[i] != '='){
		std::cout << "error  = :"<<std::endl;
	
	exit(0);
	}
        ++i;
     while(data[i] == ' '){
               ++i;
            }
     while(data[i] >= 48 && data[i] <= 57 ){
	     number = number *10;
	     number += (data[i] - 48);
	     ++i;
	     ++count;
	
	    }

     if(count == 0){
	     std::cout << "error value "<<std::endl;
	     exit(0);
     }
     count = 0;
     while(data[i] == ' ' ){
	     ++i;
     }/////////////////////////////////
     int count1= 0;
     int number2 =0;
     
     if(data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/' || data[i] == '%'){
      ++count1;
     char  c = data[i];
     ++i;
     if(count1 == 1){
         while(data[i] == ' '){
             ++i; 
         }
         while(data[i] >= 48 && data[i] <= 57 ){
	     number2 = number2 *10;
	     number2 += (data[i] - 48);
	     ++i;
	     ++count;
	
	    }
	  
     if(count == 0){
	     std::cout << "error value "<<std::endl;
	     exit(0);
     }
       int  valuee =  matem_oper(number,number2,c);
       number = valuee;  
     }
     } 
     while(data[i] == ' '){
         ++i;
     }
     
     ///////////////////////////////
     if(data[i] != ';' ){
	     std::cout << "error ; piti dnes " << std::endl;
	     exit(0);
     }
     int there  = varibl_types(varib_name);

		if(there == 1){
                std::cout << "error there is  same from name";
		exit(0);
		}
		if(there == 0){
		imp[varib_name] = number;
		}
         varib_name = "";
	 number = 0;
    return;
}
void stypes_func(std::string data,int count){
        std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(data[i] != ' '){ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(data[i] == ' '){
		++i;

	}	
		var_stypes(data,i);
	
return;
}

void itypes_func(std::string data,int count){
        std::string var_name = "";
	int j =count;
	int i = count;
	int count1 = 0;
	if(data[i] != ' '){ 
		std::cout << "error"<<std::endl;
		exit(0);
	}
	while(data[i] == ' '){
		++i;

	}	
		var_types(data,i);
	
return;
}

void var_types(std::string data ,int i){

	std::string varib_name ="";
	int count = 0;
	int number  = 0;
	while(data[i] >= 97 && data[i] <= 122){
          varib_name += data[i];
          
	     
		++i;
		++count;
	}
	if(count < 2 ){
        std::cout <<" error tpyes" <<std::endl;
	exit(0);
	}
	count = 0;

	while(data[i] == ' '){
		++i;
	}
	if(data[i] == ';'){
		
		return;
	}
	if(data[i] != '='){
		std::cout << "error  = :"<<std::endl;
	
	exit(0);
	}
        ++i;
     while(data[i] == ' '){
               ++i;
            }
     while(data[i] >= 48 && data[i] <= 57 ){
	     number = number *10;
	     number += (data[i] - 48);
	     ++i;
	     ++count;
	
	    }

     if(count == 0){
	     std::cout << "error value "<<std::endl;
	     exit(0);
     }
     count = 0;
     while(data[i] == ' ' ){
	     ++i;
     }/////////////////////////////////
     int count1= 0;
     int number2 =0;
     
     if(data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/' || data[i] == '%'){
      ++count1;
     char  c = data[i];
     ++i;
     if(count1 == 1){
         while(data[i] == ' '){
             ++i; 
         }
         while(data[i] >= 48 && data[i] <= 57 ){
	     number2 = number2 *10;
	     number2 += (data[i] - 48);
	     ++i;
	     ++count;
	
	    }
	  
     if(count == 0){
	     std::cout << "error value "<<std::endl;
	     exit(0);
     }
       int  valuee =  matem_oper(number,number2,c);
       number = valuee;  
     }
     } 
     while(data[i] == ' '){
         ++i;
     }
     
     ///////////////////////////////
     if(data[i] != ';' ){
	     std::cout << "error ; piti dnes " << std::endl;
	     exit(0);
     }
     int there  = varibl_types(varib_name);

		if(there == 1){
                std::cout << "error there is  same from name";
		exit(0);
		}
		if(there == 0){
		imp[varib_name] = number;
		}
         varib_name = "";
	 number = 0;
    return;

}
void var_stypes(std::string data ,int i){
    
    std::string str1 = "";
	std::string varibs_name ="";
	int count = 0;
	int number  = 0;
	while(data[i] >= 97 && data[i] <= 122){
          varibs_name += data[i];
          
	     
		++i;
		++count;
	}
	if(count < 2 ){
        std::cout <<" error tpyes" <<std::endl;
	exit(0);
	}
	count = 0;

	while(data[i] == ' '){
		++i;
	}
	if(data[i] == ';'){
		
		return;
	}
	if(data[i] != '='){
		std::cout << "error  = :"<<std::endl;
	
	exit(0);
	}
       ++i;
     while(data[i] == ' '){
               ++i;
            }
            
        if(data[i] != '<'){
            std::cout << "errrrrr";
            exit(0);
        }
        ++i;
     while(data[i] != '>'  ){
	 	     str1 +=data[i];
	 	     ++i;
	     ++count;
	    
	    }
	   
	    while(data[i] != '>'){
	        std::cout << "error '>'" << std::endl;
	        exit(0);
	    }
	    ++i;
	    while(data[i] == ' '){
		++i;
	}
	    


     count = 0;

     if(data[i] != ';' ){
	     std::cout << "error ; piti dnes " << std::endl;
	     exit(0);
     }
     
     int thekkre  = varibl_types(varibs_name);

		if(thekkre == 1){
                std::cout << "error th,kere is  same from name";
		exit(0);
		}
		if(thekkre == 0){
		smp[varibs_name] = str1;
		}
         varibs_name = "";
	 number = 0;
    return;

}


int varibl_types(std::string str){
 if(imp.count(str) == 2){
     std::cout << "errrrrr";
 }
	if(imp.count(str) == 1){
		return 1;

	}

         else if( smp.count( str ) == 1 )
         {
                 return 1;
         }
         
         else
                 return 0;

}

int  matem_oper(int number,int number2,char c){
    if(c == '+'){
        number += number2;
        
        return number;
    }
    if(c == '-'){
        number -= number2;
        return number;
    }
    if(c == '*'){
        number *= number2;
        return number;
    }
    if(c == '/'){
        number /=number2;
        return number;
    }
    if(c == '%'){
        number %=number2;
        return number;
    }
    
    return number;
}

