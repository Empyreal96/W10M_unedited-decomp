// IoPerfReset 
 
int __fastcall IoPerfReset(char a1, int a2, int a3, int a4)
{
  int v5; // r3
  unsigned int v6; // r2
  _DWORD v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&IopFunctionPointerLock, (unsigned int)v8);
  if ( (a1 & 1) == 0 || (v5 = dword_64B0C0 - 1, (dword_64B0C0 = v5) != 0) )
  {
    v6 = IopPerfStatus;
  }
  else
  {
    v5 = IopPerfStatus;
    v6 = IopPerfStatus & 0xFFFFFFFE;
    IopPerfStatus &= 0xFFFFFFFE;
  }
  if ( (a1 & 2) != 0 )
  {
    v5 = dword_64B0C4 - 1;
    dword_64B0C4 = v5;
    if ( !v5 )
    {
      v6 &= 0xFFFFFFFD;
      IopPerfStatus = v6;
    }
  }
  if ( !v6 )
    IopUpdateFunctionPointers(2, 0, 1, v5);
  KeReleaseInStackQueuedSpinLock((int)v8);
  return 0;
}
