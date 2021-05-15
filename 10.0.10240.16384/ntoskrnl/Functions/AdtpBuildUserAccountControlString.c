// AdtpBuildUserAccountControlString 
 
int __fastcall AdtpBuildUserAccountControlString(int a1, int a2, int a3, _BYTE *a4, int a5, _BYTE *a6, unsigned int a7, _BYTE *a8)
{
  __int16 v10; // r5
  int v11; // r0
  int v13; // r0
  int v14; // r2
  int v15; // r3
  int v16; // r4
  int v17; // r2
  int v18; // r3
  int v19; // r8
  int v20; // r7
  int v21; // r3
  unsigned __int16 v22; // r3
  int v23; // r0
  unsigned int v24; // r5
  int v25; // r4
  int v26; // r3
  int v27; // r2
  int v28; // r3
  unsigned __int16 v29[2]; // [sp+0h] [bp-50h] BYREF
  char *v30; // [sp+4h] [bp-4Ch]
  int v31; // [sp+8h] [bp-48h]
  int v32; // [sp+Ch] [bp-44h]
  _BYTE *v33; // [sp+10h] [bp-40h]
  char v34; // [sp+18h] [bp-38h] BYREF

  v32 = a1;
  v33 = a6;
  *a4 = 0;
  *a6 = 0;
  v29[1] = 20;
  *a8 = 0;
  v31 = a2;
  *(_WORD *)a3 = 0;
  v29[0] = 0;
  *(_WORD *)(a3 + 2) = 22;
  v10 = 0;
  v30 = &v34;
  v11 = ExAllocatePoolWithTag(1, 22, 1799447891);
  *(_DWORD *)(a3 + 4) = v11;
  if ( !v11 )
    return -1073741801;
  *a4 = 1;
  *(_WORD *)a5 = 0;
  *(_WORD *)(a5 + 2) = 22;
  v13 = ExAllocatePoolWithTag(1, 22, 1799447891);
  *(_DWORD *)(a5 + 4) = v13;
  if ( !v13 )
    return -1073741801;
  v15 = (int)v33;
  *v33 = 1;
  RtlAppendUnicodeToString((unsigned __int16 *)a3, (int)L"0x", v14, v15);
  v16 = v32;
  RtlIntegerToUnicodeString(v32, 16, v29);
  RtlAppendUnicodeStringToString((unsigned __int16 *)a3, v29);
  RtlAppendUnicodeToString((unsigned __int16 *)a5, (int)L"0x", v17, v18);
  v19 = v31;
  RtlIntegerToUnicodeString(v31, 16, v29);
  RtlAppendUnicodeStringToString((unsigned __int16 *)a5, v29);
  v20 = v16 ^ v19;
  if ( v16 != v19 )
  {
    v21 = 1;
    do
    {
      if ( (v21 & v20) != 0 )
        ++v10;
      v21 *= 2;
    }
    while ( v21 );
    *(_WORD *)a7 = 0;
    v22 = 32 * v10 + 2;
    *(_WORD *)(a7 + 2) = v22;
    v23 = ExAllocatePoolWithTag(1, v22, 1799447891);
    *(_DWORD *)(a7 + 4) = v23;
    if ( v23 )
    {
      v24 = 0;
      *a8 = 1;
      v25 = 1;
      do
      {
        if ( !v25 )
          break;
        if ( (v25 & v20) != 0 )
        {
          if ( (v25 & v19) != 0 )
            v26 = 2080;
          else
            v26 = 2048;
          if ( RtlIntegerToUnicodeString(v26 + v24, 10, v29) >= 0 )
          {
            RtlAppendUnicodeToString((unsigned __int16 *)a7, (int)L"\r\n\t\t%%", v27, v28);
            RtlAppendUnicodeStringToString((unsigned __int16 *)a7, v29);
          }
        }
        ++v24;
        v25 *= 2;
      }
      while ( v24 < 0x20 );
      return 0;
    }
    return -1073741801;
  }
  RtlInitUnicodeString(a7, L"-");
  return 0;
}
