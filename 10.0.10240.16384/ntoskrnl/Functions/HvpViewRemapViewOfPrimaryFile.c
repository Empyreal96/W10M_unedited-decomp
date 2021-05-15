// HvpViewRemapViewOfPrimaryFile 
 
int __fastcall HvpViewRemapViewOfPrimaryFile(int a1, int a2, int a3, unsigned int a4, unsigned int a5)
{
  int v6; // r8
  int v7; // r9
  int v8; // r5
  unsigned int v9; // r3
  int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r3
  int v16; // [sp+Ch] [bp-34h] BYREF
  int v17; // [sp+10h] [bp-30h] BYREF
  int v18; // [sp+14h] [bp-2Ch]
  int v19; // [sp+18h] [bp-28h]
  _DWORD v20[8]; // [sp+20h] [bp-20h] BYREF

  v6 = 0;
  v18 = 0;
  v7 = 0;
  v17 = 0;
  v8 = *(_DWORD *)(a2 + 4 * (HIBYTE(a4) & 0x7F)) + 24 * ((a4 >> 18) & 0x3F);
  v19 = v8;
  v20[0] = a4;
  v20[1] = 0;
  v9 = *(_DWORD *)(v8 + 16);
  if ( a5 > v9 )
  {
    if ( !CmpClaimGlobalQuota(a5 - v9) )
    {
      v10 = -1073741670;
      goto LABEL_17;
    }
    v6 = a5 - *(_DWORD *)(v8 + 16);
    v18 = v6;
  }
  if ( !CcMapData(a3, v20, a5, 17, &v17, &v16) )
  {
    v10 = -1073741670;
LABEL_16:
    v7 = v17;
    goto LABEL_17;
  }
  v11 = (a5 + 4095) & 0xFFFFF000;
  if ( *(_QWORD *)(v8 + 8) )
  {
    v10 = MmProtectSystemCacheView(v16, v11, 4u);
    if ( v10 < 0 )
      goto LABEL_16;
  }
  else
  {
    MmProtectSystemCacheView(v16, v11, 2u);
  }
  v12 = *(_DWORD *)(v8 + 16);
  if ( v12 > a5 )
    MmProtectSystemCacheView((*(_DWORD *)v8 & 0xFFFFFFFE) + a5, v12 - a5, 4u);
  CcUnpinData(*(_DWORD *)(v8 + 4));
  v13 = *(_DWORD *)(v8 + 16);
  if ( v13 > a5 )
    CmpReleaseGlobalQuota(v13 - a5);
  *(_DWORD *)v8 = v16;
  *(_DWORD *)v8 = v16 & 0xFFFFFFFE | (*(_QWORD *)(v8 + 8) != 0i64);
  *(_DWORD *)(v8 + 4) = v17;
  *(_DWORD *)(v8 + 16) = a5;
  v7 = 0;
  v10 = 0;
LABEL_17:
  if ( v7 )
    CcUnpinData(v7);
  if ( v10 < 0 )
  {
    v14 = *(_DWORD *)(v8 + 16);
    if ( v14 > a5 )
    {
      CmpReleaseGlobalQuota(v14 - a5);
      *(_DWORD *)(v8 + 16) = a5;
      v10 = 0;
    }
    if ( v10 < 0 && v6 )
      CmpReleaseGlobalQuota(v6);
  }
  return v10;
}
