#AeroMACS

Initial development of the radio interface with the CMU
SATCOM Wifi supports the TCP/IP network but I worked on the inclusion of AeroMACS
AeroMACS is cheap than the HF VHF and satcom
more expensive than the wifi but more secure and scalable than the wifi and requires lesser maintenance.
Wifi is used more for the non critical communication.
Wimax provides the Access better control as it uses the separate band than the commercial networks. 

WiMAX uses the EAP-TLS security

Base station connects to the AAA server that hosts the certificate authority for the network and it can be integrated with x509 trust highrarchy

This ensures second level of access controls
provides the authentication and authorization at the network level.

Dont remember the method of integrity. but I understand EAP-TLS uses the AES sysmetric key for integiryt.

Base station works as the server for EAP-TLS based network service and 
ES (user device - ES term is correct?) 

Use of EAP-TLS satiesfies all the priciples CI AA NR

Designed the VLANs for 
1. High priority secure data - location data - PM-CPDLC messages
2. low priority secure data - ACARS 
3. High priority cabin data
4. Low priority cabin data

I implemented the Datalink layer interface with the ATN Stack using SNMP interface from SNSME for control part and IP-SNDCF over the IPSec tunnel for the data.

ES allows the SNMP interface for configuration and establishing the connection.
Used the Securre SNMPv3 for the control path
Developed the control to enable the ES, set the address 

here from security Threat modelling to identify the assets and threats
assets - 
secure vlans
provide QoS 
Used TPM1.2 to store the certificate on the SPIe interface.
