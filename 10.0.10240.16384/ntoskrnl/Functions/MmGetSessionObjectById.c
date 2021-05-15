// MmGetSessionObjectById 
 
int __fastcall MmGetSessionObjectById(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r0
  int v6; // r6
  int v7; // r4
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[1] = a3;
  v9[2] = a4;
  v4 = 0;
  v5 = MmGetSessionById(a1, a2, a3, a4);
  v6 = v5;
  if ( v5 )
  {
    v7 = *(_DWORD *)(v5 + 324);
    v4 = *(_DWORD *)(v7 + 44);
    KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v9);
    if ( (*(_DWORD *)(v7 + 4) & 2) != 0 )
      v4 = 0;
    else
      ObfReferenceObjectWithTag(v4);
    KeReleaseInStackQueuedSpinLock((int)v9);
    ObfDereferenceObjectWithTag(v6);
  }
  return v4;
}
