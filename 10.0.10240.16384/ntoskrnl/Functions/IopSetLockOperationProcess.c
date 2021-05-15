// IopSetLockOperationProcess 
 
int __fastcall IopSetLockOperationProcess(int a1, int a2, int a3)
{
  _DWORD *v3; // r5
  int v4; // r9
  int v8; // r4
  int v9; // r0
  int v10; // r7
  unsigned int *v11; // r6
  unsigned int v12; // r2
  int v13; // r1
  int v14; // r8
  _DWORD *v15; // r2
  int v16; // r3
  int v18[9]; // [sp+Ch] [bp-24h] BYREF

  v3 = 0;
  v4 = 0;
  if ( !a2 )
    return sub_529F9C();
  if ( a3 )
  {
    v8 = 0;
    v10 = IopGetFileObjectExtension(a1, 1, 0);
    if ( !v10 )
      return -1073741823;
LABEL_8:
    v11 = (unsigned int *)(a1 + 112);
    v18[0] = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(a1 + 112);
    }
    else
    {
      do
        v12 = __ldrex(v11);
      while ( __strex(1u, v11) );
      __dmb(0xBu);
      if ( v12 )
        KxWaitForSpinLockAndAcquire(a1 + 112);
    }
    v13 = *(_DWORD *)(v10 + 8);
    v14 = *(unsigned __int8 *)(a1 + 36);
    if ( v13 )
    {
      v15 = *(_DWORD **)(v10 + 8);
      while ( v15[1] != a2 )
      {
        v15 = (_DWORD *)*v15;
        if ( !v15 )
          goto LABEL_25;
      }
      v4 = 1;
    }
    else
    {
LABEL_25:
      if ( !a3 )
      {
        if ( v3 )
        {
          *v3 = v13;
          *(_DWORD *)(v10 + 8) = v3;
          v3[1] = a2;
        }
        else
        {
          v8 = -1073741670;
        }
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v11);
    }
    else
    {
      __dmb(0xBu);
      *v11 = 0;
    }
    KfLowerIrql(v18[0]);
    if ( v4 && v3 )
      ExFreePoolWithTag(v3, 0);
    if ( !a3 )
      return v8;
    if ( v14 && v4 )
      return 0;
    return -1073741823;
  }
  v8 = IopGetSetSpecificExtension(a1, 1, 16, 1, v18, 0);
  if ( v8 >= 0 )
  {
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v16 = 40;
      else
        v16 = 32;
      v9 = ExAllocatePoolWithTagPriority(512, 8, 538996553, v16);
    }
    else
    {
      v9 = ExAllocatePoolWithTag(512, 8, 538996553);
    }
    v10 = v18[0];
    v3 = (_DWORD *)v9;
    goto LABEL_8;
  }
  return v8;
}
