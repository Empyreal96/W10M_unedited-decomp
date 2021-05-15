// PoRegisterDeviceForIdleDetection 
 
int __fastcall PoRegisterDeviceForIdleDetection(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r7
  int v9; // r8
  unsigned int v11; // r2
  _DWORD *v12; // r2
  _DWORD *v13; // r1
  int v14; // r3
  int v15; // r5
  _DWORD *v16; // r0
  int v17; // r3
  int v18; // r6
  _DWORD *v19; // r5
  unsigned int v20; // r2
  int *v21; // r2
  int **v22; // r0
  int v23; // [sp+0h] [bp-20h]

  v4 = 0;
  if ( a2 || a3 )
  {
    if ( (unsigned int)(a4 - 2) <= 2 )
    {
      v17 = a1[11];
      v18 = 0;
      if ( v17 == 7 || v17 == 45 )
      {
        if ( !PopPlatformAoAc && (a1[8] & 1) != 0 )
          return (int)v4;
        v18 = 1;
      }
      v19 = (_DWORD *)PopGetDope(a1);
      if ( v19 )
      {
        v23 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(&PopDopeGlobalLock);
        }
        else
        {
          do
            v20 = __ldrex((unsigned int *)&PopDopeGlobalLock);
          while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
          __dmb(0xBu);
          if ( v20 )
            KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
        }
        v21 = v19 + 7;
        v19[4] = a2;
        v19[5] = a3;
        v19[9] = v18;
        v19[10] = a4;
        if ( (_DWORD *)v19[7] == v19 + 7 )
        {
          v19[11] = 1;
          v22 = (int **)dword_61E8E4;
          *v21 = (int)&PopIdleDetectList;
          v19[8] = v22;
          if ( *v22 != &PopIdleDetectList )
            __fastfail(3u);
          *v22 = v21;
          dword_61E8E4 = (int)(v19 + 7);
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(&PopDopeGlobalLock);
        }
        else
        {
          __dmb(0xBu);
          PopDopeGlobalLock = 0;
        }
        KfLowerIrql(v23);
        PopCheckForWork();
        v4 = v19;
      }
      return (int)v4;
    }
  }
  else
  {
    v9 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_527D68();
    do
      v11 = __ldrex((unsigned int *)&PopDopeGlobalLock);
    while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
    __dmb(0xBu);
    if ( v11 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
    v12 = *(_DWORD **)(a1[44] + 12);
    if ( v12 )
    {
      v13 = v12 + 7;
      v14 = v12[7];
      if ( (_DWORD *)v14 != v12 + 7 )
      {
        v15 = v12[7];
        v16 = (_DWORD *)v12[8];
        if ( *(_DWORD **)(v14 + 4) != v13 || (_DWORD *)*v16 != v13 )
          __fastfail(3u);
        *v16 = v15;
        *(_DWORD *)(v15 + 4) = v16;
        v12[9] = 0;
        v12[10] = 0;
        v12[4] = 0;
        v12[5] = 0;
        v12[11] = 0;
        *v12 = 0;
        v12[1] = 0;
        v12[2] = 0;
        v12[3] = 0;
        v12[15] = 0;
        v12[16] = 0;
        *v13 = v13;
        v12[8] = v12 + 7;
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PopDopeGlobalLock);
    }
    else
    {
      __dmb(0xBu);
      PopDopeGlobalLock = 0;
    }
    KfLowerIrql(v9);
  }
  return (int)v4;
}
