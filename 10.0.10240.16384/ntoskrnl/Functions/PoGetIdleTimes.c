// PoGetIdleTimes 
 
int __fastcall PoGetIdleTimes(int a1, int a2, int a3)
{
  char v4; // r7
  int result; // r0
  unsigned int v6; // r4
  int v7; // r10
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r5
  int v13; // r4
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r1
  __int16 v18; // r3
  __int16 v21[2]; // [sp+8h] [bp-30h] BYREF
  int v22; // [sp+Ch] [bp-2Ch]
  int v23; // [sp+10h] [bp-28h]

  v4 = -1;
  if ( *(_BYTE *)(a1 + 3) )
    return sub_52957C(KeNumberProcessors_0);
  if ( *(_WORD *)a1 )
    return sub_52957C(KeNumberProcessors_0);
  v6 = *(unsigned __int8 *)(a1 + 2);
  if ( v6 >= KeNumberProcessors_0 )
    return sub_52957C(KeNumberProcessors_0);
  v7 = (int)*(&KiProcessorBlock + v6);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(&PpmIdlePolicyLock, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( !v11 && __strex(0x11u, (unsigned int *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( v11 )
    ExfAcquirePushLockSharedEx(&PpmIdlePolicyLock, v9, &PpmIdlePolicyLock);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = KfRaiseIrql(2);
  v13 = PopGetIdleTimesCallback(v7, a2, a3);
  KfLowerIrql(v12);
  if ( v13 < 0 )
  {
    v21[0] = 1;
    v21[1] = 1;
    v22 = 0;
    if ( !*(_BYTE *)(a1 + 3) && !*(_WORD *)a1 && *(unsigned __int8 *)(a1 + 2) < (unsigned int)KeNumberProcessors_0 )
      v4 = *(_BYTE *)(a1 + 2);
    v23 = 1 << v4;
    PopExecuteOnTargetProcessors((int)v21, (int)PopGetIdleTimesCallback, a2, a3);
  }
  dword_61E89C = 0;
  __pld(&PpmIdlePolicyLock);
  v14 = PpmIdlePolicyLock;
  if ( (PpmIdlePolicyLock & 0xFFFFFFF0) > 0x10 )
    v15 = PpmIdlePolicyLock - 16;
  else
    v15 = 0;
  if ( (PpmIdlePolicyLock & 2) != 0 )
    goto LABEL_31;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( v16 == v14 && __strex(v15, (unsigned int *)&PpmIdlePolicyLock) );
  if ( v16 != v14 )
LABEL_31:
    ExfReleasePushLock(&PpmIdlePolicyLock);
  result = KeAbPostRelease(&PpmIdlePolicyLock);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
