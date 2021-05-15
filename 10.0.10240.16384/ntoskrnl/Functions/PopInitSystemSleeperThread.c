// PopInitSystemSleeperThread 
 
int __fastcall PopInitSystemSleeperThread(int a1, unsigned int a2)
{
  int result; // r0
  int v4; // [sp+10h] [bp-28h] BYREF
  int v5[8]; // [sp+18h] [bp-20h] BYREF

  *(_DWORD *)(a2 + 48) = a1;
  KeInitializeEvent(a2, 1, 0);
  KeInitializeEvent(a2 + 16, 1, 0);
  KeInitializeEvent(a2 + 32, 1, 0);
  v5[0] = 24;
  v5[1] = 0;
  v5[3] = 512;
  v5[2] = 0;
  v5[4] = 0;
  v5[5] = 0;
  result = PsCreateSystemThread((int)&v4, 0, (int)v5);
  if ( result >= 0 )
  {
    ZwClose();
    KeWaitForSingleObject(a2, 0, 0, 0, 0);
    result = 0;
  }
  return result;
}
