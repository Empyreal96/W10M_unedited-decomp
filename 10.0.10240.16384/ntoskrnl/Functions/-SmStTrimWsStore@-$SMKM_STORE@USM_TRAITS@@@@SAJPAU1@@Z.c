// -SmStTrimWsStore@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStTrimWsStore(int a1)
{
  int v2; // r4
  unsigned int *v3; // r10
  _DWORD *v4; // r5
  unsigned int *v5; // r8
  int v6; // r7
  unsigned int v7; // r2
  unsigned int *v8; // r9
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  unsigned int v12; // r6
  unsigned int v13; // r0
  unsigned int v14; // r10
  int v15; // r3
  int v16; // r0
  unsigned int v17; // r6
  int v18; // r3
  int v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int v24; // r2
  unsigned int v26; // [sp+8h] [bp-80h] BYREF
  _DWORD *v27; // [sp+Ch] [bp-7Ch]
  char v28[24]; // [sp+10h] [bp-78h] BYREF
  _DWORD v29[8]; // [sp+28h] [bp-60h] BYREF
  _DWORD v30[16]; // [sp+48h] [bp-40h] BYREF

  KiStackAttachProcess(PsInitialSystemProcess, 0, (int)v28);
  if ( (*(_BYTE *)(a1 + 3517) & 8) != 0 )
  {
    v2 = 0;
  }
  else
  {
    __dmb(0xBu);
    v3 = (unsigned int *)(a1 + 3860);
    do
      v4 = (_DWORD *)__ldrex(v3);
    while ( __strex(0xFFFFFFFF, v3) );
    v27 = v4;
    __dmb(0xBu);
    if ( v4 == (_DWORD *)-1 )
    {
      v2 = -1073740682;
    }
    else
    {
      if ( v4 && *v4 )
        v5 = v4 + 1;
      else
        v5 = 0;
      v6 = 0;
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v7 + 310);
      v8 = (unsigned int *)(a1 + 3520);
      v9 = KeAbPreAcquire(a1 + 3520, 0, 0);
      v10 = v9;
      do
        v11 = __ldrex(v8);
      while ( !v11 && __strex(0x11u, v8) );
      __dmb(0xBu);
      if ( v11 )
        ExfAcquirePushLockSharedEx((_DWORD *)(a1 + 3520), v9, a1 + 3520);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      if ( v5 )
      {
        v12 = 0;
LABEL_20:
        v26 = v12;
        while ( 1 )
        {
          v13 = RtlFindNextForwardRunClearCapped(v5, v12, 0xFFFFFFFF, &v26);
          if ( !v13 )
            break;
          v12 = v26;
          v14 = v13 + v26;
          if ( v26 < v13 + v26 )
          {
            do
            {
              v15 = *(_DWORD *)(*(_DWORD *)(a1 + 3660) + 4 * v12);
              if ( (v15 & 0x7FFF0000) != 0 )
              {
                v16 = SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion(a1, v12, 0, v15, 4u);
                v30[v6] = v12;
                v29[v6++] = v16;
                if ( v6 == 8 )
                {
                  SMKM_STORE<SM_TRAITS>::SmStTrimWsStoreBatch(a1, v30, v29, 8);
                  v6 = 0;
                }
              }
              ++v12;
            }
            while ( v12 < v14 );
            goto LABEL_20;
          }
        }
        v4 = v27;
        v3 = (unsigned int *)(a1 + 3860);
      }
      v17 = 0;
      if ( *(_DWORD *)(a1 + 3656) )
      {
        do
        {
          v18 = *(_DWORD *)(*(_DWORD *)(a1 + 3660) + 4 * v17);
          if ( (v18 & 0x7FFF0000) != 0 )
          {
            if ( !v5 || (v18 = *(int *)(v5[1] + 4 * (v17 >> 5)) >> (v17 & 0x1F), (v18 & 1) != 0) )
            {
              v19 = SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion(a1, v17, 0, v18, 4u);
              v30[v6] = v17;
              v29[v6++] = v19;
              if ( v6 == 8 )
              {
                SMKM_STORE<SM_TRAITS>::SmStTrimWsStoreBatch(a1, v30, v29, 8);
                v6 = 0;
              }
            }
          }
          ++v17;
        }
        while ( v17 < *(_DWORD *)(a1 + 3656) );
        v4 = v27;
        v8 = (unsigned int *)(a1 + 3520);
        v3 = (unsigned int *)(a1 + 3860);
      }
      if ( v6 )
        SMKM_STORE<SM_TRAITS>::SmStTrimWsStoreBatch(a1, v30, v29, v6);
      __dmb(0xBu);
      do
        v20 = __ldrex(v8);
      while ( v20 == 17 && __strex(0, v8) );
      if ( v20 != 17 )
        ExfReleasePushLockShared(v8);
      v21 = KeAbPostRelease((unsigned int)v8);
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v23 = *(_WORD *)(v22 + 0x136) + 1;
      *(_WORD *)(v22 + 310) = v23;
      if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 )
        KiCheckForKernelApcDelivery(v21);
      v2 = 0;
      __dmb(0xBu);
      do
        v24 = __ldrex(v3);
      while ( __strex((unsigned int)v4, v3) );
      __dmb(0xBu);
    }
  }
  KiUnstackDetachProcess((unsigned int)v28, 0);
  return v2;
}
