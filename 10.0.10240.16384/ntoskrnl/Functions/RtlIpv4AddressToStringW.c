// RtlIpv4AddressToStringW 
 
int __fastcall RtlIpv4AddressToStringW(unsigned __int8 *a1, int a2)
{
  return a2 + 2 * swprintf_s(a2, 16, (int)L"%u.%u.%u.%u", *a1, a1[1], a1[2], a1[3]);
}
