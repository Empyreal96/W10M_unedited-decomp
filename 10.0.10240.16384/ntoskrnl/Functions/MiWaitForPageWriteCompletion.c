// MiWaitForPageWriteCompletion 
 
int __fastcall MiWaitForPageWriteCompletion(int a1, int a2, int a3, int a4)
{
  unsigned int *v8; // r5
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  unsigned int *v13; // r2
  unsigned int v14; // r0
  int v16[3]; // [sp+0h] [bp-38h] BYREF
  char v17[4]; // [sp+Ch] [bp-2Ch] BYREF
  int v18; // [sp+10h] [bp-28h]
  int var24[11]; // [sp+14h] [bp-24h] BYREF

  v16[1] = 8;
  v17[0] = 7;
  var24[1] = (int)var24;
  v17[1] = 1;
  var24[0] = (int)var24;
  v17[2] = 4;
  v18 = 0;
  v8 = (unsigned int *)(a2 + 36);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(a2 + 36));
  }
  else
  {
    v9 = (unsigned __int8 *)(a2 + 39);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v8);
    while ( 1 )
    {
      v11 = *v8;
      if ( (*v8 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v11 & 0x40000000) == 0 )
      {
        do
          v12 = __ldrex(v8);
        while ( v12 == v11 && __strex(v11 | 0x40000000, v8) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v16[0] = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(a2 + 44) = v16;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v8, var24[10]);
  }
  else
  {
    __dmb(0xBu);
    *v8 = 0;
  }
  __dmb(0xBu);
  v13 = (unsigned int *)(a1 + 12);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 & 0x7FFFFFFF, v13) );
  MiUnlockProtoPoolPage(a3, a4);
  return KeWaitForGate((int)v17, 18);
}
