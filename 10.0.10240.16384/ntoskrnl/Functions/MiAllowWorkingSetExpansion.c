// MiAllowWorkingSetExpansion 
 
int __fastcall MiAllowWorkingSetExpansion(int a1, int a2, int a3, int a4)
{
  int **v6; // r6
  int *v7; // r0
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  KeAcquireInStackQueuedSpinLock(&dword_634980, v8);
  if ( (*(_BYTE *)(a1 + 112) & 7) == 1 )
  {
    v6 = (int **)dword_634D2C;
    v7 = (int *)(a1 - 3152);
    *v7 = (int)&dword_634D28;
    v7[1] = (int)v6;
    if ( *v6 != &dword_634D28 )
      sub_50BC38();
    *v6 = v7;
    dword_634D2C = a1 - 3152;
  }
  MiReturnWsToExpansionList(a1, 0);
  return KeReleaseInStackQueuedSpinLock(v8);
}
