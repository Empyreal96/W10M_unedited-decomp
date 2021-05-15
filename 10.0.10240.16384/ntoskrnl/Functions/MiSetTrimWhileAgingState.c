// MiSetTrimWhileAgingState 
 
int __fastcall MiSetTrimWhileAgingState(int a1, int a2)
{
  int v2; // r4
  int v3; // r8
  unsigned int v5; // r1
  int v6; // r7
  int v7; // r3
  int v8; // r3
  unsigned int v9; // r0

  v2 = *(_DWORD *)(a1 + 3512);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54E214();
  do
    v5 = __ldrex((unsigned __int8 *)&dword_634E00 + 3);
  while ( __strex(v5 | 0x80, (unsigned __int8 *)&dword_634E00 + 3) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E00);
  while ( 1 )
  {
    v6 = dword_634E00;
    if ( (dword_634E00 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_634E00 & 0x40000000) == 0 )
    {
      do
        v9 = __ldrex((unsigned int *)&dword_634E00);
      while ( v9 == v6 && __strex(v6 | 0x40000000, (unsigned int *)&dword_634E00) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v7 = (unsigned __int8)a2;
  if ( (unsigned __int8)a2 == 3 )
  {
    *(_DWORD *)(v2 + 60) = 204800;
    v8 = 12800;
    goto LABEL_13;
  }
  if ( !(_BYTE)a2 )
  {
    v8 = 0;
    *(_DWORD *)(v2 + 60) = 0;
    goto LABEL_13;
  }
  switch ( (unsigned __int8)a2 )
  {
    case 1u:
      *(_DWORD *)(v2 + 60) = 204800;
      v8 = -1;
      goto LABEL_13;
    case 2u:
      *(_DWORD *)(v2 + 60) = 204800;
      v8 = 51200;
      goto LABEL_13;
    case 4u:
      *(_DWORD *)(v2 + 60) = 384000;
      v8 = 0;
LABEL_13:
      *(_DWORD *)(v2 + 56) = v8;
      v7 = (unsigned __int8)a2;
      break;
  }
  *(_DWORD *)(v2 + 64) = v7;
  *(_WORD *)(v2 + 1222) = *(_WORD *)((char *)&a2 + 1);
  return MiUnlockWorkingSetExclusive((int)&dword_634E00, v3);
}
