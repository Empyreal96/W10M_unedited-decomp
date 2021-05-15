// IovpCallDriverWithStackBuffer 
 
int __fastcall IovpCallDriverWithStackBuffer(int a1, __int16 *a2, int a3)
{
  int v6; // r3
  char v7; // r6
  unsigned int v8; // r1
  char v9; // r5
  unsigned int v10; // r1
  int v11; // r7
  int v12; // r3
  char v13; // r8
  unsigned int v14; // r1
  int v15; // r3
  int v16; // r1
  int v17; // r7
  int v18; // r0
  int v19; // r3
  unsigned __int8 *v20; // r3
  int v21; // r2
  int v22; // r3
  int v24; // [sp+8h] [bp-98h] BYREF
  _DWORD v25[36]; // [sp+10h] [bp-90h] BYREF

  memset(v25, 0, 120);
  v6 = *a2;
  v25[24] = a1;
  v25[25] = a2;
  v25[26] = a3;
  if ( v6 != 6 )
  {
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
    }
    else
    {
      do
        v8 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
      while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
    }
    VfBugcheckTmpData = 201;
    dword_909044 = 3;
    dword_909048 = (int)a2;
    dword_90904C = 0;
    dword_909050 = 0;
    BYTE1(v25[23]) = v7;
    VfBugCheckNoStackUsage();
  }
  if ( !IovpValidateDeviceObject(a1) )
  {
    v9 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
    }
    else
    {
      do
        v10 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
      while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
      __dmb(0xBu);
      if ( v10 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
    }
    VfBugcheckTmpData = 201;
    dword_909044 = 4;
    dword_909048 = a1;
    dword_90904C = 0;
    dword_909050 = 0;
    BYTE1(v25[23]) = v9;
    VfBugCheckNoStackUsage();
  }
  v11 = *((_DWORD *)a2 + 24);
  if ( !*(_BYTE *)(v11 - 40) )
  {
    v12 = *(_DWORD *)(v11 - 12);
    if ( v12 )
    {
      if ( (*(_DWORD *)(v12 + 44) & 0x204000) == 2113536 )
      {
        v13 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)&VfBugcheckTmpDataLock);
        }
        else
        {
          do
            v14 = __ldrex((unsigned int *)&VfBugcheckTmpDataLock);
          while ( __strex(1u, (unsigned int *)&VfBugcheckTmpDataLock) );
          __dmb(0xBu);
          if ( v14 )
            KxWaitForSpinLockAndAcquire((unsigned int *)&VfBugcheckTmpDataLock);
        }
        VfBugcheckTmpData = 201;
        dword_909044 = 15;
        dword_909048 = a1;
        BYTE1(v25[23]) = v13;
        v15 = *(_DWORD *)(v11 - 12);
        dword_90904C = (int)a2;
        dword_909050 = v15;
        VfBugCheckNoStackUsage();
      }
    }
  }
  v17 = VfBeforeCallDriver(a1, a2, v25);
  if ( (IopFunctionPointerMask & 2) != 0 )
  {
    v18 = IopPerfCallDriver(a1, (int)a2);
  }
  else
  {
    v19 = (char)(*((_BYTE *)a2 + 35) - 1);
    *((_BYTE *)a2 + 35) = v19;
    if ( v19 <= 0 )
      KeBugCheckEx(53, (int)a2, 0, 0, 0);
    v20 = (unsigned __int8 *)(*((_DWORD *)a2 + 24) - 40);
    *((_DWORD *)a2 + 24) = v20;
    v21 = *v20;
    *((_DWORD *)v20 + 6) = a1;
    if ( v21 == 22 && ((v22 = v20[1], v22 == 2) || v22 == 3) )
      v18 = IopPoHandleIrp((int)a2, v16, 22, v22);
    else
      v18 = (*(int (__fastcall **)(int, __int16 *))(*(_DWORD *)(a1 + 8) + 4 * v21 + 56))(a1, a2);
  }
  v24 = v18;
  VfAfterCallDriver(v25, &v24, v17);
  return v24;
}
