// -SmStMapVirtualRegion@-$SMKM_STORE@USM_TRAITS@@@@SAPAXPAU1@KKKK@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion(int a1, unsigned int a2, int a3, int a4, unsigned __int8 a5)
{
  unsigned int v5; // r10
  unsigned __int16 *v7; // r5
  int v10; // r4
  int v11; // r1
  unsigned int v12; // r1
  unsigned int v13; // r7
  int v14; // r0
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r0
  unsigned int v19; // r4
  int v20; // r0
  unsigned __int16 v21; // r7
  unsigned int v22; // r1
  unsigned int v23; // r7
  int v24; // [sp+0h] [bp-40h]
  _DWORD v25[2]; // [sp+8h] [bp-38h] BYREF
  unsigned int v26; // [sp+10h] [bp-30h]
  int v27; // [sp+14h] [bp-2Ch]
  int v28; // [sp+18h] [bp-28h]
  int v29; // [sp+1Ch] [bp-24h]

  v5 = *(_DWORD *)(a1 + 3652);
  v7 = (unsigned __int16 *)(*(_DWORD *)(a1 + 3660) + 4 * a2);
  v24 = *(_DWORD *)v7 & 0x7FFF0000;
  if ( (a5 & 8) != 0 )
  {
    v10 = 0;
    if ( (*v7 & 0x4000) != 0 )
    {
      *v7 &= 0xBFFFu;
      return v10;
    }
    if ( SMKM_STORE<SM_TRAITS>::SmStCheckLockInProgressRegionComplete(a1, (int)v7) )
      return v10;
    return 3;
  }
  if ( (a5 & 0x10) == 0 )
  {
    if ( (a5 & 4) != 0 )
    {
      __dmb(0xBu);
      do
        v17 = __ldrex(v7);
      while ( __strex(v17 | 0x8000, v7) );
      __dmb(0xBu);
    }
    else if ( (a5 & 2) == 0 )
    {
      v19 = *v7;
      if ( (*v7 & 0x1FFF) != 0x1FFF )
      {
        while ( 1 )
        {
          v20 = 0;
          v21 = v19 & 0xE000 | (v19 + 1) & 0x1FFF;
          if ( (v19 & 0x1FFF) == 0 )
          {
            v20 = SmAcquireReleaseCharges(v5, 1, 0);
            if ( !v20 )
            {
              if ( (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) != *(_DWORD *)(a1 + 3812) )
                return 2;
              v21 = v21 & 0xC000 | 0x2000;
            }
          }
          __dmb(0xBu);
          do
            v22 = __ldrex(v7);
          while ( v22 == v19 && __strex(v21, v7) );
          __dmb(0xBu);
          v23 = v22;
          if ( v22 == v19 )
            return v24 + a3;
          if ( v20 )
            SmAcquireReleaseCharges(v5, 1, 1);
          v19 = v23;
          if ( (v23 & 0x1FFF) == 0x1FFF )
            return 1;
        }
      }
      return 1;
    }
    return v24 + a3;
  }
  v11 = *(_DWORD *)(a1 + 3864);
  if ( v11 && !SMKM_STORE<SM_TRAITS>::SmStCheckLockInProgressRegionComplete(a1, v11) )
    return 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v13 = SMKM_STORE<SM_TRAITS>::SmStFindVirtualLockedRegion(a1, a5 >> 5, 0);
  *(_DWORD *)(a1 + 3864) = v7;
  v25[0] = v24;
  v25[1] = v5;
  if ( *(_BYTE *)(a1 + 3519) && v12 < 6 )
    v26 = 6;
  else
    v26 = v12;
  if ( (a5 & 1) != 0 )
    v27 = 1;
  v14 = SMKM_STORE<SM_TRAITS>::SmStHelperSendCommand(a1, 4, (int)v25, 4);
  if ( v14 < 0 )
  {
    if ( v14 == -1073741536 )
      return 3;
    *(_DWORD *)(a1 + 3864) = 0;
    return 0;
  }
  v15 = v29;
  *(_DWORD *)(a1 + 3864) = 0;
  if ( v15 < 0 )
  {
    v10 = 0;
    if ( v15 != -1073740749 )
      return v10;
    *v7 |= 0x4000u;
    return 1;
  }
  *(_DWORD *)v13 = v28;
  *(_DWORD *)v7 |= 0x80000000;
  v16 = *(_DWORD *)(a1 + 3860);
  __dmb(0xBu);
  if ( v16 && v16 != -1 )
    *(_BYTE *)((a2 >> 3) + *(_DWORD *)(v16 + 8)) &= ~(1 << (a2 & 7));
  return *(_DWORD *)(*(_DWORD *)v13 + 12);
}
