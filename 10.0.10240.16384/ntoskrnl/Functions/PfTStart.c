// PfTStart 
 
int __fastcall PfTStart(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r5
  int v5; // r1
  int v6; // r6
  int v7; // r0
  int v8; // r1
  unsigned __int8 *v9; // r6
  int v10; // r7
  int v11; // r1
  unsigned int v12; // r2
  int v13; // r7
  unsigned int v14; // r1
  int v16; // [sp+10h] [bp-30h] BYREF
  int v17; // [sp+14h] [bp-2Ch] BYREF
  char v18[40]; // [sp+18h] [bp-28h] BYREF

  v3 = a3;
  if ( (a3 & 1) != 0 && (dword_6370C4 & 1) == 0 )
    v3 = a3 & 0xFFFFFFFE;
  if ( (v3 & 2) != 0 && (dword_6370C4 & 1) == 0 && dword_6370E0 != 1 && dword_6370E4 != 1 )
    v3 &= 0xFFFFFFFD;
  if ( (v3 & 1) != 0 )
  {
    v6 = PfTAllocateBuffers(a1 + 16, 0x8000, 8u, 1112303184);
    if ( v6 < 0 )
      goto LABEL_17;
    v6 = PfTAllocateBuffers(a1 + 40, 40992, 2u, 1413834320);
    if ( v6 < 0 )
      goto LABEL_17;
    v6 = PsCreateSystemThread((int)&v16, 0x1FFFFF, 0);
    if ( v6 < 0 )
      goto LABEL_17;
    ObReferenceObjectByHandle(v16, 0x1FFFFF, PsThreadType, 0, (int)&v17, 0);
    v7 = v16;
    *(_DWORD *)(a1 + 64) = v17;
    ObCloseHandle(v7);
  }
  if ( (v3 & 3) != 0 && !*(_DWORD *)(a1 + 416) )
  {
    RtlInitUnicodeString((unsigned int)v18, L"\\KernelObjects\\SuperfetchTracesReady");
    v6 = PfpCreateEvent((int)v18, 1, (_DWORD *)(a1 + 416));
    if ( v6 < 0 )
    {
LABEL_17:
      PfTCleanup(a1, v5);
      PfTInitialize((_BYTE *)a1, v8, 1);
      return v6;
    }
  }
  if ( (v3 & 1) != 0 )
  {
    PfFbBufferListUpdateMax(a1 + 256, 0x100000u);
    PfFbBufferListAllocate(a1 + 256, (KeNumberProcessors_0 + 2) << 12, 2 * (KeNumberProcessors_0 + 2));
  }
  if ( (v3 & 2) != 0 )
  {
    PfFbBufferListUpdateMax(a1 + 160, 0x1000000u);
    PfFbBufferListAllocate(a1 + 160, (KeNumberProcessors_0 + 7) << 15, 2 * (KeNumberProcessors_0 + 7));
  }
  v9 = (unsigned __int8 *)(a1 + 384);
  v10 = KeAbPreAcquire(a1 + 384, 0, 0);
  v11 = KfRaiseIrql(1);
  v17 = v11;
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 & 0xFE, v9) );
  __dmb(0xBu);
  if ( (v12 & 1) == 0 )
  {
    ExpAcquireFastMutexContended(a1 + 384, v10);
    v11 = v17;
  }
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  *(_DWORD *)(a1 + 388) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(a1 + 412) = v11;
  if ( (v3 & 1) != 0 )
  {
    *(_DWORD *)(a1 + 368) = dword_6370D0;
    if ( dword_643A6C < (unsigned int)dword_643A70 )
      PfTAccessTracingStart(a1, (int)&PfKernelGlobals, 2);
  }
  if ( (v3 & 2) != 0 )
    *(_DWORD *)(a1 + 376) = dword_6370CC;
  v13 = *(_DWORD *)(a1 + 412);
  *(_DWORD *)(a1 + 388) = 0;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)v9);
  while ( !v14 && __strex(1u, (unsigned int *)v9) );
  if ( v14 )
    ExpReleaseFastMutexContended((unsigned int *)(a1 + 384), v14);
  KfLowerIrql((unsigned __int8)v13);
  KeAbPostRelease(a1 + 384);
  *(_DWORD *)(a1 + 4) |= v3;
  if ( (v3 & 1) != 0 )
  {
    __dmb(0xFu);
    PsEnumProcesses((int (__fastcall *)(int *, int))PfCalculateProcessHash, 0);
    PfTAccessTracingStart(a1, (int)&PfKernelGlobals, 1);
  }
  return 0;
}
