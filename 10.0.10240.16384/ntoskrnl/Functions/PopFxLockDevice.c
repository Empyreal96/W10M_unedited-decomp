// PopFxLockDevice 
 
int __fastcall PopFxLockDevice(_DWORD *a1, int a2)
{
  int v3; // r4
  unsigned int *v5; // r5
  int v6; // r9
  int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r2
  unsigned int *v12; // r1
  unsigned int v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // r2

  v3 = 0;
  if ( a1 )
  {
    v5 = a1 + 11;
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_526EB0();
    v8 = *v5 & 0x7FFFFFFF;
    do
      v9 = __ldrex(v5);
    while ( v9 == v8 && __strex(v8 + 1, v5) );
    __dmb(0xBu);
    if ( v9 != v8 )
      ExpWaitForSpinLockSharedAndAcquire(v5);
    v3 = a1[10];
    if ( a2 && (a1[42] & 4) == 0 )
      v3 = 0;
    if ( v3 )
    {
      __dmb(0xBu);
      v12 = (unsigned int *)(v3 + 112);
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 + 1, v12) );
      __dmb(0xBu);
      if ( *(_BYTE *)(v3 + 108) )
      {
        __dmb(0xBu);
        do
        {
          v14 = __ldrex(v12);
          v15 = v14 - 1;
        }
        while ( __strex(v15, v12) );
        __dmb(0xBu);
        if ( !v15 )
          KeSetEvent(v3 + 116, 0, 0);
        v3 = 0;
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v5);
    }
    else
    {
      __dmb(0xBu);
      do
        v10 = __ldrex(v5);
      while ( __strex(v10 & 0xBFFFFFFF, v5) );
      __dmb(0xBu);
      do
        v11 = __ldrex(v5);
      while ( __strex(v11 - 1, v5) );
    }
    KfLowerIrql(v6);
  }
  return v3;
}
