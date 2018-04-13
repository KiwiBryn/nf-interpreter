//
// Copyright (c) 2017 The nanoFramework project contributors
// See LICENSE file in the project root for full license information.
//

#ifndef _NANOHAL_NETWORK_H_
#define _NANOHAL_NETWORK_H_ 1

#include <nanoPackStruct.h>
#include <nanoWeak.h>

///////////////////////////////////////////////////////////////////////////////////////////
// !!! KEEP IN SYNC WITH System.Net.NetworkInformation.AddressMode (in managed code) !!! //
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////
// Description: Startup network IP assigning modes
typedef enum AddressMode
{
    AddressMode_DHCP       = 0x01,
    AddressMode_Static     = 0x02,

    ////////////////////////////////////////
    // for this option to be valid 
    // LWIP_AUTOIP (lwIP option) has to be defined
    AddressMode_AutoIP     = 0x03
    
}AddressMode;

//////////////////////////////////////////////////////////////////////////////////////////////////
// !!! KEEP IN SYNC WITH System.Net.NetworkInformation.AuthenticationType (in managed code) !!! //
//////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Description: authentication used in wireless network
typedef enum AuthenticationType
{
    AuthenticationType_None     = 0x00,
    AuthenticationType_EAP      = 0x01,
    AuthenticationType_PEAP     = 0x02,
    AuthenticationType_WCN      = 0x03,
    AuthenticationType_Open     = 0x04,
    AuthenticationType_Shared   = 0x05,
    AuthenticationType_WEP      = 0x06,
    AuthenticationType_WPA      = 0x07,
    AuthenticationType_WPA2     = 0x08,
    
}AuthenticationType;

//////////////////////////////////////////////////////////////////////////////////////////////
// !!! KEEP IN SYNC WITH System.Net.NetworkInformation.EncryptionType (in managed code) !!! //
//////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Description: encryption used in wireless network
typedef enum EncryptionType
{
    EncryptionType_None         = 0x00,
    EncryptionType_WEP          = 0x01,
    EncryptionType_WPA          = 0x02,
    EncryptionType_WPA2         = 0x03,
    EncryptionType_WPA_PSK      = 0x04,
    EncryptionType_WPA2_PSK     = 0x05,
    EncryptionType_Certificate  = 0x06,
    
}EncryptionType;

/////////////////////////////////////////////////////////////////////////////////////////
// !!! KEEP IN SYNC WITH System.Net.NetworkInformation.RadioType (in managed code) !!! //
/////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Description: type of radio that the wireless network uses
typedef enum RadioType
{
    RadioType_None      = 0x00,
    RadioType_802_11a   = 0x01,
    RadioType_802_11b   = 0x02,
    RadioType_802_11g   = 0x03,
    RadioType_802_11n   = 0x04,
}RadioType;

typedef struct __nfpack Configuration_NetworkInterface {

    // this is the marker placeholder for this configuration block
    uint8_t Marker[4];

    // Pointer to MAC address as an array of 6 unsigned bytes.
    uint8_t MacAddress[6];

    // Network IPv4 address as 32-bit unsigned integer
    uint32_t  IPv4Address;

    // Network IPv4 subnet mask as 32-bit unsigned integer
    uint32_t  IPv4NetMask;

    // Network gateway IPv4 address as 32-bit unsigned integer
    uint32_t  IPv4GatewayAddress;

    // DNS server 1 IPv4 address as 32-bit unsigned integer
    uint32_t  IPv4DNSAddress1;

    // DNS server 2 IPv4 address as 32-bit unsigned integer
    uint32_t  IPv4DNSAddress2;

    // Network IPv6 address as an array of 4 32-bit unsigned integers
    uint32_t  IPv6Address[4];

    // Network IPv6 subnet mask as an array of 4 32-bit unsigned integers
    uint32_t  IPv6NetMask[4];

    // Network gateway IPv6 address as an array of 4 32-bit unsigned integers
    uint32_t  IPv6GatewayAddress[4];

    // DNS server 1 IPv6 address as an array of 4 32-bit unsigned integers
    uint32_t  IPv6DNSAddress1[4];

    // DNS server 2 IPv6 address as an array of 4 32-bit unsigned integers
    uint32_t  IPv6DNSAddress2[4];

    // Startup network addressing mode - static, DHCP, auto
    AddressMode StartupAddressMode;

} Configuration_NetworkInterface;


typedef struct __nfpack Configuration_Wireless80211NetworkInterface {

    // this is the marker placeholder for this configuration block
    uint8_t Marker[4];
    
    // Network interface configuration
    Configuration_NetworkInterface NetworkConfig;

    // Type of authentication used on the wireless network
    AuthenticationType Authentication;

    // Type of encryption used on the wireless network.
    EncryptionType Encryption;

    // Type of radio used by the wireless network adapter.
    RadioType Radio;

    // Network SSID
    uint8_t Ssid[32];

    // Network password
    uint8_t Password[64];

} Configuration_Wireless80211NetworkInterface;

void 	nanoHAL_Network_Initialize();

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif //_NANOHAL_NETWORK_H_
