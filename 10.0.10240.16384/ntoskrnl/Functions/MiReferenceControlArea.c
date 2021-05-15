// MiReferenceControlArea 
 
int __fastcall MiReferenceControlArea(int a1, int a2, _DWORD *a3, int a4, _DWORD *a5)
{
  _DWORD *v6; // r9
  int result; // r0
  unsigned int v8; // r2
  int v9; // r4
  _DWORD *v10; // r4
  int v11; // r5
  int v12; // r0
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r5
  int v17; // r1
  unsigned int v18; // r0
  int v19; // [sp+0h] [bp-48h]
  int v22[3]; // [sp+10h] [bp-38h] BYREF
  char v23[4]; // [sp+1Ch] [bp-2Ch] BYREF
  int v24; // [sp+20h] [bp-28h]
  _DWORD v25[9]; // [sp+24h] [bp-24h] BYREF

  if ( (a1 & 0x1000000) != 0 )
    v6 = (_DWORD *)(*(_DWORD *)(a2 + 20) + 8);
  else
    v6 = *(_DWORD **)(a2 + 20);
  while ( 1 )
  {
    v19 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_5469E8();
    do
      v8 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
    while ( __strex(v8 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
    __dmb(0xBu);
    if ( v8 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
    while ( 1 )
    {
      v9 = dword_632E00;
      if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632E00 & 0x40000000) == 0 )
      {
        v17 = dword_632E00 | 0x40000000;
        do
          v18 = __ldrex((unsigned int *)&dword_632E00);
        while ( v18 == v9 && __strex(v17, (unsigned int *)&dword_632E00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v10 = (_DWORD *)*v6;
    if ( !*v6 )
    {
      v10 = a3;
      *v6 = a3;
      v12 = KeAbPreAcquire((unsigned int)v6, 0, 2);
      if ( v12 )
        *(_BYTE *)(v12 + 14) |= 1u;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
      }
      else
      {
        __dmb(0xBu);
        dword_632E00 = 0;
      }
      KfLowerIrql(v19);
      result = 1;
      goto LABEL_19;
    }
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel(v10 + 9) )
      break;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
    }
    else
    {
      __dmb(0xBu);
      dword_632E00 = 0;
    }
    KfLowerIrql(v19);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
  }
  else
  {
    __dmb(0xBu);
    dword_632E00 = 0;
  }
  if ( ((v10[7] | (v10[7] >> 1)) & 1) == 0 )
  {
    v11 = MiBuildWakeList(v10, 4);
    ++v10[3];
    MiRemoveUnusedSegment(v10);
    if ( a4 )
      v10[7] |= 0x8000u;
    else
      ++v10[6];
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v10 + 9);
    }
    else
    {
      __dmb(0xBu);
      v10[9] = 0;
    }
    KfLowerIrql(v19);
    MiReleaseControlAreaWaiters(v11);
    result = 1;
LABEL_19:
    *a5 = v10;
    return result;
  }
  v13 = KeAbPreAcquire((unsigned int)v6, 0, 2);
  v16 = v13;
  if ( v13 )
    KeAbPreWait(v13, v14, v15);
  v23[0] = 7;
  v24 = 0;
  v23[1] = 1;
  v23[2] = 4;
  v25[0] = v25;
  v25[1] = v25;
  v22[1] = 1;
  v22[0] = v10[11];
  v10[11] = v22;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v10 + 9);
  }
  else
  {
    __dmb(0xBu);
    v10[9] = 0;
  }
  KfLowerIrql(v19);
  if ( !a4 )
  {
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
    FsRtlReleaseFile(a2);
  }
  KeWaitForGate((int)v23, 18);
  if ( v16 )
  {
    KeAbPreAcquire((unsigned int)v6, v16, 0);
    KeAbPostReleaseEx(v6, v16);
  }
  result = 0;
  *a5 = 0;
  return result;
}
