// CmpDelayDerefKeyControlBlock 
 
unsigned int __fastcall CmpDelayDerefKeyControlBlock(unsigned int *a1)
{
  unsigned int result; // r0
  unsigned int v3; // r1
  unsigned int v4; // r2

  result = *a1;
  __dmb(0xBu);
  while ( result > 1 )
  {
    v3 = result - 1;
    __dmb(0xBu);
    do
      v4 = __ldrex(a1);
    while ( v4 == result && __strex(v3, a1) );
    result = v4;
    __dmb(0xBu);
    if ( v4 == v3 + 1 )
      return result;
  }
  if ( (a1[1] & 0x20000) != 0 && a1[4] != -1 )
  {
    CmpLockDeletedHashEntryExclusiveByKcb((int)a1);
    CmpRemoveKeyHashFromDeletedKcbTable(a1[5], a1 + 3);
    CmpUnlockDeletedHashEntryByKcb((int)a1);
    a1[4] = -1;
  }
  return sub_804E74();
}
