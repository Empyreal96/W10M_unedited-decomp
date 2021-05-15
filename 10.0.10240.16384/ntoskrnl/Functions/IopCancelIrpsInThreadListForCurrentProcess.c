// IopCancelIrpsInThreadListForCurrentProcess 
 
int __fastcall IopCancelIrpsInThreadListForCurrentProcess(int a1, int a2)
{
  int v4; // r6
  int v5; // r5
  int i; // r1
  int v7; // r0
  int v8; // r4
  _DWORD v10[26]; // [sp+0h] [bp-68h] BYREF

  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v5 = 0;
  memset(v10, 0, 80);
  LOBYTE(v10[18]) = 0;
  v10[12] = a1;
  v10[13] = a2;
  KeInitializeEvent((int)&v10[14], 0, 0);
  for ( i = 0; ; i = v8 )
  {
    v7 = PsGetNextProcessThread(v4, i);
    v8 = v7;
    if ( !v7 )
      break;
    if ( IopCancelApcRequired(v7, a1, a2) )
      v5 |= IopCancelIrpsInThreadList(v8, (int)v10);
  }
  return v5;
}
