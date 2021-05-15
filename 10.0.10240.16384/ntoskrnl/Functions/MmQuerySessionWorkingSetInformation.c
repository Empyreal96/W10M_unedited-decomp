// MmQuerySessionWorkingSetInformation 
 
int __fastcall MmQuerySessionWorkingSetInformation(int a1, _DWORD *a2, int a3, int a4)
{
  int v5; // r10
  int v6; // r5
  int v7; // r7
  int v8; // r6
  int *v9; // r4
  unsigned int i; // r2
  _DWORD v12[10]; // [sp+0h] [bp-28h] BYREF

  v12[1] = a3;
  v12[2] = a4;
  v5 = a1 + 20 * *a2;
  v6 = a1;
  v7 = 0;
  v8 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v12);
  v9 = (int *)dword_634D28;
  for ( i = 0x22A8u; v9 != &dword_634D28; ++v8 )
  {
    if ( v6 == v5 )
    {
      v7 = -1073741820;
    }
    else
    {
      MiFillSessionWorkingSetEntry(v6, v9 - 24, i);
      v6 += 20;
    }
    v9 = (int *)*v9;
  }
  KeReleaseInStackQueuedSpinLock((int)v12);
  *a2 = v8;
  return v7;
}
