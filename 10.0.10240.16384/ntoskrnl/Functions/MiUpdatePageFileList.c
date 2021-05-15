// MiUpdatePageFileList 
 
int __fastcall MiUpdatePageFileList(int result, int a2)
{
  int v3; // r8
  unsigned int v4; // r1
  int v5; // r6
  unsigned int v6; // r7
  int v7; // r2
  _DWORD *v8; // r6
  _DWORD *v9; // r3
  unsigned int v10; // r0
  int v11; // [sp+0h] [bp-20h]

  v3 = result;
  if ( !*(_DWORD *)(result + 32) )
    return result;
  v11 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54E97C();
  do
    v4 = __ldrex((unsigned __int8 *)&dword_6348BC + 3);
  while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_6348BC + 3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_6348BC);
  while ( 1 )
  {
    v5 = dword_6348BC;
    if ( (dword_6348BC & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_6348BC & 0x40000000) == 0 )
    {
      do
        v10 = __ldrex((unsigned int *)&dword_6348BC);
      while ( v10 == v5 && __strex(v5 | 0x40000000, (unsigned int *)&dword_6348BC) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( !a2 )
  {
    RtlAvlRemoveNode((int)&dword_6348B8, v3 + 132);
    goto LABEL_14;
  }
  v6 = *(_DWORD *)(v3 + 32);
  v7 = 0;
  *(_WORD *)(v3 + 96) |= 0x100u;
  v8 = (_DWORD *)dword_6348B8;
  if ( !dword_6348B8 )
    goto LABEL_13;
  while ( MiPagefileCompare(v6, (int)v8) < 0 )
  {
    v9 = (_DWORD *)*v8;
    if ( !*v8 )
    {
      v7 = 0;
      goto LABEL_13;
    }
LABEL_18:
    v8 = v9;
  }
  v9 = (_DWORD *)v8[1];
  if ( v9 )
    goto LABEL_18;
  v7 = 1;
LABEL_13:
  RtlAvlInsertNodeEx((int)&dword_6348B8, (int)v8, v7, (_DWORD *)(v3 + 132));
LABEL_14:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_6348BC);
  }
  else
  {
    __dmb(0xBu);
    dword_6348BC = 0;
  }
  return KfLowerIrql(v11);
}
