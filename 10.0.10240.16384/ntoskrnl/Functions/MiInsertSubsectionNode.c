// MiInsertSubsectionNode 
 
int __fastcall MiInsertSubsectionNode(_DWORD *a1, int a2, int a3)
{
  unsigned int *v5; // r4
  int v6; // r7
  int result; // r0
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  _DWORD *v11; // r4
  int v12; // r2
  _DWORD *v13; // r3
  unsigned int v14; // r1

  if ( a3 )
  {
    v6 = 17;
  }
  else
  {
    v5 = a1 + 9;
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_51A804();
    v8 = (unsigned __int8 *)v5 + 3;
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v5);
    while ( 1 )
    {
      v10 = *v5;
      if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v14 = __ldrex(v5);
        while ( v14 == v10 && __strex(v10 | 0x40000000, v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v11 = (_DWORD *)a1[37];
  v12 = 0;
  if ( v11 )
  {
    while ( 1 )
    {
      if ( MiSubsectionCompare(a2, v11, v12) < 0 )
      {
        v13 = (_DWORD *)*v11;
        if ( !*v11 )
        {
          v12 = 0;
          break;
        }
      }
      else
      {
        v13 = (_DWORD *)v11[1];
        if ( !v13 )
        {
          v12 = 1;
          break;
        }
      }
      v11 = v13;
    }
  }
  result = RtlAvlInsertNodeEx(a1 + 37, v11, v12, a2 + 40);
  ++a1[38];
  a1[39] = a2;
  if ( v6 != 17 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9);
    }
    else
    {
      __dmb(0xBu);
      a1[9] = 0;
    }
    result = KfLowerIrql(v6);
  }
  return result;
}
