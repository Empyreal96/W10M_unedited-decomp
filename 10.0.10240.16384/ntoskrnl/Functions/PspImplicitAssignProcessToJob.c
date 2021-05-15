// PspImplicitAssignProcessToJob 
 
int __fastcall PspImplicitAssignProcessToJob(int a1, _DWORD *a2, int a3)
{
  int v7; // r5
  _DWORD *v8; // r6
  int v9; // r3
  int v10; // r4
  unsigned __int8 *v11; // r3
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r3

  if ( (a3 & 0x400) != 0 )
    return sub_7EBC5C();
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  PspLockJobChain(a1, v7, a3);
  v8 = (_DWORD *)a1;
  if ( a1 )
  {
    do
    {
      v9 = v8[44];
      if ( (v9 & 0x1000) == 0 && ((a3 & 1) == 0 || (v9 & 0x800) == 0) )
        break;
      v8 = (_DWORD *)v8[143];
    }
    while ( v8 );
  }
  if ( (a3 & 1) != 0 && v8 == (_DWORD *)a1 )
  {
    v10 = -1073741790;
  }
  else if ( v8 )
  {
    v10 = PspEstablishJobHierarchy((int)v8, (int)a2, 1);
    if ( v10 >= 0 )
    {
      v10 = PspAddProcessToJobChain((int)v8, 0, (int)a2, a3);
      if ( v10 >= 0 )
      {
        if ( (v8[186] & 0x1000) != 0 )
        {
          __dmb(0xBu);
          v11 = (unsigned __int8 *)a2 + 787;
          do
            v12 = __ldrex(v11);
          while ( __strex(v12 | 0x80, v11) );
          __dmb(0xBu);
        }
        PspUnlockJobChain(a1, v7);
        v10 = PspApplyWorkingSetLimitsToProcess(a2);
        if ( v10 >= 0 && !MmAssignProcessToJob(a2, 0) )
          v10 = -1073741756;
        --*(_WORD *)(v7 + 308);
        v13 = PspChangeProcessExecutionState((int)a2);
        v14 = (__int16)(*(_WORD *)(v7 + 308) + 1);
        *(_WORD *)(v7 + 308) = v14;
        if ( !v14 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
          KiCheckForKernelApcDelivery(v13);
        return v10;
      }
    }
  }
  else
  {
    v10 = 0;
  }
  PspUnlockJobChain(a1, v7);
  return v10;
}
