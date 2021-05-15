// RtlIpv6AddressToStringExA 
 
int __fastcall RtlIpv6AddressToStringExA(unsigned __int16 *a1, int a2, unsigned int a3, int a4, unsigned int *a5)
{
  _BYTE *v9; // r1
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r3
  _BYTE v15[65]; // [sp-4h] [bp-60h] BYREF
  char v16[31]; // [sp+3Dh] [bp-1Fh] BYREF

  if ( !a1 || !a5 || !a4 && *a5 )
    return -1073741811;
  v9 = v15;
  if ( a3 )
    v9 = &v15[sprintf_s((int)v15, 65, (int)"[")];
  v10 = RtlIpv6AddressToStringA(a1, (int)v9);
  v11 = v10;
  if ( a2 )
    v11 = v10 + sprintf_s(v10, (int)&v16[-v10], (int)"%%%u", a2);
  if ( a3 )
    v11 += sprintf_s(v11, (int)&v16[-v11], (int)"]:%u", __rev16(a3));
  v12 = v11 - (_DWORD)v15 + 1;
  v13 = *a5;
  *a5 = v12;
  if ( v13 < v12 )
    return -1073741811;
  memmove(a4, (int)v15, v12);
  return 0;
}
