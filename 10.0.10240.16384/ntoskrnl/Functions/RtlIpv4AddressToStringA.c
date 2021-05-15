// RtlIpv4AddressToStringA 
 
int __fastcall RtlIpv4AddressToStringA(unsigned __int8 *a1, int a2)
{
  return sprintf_s(a2, 16, (int)"%u.%u.%u.%u", *a1, a1[1], a1[2], a1[3]) + a2;
}
