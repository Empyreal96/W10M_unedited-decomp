// DrvDbValidateDeviceIdName 
 
int __fastcall DrvDbValidateDeviceIdName(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v5; // r4
  unsigned __int16 *v6; // r0
  _WORD *v7; // r0
  int v8; // t1
  _DWORD v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v5 = RtlUnalignedStringCchLengthW(a2, 200, v10);
  if ( v5 < 0 || (v6 = wcschr(a2, 92)) != 0 && (v6 == a2 || (v8 = v6[1], v7 = v6 + 1, !v8) || wcschr(v7, 92)) )
    v5 = -1073741773;
  return v5;
}
