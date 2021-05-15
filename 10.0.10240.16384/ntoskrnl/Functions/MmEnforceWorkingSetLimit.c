// MmEnforceWorkingSetLimit 
 
int __fastcall MmEnforceWorkingSetLimit(int a1, char a2)
{
  int v2; // r10
  int v3; // r8
  char v4; // r4
  int v5; // r5
  int v7; // r6
  int v8; // r7
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  int v11; // r2
  unsigned int v12; // r0
  int v13; // r0
  unsigned int *v14; // r1
  int *v15; // r4
  unsigned int *v16; // r2
  unsigned int v17; // r4
  unsigned int v18; // r1
  int v19[4]; // [sp+8h] [bp-48h] BYREF
  char var38[60]; // [sp+18h] [bp-38h] BYREF
  int vars4; // [sp+54h] [bp+4h]

  v2 = 0;
  v3 = 0;
  v4 = a2;
  v5 = a1 + 492;
  if ( (a2 & 4) != 0 )
    return sub_515378();
  v7 = 0;
  if ( (a2 & 1) != 0 )
  {
    v7 = 64;
    v4 = a2 & 0xFD;
  }
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 )
  {
    v2 = 1;
    KiStackAttachProcess(a1, 0, var38);
  }
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5);
  }
  else
  {
    v9 = (unsigned __int8 *)(v5 + 3);
    do
    {
      v10 = __ldrex(v9);
      v11 = __strex(v10 | 0x80, v9);
    }
    while ( v11 );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v5);
    while ( 1 )
    {
      v12 = *(_DWORD *)v5;
      if ( (*(_DWORD *)v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v12 & 0x40000000) == 0 )
      {
        v11 = v12 | 0x40000000;
        do
          v18 = __ldrex((unsigned int *)v5);
        while ( v18 == v12 && __strex(v11, (unsigned int *)v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_634980, v19, v11, MiState);
  if ( (v4 & 8) != 0 )
    *(_BYTE *)(v5 + 112) &= 0x7Fu;
  if ( (v4 & 2) != 0 )
    *(_BYTE *)(v5 + 112) &= 0xBFu;
  if ( (*(_DWORD *)(v5 + 112) & 0x80) == 128 )
    v7 = (unsigned __int8)v7 | 0x80;
  if ( (*(_DWORD *)(v5 + 112) & 0x40) != 0 )
    v7 = (unsigned __int8)v7 | 0x40;
  if ( (v7 & 0xFFFFFF80) == 128 && (v7 & 0x40) != 0 && (unsigned int)(*(_DWORD *)(v5 + 48) + 4) >= *(_DWORD *)(v5 + 68) )
  {
    v3 = -1073741748;
    v4 &= 0xFAu;
  }
  if ( (v4 & 4) != 0 )
    *(_BYTE *)(v5 + 112) |= 0x80u;
  if ( (v4 & 1) != 0 )
    *(_BYTE *)(v5 + 112) |= 0x40u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v19, vars4);
  }
  else
  {
    v13 = v19[0];
    if ( !v19[0] )
    {
      v14 = (unsigned int *)v19[1];
      __dmb(0xBu);
      do
        v15 = (int *)__ldrex(v14);
      while ( v15 == v19 && __strex(0, v14) );
      if ( v15 == v19 )
        goto LABEL_32;
      v13 = KxWaitForLockChainValid(v19);
    }
    v19[0] = 0;
    __dmb(0xBu);
    v16 = (unsigned int *)(v13 + 4);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 ^ 1, v16) );
  }
LABEL_32:
  MiUnlockWorkingSetExclusive(v5, v8);
  if ( v2 )
    KiUnstackDetachProcess(var38, 0);
  return v3;
}
