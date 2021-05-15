// RtlEthernetAddressToStringW 
 
int __fastcall RtlEthernetAddressToStringW(unsigned __int8 *a1, int a2)
{
  return a2 + 2 * swprintf_s(a2, 18, (int)L"%02X-%02X-%02X-%02X-%02X-%02X", *a1, a1[1], a1[2], a1[3], a1[4], a1[5]);
}
