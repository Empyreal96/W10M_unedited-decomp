// NtShutdownWorkerFactory 
 
int __fastcall NtShutdownWorkerFactory(int a1, unsigned int *a2)
{
  int v3; // r4
  int v4; // r6
  int v5; // r0
  unsigned int v6; // r1
  char v8; // [sp+8h] [bp-38h]
  int v9; // [sp+10h] [bp-30h] BYREF
  _DWORD _18[14]; // [sp+18h] [bp-28h] BYREF

  _18[13] = a2;
  _18[12] = a1;
  v8 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v8 )
  {
    if ( ((unsigned __int8)a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( (unsigned int)(a2 + 1) > MmUserProbeAddress || a2 + 1 < a2 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v3 = ObReferenceObjectByHandle(a1, 32, ExpWorkerFactoryObjectType, v8, &v9, 0);
  if ( v3 >= 0 )
  {
    v4 = v9;
    ExpShutdownWorkerFactory(v9);
    v5 = *(_DWORD *)(v4 + 72);
    __dmb(0xBu);
    do
      v6 = __ldrex(a2);
    while ( __strex(v6 + v5, a2) );
    __dmb(0xBu);
    KeAcquireInStackQueuedSpinLock(*(_DWORD *)(v4 + 4), _18);
    *(_DWORD *)(v4 + 72) = 0;
    KeReleaseInStackQueuedSpinLock(_18);
    ObfDereferenceObjectWithTag(v4);
  }
  return v3;
}
