// SepValidateAndCopyGlobalEntry 
 
int __fastcall SepValidateAndCopyGlobalEntry(int a1, _DWORD *a2, __int64 a3)
{
  int v4; // r5
  _DWORD *v5; // r6
  unsigned int v6; // r0
  int v7; // r4
  int v8; // r9
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r2
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v18[2]; // [sp+0h] [bp-28h] BYREF
  __int64 v19[4]; // [sp+8h] [bp-20h] BYREF

  v18[0] = a1;
  v18[1] = (int)a2;
  v19[0] = a3;
  *a2 = 0;
  v4 = SepGetProcUniqueLuidAndIndexFromAttributeInfo(a1, v18, v19);
  if ( v4 >= 0 )
  {
    v5 = (_DWORD *)ExAllocatePoolWithTag(512, 24);
    if ( v5 )
    {
      v6 = v18[0];
      *v5 = 0;
      v5[3] = 0;
      v5[1] = v5 + 1;
      v5[2] = v5 + 1;
      v5[4] = v5 + 4;
      v5[5] = v5 + 4;
      v7 = SepGetSingletonEntryFromIndexNumber(v6);
      v8 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v7);
      }
      else
      {
        v9 = *(_DWORD *)v7 & 0x7FFFFFFF;
        do
          v10 = __ldrex((unsigned int *)v7);
        while ( v10 == v9 && __strex(v9 + 1, (unsigned int *)v7) );
        __dmb(0xBu);
        if ( v10 != v9 )
          ExpWaitForSpinLockSharedAndAcquire((unsigned int *)v7);
      }
      if ( *(_QWORD *)(v7 + 8) == v19[0] )
      {
        v11 = *(_DWORD *)(v7 + 16);
        if ( v11 )
        {
          v12 = AuthzBasepDuplicateSecurityAttributes(v11, (int)v5, 0);
          *a2 = v5;
          v4 = v12;
          v5 = 0;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v7);
        }
        else
        {
          __dmb(0xBu);
          do
            v13 = __ldrex((unsigned int *)v7);
          while ( __strex(v13 & 0xBFFFFFFF, (unsigned int *)v7) );
          __dmb(0xBu);
          do
            v14 = __ldrex((unsigned int *)v7);
          while ( __strex(v14 - 1, (unsigned int *)v7) );
        }
        KfLowerIrql(v8);
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v7);
        }
        else
        {
          __dmb(0xBu);
          do
            v15 = __ldrex((unsigned int *)v7);
          while ( __strex(v15 & 0xBFFFFFFF, (unsigned int *)v7) );
          __dmb(0xBu);
          do
            v16 = __ldrex((unsigned int *)v7);
          while ( __strex(v16 - 1, (unsigned int *)v7) );
        }
        KfLowerIrql(v8);
        v4 = -1073741275;
      }
      if ( v5 )
        ExFreePoolWithTag(v5);
    }
    else
    {
      v4 = -1073741801;
    }
  }
  return v4;
}
