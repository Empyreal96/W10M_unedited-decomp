// VmAccessFault 
 
int __fastcall VmAccessFault(int a1, int a2, unsigned int a3, int a4, int a5)
{
  unsigned int v5; // r7
  unsigned int *v6; // r4
  int i; // r5
  int v8; // r6
  unsigned int v9; // r8
  int v10; // r7
  int v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r2
  _DWORD v19[9]; // [sp+4h] [bp-24h] BYREF

  v19[0] = a3;
  v19[1] = a4;
  v5 = a3;
  v6 = *(unsigned int **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 800);
  if ( !v6 )
    return -1073741688;
  if ( a3 > MmHighestUserAddress )
    return -1073741819;
  v8 = (a4 & 1) != 0;
  if ( (a4 & 2) != 0 )
    v8 |= 2u;
  if ( (a4 & 4) != 0 )
    v8 |= 4u;
  v9 = v6[5];
  __dmb(0xBu);
  for ( i = MmVirtualAccessFault(a3, v8, v19); i >= 0; i = MmVirtualAccessFault(v5, v8, v19) )
  {
    if ( v9 == v6[5] )
    {
      v10 = KfRaiseIrql(15);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v6);
      }
      else
      {
        v11 = *v6 & 0x7FFFFFFF;
        do
          v12 = __ldrex(v6);
        while ( v12 == v11 && __strex(v11 + 1, v6) );
        __dmb(0xBu);
        if ( v12 != v11 )
          ExpWaitForSpinLockSharedAndAcquire(v6);
      }
      if ( v6[6] != a5 )
      {
        i = -1073741558;
LABEL_31:
        if ( v10 != -1 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v6);
          }
          else
          {
            __dmb(0xBu);
            do
              v15 = __ldrex(v6);
            while ( __strex(v15 & 0xBFFFFFFF, v6) );
            __dmb(0xBu);
            do
              v16 = __ldrex(v6);
            while ( __strex(v16 - 1, v6) );
          }
          KfLowerIrql((unsigned __int8)v10);
        }
        return i;
      }
      if ( v9 == v6[5] )
      {
        i = 0;
        goto LABEL_31;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v6);
      }
      else
      {
        __dmb(0xBu);
        do
          v13 = __ldrex(v6);
        while ( __strex(v13 & 0xBFFFFFFF, v6) );
        __dmb(0xBu);
        do
          v14 = __ldrex(v6);
        while ( __strex(v14 - 1, v6) );
      }
      KfLowerIrql((unsigned __int8)v10);
      v5 = a3;
    }
    v9 = v6[5];
    __dmb(0xBu);
  }
  return i;
}
