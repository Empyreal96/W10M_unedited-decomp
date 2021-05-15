// ObpSetObjectAuditInfo 
 
int __fastcall ObpSetObjectAuditInfo(int a1, int a2)
{
  unsigned int *v5; // r5
  unsigned int v6; // r8
  int v7; // r0
  unsigned int v8; // r7
  unsigned int v9; // r2
  unsigned __int8 *v10; // r4
  int v11; // r0
  int v12; // r6
  unsigned int v13; // r2
  unsigned int v14; // r3
  int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3

  if ( !RtlValidSecurityDescriptor(a2, a2) )
    return -1073741703;
  if ( (*(_BYTE *)(a1 + 14) & 0x20) != 0 )
    v5 = (unsigned int *)(a1 - ObpInfoMaskToOffset[*(_BYTE *)(a1 + 14) & 0x3F]);
  else
    v5 = 0;
  if ( v5 && !*v5 )
  {
    v6 = RtlLengthSecurityDescriptor(a2);
    v7 = ExAllocatePoolWithTag(1, v6, 1229021775);
    v8 = v7;
    if ( !v7 )
      return -1073741670;
    memmove(v7, a2, v6);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    v10 = (unsigned __int8 *)(a1 + 8);
    v11 = KeAbPreAcquire((unsigned int)v10, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v10);
    while ( __strex(v13 | 1, v10) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v10, v11, (unsigned int)v10);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    v14 = *v5;
    __pld(v10);
    if ( v14 )
    {
      v15 = *(_DWORD *)v10;
      v16 = *(_DWORD *)v10 - 16;
      if ( (*(_DWORD *)v10 & 0xFFFFFFF0) <= 0x10 )
        v16 = 0;
      if ( (v15 & 2) != 0 )
        goto LABEL_24;
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)v10);
      while ( v17 == v15 && __strex(v16, (unsigned int *)v10) );
      if ( v17 != v15 )
LABEL_24:
        ExfReleasePushLock(v10, v15);
      v18 = KeAbPostRelease((unsigned int)v10);
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v20 = *(_WORD *)(v19 + 0x134) + 1;
      *(_WORD *)(v19 + 308) = v20;
      if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
        KiCheckForKernelApcDelivery(v18);
      ExFreePoolWithTag(v8);
    }
    else
    {
      *v5 = v8;
      v21 = *(_DWORD *)v10;
      v22 = *(_DWORD *)v10 - 16;
      if ( (*(_DWORD *)v10 & 0xFFFFFFF0) <= 0x10 )
        v22 = 0;
      if ( (v21 & 2) != 0 )
        goto LABEL_37;
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)v10);
      while ( v23 == v21 && __strex(v22, (unsigned int *)v10) );
      if ( v23 != v21 )
LABEL_37:
        ExfReleasePushLock(v10, v21);
      v24 = KeAbPostRelease((unsigned int)v10);
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = *(_WORD *)(v25 + 0x134) + 1;
      *(_WORD *)(v25 + 308) = v26;
      if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
        KiCheckForKernelApcDelivery(v24);
    }
  }
  return 0;
}
