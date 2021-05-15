// RtlEthernetAddressToStringA 
 
int __fastcall RtlEthernetAddressToStringA(unsigned __int8 *a1, int a2)
{
  return sprintf_s(a2, 18, (int)"%02X-%02X-%02X-%02X-%02X-%02X", *a1, a1[1], a1[2], a1[3], a1[4], a1[5]) + a2;
}
