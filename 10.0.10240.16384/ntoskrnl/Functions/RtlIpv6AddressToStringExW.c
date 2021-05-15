// RtlIpv6AddressToStringExW 
 
int __fastcall RtlIpv6AddressToStringExW(int a1, int a2, unsigned int a3, int a4, unsigned int *a5)
{
  _WORD *v9; // r1
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r3
  _WORD v15[65]; // [sp-4h] [bp-A0h] BYREF
  char v16[30]; // [sp+7Eh] [bp-1Eh] BYREF

  if ( !a1 || !a5 || !a4 && *a5 )
    return -1073741811;
  v9 = v15;
  if ( a3 )
    v9 = &v15[swprintf_s((int)v15, 65, (int)L"[")];
  v10 = RtlIpv6AddressToStringW(a1, v9);
  v11 = v10;
  if ( a2 )
    v11 = v10 + 2 * swprintf_s(v10, (int)&v16[-v10] >> 1, (int)L"%%%u", a2);
  if ( a3 )
    v11 += 2 * swprintf_s(v11, (int)&v16[-v11] >> 1, (int)L"]:%u", __rev16(a3));
  v12 = ((v11 - (int)v15) >> 1) + 1;
  v13 = *a5;
  *a5 = v12;
  if ( v13 < v12 )
    return -1073741811;
  memmove(a4, (int)v15, 2 * v12);
  return 0;
}
