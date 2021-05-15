// MiCreateCloneChain 
 
int __fastcall MiCreateCloneChain(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  int v3; // r8
  int v5; // r6
  int v6; // r9
  unsigned int *v7; // r7
  _DWORD *v8; // r3
  _DWORD *v9; // r4
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1
  _DWORD *v14; // r0
  _DWORD *v15; // r2
  _DWORD *v16; // r3
  _DWORD *v17; // r4
  int v19; // [sp+0h] [bp-28h]

  v2 = 0;
  *a2 = 0;
  v3 = 0;
  v5 = 0;
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v7 = (unsigned int *)(v6 + 492);
  v19 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v6 + 492));
  }
  else
  {
    v10 = (unsigned __int8 *)(v6 + 495);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v6 + 492));
    while ( 1 )
    {
      v12 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v12 & 0x40000000) == 0 )
      {
        do
          v13 = __ldrex(v7);
        while ( v13 == v12 && __strex(v12 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v8 = *(_DWORD **)(v6 + 272);
  v9 = 0;
  while ( v8 )
  {
    v9 = v8;
    v8 = (_DWORD *)*v8;
  }
  while ( v9 )
  {
    v14 = (_DWORD *)ExAllocatePoolWithTag(512, 48);
    if ( !v14 )
    {
      v5 = -1073741670;
      break;
    }
    *v14 = v2;
    v2 = v14;
    v15 = v9;
    v14[8] = v9[8];
    v3 += v9[8];
    v16 = (_DWORD *)v9[1];
    if ( v16 )
    {
      do
      {
        v9 = v16;
        v16 = (_DWORD *)*v16;
      }
      while ( v16 );
    }
    else
    {
      while ( 1 )
      {
        v9 = (_DWORD *)(v9[2] & 0xFFFFFFFC);
        if ( !v9 || (_DWORD *)*v9 == v15 )
          break;
        v15 = v9;
      }
    }
  }
  MiUnlockWorkingSetExclusive(v6 + 492, v19);
  if ( v5 < 0 )
    goto LABEL_31;
  if ( v3 )
    v5 = PsChargeProcessNonPagedPoolQuota(a1, v3);
  if ( v5 < 0 )
  {
LABEL_31:
    if ( v2 )
    {
      do
      {
        v17 = (_DWORD *)*v2;
        ExFreePoolWithTag(v2);
        v2 = v17;
      }
      while ( v17 );
    }
    v2 = 0;
  }
  *a2 = v2;
  return v5;
}
