// sub_509EB0 
 
void __fastcall sub_509EB0(int a1, int a2)
{
  unsigned int *v2; // r5
  unsigned int v3; // r7
  int v4; // r9
  int v5; // r4
  unsigned int *v6; // r2
  unsigned int v7; // r0
  unsigned int v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // t1
  int v11; // r3
  unsigned int *v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r4
  unsigned int *v19; // r2
  unsigned int v20; // r1

  if ( a2 == 1 )
  {
    v4 = 17;
    if ( (dword_682604 & 0x210000) == 0 )
    {
      v5 = v2[271] & 0x7FFFFFFF;
      v6 = v2 + 271;
      do
        v7 = __ldrex(v6);
      while ( v7 == v5 && __strex(v5 + 1, v6) );
      goto LABEL_6;
    }
  }
  else
  {
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) == 0 )
    {
      v5 = v2[271] & 0x7FFFFFFF;
      v12 = v2 + 271;
      do
        v7 = __ldrex(v12);
      while ( v7 == v5 && __strex(v5 + 1, v12) );
LABEL_6:
      __dmb(0xBu);
      if ( v7 != v5 )
        ExpWaitForSpinLockSharedAndAcquire(v2 + 271);
LABEL_8:
      v8 = v2[859];
      v9 = (unsigned int *)(v2[860] + 8 * v8);
      if ( v3 >= *v9 )
      {
        while ( v3 >= v9[2] )
        {
          ++v8;
          v9 += 2;
        }
      }
      else
      {
        do
        {
          v10 = *(v9 - 2);
          v9 -= 2;
          --v8;
        }
        while ( v3 < v10 );
      }
      v11 = dword_682604;
      v2[859] = v8;
      if ( v4 == 17 )
      {
        if ( (v11 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v2 + 271);
        }
        else
        {
          __dmb(0xBu);
          v13 = v2 + 271;
          do
            v14 = __ldrex(v13);
          while ( __strex(v14 & 0xBFFFFFFF, v13) );
          __dmb(0xBu);
          v15 = v2 + 271;
          do
            v16 = __ldrex(v15);
          while ( __strex(v16 - 1, v15) );
        }
      }
      else
      {
        if ( (v11 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v2 + 271);
        }
        else
        {
          __dmb(0xBu);
          v17 = v2 + 271;
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 & 0xBFFFFFFF, v17) );
          __dmb(0xBu);
          v19 = v2 + 271;
          do
            v20 = __ldrex(v19);
          while ( __strex(v20 - 1, v19) );
        }
        KfLowerIrql(v4);
      }
      JUMPOUT(0x42E9A0);
    }
  }
  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v2 + 271);
  goto LABEL_8;
}
