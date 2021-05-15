// MiEmptyWorkingSetPrivatePagesByVa 
 
int __fastcall MiEmptyWorkingSetPrivatePagesByVa(unsigned int *a1)
{
  int v2; // r8
  int v3; // r7
  int v4; // r0
  _DWORD *v6; // r3
  _DWORD *v7; // r5
  int v8; // r9
  unsigned __int8 *v9; // r1
  unsigned int v10; // r2
  unsigned int v11; // r0
  _DWORD *v12; // r3
  _DWORD *v13; // r2
  int v14; // r5
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned int *v20; // [sp+8h] [bp-B8h] BYREF
  char v21; // [sp+Ch] [bp-B4h]
  int *v22; // [sp+10h] [bp-B0h]
  int v23; // [sp+18h] [bp-A8h] BYREF

  v23 = 0;
  v22 = &v23;
  v20 = a1;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_DWORD *)(v2 + 0x74);
  v4 = LOCK_ADDRESS_SPACE_SHARED(v2, v3);
  if ( (*(_DWORD *)(v3 + 192) & 0x20) != 0 )
    return sub_5476CC(v4);
  v6 = *(_DWORD **)(v3 + 636);
  v7 = 0;
  while ( v6 )
  {
    v7 = v6;
    v6 = (_DWORD *)*v6;
  }
  while ( v7 )
  {
    MiLockVad(v2, (int)v7);
    if ( !MiVadDeleted((int)v7) && ((1 << (v7[7] & 7)) & 0x55) != 0 && !MiVadMapsLargeImage((int)v7) )
    {
      v8 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
      }
      else
      {
        v9 = (unsigned __int8 *)a1 + 3;
        do
          v10 = __ldrex(v9);
        while ( __strex(v10 | 0x80, v9) );
        __dmb(0xBu);
        if ( v10 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(a1);
        while ( 1 )
        {
          v11 = *a1;
          if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v11 & 0x40000000) == 0 )
          {
            do
              v18 = __ldrex(a1);
            while ( v18 == v11 && __strex(v11 | 0x40000000, a1) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v21 = v8;
      MiEnumerateLeafPtes(
        v7[3] << 12,
        v7[4] << 12,
        (int (__fastcall *)(int, unsigned int, unsigned int))MiEmptyWsPrivatePagesCallback,
        (int)&v20);
      MiUnlockWorkingSetExclusive((int)a1, v8);
    }
    MiUnlockVad(v2, (int)v7);
    v12 = (_DWORD *)v7[1];
    v13 = v7;
    if ( v12 )
    {
      do
      {
        v7 = v12;
        v12 = (_DWORD *)*v12;
      }
      while ( v12 );
    }
    else
    {
      while ( 1 )
      {
        v7 = (_DWORD *)(v7[2] & 0xFFFFFFFC);
        if ( !v7 || (_DWORD *)*v7 == v13 )
          break;
        v13 = v7;
      }
    }
  }
  UNLOCK_ADDRESS_SPACE_SHARED(v2, v3);
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
  }
  else
  {
    v15 = (unsigned __int8 *)a1 + 3;
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 | 0x80, v15) );
    __dmb(0xBu);
    if ( v16 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a1);
    while ( 1 )
    {
      v17 = *a1;
      if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v17 & 0x40000000) == 0 )
      {
        do
          v19 = __ldrex(a1);
        while ( v19 == v17 && __strex(v17 | 0x40000000, a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MiRemoveWorkingSetPages((int)a1);
  MiUnlockWorkingSetExclusive((int)a1, v14);
  return 0;
}
