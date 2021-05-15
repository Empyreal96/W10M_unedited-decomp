// MmEnumerateBadPages 
 
int __fastcall MmEnumerateBadPages(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v5; // r4
  int v6; // r0
  _DWORD *v7; // r5
  int v8; // r8
  int i; // r3
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[1] = a3;
  v11[2] = a4;
  *a1 = 0;
  while ( 1 )
  {
    if ( !dword_640080 )
      return 0;
    v5 = dword_640080 + 16;
    v6 = ExAllocatePoolWithTag(512, 4 * (dword_640080 + 16));
    v7 = (_DWORD *)v6;
    if ( !v6 )
      break;
    v8 = v6;
    KeAcquireInStackQueuedSpinLock(&dword_640090, (unsigned int)v11);
    if ( dword_640080 < v5 && dword_640080 )
    {
      *v7 = dword_640080;
      for ( i = dword_640088; i != 0xFFFFF; i = *(_DWORD *)(MmPfnDatabase + 24 * i) )
      {
        *(_DWORD *)(v8 + 4) = i;
        v8 += 4;
      }
      KeReleaseInStackQueuedSpinLock((int)v11);
      *a1 = v7;
      return 0;
    }
    KeReleaseInStackQueuedSpinLock((int)v11);
    ExFreePoolWithTag(v7);
  }
  return -1073741670;
}
