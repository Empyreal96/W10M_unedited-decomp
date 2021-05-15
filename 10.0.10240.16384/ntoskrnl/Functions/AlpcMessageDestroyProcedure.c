// AlpcMessageDestroyProcedure 
 
int __fastcall AlpcMessageDestroyProcedure(int a1)
{
  int result; // r0
  int v3; // r0
  unsigned int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r5
  int v8; // r0
  int v9; // r3
  int v10; // r5
  unsigned int v11; // r3
  int v12; // r0
  int v13; // r7
  int v14; // r5
  unsigned int v15; // r1
  unsigned int *v16; // r7
  int v17; // r3
  unsigned int v18; // r2
  int v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r1
  int v25; // r1
  int v26; // r2
  char v27; // r3
  unsigned int *v28; // r2
  unsigned int v29; // r1
  int v30; // r1
  int v31; // r8
  unsigned __int8 *v32; // r9
  int v33; // r0
  int v34; // r7
  unsigned int v35; // r2
  unsigned int *v36; // r1
  unsigned int v37; // r0
  int v38; // r0
  int v39; // r7
  int v40; // r9
  char v41; // r2
  int v42; // r3
  unsigned int *v43; // r8
  unsigned int v44; // r1
  unsigned int *v45; // r2
  unsigned int v46; // r0
  int v47; // r0
  unsigned int *v48; // r2
  unsigned int v49; // r1
  int v50; // r1
  unsigned int *v51; // r2
  unsigned int v52; // r1
  int v53; // r1
  int v54; // r2
  char v55; // r3

  if ( AlpcpMessageLogEnabled )
    return sub_7F9894();
  *(_DWORD *)(a1 + 136) |= 0x80000000;
  if ( *(_DWORD *)(a1 + 52) )
  {
    v11 = *(_DWORD *)(a1 + 20);
    v12 = *(_DWORD *)(a1 + 12);
    v13 = (v11 >> 13) & 1;
    if ( v12 )
    {
      if ( (v11 & 0x1000) != 0 )
        ObfDereferenceObject(v12);
      *(_DWORD *)(a1 + 12) = 0;
    }
    *(_DWORD *)(a1 + 20) = 0;
    AlpcpReleaseAttributes((_DWORD *)(a1 + 56));
    v14 = *(_DWORD *)(a1 + 104);
    if ( v14 )
    {
      v26 = *(_DWORD *)(a1 + 104) & 7;
      v27 = 1;
      if ( v26 == 5 )
      {
        v27 = 5;
        v26 = 0;
      }
      PspChargeJobWakeCounter(
        (_DWORD *)(v14 & 0xFFFFFFF8),
        0,
        v26,
        -1,
        0xFFFFFFFF,
        0xFFFFFFFF,
        v27,
        0,
        *(_DWORD *)(a1 + 136));
      ObDereferenceObjectDeferDeleteWithTag(v14 & 0xFFFFFFF8);
      *(_DWORD *)(a1 + 104) = 0;
    }
    *(_WORD *)(a1 + 122) = 24;
    *(_WORD *)(a1 + 120) = 0;
    *(_DWORD *)(a1 + 92) = 0;
    *(_DWORD *)(a1 + 96) = 0;
    if ( v13 )
    {
      v19 = *(_DWORD *)(a1 + 52);
      __dmb(0xBu);
      v20 = (unsigned int *)(v19 + 16);
      do
        v21 = __ldrex(v20);
      while ( __strex(0, v20) );
      __dmb(0xBu);
      v22 = *(_DWORD *)(a1 + 52);
      __dmb(0xBu);
      v23 = (unsigned int *)(v22 - 12);
      do
      {
        v24 = __ldrex(v23);
        v25 = v24 - 1;
      }
      while ( __strex(v25, v23) );
      __dmb(0xBu);
      if ( v25 <= 0 )
      {
        if ( v25 )
          KeBugCheckEx(24, 0, v22, 33, v25);
        AlpcpDestroyBlob(v22);
      }
    }
    result = -1073741823;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 28);
    if ( v3 )
    {
      v15 = 400;
      if ( *(_DWORD *)(a1 + 108) )
        v15 = *(_DWORD *)(a1 + 112) + 400;
      if ( (*(_DWORD *)(a1 + 20) & 0x400) != 0 )
      {
        PsReturnSharedPoolQuota(v3, v15, 0);
      }
      else
      {
        v16 = (unsigned int *)(v3 + 668);
        v17 = *(_DWORD *)(v3 + 668);
        __dmb(0xBu);
        if ( v17 + v15 >= 0x1000 )
        {
          PsReturnProcessPagedPoolQuota(v3, v15);
        }
        else
        {
          __dmb(0xBu);
          do
            v18 = __ldrex(v16);
          while ( __strex(v18 + v15, v16) );
          __dmb(0xBu);
        }
        ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 28));
      }
      *(_DWORD *)(a1 + 28) = 0;
    }
    v4 = *(_DWORD *)(a1 + 108);
    if ( v4 )
      ExFreePoolWithTag(v4);
    v5 = *(_DWORD *)(a1 + 12);
    if ( v5 )
    {
      if ( (*(_DWORD *)(a1 + 20) & 0x1000) != 0 )
        ObfDereferenceObject(v5);
      *(_DWORD *)(a1 + 12) = 0;
    }
    v6 = *(_DWORD *)(a1 + 72);
    if ( v6 )
    {
      __dmb(0xBu);
      v28 = (unsigned int *)(v6 - 12);
      do
      {
        v29 = __ldrex(v28);
        v30 = v29 - 1;
      }
      while ( __strex(v30, v28) );
      __dmb(0xBu);
      if ( v30 <= 0 )
      {
        if ( v30 )
          KeBugCheckEx(24, 0, v6, 33, v30);
        AlpcpDestroyBlob(v6);
      }
      *(_DWORD *)(a1 + 72) = 0;
    }
    v7 = *(_DWORD *)(a1 + 76);
    if ( v7 )
    {
      v31 = *(_DWORD *)(v7 + 8);
      v32 = (unsigned __int8 *)(v31 - 4);
      v33 = KeAbPreAcquire(v31 - 4, 0, 0);
      v34 = v33;
      do
        v35 = __ldrex(v32);
      while ( __strex(v35 | 1, v32) );
      __dmb(0xBu);
      if ( (v35 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v31 - 4), v33, v31 - 4);
      if ( v34 )
        *(_BYTE *)(v34 + 14) |= 1u;
      *(_BYTE *)(v31 - 16) |= 1u;
      __dmb(0xBu);
      v36 = (unsigned int *)(v31 - 12);
      do
      {
        v37 = __ldrex(v36);
        v38 = v37 + 0x10000;
      }
      while ( __strex(v38, v36) );
      __dmb(0xBu);
      if ( v38 <= 0 )
        KeBugCheckEx(24, 0, v31, 38, v38);
      v39 = *(_DWORD *)(v7 + 8);
      v40 = 0;
      --*(_DWORD *)(v7 + 40);
      v41 = *(_BYTE *)(v39 - 16);
      if ( (v41 & 1) != 0 )
      {
        v42 = *(__int16 *)(v39 - 14);
        *(_WORD *)(v39 - 14) = 0;
        v40 = 0x10000 - v42;
        *(_BYTE *)(v39 - 16) = v41 & 0xFE;
      }
      v43 = (unsigned int *)(v39 - 4);
      __dmb(0xBu);
      do
        v44 = __ldrex(v43);
      while ( __strex(v44 - 1, v43) );
      if ( (v44 & 2) != 0 && (v44 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v39 - 4));
      KeAbPostRelease(v39 - 4);
      if ( v40 > 0 )
      {
        __dmb(0xBu);
        v45 = (unsigned int *)(v39 - 12);
        do
        {
          v46 = __ldrex(v45);
          v47 = v46 - v40;
        }
        while ( __strex(v47, v45) );
        __dmb(0xBu);
        if ( v47 <= 0 )
        {
          if ( v47 )
            KeBugCheckEx(24, 0, v39, 40, v47);
          AlpcpDestroyBlob(v39);
        }
      }
      __dmb(0xBu);
      v48 = (unsigned int *)(v7 - 12);
      do
      {
        v49 = __ldrex(v48);
        v50 = v49 - 1;
      }
      while ( __strex(v50, v48) );
      __dmb(0xBu);
      if ( v50 <= 0 )
      {
        if ( v50 )
          KeBugCheckEx(24, 0, v7, 33, v50);
        AlpcpDestroyBlob(v7);
      }
      *(_DWORD *)(a1 + 76) = 0;
    }
    v8 = *(_DWORD *)(a1 + 80);
    if ( v8 )
    {
      __dmb(0xBu);
      v51 = (unsigned int *)(v8 - 12);
      do
      {
        v52 = __ldrex(v51);
        v53 = v52 - 1;
      }
      while ( __strex(v53, v51) );
      __dmb(0xBu);
      if ( v53 <= 0 )
      {
        if ( v53 )
          KeBugCheckEx(24, 0, v8, 33, v53);
        AlpcpDestroyBlob(v8);
      }
      *(_DWORD *)(a1 + 80) = 0;
    }
    v9 = *(_DWORD *)(a1 + 84);
    if ( v9 )
    {
      if ( (v9 & 1) != 0 )
        ObfDereferenceObject(v9 & 0xFFFFFFFE);
      *(_DWORD *)(a1 + 84) = 0;
    }
    v10 = *(_DWORD *)(a1 + 104);
    if ( v10 )
    {
      v54 = *(_DWORD *)(a1 + 104) & 7;
      v55 = 1;
      if ( v54 == 5 )
      {
        v55 = 5;
        v54 = 0;
      }
      PspChargeJobWakeCounter(
        (_DWORD *)(v10 & 0xFFFFFFF8),
        0,
        v54,
        -1,
        0xFFFFFFFF,
        0xFFFFFFFF,
        v55,
        0,
        *(_DWORD *)(a1 + 136));
      ObDereferenceObjectDeferDeleteWithTag(v10 & 0xFFFFFFF8);
      *(_DWORD *)(a1 + 104) = 0;
    }
    result = 0;
  }
  return result;
}
