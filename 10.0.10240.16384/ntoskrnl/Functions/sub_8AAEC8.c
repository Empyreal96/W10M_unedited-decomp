// sub_8AAEC8 
 
int __fastcall sub_8AAEC8(int a1, int a2, int a3)
{
  unsigned int v3; // r6
  int v7; // r0
  int v8; // r0
  int v9; // r4
  int v10; // r9
  int v11; // r0
  int v13[8]; // [sp+10h] [bp-58h] BYREF
  int v14; // [sp+30h] [bp-38h] BYREF
  __int16 v15; // [sp+34h] [bp-34h]
  int v16[10]; // [sp+40h] [bp-28h] BYREF

  v3 = 0;
  if ( !*(_BYTE *)(a1 + 12) )
  {
    v16[0] = 66067;
    v7 = sub_8AB264(a2, 1507330, v16, 8);
    if ( v7 < 0 )
      v16[0] = v7;
    v14 = 16843009;
    v8 = sub_8AB264(a2, 1507330, &v14, 10);
    if ( v8 < 0 )
    {
      *(_BYTE *)(a3 + 29) |= 0x20u;
      v14 = v8;
      v15 = 0;
    }
  }
  if ( !*(_BYTE *)(a1 + 12) )
  {
    memset(v13, 0, sizeof(v13));
    LOBYTE(v13[1]) = 2;
    v13[3] = -1387689660;
    v13[4] = 298874415;
    v13[5] = -1073689715;
    v13[6] = -1942633649;
    HIWORD(v13[1]) = *(_WORD *)(a3 + 28);
    BYTE1(v13[1]) = *(_BYTE *)(a3 + 30);
    v13[2] = *(_DWORD *)(a3 + 32);
  }
  v9 = sub_8AA490((__int64 *)a1, (int)v13, (int)&v14, 6u);
  if ( v9 >= 0 )
  {
    v10 = *(unsigned __int16 *)(a3 + 36);
    if ( !*(_BYTE *)(a1 + 12) )
    {
      v11 = ExAllocatePoolWithTag(1, v10 + 10, 5459027);
      v3 = v11;
      if ( !v11 )
        return -1073741670;
      *(_DWORD *)v11 = v16[0];
      *(_DWORD *)(v11 + 4) = v14;
      *(_WORD *)(v11 + 8) = v15;
      if ( *(_WORD *)(a3 + 36) )
        memmove(v11 + 10, *(_DWORD *)(a3 + 44), *(unsigned __int16 *)(a3 + 36));
      memset(v13, 0, sizeof(v13));
      LOBYTE(v13[1]) = 2;
      v13[3] = -165009370;
      v13[4] = 1188975584;
      v13[5] = 1471562655;
      v13[6] = 646114032;
      HIWORD(v13[1]) = *(_WORD *)(a3 + 28);
      BYTE1(v13[1]) = *(_BYTE *)(a3 + 30);
      v13[2] = *(_DWORD *)(a3 + 32);
    }
    v9 = sub_8AA490((__int64 *)a1, (int)v13, v3, v10 + 10);
    if ( v3 )
      ExFreePoolWithTag(v3);
  }
  return v9;
}
