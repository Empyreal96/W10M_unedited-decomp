// PfTCleanup 
 
int __fastcall PfTCleanup(int a1, int a2)
{
  BOOL v3; // r7
  unsigned __int8 *v4; // r6
  int v5; // r4
  int v6; // r8
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r1
  int v10; // r4
  unsigned int v11; // r1
  _DWORD *v12; // r4
  _DWORD *v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r0
  int v18; // [sp+0h] [bp-28h]
  int v19[8]; // [sp+8h] [bp-20h] BYREF

  v18 = a1;
  v19[1] = (int)v19;
  v19[0] = (int)v19;
  v3 = (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) == *(_DWORD *)(a1 + 64);
  PfTAccessTracingCleanup(a1, a2, 1);
  v4 = (unsigned __int8 *)(a1 + 384);
  v5 = KeAbPreAcquire(a1 + 384, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex(v4);
  while ( __strex(v7 & 0xFE, v4) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended(a1 + 384, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(a1 + 412) = v6;
  *(_DWORD *)(a1 + 388) = v8;
  *(_DWORD *)(a1 + 368) = 0;
  *(_DWORD *)(a1 + 376) = 0;
  PfTTraceListTrim(0, 0, v19);
  PfTTraceListTrim(1, 0, v19);
  *(_DWORD *)(a1 + 380) = 0;
  PfTAccessTracingCleanup(a1, v9, 2);
  v10 = *(_DWORD *)(a1 + 412);
  *(_DWORD *)(a1 + 388) = 0;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v4);
  while ( !v11 && __strex(1u, (unsigned int *)v4) );
  if ( v11 )
    ExpReleaseFastMutexContended((unsigned int *)(a1 + 384), v11);
  KfLowerIrql((unsigned __int8)v10);
  KeAbPostRelease(a1 + 384);
  PfTTraceListFree(v19);
  *(_DWORD *)(a1 + 344) = 0;
  v12 = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)(a1 + 336));
  while ( v12 )
  {
    v13 = v12;
    v14 = v12[3];
    v15 = v12[5];
    v12 = (_DWORD *)*v12;
    PfFbBufferListInsertInFree((_DWORD *)(a1 + 256), v13, v14 - (_DWORD)v13, v15, 1);
  }
  PfFbBufferListShutdown((unsigned int *)(a1 + 160));
  PfFbBufferListShutdown((unsigned int *)(a1 + 256));
  if ( !v3 && *(_DWORD *)(a1 + 64) )
  {
    KeSetEvent(a1 + 128, 0, 0);
    KeWaitForSingleObject(*(_DWORD *)(a1 + 64), 0, 0, 0, 0);
    ObfDereferenceObject(*(_DWORD *)(a1 + 64));
    *(_DWORD *)(a1 + 64) = 0;
  }
  PfTCleanupBuffers(&algn_64390C[4]);
  PfTCleanupBuffers(&unk_643928);
  PfFbBufferListCleanup(a1 + 160);
  PfFbBufferListCleanup(a1 + 256);
  v16 = *(_DWORD *)(a1 + 416);
  if ( v16 )
  {
    ObfDereferenceObject(v16);
    *(_DWORD *)(a1 + 416) = 0;
  }
  *(_DWORD *)(a1 + 4) = 0;
  return v18;
}
