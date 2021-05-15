// RtlIpv4AddressToStringExW 
 
int __fastcall RtlIpv4AddressToStringExW(int a1, unsigned int a2, int a3, unsigned int *a4)
{
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r4
  _BYTE v11[44]; // [sp-4h] [bp-40h] BYREF
  char v12[20]; // [sp+28h] [bp-14h] BYREF

  if ( a1 && a4 && (a3 || !*a4) )
  {
    v7 = RtlIpv4AddressToStringW();
    v8 = v7;
    if ( a2 )
      v8 = v7 + 2 * swprintf_s(v7, (int)&v12[-v7] >> 1, (int)L":%u", __rev16(a2));
    v9 = ((v8 - (int)v11) >> 1) + 1;
    if ( *a4 >= v9 )
    {
      memmove(a3, (int)v11, 2 * v9);
      *a4 = v9;
      return 0;
    }
    *a4 = v9;
  }
  return -1073741811;
}
