// HvInitializeHive 
 
int __fastcall HvInitializeHive(int a1, unsigned int a2, int a3, unsigned int a4, _DWORD *a5, _DWORD *a6, unsigned int a7, int a8, int a9, int a10, _BYTE *a11, _DWORD *a12)
{
  int v12; // r4
  int v13; // r5
  _DWORD *v15; // r3
  int v16; // r2
  _DWORD *v17; // r3
  int v18; // r2
  char v19; // r3
  int v20; // r3
  __int64 v21; // r0
  int v22; // r4
  int v23; // r2
  int v24; // r3
  int v25; // r0
  _DWORD *v26; // r7
  int v27; // r3
  unsigned int v28; // r3
  int v29; // r0
  int v30; // r3
  int v31; // r1
  int v32; // [sp+0h] [bp-38h]
  int v33; // [sp+4h] [bp-34h]
  int v34; // [sp+8h] [bp-30h]
  int v35; // [sp+Ch] [bp-2Ch]
  int v36; // [sp+10h] [bp-28h] BYREF
  int v37; // [sp+14h] [bp-24h]
  int v38; // [sp+18h] [bp-20h]
  int v39; // [sp+1Ch] [bp-1Ch]
  int v40; // [sp+20h] [bp-18h]
  int v41; // [sp+24h] [bp-14h]
  int v42; // [sp+28h] [bp-10h]
  int v43; // [sp+2Ch] [bp-Ch]
  char v44; // [sp+30h] [bp-8h]

  v12 = a2;
  v13 = a1;
  if ( a2 > 5 )
    return sub_7D2BCC();
  if ( (a3 & 0xFFF97CEC) != 0 )
    JUMPOUT(0x7D2BD0);
  if ( a4 > 2 )
    JUMPOUT(0x7D2BD4);
  if ( !a7 || a7 > 8 )
    JUMPOUT(0x7D2E6A);
  if ( !a5 && (a2 == 4 || a2 == 3 || a2 == 1) )
    JUMPOUT(0x7D2BD8);
  if ( (a3 & 1) != 0 && a4 )
    JUMPOUT(0x7D2BDC);
  if ( a11 )
    *a11 = 0;
  *(_DWORD *)a1 = -1092567328;
  if ( a6 )
  {
    *(_DWORD *)(a1 + 12) = *a6;
    *(_DWORD *)(a1 + 16) = a6[1];
    *(_DWORD *)(a1 + 20) = a6[3];
    *(_DWORD *)(a1 + 24) = a6[4];
  }
  else
  {
    *(_DWORD *)(a1 + 12) = 0;
    *(_DWORD *)(a1 + 16) = 0;
    *(_DWORD *)(a1 + 20) = 0;
    *(_DWORD *)(a1 + 24) = 0;
  }
  if ( a4 )
  {
    if ( a4 == 1 )
      *(_DWORD *)(a1 + 96) = 1;
    else
      *(_DWORD *)(a1 + 96) = 4;
  }
  else
  {
    *(_DWORD *)(a1 + 96) = 0;
  }
  *(_DWORD *)(a1 + 140) = 0;
  *(_DWORD *)(a1 + 144) = 2;
  *(_DWORD *)(a1 + 92) = a3;
  *(_DWORD *)(a1 + 68) = a7;
  *(_DWORD *)(a1 + 1364) = 0;
  *(_DWORD *)(a1 + 1368) = 0;
  *(_DWORD *)(a1 + 1372) = 0;
  *(_DWORD *)(a1 + 1376) = -1;
  *(_DWORD *)(a1 + 1772) = 0;
  *(_DWORD *)(a1 + 1764) = a1 + 1764;
  *(_DWORD *)(a1 + 1768) = a1 + 1764;
  v15 = (_DWORD *)a1;
  v16 = 24;
  do
  {
    v15[347] = 0;
    v15[348] = 0;
    v15[345] = 0;
    v15 += 4;
    --v16;
  }
  while ( v16 );
  *(_DWORD *)(a1 + 952) = 0;
  *(_DWORD *)(a1 + 956) = 0;
  *(_DWORD *)(a1 + 960) = 0;
  *(_DWORD *)(a1 + 964) = -1;
  *(_DWORD *)(a1 + 1360) = 0;
  *(_DWORD *)(a1 + 1352) = a1 + 1352;
  *(_DWORD *)(a1 + 1356) = a1 + 1352;
  v17 = (_DWORD *)a1;
  v18 = 24;
  do
  {
    v17[244] = 0;
    v17[245] = 0;
    v17[242] = 0;
    v17 += 4;
    --v18;
  }
  while ( v18 );
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  *(_DWORD *)(a1 + 4) = HvpGetCellPaged;
  *(_DWORD *)(a1 + 44) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  *(_BYTE *)(a1 + 73) = 0;
  *(_DWORD *)(a1 + 8) = HvpReleaseCellPaged;
  v19 = *(_BYTE *)(a1 + 72);
  *(_DWORD *)(a1 + 64) = 4096;
  *(_DWORD *)(a1 + 52) = 0;
  *(_DWORD *)(a1 + 56) = 0;
  *(_BYTE *)(a1 + 72) = v19 & 0xFC;
  v20 = *(_DWORD *)(a1 + 92);
  *(_DWORD *)(a1 + 76) = 0;
  *(_DWORD *)(a1 + 80) = 0;
  *(_DWORD *)(a1 + 84) = 0;
  *(_DWORD *)(a1 + 88) = 0;
  *(_DWORD *)(a1 + 108) = 0;
  *(_BYTE *)(a1 + 121) = 0;
  *(_BYTE *)(a1 + 120) = 0;
  *(_BYTE *)(a1 + 123) = 0;
  v34 = (v20 & 1) == 0;
  KeQuerySystemTime(&v36);
  *(_DWORD *)(v13 + 128) = v36;
  *(_DWORD *)(v13 + 132) = v37;
  memset((_BYTE *)(v13 + 152), 0, 800);
  *(_DWORD *)(v13 + 156) = 0;
  *(_BYTE *)(v13 + 122) = 1;
  if ( v12 )
  {
    if ( v12 == 4 )
    {
      *(_DWORD *)(v13 + 32) = a5;
      *(_DWORD *)(v13 + 148) = a5[6] + ((a5[5] - 1) << 12);
      *(_BYTE *)(v13 + 72) |= 3u;
      *(_DWORD *)(v13 + 4) = HvpGetCellFlat;
      *(_DWORD *)(v13 + 8) = HvpReleaseCellFlat;
      *(_DWORD *)(v13 + 952) = a5[10];
      *(_DWORD *)(v13 + 144) = 1;
      if ( a12 )
        *a12 = 0;
    }
    else
    {
      if ( v12 == 3 )
        JUMPOUT(0x7D2C3C);
      if ( v12 == 1 )
      {
        if ( *a5 != 1718052210
          || a5[7]
          || a5[8] != 1
          || a5[5] > 1u
          || (v28 = a5[6], v28 > 5)
          || v28 < 3
          || a5[10] > 0x7FFFE000u
          || HvpHeaderCheckSum(a5) != a5[127] )
        {
          JUMPOUT(0x7D2E6E);
        }
        v29 = (*(int (__fastcall **)(_DWORD, int, int))(v13 + 12))(*(_DWORD *)(v13 + 64), v34, 858869059);
        *(_DWORD *)(v13 + 32) = v29;
        if ( !v29 )
          JUMPOUT(0x7D2CEA);
        if ( (((a7 << 9) - 1) & v29) != 0 )
          JUMPOUT(0x7D2CEE);
        if ( a12 )
          *a12 = 858869059;
        memmove(*(_DWORD *)(v13 + 32), (int)a5, 0x200u);
        *(_DWORD *)(*(_DWORD *)(v13 + 32) + 4092) = a5[1023];
        *(_DWORD *)(*(_DWORD *)(v13 + 32) + 4088) = a5[1022];
        v30 = a5[1];
        v31 = *(_DWORD *)(v13 + 32);
        *(_DWORD *)(v13 + 100) = v30;
        *(_DWORD *)(v13 + 104) = v30;
        *(_DWORD *)(v13 + 112) = v30;
        *(_DWORD *)(v13 + 148) = *(_DWORD *)(v31 + 24) + ((*(_DWORD *)(v31 + 20) - 1) << 12);
        if ( HvpAdjustHiveFreeDisplay(v13, a5[10], 0) < 0 )
          JUMPOUT(0x7D2D10);
        if ( HvpBuildMapForLoaderHive(v13, a5 + 1024) < 0 )
          JUMPOUT(0x7D2D24);
        if ( (*(_DWORD *)(*(_DWORD *)(v13 + 32) + 144) & 1) != 0 )
          JUMPOUT(0x7D2D4A);
        *(_DWORD *)(*(_DWORD *)(v13 + 32) + 144) &= 0xFFFFFFFE;
        HvpFillFileName(*(_DWORD *)(v13 + 32), a8);
      }
      else
      {
        if ( v12 == 5 )
          v12 = 2;
        if ( v12 != 2 )
          JUMPOUT(0x7D2E64);
        CmpTraceHiveMountStart();
        v21 = HvLoadHive(v13);
        v22 = v21;
        CmpTraceHiveMountStop(
          v21,
          SHIDWORD(v21),
          v23,
          v24,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44);
        if ( v22 )
          JUMPOUT(0x7D2D5A);
        if ( a12 )
          *a12 = 825445699;
        if ( (*(_DWORD *)(*(_DWORD *)(v13 + 32) + 144) & 1) != 0 )
          JUMPOUT(0x7D2D6A);
        *(_DWORD *)(*(_DWORD *)(v13 + 32) + 144) &= 0xFFFFFFFE;
        HvpFillFileName(*(_DWORD *)(v13 + 32), a8);
        HvpSetRangeProtection(v13, 0, *(_DWORD *)(*(_DWORD *)(v13 + 32) + 40), 2);
        if ( (*(_BYTE *)(v13 + 72) & 4) != 0 )
          HvViewMapUnpinFile((_DWORD *)(v13 + 152));
      }
    }
  }
  else
  {
    v25 = (*(int (__fastcall **)(_DWORD, int, int))(v13 + 12))(*(_DWORD *)(v13 + 64), v34, 825314627);
    v26 = (_DWORD *)v25;
    if ( !v25 )
      JUMPOUT(0x7D2BE0);
    if ( (((a7 << 9) - 1) & v25) != 0 )
      JUMPOUT(0x7D2BEA);
    if ( a12 )
      *a12 = 825314627;
    memset((_BYTE *)v25, 0, 4096);
    *v26 = 1718052210;
    v26[8] = 1;
    v26[9] = -1;
    v26[1] = 1;
    v26[2] = 1;
    v26[7] = 0;
    v26[10] = 0;
    v26[11] = 1;
    v26[127] = 0;
    HvpFillFileName(v26, a8);
    v26[5] = 1;
    v26[6] = 3;
    v26[36] = 0;
    *(_DWORD *)(v13 + 148) = 3;
    v26[41] = 1836346738;
    v27 = v36;
    *(_DWORD *)(v13 + 100) = 1;
    *(_DWORD *)(v13 + 104) = 1;
    *(_DWORD *)(v13 + 112) = 1;
    v26[3] = v27;
    v26[4] = v37;
    if ( a9 )
      JUMPOUT(0x7D2C0E);
    if ( a10 )
      JUMPOUT(0x7D2C26);
    *(_DWORD *)(v13 + 32) = v26;
    v26[1022] = 0;
    if ( HvpIsHiveEligibleForSystemCacheBacking(v13) )
    {
      if ( CmpDoFileSetSizeEx(v13, 0, 0x1000u, 0, 0) < 0 )
        JUMPOUT(0x7D2C34);
      if ( HvViewMapStart(v13 + 152, v13, *(_DWORD *)(v13 + 1776), 4096, 1) < 0 )
        JUMPOUT(0x7D2C38);
      *(_BYTE *)(v13 + 72) |= 4u;
    }
  }
  return 0;
}
