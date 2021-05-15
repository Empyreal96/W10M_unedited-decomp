// IoPerfInit 
 
int __fastcall IoPerfInit(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r3
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a1;
  v8[1] = a2;
  v8[2] = a3;
  v8[3] = a4;
  v5 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&IopFunctionPointerLock, (unsigned int)v8);
  if ( !IopPerfStatus )
    v5 = 1;
  v6 = IopPerfStatus | a1;
  IopPerfStatus |= a1;
  if ( (a1 & 1) != 0 )
    v6 = ++dword_64B0C0;
  if ( (a1 & 2) != 0 )
    v6 = ++dword_64B0C4;
  if ( v5 == 1 )
    IopUpdateFunctionPointers(2, 1, 1, v6);
  KeReleaseInStackQueuedSpinLock((int)v8);
  return 0;
}
