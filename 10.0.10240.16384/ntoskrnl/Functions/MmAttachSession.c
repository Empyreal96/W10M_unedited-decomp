// MmAttachSession 
 
int __fastcall MmAttachSession(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r7
  int v9; // r0
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a2;
  v11[1] = a3;
  v11[2] = a4;
  v4 = *(_DWORD *)(a1 + 324);
  v6 = a1;
  v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v8 = *(_DWORD *)(v7 + 324);
  v9 = KeAcquireInStackQueuedSpinLock(&dword_634980, v11);
  if ( (*(_DWORD *)(v4 + 4) & 2) != 0 )
    return sub_50A1DC(v9);
  ++*(_DWORD *)(v4 + 76);
  KeReleaseInStackQueuedSpinLock(v11);
  if ( v8 && !PsIsSystemProcess(v7) && v8 == v4 )
    v6 = v7;
  KiStackAttachProcess(v6, 0, a2);
  return 0;
}
