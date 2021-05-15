// MiUpdatePerSessionProto 
 
int __fastcall MiUpdatePerSessionProto(int a1, int a2, _DWORD *a3, int a4)
{
  unsigned int *v4; // r5
  int v8; // r10
  _DWORD *v9; // r4
  unsigned int v10; // r6
  int v11; // r2
  _DWORD *v12; // r3
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  int vars4; // [sp+24h] [bp+4h]

  v4 = (unsigned int *)(a1 + 36);
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4);
  }
  else
  {
    v13 = (unsigned __int8 *)v4 + 3;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4);
    while ( 1 )
    {
      v15 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v16 = __ldrex(v4);
        while ( v16 == v15 && __strex(v15 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( !a4 )
  {
    RtlAvlRemoveNode(a2 + 12, (int)a3);
    goto LABEL_23;
  }
  v9 = *(_DWORD **)(a2 + 12);
  v10 = a3[3];
  v11 = 0;
  if ( !v9 )
    goto LABEL_21;
  while ( MiPerSessionProtosCompare(v10, (int)v9) >= 0 )
  {
    v12 = (_DWORD *)v9[1];
    if ( !v12 )
    {
      v11 = 1;
      goto LABEL_21;
    }
LABEL_19:
    v9 = v12;
  }
  v12 = (_DWORD *)*v9;
  if ( *v9 )
    goto LABEL_19;
  v11 = 0;
LABEL_21:
  RtlAvlInsertNodeEx(a2 + 12, (int)v9, v11, a3);
LABEL_23:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  return KfLowerIrql(v8);
}
