// sub_9650D0 
 
void sub_9650D0()
{
  int v0; // r4
  int *v1; // r5
  int v2; // r7
  int v3; // r8
  int v4; // r9
  unsigned int v5; // r1
  unsigned int v6; // r4
  unsigned int v7; // r0

  if ( !MiChargeWsles((int)dword_634F00, v0, 0) )
  {
    ExFreePoolWithTag((unsigned int)v1);
    JUMPOUT(0x94CC6A);
  }
  *v1 = v0;
  KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(dword_634F00);
  }
  else
  {
    do
      v5 = __ldrex((unsigned __int8 *)dword_634F00 + 3);
    while ( __strex(v5 | 0x80, (unsigned __int8 *)dword_634F00 + 3) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(dword_634F00);
    while ( 1 )
    {
      v6 = dword_634F00[0];
      if ( (dword_634F00[0] & 0xBFFFFFFF) == v4 )
        break;
      if ( (dword_634F00[0] & 0x40000000) == 0 )
      {
        do
          v7 = __ldrex(dword_634F00);
        while ( v7 == v6 && __strex(v6 | 0x40000000, dword_634F00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( *(_DWORD *)(v3 + 24) != v2 )
    JUMPOUT(0x94CBFE);
  JUMPOUT(0x94CC16);
}
