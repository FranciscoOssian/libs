#ifndef _NETWORK_H
#define _NETWORK_H

void getHostByDomainName (char *domain, char * ip);

void fetch(char * domain, long int r_size, char * server_reply);

#endif