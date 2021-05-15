// MiDereferencePartition 
 
int __fastcall MiDereferencePartition(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  int result; // r0
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a2;
  v8[1] = a3;
  v8[2] = a4;
  v5 = KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634318, (unsigned int)v8);
  v6 = *(_DWORD *)(a1 + 8) - 1;
  *(_DWORD *)(a1 + 8) = v6;
  if ( v6 )
    result = KeReleaseInStackQueuedSpinLock((int)v8);
  else
    result = sub_527AD0(v5);
  return result;
}
