// MiGetVadWakeList 
 
int __fastcall MiGetVadWakeList(int a1, int a2)
{
  _DWORD *v3; // r8
  _DWORD *v4; // r10
  int v5; // r4
  int v6; // r9
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r5
  _DWORD *v11; // r2
  __int64 v12; // kr00_8
  unsigned int v13; // r1
  int v14; // r2

  v3 = 0;
  v4 = (_DWORD *)(a1 + 36);
  v5 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5448D8();
  v8 = (unsigned __int8 *)(v5 + 3);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v5);
  while ( 1 )
  {
    v10 = *(_DWORD *)v5;
    if ( (*(_DWORD *)v5 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v10 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex((unsigned int *)v5);
      while ( v13 == v10 && __strex(v10 | 0x40000000, (unsigned int *)v5) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v11 = *(_DWORD **)(a1 + 36);
  if ( v11 )
  {
    do
    {
      v12 = *(_QWORD *)v11;
      if ( (v11[1] & a2) != 0 )
      {
        *v11 = v3;
        v3 = v11;
        *v4 = v12;
      }
      else
      {
        v4 = v11;
      }
      v11 = (_DWORD *)v12;
    }
    while ( (_DWORD)v12 );
  }
  if ( (*(_BYTE *)(v5 + 115) & 0x10) != 0 )
  {
    *(_BYTE *)(v5 + 115) &= 0xEFu;
    MiAgeWorkingSet(v5, v6, 1, *(unsigned __int16 *)(dword_6404B8 + 1218));
  }
  if ( (*(_BYTE *)(v5 + 115) & 0x20) != 0 )
  {
    v14 = *(_DWORD *)(v5 + 68);
    *(_BYTE *)(v5 + 115) &= 0xDFu;
    MiReduceWs(v5, v6, v14);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v5 = 0;
  }
  KfLowerIrql(v6);
  return (int)v3;
}
