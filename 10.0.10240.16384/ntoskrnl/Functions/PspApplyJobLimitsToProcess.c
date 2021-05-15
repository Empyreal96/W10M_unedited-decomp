// PspApplyJobLimitsToProcess 
 
int __fastcall PspApplyJobLimitsToProcess(int a1, __int16 a2, int a3, int a4)
{
  int v6; // r3
  _DWORD *v7; // r6
  unsigned int v8; // r5
  unsigned int *v9; // r8
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r2
  int v13; // r3
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r3
  unsigned int v17; // r5
  int v18; // r3
  int v20; // r0
  int *v21; // [sp+0h] [bp-28h]
  int v22[8]; // [sp+8h] [bp-20h] BYREF

  v21 = (int *)a1;
  v22[0] = a3;
  v22[1] = a4;
  v6 = __mrc(15, 0, 13, 0, 3);
  v7 = *(_DWORD **)(a1 + 288);
  v8 = v6 & 0xFFFFFFC0;
  __dmb(0xBu);
  if ( (a2 & 0x20) == 0 && (v7[100] & 0x20) != 0 )
    return sub_7C1CB4();
  if ( (a2 & 0x10) == 0 && (v7[100] & 0x10) != 0 )
  {
    v21 = v22;
    v20 = PspSetProcessAffinitySafe(a1, 1, v7 + 87, 0);
    if ( v20 >= 0 && v22[0] )
      PspWritePebAffinityInfo(v8, a1);
  }
  if ( (a2 & 0x100) == 0 )
  {
    if ( v8 )
      --*(_WORD *)(v8 + 310);
    v9 = v7 + 138;
    v10 = KeAbPreAcquire((unsigned int)(v7 + 138), 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v9);
    while ( !v12 && __strex(0x11u, v9) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(v7 + 138, v10, (unsigned int)(v7 + 138));
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    if ( (v7[100] & 0x100) != 0 )
      v13 = v7[94];
    else
      v13 = 0;
    *(_DWORD *)(a1 + 480) = v13;
    __dmb(0xBu);
    do
      v14 = __ldrex(v9);
    while ( v14 == 17 && __strex(0, v9) );
    if ( v14 != 17 )
      ExfReleasePushLockShared(v7 + 138);
    v15 = KeAbPostRelease((unsigned int)(v7 + 138));
    if ( v8 )
    {
      v16 = (__int16)(*(_WORD *)(v8 + 310) + 1);
      *(_WORD *)(v8 + 310) = v16;
      if ( !v16 )
      {
        a3 = v8 + 100;
        if ( *(_DWORD *)(v8 + 100) != v8 + 100 )
          KiCheckForKernelApcDelivery(v15);
      }
    }
  }
  if ( (a2 & 0x80) == 0 && *(_BYTE *)(a1 + 375) != 1 )
  {
    v17 = v7[101];
    if ( v17 >= 0xA )
      v17 = v7[59];
    v18 = (unsigned __int8)PspUseJobSchedulingClasses;
    if ( PspUseJobSchedulingClasses )
      KeSetQuantumProcess(a1, *((_BYTE *)PspJobSchedulingClasses + v17));
    KeSetDisableQuantumProcess(a1, v17 == 9, a3, v18);
  }
  return (int)v21;
}
