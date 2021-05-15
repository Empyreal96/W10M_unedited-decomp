// MiFinishPageFileExtension 
 
int __fastcall MiFinishPageFileExtension(int a1, int a2, unsigned int a3, int a4)
{
  int v7; // r7
  int v8; // r4
  int v9; // r0
  unsigned int v10; // r2
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r3
  int result; // r0
  _DWORD v15[8]; // [sp+0h] [bp-20h] BYREF

  v15[0] = a2;
  v15[1] = a3;
  v15[2] = a4;
  v7 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a2 + 116), (unsigned int)v15);
  v8 = *(_DWORD *)(a2 + 64);
  RtlClearBits((_BYTE *)(v8 + 4), *(_DWORD *)a2, a3);
  RtlClearBits((_BYTE *)(v8 + 12), *(_DWORD *)a2, a3);
  v9 = *(_DWORD *)(a2 + 128);
  *(_DWORD *)a2 += a3;
  v10 = *(_DWORD *)(a2 + 12) + a3;
  v11 = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(a2 + 12) = v10;
  v12 = v11 + a3;
  v13 = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(a2 + 24) = v12;
  *(_DWORD *)(a2 + 80) = v13 + 1;
  if ( v10 >= v12 )
    v10 = v12;
  if ( (*(_BYTE *)(a2 + 98) & 1) != 0 )
    v7 = 1;
  *(_DWORD *)(a2 + 28) = v10;
  MiUpdateReserveClusterInfo(v9, 0);
  result = KeReleaseInStackQueuedSpinLock((int)v15);
  if ( v7 == 1 )
    result = KeSetEvent(a1 + 520, 0, 0);
  return result;
}
