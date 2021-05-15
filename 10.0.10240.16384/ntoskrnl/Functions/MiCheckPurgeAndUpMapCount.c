// MiCheckPurgeAndUpMapCount 
 
int __fastcall MiCheckPurgeAndUpMapCount(_DWORD *a1)
{
  unsigned int *v2; // r5
  int v3; // r9
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r1
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  int v13[3]; // [sp+0h] [bp-38h] BYREF
  char v14[4]; // [sp+Ch] [bp-2Ch] BYREF
  int v15; // [sp+10h] [bp-28h]
  int var24[10]; // [sp+14h] [bp-24h] BYREF

  v2 = a1 + 9;
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54602C();
  v5 = (unsigned __int8 *)v2 + 3;
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v2);
  while ( 1 )
  {
    v7 = *v2;
    if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v7 & 0x40000000) == 0 )
    {
      do
        v8 = __ldrex(v2);
      while ( v8 == v7 && __strex(v7 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  while ( (a1[7] & 4) != 0 )
  {
    v13[1] = 2;
    v14[0] = 7;
    v14[1] = 1;
    v14[2] = 4;
    v15 = 0;
    var24[1] = (int)var24;
    var24[0] = (int)var24;
    v13[0] = a1[11];
    a1[11] = v13;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2);
    }
    else
    {
      __dmb(0xBu);
      *v2 = 0;
    }
    KfLowerIrql(v3);
    KeWaitForGate((int)v14, 18);
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2);
    }
    else
    {
      v9 = (unsigned __int8 *)v2 + 3;
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | 0x80, v9) );
      __dmb(0xBu);
      if ( v10 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v2);
      while ( 1 )
      {
        v11 = *v2;
        if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v11 & 0x40000000) == 0 )
        {
          do
            v12 = __ldrex(v2);
          while ( v12 == v11 && __strex(v11 | 0x40000000, v2) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  ++a1[5];
  ++a1[6];
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  return KfLowerIrql(v3);
}
