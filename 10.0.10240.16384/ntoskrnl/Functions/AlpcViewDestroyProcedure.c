// AlpcViewDestroyProcedure 
 
int __fastcall AlpcViewDestroyProcedure(int a1)
{
  int v2; // r8
  int v3; // r3
  _DWORD *v4; // r5
  int v5; // r10
  unsigned __int8 *v6; // r9
  int v7; // r6
  unsigned int v8; // r2
  unsigned int *v10; // r1
  unsigned int v11; // r2
  int v12; // r2
  int v13; // r2
  int v14; // r3
  char v15; // r2
  int v16; // r9
  int v17; // r3
  unsigned int *v18; // r6
  unsigned int v19; // r1
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r0
  unsigned __int8 *v23; // r7
  _DWORD *v24; // r5
  int v25; // r0
  int v26; // r6
  unsigned int v27; // r2
  _DWORD *v28; // r2
  _DWORD *v29; // r1
  unsigned int v30; // r1
  int v31; // r0
  int v32; // r0
  unsigned int *v33; // r2
  unsigned int v34; // r1
  int v35; // r1
  unsigned int *v36; // r2
  unsigned int v37; // r1
  int v38; // r1
  unsigned __int8 *v39; // r6
  int v40; // r0
  int v41; // r5
  unsigned int v42; // r2
  unsigned int *v43; // r5
  unsigned int v44; // r1
  char v45[56]; // [sp+8h] [bp-38h] BYREF

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = *(_DWORD **)(a1 + 8);
  v5 = *(_DWORD *)((v3 & 0xFFFFFFC0) + 0x74);
  if ( v4 )
  {
    v6 = (unsigned __int8 *)(v4 - 1);
    v7 = KeAbPreAcquire((unsigned int)(v4 - 1), 0, 0);
    do
      v8 = __ldrex(v6);
    while ( __strex(v8 | 1, v6) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      return sub_7E6C78();
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    *((_BYTE *)v4 - 16) |= 1u;
    __dmb(0xBu);
    v10 = v4 - 3;
    do
    {
      v11 = __ldrex(v10);
      v12 = v11 + 0x10000;
    }
    while ( __strex(v12, v10) );
    __dmb(0xBu);
    if ( v12 <= 0 )
      KeBugCheckEx(24, 0, (int)v4, 38, v12);
    **(_DWORD **)(a1 + 4) = *(_DWORD *)a1;
    *(_DWORD *)(*(_DWORD *)a1 + 4) = *(_DWORD *)(a1 + 4);
    v13 = v4[7] - 1;
    v4[7] = v13;
    if ( (*(_DWORD *)(a1 + 36) & 4) == 0 )
    {
      v14 = v4[6];
      if ( (v14 & 1) != 0 )
      {
        v2 = v4[10];
        v4[11] = 0;
        if ( v2 )
        {
          AlpcpRestoreWriteAccess(v2);
        }
        else if ( !v13 )
        {
          v4[6] = v14 & 0xFFFFFFFE;
        }
      }
    }
    v15 = *((_BYTE *)v4 - 16);
    v16 = 0;
    if ( (v15 & 1) != 0 )
    {
      v17 = *((__int16 *)v4 - 7);
      *((_WORD *)v4 - 7) = 0;
      v16 = 0x10000 - v17;
      *((_BYTE *)v4 - 16) = v15 & 0xFE;
    }
    v18 = v4 - 1;
    __dmb(0xBu);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 - 1, v18) );
    if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
      ExfTryToWakePushLock(v4 - 1);
    KeAbPostRelease((unsigned int)(v4 - 1));
    if ( v16 > 0 )
    {
      __dmb(0xBu);
      v20 = v4 - 3;
      do
      {
        v21 = __ldrex(v20);
        v22 = v21 - v16;
      }
      while ( __strex(v22, v20) );
      __dmb(0xBu);
      if ( v22 <= 0 )
      {
        if ( v22 )
          KeBugCheckEx(24, 0, (int)v4, 40, v22);
        AlpcpDestroyBlob(v4);
      }
    }
    v23 = (unsigned __int8 *)(*(_DWORD *)(a1 + 12) + 196);
    v24 = (_DWORD *)(a1 - 24);
    v25 = KeAbPreAcquire((unsigned int)v23, 0, 0);
    v26 = v25;
    do
      v27 = __ldrex(v23);
    while ( __strex(v27 | 1, v23) );
    __dmb(0xBu);
    if ( (v27 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v23, v25, (unsigned int)v23);
    if ( v26 )
      *(_BYTE *)(v26 + 14) |= 1u;
    v28 = (_DWORD *)*v24;
    if ( (_DWORD *)*v24 != v24 )
    {
      v29 = *(_DWORD **)(a1 - 20);
      if ( (_DWORD *)v28[1] != v24 || (_DWORD *)*v29 != v24 )
        __fastfail(3u);
      *v29 = v28;
      v28[1] = v29;
      *v24 = v24;
      *(_DWORD *)(a1 - 20) = a1 - 24;
    }
    __dmb(0xBu);
    do
      v30 = __ldrex((unsigned int *)v23);
    while ( __strex(v30 - 1, (unsigned int *)v23) );
    if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v23);
    KeAbPostRelease((unsigned int)v23);
    ObfDereferenceObject(*(_DWORD *)(a1 + 12));
    v31 = *(_DWORD *)(a1 + 16);
    if ( v5 != v31 )
      KiStackAttachProcess(v31, 0, (int)v45);
    if ( *(_DWORD *)(a1 + 28) )
      MmUnsecureVirtualMemory();
    MiUnmapViewOfSection(*(_DWORD *)(a1 + 16), *(_DWORD *)(a1 + 20), 0);
    if ( v5 != *(_DWORD *)(a1 + 16) )
      KiUnstackDetachProcess((unsigned int)v45, 0);
    if ( v2 )
    {
      __dmb(0xBu);
      v36 = (unsigned int *)(v2 - 12);
      do
      {
        v37 = __ldrex(v36);
        v38 = v37 - 1;
      }
      while ( __strex(v38, v36) );
      __dmb(0xBu);
      if ( v38 <= 0 )
      {
        if ( v38 )
          KeBugCheckEx(24, 0, v2, 33, v38);
        AlpcpDestroyBlob(v2);
      }
    }
    v32 = *(_DWORD *)(a1 + 8);
    __dmb(0xBu);
    v33 = (unsigned int *)(v32 - 12);
    do
    {
      v34 = __ldrex(v33);
      v35 = v34 - 1;
    }
    while ( __strex(v35, v33) );
    __dmb(0xBu);
    if ( v35 <= 0 )
    {
      if ( v35 )
        KeBugCheckEx(24, 0, v32, 33, v35);
      AlpcpDestroyBlob(v32);
    }
    v39 = (unsigned __int8 *)(*(_DWORD *)(a1 + 16) + 656);
    v40 = KeAbPreAcquire((unsigned int)v39, 0, 0);
    v41 = v40;
    do
      v42 = __ldrex(v39);
    while ( __strex(v42 | 1, v39) );
    __dmb(0xBu);
    if ( (v42 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v39, v40, (unsigned int)v39);
    if ( v41 )
      *(_BYTE *)(v41 + 14) |= 1u;
    **(_DWORD **)(a1 + 48) = *(_DWORD *)(a1 + 44);
    *(_DWORD *)(*(_DWORD *)(a1 + 44) + 4) = *(_DWORD *)(a1 + 48);
    v43 = (unsigned int *)(*(_DWORD *)(a1 + 16) + 656);
    __dmb(0xBu);
    do
      v44 = __ldrex(v43);
    while ( __strex(v44 - 1, v43) );
    if ( (v44 & 2) != 0 && (v44 & 4) == 0 )
      ExfTryToWakePushLock(v43);
    KeAbPostRelease((unsigned int)v43);
    ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 16));
  }
  return 0;
}
