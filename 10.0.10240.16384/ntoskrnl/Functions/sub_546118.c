// sub_546118 
 
void sub_546118()
{
  _DWORD *v0; // r5
  char v1; // r6
  int v2; // r7
  int v3; // r8
  int v4; // r9
  int v5; // r10
  int v6; // r2
  int v7; // r0
  unsigned int v8; // r9
  int v9; // r6
  unsigned int v10; // r1
  int v11; // r0
  unsigned int v12; // r0
  int v13; // r0
  __int16 v14; // r3
  int v15; // r3
  bool v16; // zf
  int *v17; // r2
  int v18; // r2
  int v19; // [sp+0h] [bp-38h]
  char v20[48]; // [sp+8h] [bp-30h] BYREF

  MiIssuePageExtendRequestNoWait(v0, v2, 0);
  v6 = v1 & 0x20;
  if ( (v1 & 0x20) == 0 )
  {
    if ( v5 )
    {
      ++dword_632D20;
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v8 + 310);
      v9 = KeAbPreAcquire((unsigned int)dword_634D34, 0, 0);
      do
        v10 = __ldrex((unsigned __int8 *)dword_634D34);
      while ( __strex(v10 | 1, (unsigned __int8 *)dword_634D34) );
      __dmb(0xBu);
      if ( (v10 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(dword_634D34, v9, (unsigned int)dword_634D34);
      if ( v9 )
        *(_BYTE *)(v9 + 14) |= 1u;
      v11 = v0[49];
      if ( !*(_DWORD *)(v11 + 4) )
        KePulseEvent(v11, 0, 0);
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)dword_634D34);
      while ( __strex(v12 - 1, (unsigned int *)dword_634D34) );
      if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)dword_634D34);
      v13 = KeAbPostRelease((unsigned int)dword_634D34);
      v14 = *(_WORD *)(v8 + 310) + 1;
      *(_WORD *)(v8 + 310) = v14;
      if ( !v14 && *(_DWORD *)(v8 + 100) != v8 + 100 )
        KiCheckForKernelApcDelivery(v13);
      v4 = v19;
    }
    else
    {
      ++dword_632D1C;
      KeAcquireInStackQueuedSpinLock(v0 + 736, (unsigned int)v20);
      v7 = v0[51];
      if ( !*(_DWORD *)(v7 + 4) )
        KePulseEvent(v7, 0, 0);
      KeReleaseInStackQueuedSpinLock((int)v20);
    }
    if ( !MiFreeExcessSegments(1) )
      MiTrimSegmentCache(0);
    v6 = 0;
  }
  if ( !v3 )
  {
    if ( v4 == 16 )
      v15 = 1;
    else
      v15 = 2;
    if ( v5 )
    {
      v16 = v6 == 0;
      v17 = &MiState[v15];
      if ( v16 )
      {
        ++v17[9];
      }
      else
      {
        ++v17[12];
        v18 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
        ++*(_DWORD *)(v18 + 52);
      }
    }
    else
    {
      ++MiState[v15 + 6];
    }
    ++dword_632AC0;
  }
  JUMPOUT(0x4BFE30);
}
