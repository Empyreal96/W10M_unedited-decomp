// MiEmptyWorkingSet 
 
int __fastcall MiEmptyWorkingSet(unsigned int *a1, int a2, char a3)
{
  unsigned int v3; // r9
  _DWORD *v4; // r5
  int v6; // lr
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  int v12; // r1
  unsigned int v13; // r4
  unsigned int v14; // r6
  unsigned int v15; // r3
  int v16; // r6
  unsigned __int8 *v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r1
  int v22; // [sp+0h] [bp-C0h]
  int v23; // [sp+4h] [bp-BCh]
  int *v24; // [sp+8h] [bp-B8h]
  int v25; // [sp+10h] [bp-B0h] BYREF
  unsigned int v26[42]; // [sp+18h] [bp-A8h] BYREF

  v25 = 0;
  v3 = 0;
  v4 = (_DWORD *)a1[23];
  v22 = a2;
  v24 = &v25;
  v6 = a2;
  v26[0] = 0;
  if ( a2 == 17 )
  {
    v23 = 1;
    v6 = KfRaiseIrql(2);
    v22 = v6;
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_53DEB0();
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
          v21 = __ldrex(a1);
        while ( v21 == v11 && __strex(v11 | 0x40000000, a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v12 = 1;
  }
  else
  {
    v12 = 0;
    v23 = 0;
  }
  if ( v4 != (_DWORD *)-1069539328
    || (v24 = (int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 192), (*v24 & 0x20) == 0) )
  {
    v14 = v4[2];
    v13 = v4[1];
    if ( v13 > v14 )
    {
LABEL_22:
      MiRemoveWorkingSetPages((int)a1);
      if ( v23 == 1 )
        MiUnlockWorkingSetExclusive(a1, v22);
      return 0;
    }
    while ( 1 )
    {
      if ( (v13 & 0xF) == 0 && ExSpinLockIsContended(a1) || KeShouldYieldProcessor() )
      {
        if ( v3 )
        {
          MiFreeWsleList((int)a1, v26, 0);
          v3 = 0;
          v26[0] = 0;
        }
        MiUnlockWorkingSetExclusive(a1, v22);
        v16 = KfRaiseIrql(2);
        v22 = v16;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
        }
        else
        {
          v17 = (unsigned __int8 *)a1 + 3;
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 | 0x80, v17) );
          __dmb(0xBu);
          if ( v18 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(a1);
          while ( 1 )
          {
            v19 = *a1;
            if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v19 & 0x40000000) == 0 )
            {
              do
                v20 = __ldrex(a1);
              while ( v20 == v19 && __strex(v19 | 0x40000000, a1) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        if ( (*v24 & 0x20) != 0 )
        {
          if ( v23 != 1 )
            return -1073741558;
          MiUnlockWorkingSetExclusive(a1, v16);
          return -1073741558;
        }
        v14 = v4[2];
        if ( v13 < v4[1] )
          v13 = v4[1];
        if ( v13 > v14 )
        {
LABEL_20:
          if ( v3 )
            MiFreeWsleList((int)a1, v26, 0);
          goto LABEL_22;
        }
      }
      v15 = *(_DWORD *)(v13 * v4[9] + v4[63]);
      if ( (v15 & 1) != 0 && ((a3 & 2) == 0 || v15 < 0xC0000000 || v15 > 0xC03FFFFF) )
      {
        MiEmptyWorkingSetHelper(a1, ((v15 >> 10) & 0x3FFFFC) - 0x40000000, v13, v26);
        v3 = v26[0];
      }
      if ( ++v13 > v14 )
        goto LABEL_20;
    }
  }
  if ( v12 == 1 )
    MiUnlockWorkingSetExclusive(a1, v6);
  return -1073741558;
}
