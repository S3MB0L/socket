#SOCKET

##Usage
        socket -s 1 -p 67677 -b 256                 ==> Server
        socket -c 1 -p 67677 -b 256 -n 127.0.0.1    ==> Client
        
        -s : works as server side
        -c : works as client side
        -p : port number
        -n : hostName
        
##Install
        [bash]$ make install

##Commands 
        ./close
        ./status
        ./set_relayx
        !!!Fonctions not defined, commands just prints some text but you can define 
