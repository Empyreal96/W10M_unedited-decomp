// MiObtainPagefileHashes 
 
int __fastcall MiObtainPagefileHashes(int a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v6; // r6
  int v7; // r7
  unsigned int i; // r0
  int v9; // r3
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a1;
  v11[2] = a3;
  v11[3] = a4;
  v6 = a4;
  v7 = a3;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 116), (unsigned int)v11);
  for ( i = *(_DWORD *)(a1 + 108) + 4 * a2; v7; --v7 )
  {
    if ( (*(_DWORD *)(((i >> 10) & 0x3FFFFC) - 0x40000000) & 2) != 0 )
      v9 = *(_DWORD *)i;
    else
      v9 = 0;
    *v6++ = v9;
    i += 4;
  }
  KeReleaseInStackQueuedSpinLock((int)v11);
  return v11[0];
}
