// MiUnlinkWorkingSet 
 
int __fastcall MiUnlinkWorkingSet(int result, _DWORD *a2)
{
  int v3; // r4
  int v4; // r7
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  _DWORD *i; // r1
  int v9; // r3
  int *v10; // r2
  unsigned int v11; // r1
  _DWORD v12[4]; // [sp+0h] [bp-38h] BYREF
  char v13[4]; // [sp+10h] [bp-28h] BYREF
  int v14; // [sp+14h] [bp-24h]
  int v15[8]; // [sp+18h] [bp-20h] BYREF

  v3 = result;
  __dmb(0xBu);
  v12[0] = 0;
  v12[1] = 0;
  v12[2] = 0;
  if ( (*(_BYTE *)(result + 112) & 7) == 0 )
  {
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_515000();
    v5 = (unsigned __int8 *)(v3 + 3);
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x80, v5) );
    __dmb(0xBu);
    if ( v6 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v3);
    while ( 1 )
    {
      v7 = *(_DWORD *)v3;
      if ( (*(_DWORD *)v3 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v7 & 0x40000000) == 0 )
      {
        do
          v11 = __ldrex((unsigned int *)v3);
        while ( v11 == v7 && __strex(v7 | 0x40000000, (unsigned int *)v3) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    MiDeleteAllHashMappings(v3);
    result = MiUnlockWorkingSetExclusive(v3, v4);
  }
  v13[0] = 7;
  v13[1] = 1;
  v13[2] = 4;
  v14 = 0;
  v15[1] = (int)v15;
  v15[0] = (int)v15;
  if ( a2 )
    goto LABEL_13;
  a2 = v12;
  for ( i = v12; ; i = a2 )
  {
    result = KeAcquireInStackQueuedSpinLock(&dword_634980, i);
LABEL_13:
    v9 = *(unsigned __int8 *)(v3 + 113);
    if ( (v9 & 6) == 0 && (v9 & 0xFFFFFFF0) == 0 )
      break;
    *(_DWORD *)(v3 + 4) = v13;
    KeReleaseInStackQueuedSpinLock(a2);
    KeWaitForGate(v13, 18);
  }
  if ( *(_DWORD *)(v3 + 12) )
  {
    v10 = *(int **)(v3 + 16);
    result = *(_DWORD *)(v3 + 12);
    if ( *(_DWORD *)(result + 4) != v3 + 12 || *v10 != v3 + 12 )
      __fastfail(3u);
    *v10 = result;
    *(_DWORD *)(result + 4) = v10;
    *(_DWORD *)(v3 + 12) = 0;
  }
  *(_DWORD *)(v3 + 4) = MmBadPointer;
  if ( a2 == v12 )
    result = KeReleaseInStackQueuedSpinLock(a2);
  return result;
}
