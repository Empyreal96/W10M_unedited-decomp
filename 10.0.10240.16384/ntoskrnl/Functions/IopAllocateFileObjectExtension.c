// IopAllocateFileObjectExtension 
 
int __fastcall IopAllocateFileObjectExtension(int a1, _DWORD *a2)
{
  int *v3; // r2
  unsigned int v4; // r7
  unsigned int *v6; // r8
  int v7; // r9
  unsigned int v9; // r2
  unsigned int v10; // r6
  _BYTE *v11; // r0
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r1
  int v15; // r3

  v3 = *(int **)(a1 + 124);
  v4 = 0;
  if ( !v3 )
  {
    v6 = (unsigned int *)(a1 + 112);
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_52A058();
    do
      v9 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire(v6);
    v10 = *(_DWORD *)(a1 + 124);
    if ( v10 )
      goto LABEL_21;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v6);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(v7);
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v15 = 40;
      else
        v15 = 32;
      v11 = (_BYTE *)ExAllocatePoolWithTagPriority(512, 36, 538996553, v15);
    }
    else
    {
      v11 = (_BYTE *)ExAllocatePoolWithTag(512, 36, 538996553);
    }
    v10 = (unsigned int)v11;
    if ( v11 )
    {
      memset(v11, 0, 36);
      v7 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v6);
      }
      else
      {
        do
          v12 = __ldrex(v6);
        while ( __strex(1u, v6) );
        __dmb(0xBu);
        if ( v12 )
          KxWaitForSpinLockAndAcquire(v6);
      }
      if ( *(_DWORD *)(a1 + 124) )
      {
        v4 = v10;
        v10 = *(_DWORD *)(a1 + 124);
      }
      else
      {
        __dmb(0xBu);
        v13 = (unsigned int *)(a1 + 124);
        do
          v14 = __ldrex(v13);
        while ( __strex(v10, v13) );
        __dmb(0xBu);
      }
LABEL_21:
      if ( a2 )
        *a2 = v10;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v6);
      }
      else
      {
        __dmb(0xBu);
        *v6 = 0;
      }
      KfLowerIrql(v7);
      if ( v4 )
        ExFreePoolWithTag(v4, 0);
      return 0;
    }
    return -1073741670;
  }
  if ( v3 == IopRevocationExtension )
    return -1073741670;
  if ( a2 )
    *a2 = v3;
  return 0;
}
