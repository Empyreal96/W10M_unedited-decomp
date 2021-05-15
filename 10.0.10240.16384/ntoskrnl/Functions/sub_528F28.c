// sub_528F28 
 
void __fastcall sub_528F28(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  char v12; // r6
  _DWORD *v13; // r7
  int v14; // r9
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r6
  unsigned int v19; // r0
  unsigned int v20; // r1
  unsigned int *v21; // r4
  unsigned int v22; // r0
  unsigned __int8 *v23; // r3
  unsigned int v24; // r1

  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&ExpCallBackFlush);
  }
  else
  {
    do
      v15 = __ldrex((unsigned __int8 *)&ExpCallBackFlush + 3);
    while ( __strex(v15 | 0x80, (unsigned __int8 *)&ExpCallBackFlush + 3) );
    __dmb(0xBu);
    if ( v15 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&ExpCallBackFlush);
    while ( 1 )
    {
      v16 = ExpCallBackFlush;
      if ( (ExpCallBackFlush & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (ExpCallBackFlush & 0x40000000) == 0 )
      {
        do
          v17 = __ldrex((unsigned int *)&ExpCallBackFlush);
        while ( v17 == v16 && __strex(v16 | 0x40000000, (unsigned int *)&ExpCallBackFlush) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ExpCallBackFlush, a12);
  }
  else
  {
    __dmb(0xBu);
    ExpCallBackFlush = 0;
  }
  KfLowerIrql(v14);
  __pld(v13);
  v18 = (v12 & 7) + 1;
  v19 = *v13;
  if ( (*v13 & 1) != 0 )
  {
LABEL_21:
    v21 = (unsigned int *)(v19 & 0xFFFFFFFE);
    __dmb(0xBu);
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 - v18, v21) );
    __dmb(0xBu);
    if ( v22 == v18 )
    {
      __dmb(0xBu);
      v23 = (unsigned __int8 *)(v21 + 5);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 & 0xFE, v23) );
      __dmb(0xBu);
      if ( (v24 & 1) == 0 )
        KeSetEvent((int)(v21 + 1), 0, 0);
    }
  }
  else
  {
    while ( 1 )
    {
      __dmb(0xBu);
      do
        v20 = __ldrex(v13);
      while ( v20 == v19 && __strex(v19 - 2 * v18, v13) );
      __dmb(0xBu);
      if ( v20 == v19 )
        break;
      v19 = v20;
      if ( (v20 & 1) != 0 )
        goto LABEL_21;
    }
  }
  JUMPOUT(0x4E1290);
}
