// sub_5455AC 
 
void __fastcall sub_5455AC(int a1, int a2, int a3, int (__fastcall *a4)(int))
{
  int v4; // r4
  unsigned int *v5; // r5
  int v6; // r6
  char v7; // r8
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r6
  unsigned int v11; // r1

  v7 = a4(2);
  if ( (*(_DWORD *)(v6 + 1448) & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5);
  }
  else
  {
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
          v11 = __ldrex(v5);
        while ( v11 == v10 && __strex(v10 | 0x40000000, v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  *(_BYTE *)(v4 + 44) = v7;
  JUMPOUT(0x4BE326);
}
