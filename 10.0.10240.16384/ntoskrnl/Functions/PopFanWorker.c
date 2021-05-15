// PopFanWorker 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopFanWorker(int a1)
{
  int v1; // r7
  __int64 v2; // kr00_8
  int v3; // r8
  unsigned int v5; // r5
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r6
  unsigned int v9; // r2
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int (__fastcall *v13)(int, int, int); // r3
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int result; // r0
  unsigned int v18; // r1
  __int16 v19; // r3

  v1 = 0;
  v2 = *(_QWORD *)(a1 + 24);
  v3 = 0;
  v5 = a1 + 60;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire(a1 + 60, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned __int8 *)v5);
  while ( __strex(v9 | 1, (unsigned __int8 *)v5) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)v5, v7, v5);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  *(_DWORD *)(v5 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(a1 + 84) )
  {
    if ( *(_BYTE *)(a1 + 40) )
    {
      v3 = 1;
      *(_BYTE *)(a1 + 40) = 0;
      v1 = 0;
    }
    if ( (PoDebug & 0x20) != 0 )
      DbgPrint("Fan %p is being removed\n", (const void *)a1);
LABEL_12:
    KeSetEvent(a1 + 68, 0, 0);
    goto LABEL_22;
  }
  v10 = *(_DWORD *)(HIDWORD(v2) + 24);
  if ( v10 < 0 )
  {
    if ( v10 != -1073741667 && v10 != -1073741536 )
    {
      if ( (PoDebug & 1) != 0 )
        DbgPrint("Fan %p: unexpected error %x\n", (const void *)a1, *(_DWORD *)(HIDWORD(v2) + 24));
      if ( *(_BYTE *)(a1 + 40) )
      {
        v3 = 1;
        *(_BYTE *)(a1 + 40) = 0;
        v1 = 0;
      }
      goto LABEL_12;
    }
  }
  else
  {
    if ( *(_BYTE *)(a1 + 40) )
      goto LABEL_17;
    v11 = *(unsigned __int8 *)(a1 + 36);
    if ( *(_BYTE *)(a1 + 36) )
    {
LABEL_18:
      v3 = 1;
      *(_BYTE *)(a1 + 40) = v11;
      v1 = v11;
      goto LABEL_19;
    }
    if ( *(_BYTE *)(a1 + 40) )
    {
LABEL_17:
      v11 = *(unsigned __int8 *)(a1 + 36);
      if ( !*(_BYTE *)(a1 + 36) )
        goto LABEL_18;
    }
  }
LABEL_19:
  PopPrepareIoctl(*(_DWORD *)(a1 + 28), 2703936, 1, a1 + 32, 8, 8);
  if ( (PoDebug & 0x20) != 0 )
    DbgPrint("Fan %p: Sending Query Status - Stamp = 0x%x\n", (const void *)a1, *(_DWORD *)(a1 + 32));
  v12 = *(_DWORD *)(HIDWORD(v2) + 96);
  v13 = PopFanIrpComplete;
  *(_QWORD *)(v12 - 8) = *(_QWORD *)(&a1 - 1);
  *(_BYTE *)(v12 - 37) = -32;
  IofCallDriver(v2, SHIDWORD(v2));
LABEL_22:
  if ( v3 )
    PopFanUpdateRunningState(v1);
  if ( *(_DWORD *)(v5 + 4) )
    *(_DWORD *)(v5 + 4) = 0;
  __pld((void *)v5);
  v14 = *(_DWORD *)v5;
  if ( (*(_DWORD *)v5 & 0xFFFFFFF0) <= 0x10 )
    v15 = 0;
  else
    v15 = v14 - 16;
  if ( (v14 & 2) != 0 )
    goto LABEL_40;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)v5);
  while ( v16 == v14 && __strex(v15, (unsigned int *)v5) );
  if ( v16 != v14 )
LABEL_40:
    ExfReleasePushLock((_DWORD *)v5, v14);
  result = KeAbPostRelease(v5);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
