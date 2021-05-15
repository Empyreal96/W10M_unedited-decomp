// PopPepLockActivityLink 
 
int __fastcall PopPepLockActivityLink(int a1, unsigned int *a2, int a3, unsigned int a4, _BYTE *a5)
{
  _BYTE *v6; // r8
  int v7; // r7
  unsigned int *v9; // r4
  char v10; // r6
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r5
  unsigned int *v15; // r6
  int v16; // r8
  int v17; // r4
  unsigned int v18; // r1
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r4
  unsigned int v22; // r1
  unsigned int v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // r1

  v6 = a5;
  v7 = 0;
  if ( !a2 || *(_DWORD *)(a1 + 120) == 1 )
    goto LABEL_2;
  if ( a3 == 6 )
  {
    if ( a4 != 6 && (a4 > 5 || ActivityAttributes[124 * a4] != 1) )
    {
      v15 = (unsigned int *)(a1 + 44);
      v16 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(a1 + 44);
      }
      else
      {
        v17 = *v15 & 0x7FFFFFFF;
        do
          v18 = __ldrex(v15);
        while ( v18 == v17 && __strex(v17 + 1, v15) );
        __dmb(0xBu);
        if ( v18 != v17 )
          ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(a1 + 44));
      }
      *a5 = v16;
      if ( *(_BYTE *)(a1 + 77) != 1 )
      {
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a2);
        }
        else
        {
          v19 = (unsigned __int8 *)a2 + 3;
          do
            v20 = __ldrex(v19);
          while ( __strex(v20 | 0x80, v19) );
          __dmb(0xBu);
          if ( v20 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(a2);
          while ( 1 )
          {
            v21 = *a2;
            if ( (*a2 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v21 & 0x40000000) == 0 )
            {
              do
                v24 = __ldrex(a2);
              while ( v24 == v21 && __strex(v21 | 0x40000000, a2) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        return v7;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(a1 + 44);
      }
      else
      {
        __dmb(0xBu);
        do
          v22 = __ldrex(v15);
        while ( __strex(v22 & 0xBFFFFFFF, v15) );
        __dmb(0xBu);
        do
          v23 = __ldrex(v15);
        while ( __strex(v23 - 1, v15) );
      }
      KfLowerIrql(v16);
      v6 = a5;
    }
LABEL_2:
    v7 = 1;
    v9 = (unsigned int *)(a1 + 44);
    v10 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 44);
    }
    else
    {
      v11 = (unsigned __int8 *)(a1 + 47);
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 | 0x80, v11) );
      __dmb(0xBu);
      if ( v12 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 44));
      while ( 1 )
      {
        v13 = *v9;
        if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v13 & 0x40000000) == 0 )
        {
          do
            v25 = __ldrex(v9);
          while ( v25 == v13 && __strex(v13 | 0x40000000, v9) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    *(_BYTE *)(a1 + 77) = 1;
    *v6 = v10;
    return v7;
  }
  return sub_53F048();
}
