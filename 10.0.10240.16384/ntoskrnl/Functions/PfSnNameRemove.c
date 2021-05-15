// PfSnNameRemove 
 
int __fastcall PfSnNameRemove(_DWORD *a1, unsigned int a2)
{
  unsigned int *v3; // r5
  int v5; // r6
  int v6; // r10
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  _DWORD *v11; // r4
  unsigned int v12; // r3
  unsigned int v13; // r1
  _DWORD *v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2

  v3 = a1 + 98;
  v5 = 0;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_547758();
  v8 = (unsigned __int8 *)v3 + 3;
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v3);
  while ( 1 )
  {
    v10 = *v3;
    if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v10 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex(v3);
      while ( v13 == v10 && __strex(v10 | 0x40000000, v3) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v11 = (_DWORD *)a1[91];
  if ( !v11 )
    goto LABEL_14;
  do
  {
    v12 = v11[3];
    if ( v12 > a2 )
    {
      v11 = (_DWORD *)*v11;
    }
    else
    {
      if ( v12 >= a2 )
        break;
      v11 = (_DWORD *)v11[1];
    }
  }
  while ( v11 );
  if ( v11 )
  {
    RtlRbRemoveNode(a1 + 91, v11);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3);
    }
    else
    {
      __dmb(0xBu);
      *v3 = 0;
    }
    KfLowerIrql(v6);
    v14 = a1 + 87;
    v15 = 0;
    if ( a1 + 87 > a1 + 91 )
      v16 = 0;
    else
      v16 = 4;
    if ( v16 )
    {
      do
      {
        if ( *v14 == a2 )
          *v14 = 0;
        ++v15;
        ++v14;
      }
      while ( v15 < v16 );
    }
    v5 = 1;
    ExFreePoolWithTag(v11, 0);
  }
  else
  {
LABEL_14:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3);
    }
    else
    {
      __dmb(0xBu);
      *v3 = 0;
    }
    KfLowerIrql(v6);
  }
  return v5;
}
