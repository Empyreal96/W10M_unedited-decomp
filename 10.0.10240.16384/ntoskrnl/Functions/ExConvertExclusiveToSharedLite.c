// ExConvertExclusiveToSharedLite 
 
int __fastcall ExConvertExclusiveToSharedLite(int a1)
{
  int v2; // r1
  __int16 v3; // r2
  int result; // r0
  unsigned int v5; // r3
  int v6; // r3
  int v7; // r4
  int v8; // r6
  int v9; // r0
  int v10; // [sp+0h] [bp-20h] BYREF
  char v11[24]; // [sp+8h] [bp-18h] BYREF

  KeAcquireInStackQueuedSpinLock(a1 + 52, v11);
  v2 = *(_DWORD *)(a1 + 40);
  v3 = *(_WORD *)(a1 + 14) & 0xFF7F;
  *(_WORD *)(a1 + 14) = v3;
  if ( !v2 )
  {
    result = KeReleaseInStackQueuedSpinLock(v11);
LABEL_3:
    v5 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v5 & 0xFFFFF000) + 0x1434);
    return result;
  }
  *(_DWORD *)(a1 + 32) += v2;
  v6 = *(_DWORD *)(a1 + 44);
  *(_DWORD *)(a1 + 40) = 0;
  if ( !v6 )
    *(_WORD *)(a1 + 14) = v3 & 0xFB;
  v7 = *(unsigned __int8 *)(a1 + 15);
  v10 = *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 16) = 0;
  KeReleaseInStackQueuedSpinLock(v11);
  v8 = KfRaiseIrql(2);
  v9 = KeWakeWaitChain(&v10, 0, 0);
  if ( !v7 )
  {
    result = KfLowerIrql(v8);
    goto LABEL_3;
  }
  return sub_52121C(v9);
}
