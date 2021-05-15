// IopCancelSynchronousIrpsForThread 
 
int __fastcall IopCancelSynchronousIrpsForThread(int a1, int a2)
{
  _DWORD v5[22]; // [sp+0h] [bp-58h] BYREF

  if ( !IopCancelApcRequired(a1, 0, a2) )
    return 0;
  memset(v5, 0, 80);
  v5[12] = 0;
  v5[13] = a2;
  LOBYTE(v5[18]) = 1;
  KeInitializeEvent((int)&v5[14], 0, 0);
  return IopCancelIrpsInThreadList(a1, (int)v5);
}
