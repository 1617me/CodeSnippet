#ifndef __SOCKET_WRAP_H__
#define __SOCKET_WRAP_H_
voidperr_exit(constchar*s);
intAccept(intfd,structsockaddr*sa,socklen_t*salenptr);
voidBind(intfd,conststructsockaddr*sa,socklen_tsalen);
voidConnect(intfd,conststructsockaddr*sa,socklen_tsalen); 
voidListen(intfd,intbacklog);
intSocket(intfamily,inttype,intprotocol);
ssize_tRead(intfd,void*ptr,size_tnbytes);
ssize_tWrite(intfd,constvoid*ptr,size_tnbytes); 
voidClose(intfd);
ssize_tReadn(intfd,void*vptr,size_tn);
ssize_tWriten(intfd,constvoid*vptr,size_tn);
staticssize_tmy_read(intfd,char*ptr);
ssize_tReadline(intfd,void*vptr,size_tmaxlen);
#endif
