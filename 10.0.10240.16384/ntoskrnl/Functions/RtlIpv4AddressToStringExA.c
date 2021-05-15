// RtlIpv4AddressToStringExA 
 
int __fastcall RtlIpv4AddressToStringExA(unsigned __int8 *a1, unsigned int a2, int a3, unsigned int *a4)
{
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r4
  _BYTE v11[22]; // [sp-4h] [bp-30h] BYREF
  char v12[26]; // [sp+12h] [bp-1Ah] BYREF

  if ( a1 && a4 && (a3 || !*a4) )
  {
    v7 = RtlIpv4AddressToStringA(a1, (int)v11);
    v8 = v7;
    if ( a2 )
      v8 = v7 + sprintf_s(v7, (int)&v12[-v7], (int)":%u", __rev16(a2));
    v9 = v8 - (_DWORD)v11 + 1;
    if ( *a4 >= v9 )
    {
      memmove(a3, (int)v11, v9);
      *a4 = v9;
      return 0;
    }
    *a4 = v9;
  }
  return -1073741811;
}
