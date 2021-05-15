// VmpRemoveMemoryRange 
 
int __fastcall VmpRemoveMemoryRange(_DWORD *a1, unsigned int *a2, int a3)
{
  _DWORD *v6; // r7
  int v7; // r9
  int v8; // r4
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  _DWORD *v13; // r4
  int v14; // r0
  int vars4; // [sp+24h] [bp+4h]

  v6 = 0;
  v7 = KfRaiseIrql(15);
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
          v12 = __ldrex(a1);
        while ( v12 == v11 && __strex(v11 | 0x40000000, a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( a1[6] == a3 )
  {
    v13 = (_DWORD *)a1[1];
    if ( !v13 )
      goto LABEL_30;
    do
    {
      v14 = VmpProcessMemoryRangeCompareGpn(a2 + 6, (int)v13);
      if ( v14 >= 0 )
      {
        if ( v14 <= 0 )
          break;
        v13 = (_DWORD *)v13[1];
      }
      else
      {
        v13 = (_DWORD *)*v13;
      }
    }
    while ( v13 );
    if ( v13 )
    {
      if ( v13[3] == a2[6] && v13[4] == a2[7] && v13[5] == a2[8] && v13[6] == a2[9] )
      {
        RtlRbRemoveNode(a1 + 1, v13);
        RtlRbRemoveNode(a1 + 3, v13 - 3);
        if ( !a1[1] )
          a1[6] = -1;
        v6 = v13 - 3;
        v8 = 0;
      }
      else
      {
        v8 = -1073741637;
      }
    }
    else
    {
LABEL_30:
      v8 = -1073741172;
    }
  }
  else
  {
    v8 = -1073740007;
  }
  if ( v7 != -1 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1, vars4);
    }
    else
    {
      __dmb(0xBu);
      *a1 = 0;
    }
    KfLowerIrql((unsigned __int8)v7);
  }
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v8;
}
