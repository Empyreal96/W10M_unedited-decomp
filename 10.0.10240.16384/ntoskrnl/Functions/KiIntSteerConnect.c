// KiIntSteerConnect 
 
int __fastcall KiIntSteerConnect(unsigned int a1, unsigned int a2, int a3)
{
  unsigned __int64 v4; // r6
  int v6; // r0
  _DWORD *v7; // r5
  _DWORD *v8; // t1
  unsigned int v9; // r2
  int v10; // r10
  int i; // r4
  int v12; // r3
  int v13; // r6
  _DWORD *v14; // r1
  int v15; // r0
  __int16 v16; // r3
  __int16 v17; // r2
  int v18; // r3
  int **v19; // r2
  unsigned int *v20; // r3
  unsigned int v21; // r6
  unsigned int v22; // r2
  int v23; // r2
  int v24; // r3
  char v25[4]; // [sp+8h] [bp-50h] BYREF
  int v26; // [sp+Ch] [bp-4Ch] BYREF
  unsigned int v27; // [sp+10h] [bp-48h]
  int v28; // [sp+14h] [bp-44h]
  int v29; // [sp+18h] [bp-40h]
  __int16 v30; // [sp+1Ch] [bp-3Ch]
  __int16 v31[2]; // [sp+28h] [bp-30h] BYREF
  int v32; // [sp+2Ch] [bp-2Ch]
  int v33; // [sp+30h] [bp-28h]

  v4 = __PAIR64__(a1, a2);
  if ( !KiIntSteerEtwHandle )
    EtwRegister(INTSTEER_ETW_PROVIDER, KiIntSteerEventTraceControlCallback, 0);
  if ( KiIntSteerGetLineInformation(a3, &v26, v25) < 0 )
    return sub_51FA0C();
  v6 = ExAllocatePoolWithTag(512, 120, 1802654793);
  v7 = (_DWORD *)v6;
  if ( !v6 )
    return -1073741670;
  *(_BYTE *)(v6 + 40) = v25[0];
  *(_QWORD *)(v6 + 12) = v4;
  *(_DWORD *)(v6 + 24) = 0;
  *(_DWORD *)(v6 + 28) = 0;
  *(_DWORD *)(v6 + 32) = 0;
  *(_DWORD *)(v6 + 36) = 0;
  memmove(v6 + 48, a3, 0x48u);
  for ( ; (_DWORD)v4; v8[25] = v7 )
  {
    v8 = (_DWORD *)*(_DWORD *)HIDWORD(v4);
    HIDWORD(v4) += 4;
    LODWORD(v4) = v4 - 1;
    v8[26] = 0;
    v8[27] = 0;
    v8[30] = 0;
    v8[31] = 0;
    v8[32] = 0;
    v8[33] = 0;
    v8[36] = 0;
    v8[37] = 0;
  }
  v28 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&KiIntTrackSpinlock);
  }
  else
  {
    do
      v9 = __ldrex((unsigned int *)&KiIntTrackSpinlock);
    while ( __strex(1u, (unsigned int *)&KiIntTrackSpinlock) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire(&KiIntTrackSpinlock);
  }
  v10 = v26;
  if ( !*(_DWORD *)a3 )
  {
    for ( i = KiIntTrackRootList; (int *)i != &KiIntTrackRootList; i = *(_DWORD *)i )
    {
      v12 = *(_DWORD *)(i + 16);
      if ( v12 == v26 && v12 != -1 )
      {
        if ( *(_DWORD *)(i + 96) == 2 )
        {
          *(_DWORD *)(i + 96) = 0;
          *(_BYTE *)(i + 100) = 0;
          dword_621818 |= *(_DWORD *)(a3 + 20);
        }
        goto LABEL_20;
      }
    }
  }
  v15 = ExAllocatePoolWithTag(512, 160, 1802654793);
  i = v15;
  if ( v15 )
  {
    KiIntSteerChooseInitialTargetProcessors(v15);
    memset((_BYTE *)i, 0, 160);
    *(_DWORD *)(i + 8) = i + 8;
    *(_DWORD *)(i + 12) = i + 8;
    *(_DWORD *)(i + 16) = v10;
    *(_BYTE *)(i + 100) = 0;
    *(_DWORD *)(i + 116) = 0;
    v16 = *(_WORD *)(a3 + 24);
    v17 = v30;
    *(_DWORD *)(i + 104) = 0;
    *(_WORD *)(i + 108) = v16;
    *(_DWORD *)(i + 96) = v26;
    v18 = v29;
    *(_WORD *)(i + 124) = v17;
    *(_DWORD *)(i + 120) = v18;
    *(_WORD *)(i + 136) = v17;
    *(_DWORD *)(i + 132) = v18;
    memmove(i + 24, a3, 0x48u);
    if ( *(_DWORD *)(i + 96) == 2 )
      *(_DWORD *)(i + 152) = 0;
    v19 = (int **)dword_6217DC;
    *(_DWORD *)i = &KiIntTrackRootList;
    *(_DWORD *)(i + 4) = v19;
    if ( *v19 != &KiIntTrackRootList )
      __fastfail(3u);
    *v19 = (int *)i;
    dword_6217DC = i;
    ++KiIntTrackRootCount;
    if ( *(_DWORD *)(i + 96) == 2 )
      v20 = (unsigned int *)(i + 44);
    else
      v20 = (unsigned int *)(i + 120);
    v21 = *v20;
    while ( v21 )
    {
      v22 = __clz(__rbit(v21));
      v21 &= ~(1 << v22);
      v27 = v22;
      if ( v22 >= KeNumberProcessors_0 )
        v23 = 0;
      else
        v23 = (int)*(&KiProcessorBlock + v22);
      v24 = *(_DWORD *)(v23 + 3272) + 1;
      *(_DWORD *)(v23 + 3272) = v24;
      if ( v24 == 1 )
      {
        v31[0] = 1;
        v31[1] = 1;
        v32 = 0;
        v33 = 1 << v27;
        HalRequestIpi(0, v31);
      }
    }
    if ( *(_DWORD *)(i + 96) )
      KiIntSteerSetDestination(i, i + 120);
LABEL_20:
    v13 = 0;
    v7[2] = i;
    v14 = *(_DWORD **)(i + 12);
    *v7 = i + 8;
    v7[1] = v14;
    if ( *v14 != i + 8 )
      __fastfail(3u);
    *v14 = v7;
    *(_DWORD *)(i + 12) = v7;
    KiIntSteerLogState(v7, PPM_ETW_INTERRUPT_STEERING_STATE_CONNECT);
  }
  else
  {
    v13 = -1073741670;
    ExFreePoolWithTag(v7, 1802654793);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KiIntTrackSpinlock);
  }
  else
  {
    __dmb(0xBu);
    KiIntTrackSpinlock = 0;
  }
  KfLowerIrql(v28);
  return v13;
}
