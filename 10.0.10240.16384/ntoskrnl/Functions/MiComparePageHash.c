// MiComparePageHash 
 
int __fastcall MiComparePageHash(int a1, int a2, int a3, int a4)
{
  int v7; // r6
  unsigned int v8; // r1
  unsigned int v9; // r3
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a1;
  v11[1] = a2;
  v11[2] = a3;
  v11[3] = a4;
  v7 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 116), (unsigned int)v11);
  v8 = *(_DWORD *)(a1 + 108) + 4 * a2;
  v9 = *(_DWORD *)(((v8 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( (v9 & 2) != 0 )
  {
    if ( (*(_BYTE *)(MmPfnDatabase + 24 * (v9 >> 12) + 18) & 0x10) != 0 )
    {
      if ( !byte_634580 )
        v7 = -1073741761;
    }
    else
    {
      *(_DWORD *)v8 = a3;
    }
  }
  KeReleaseInStackQueuedSpinLock((int)v11);
  return v7;
}
