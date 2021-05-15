// RtlpFindRegTziForCurrentYear 
 
int __fastcall RtlpFindRegTziForCurrentYear(_BYTE *a1, int a2, __int16 a3)
{
  int v3; // r5
  int v5; // r4
  int v7; // r0
  int v9; // [sp+8h] [bp-A8h] BYREF
  int v10; // [sp+Ch] [bp-A4h] BYREF
  int v11[28]; // [sp+10h] [bp-A0h] BYREF
  char v12[48]; // [sp+80h] [bp-30h] BYREF

  v3 = a3;
  v5 = -1073741811;
  memset(a1, 0, 44);
  if ( !itow_s(v3, v12, 5, 10) )
  {
    memset(v11, 0, sizeof(v11));
    v11[2] = (int)L"FirstEntry";
    v11[3] = (int)&v10;
    v11[9] = (int)&szLastEntry;
    v11[10] = (int)&v9;
    v11[15] = 288;
    v11[16] = (int)v12;
    v11[17] = (int)a1;
    *(_DWORD *)a1 = -44;
    v9 = -4;
    v10 = -4;
    v11[1] = 292;
    v11[4] = 0x4000000;
    v11[8] = 292;
    v11[11] = 0x4000000;
    v11[18] = 50331648;
    v5 = RtlQueryRegistryValuesEx(0x40000000, a2, v11);
    if ( v5 >= 0 )
    {
      if ( v9 == -4 || v10 == -4 )
        v5 = -1073741762;
      if ( v5 >= 0 && (v3 > v9 || v3 < v10) )
      {
        if ( v3 <= v9 )
          v7 = (__int16)v10;
        else
          v7 = (__int16)v9;
        if ( itow_s(v7, v12, 5, 10) )
        {
          v5 = -1073741762;
        }
        else
        {
          *(_DWORD *)a1 = -44;
          v11[15] = 292;
          v11[18] = 50331648;
          v5 = RtlQueryRegistryValuesEx(0x40000000, a2, &v11[14]);
        }
      }
    }
  }
  return v5;
}
