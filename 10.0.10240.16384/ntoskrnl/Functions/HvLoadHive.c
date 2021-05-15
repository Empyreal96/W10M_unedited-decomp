// HvLoadHive 
 
int __fastcall HvLoadHive(int a1)
{
  int v2; // r0
  int v3; // r8
  _DWORD *v5; // r6
  int v6; // r10
  unsigned int v7; // r9
  unsigned int v8; // r2
  int v9; // r1
  int v10; // r2
  int v11; // r0
  int v12; // r3
  int v13; // r5
  _DWORD *v14; // [sp+14h] [bp-8Ch] BYREF
  unsigned int v15; // [sp+18h] [bp-88h] BYREF
  _DWORD *v16; // [sp+1Ch] [bp-84h]
  int v17; // [sp+20h] [bp-80h]
  int v18; // [sp+24h] [bp-7Ch]
  _DWORD v19[2]; // [sp+28h] [bp-78h] BYREF
  int v20; // [sp+30h] [bp-70h]
  int v21; // [sp+34h] [bp-6Ch]
  char v22[104]; // [sp+38h] [bp-68h] BYREF

  v14 = 0;
  v19[0] = 0;
  v19[1] = 0;
  v17 = 0;
  v18 = 0;
  v20 = 0;
  v2 = HvpGetHiveHeader(a1, &v14, v22);
  v3 = v2;
  switch ( v2 )
  {
    case 2:
      return sub_7F3A40();
    case 0:
      JUMPOUT(0x7F3A4A);
    case 5:
    case 4:
      JUMPOUT(0x7F3A60);
  }
  v5 = v14;
  v6 = v14[1];
  *(_DWORD *)(a1 + 32) = v14;
  *(_DWORD *)(a1 + 148) = v5[6] + ((v5[5] - 1) << 12);
  if ( CmpInitializeActualPrimaryFileSize(a1, &v15) < 0 )
    JUMPOUT(0x7F3B8A);
  v7 = v15;
  v16 = (_DWORD *)(v5[10] + 4096);
  if ( v15 < (unsigned int)v16 )
    JUMPOUT(0x7F3B06);
  v8 = v5[10];
  if ( v8 > 0x7FFFE000 || !v8 )
    JUMPOUT(0x7F3C46);
  if ( HvpIsHiveEligibleForSystemCacheBacking(a1) )
  {
    if ( HvViewMapStart(a1 + 152, a1, *(_DWORD *)(a1 + 1776), v7, 0) < 0 )
      JUMPOUT(0x7F3B86);
    if ( HvViewMapPinForFileOffset(a1 + 152, 0, v7) < 0 )
      JUMPOUT(0x7F3B92);
    *(_BYTE *)(a1 + 72) |= 4u;
  }
  if ( (*(_BYTE *)(a1 + 72) & 4) != 0 )
    v11 = HvpMapHiveImageFromSystemCache(a1, v9, v5[10]);
  else
    v11 = HvpMapHiveImageFromFile(a1, v9, v10, v5[10]);
  if ( v11 < 0 )
    JUMPOUT(0x7F3B96);
  CmpTraceHiveMountBaseFileMounted(*(_DWORD *)(a1 + 1776), v5[10]);
  v14 = (_DWORD *)v6;
  v15 = 0;
  v16 = v19;
  v21 = v19[0];
  if ( v19[0] )
    JUMPOUT(0x7F3B9A);
  v12 = v5[1];
  *(_DWORD *)(a1 + 100) = v12;
  *(_DWORD *)(a1 + 104) = v12;
  *(_DWORD *)(a1 + 112) = v12;
  if ( HvpAdjustHiveFreeDisplay(a1, v5[10], 0) < 0 )
    JUMPOUT(0x7F3C24);
  v13 = HvpRemapAndEnlistHiveBins(a1);
  if ( v13 < 0 )
    JUMPOUT(0x7F3C28);
  if ( v3 == 4 || v20 )
    v13 = 1073741833;
  *(_DWORD *)(a1 + 92) |= 0x10000u;
  v5[2] = v5[1];
  v5[1023] = 0;
  return v13;
}
