// CcSetAdditionalCacheAttributes 
 
int __fastcall CcSetAdditionalCacheAttributes(int a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r0
  int v7; // r3
  unsigned int v8; // r3
  unsigned int v9; // r3

  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  if ( !*(_DWORD *)(v5 + 4) )
    sub_521914();
  v6 = KeAcquireQueuedSpinLock(5);
  v7 = *(_DWORD *)(v5 + 96);
  if ( a2 )
    v8 = v7 | 1;
  else
    v8 = v7 & 0xFFFFFFFE;
  *(_DWORD *)(v5 + 96) = v8;
  if ( a3 )
    v9 = *(_DWORD *)(v5 + 96) | 0x202;
  else
    v9 = v8 & 0xFFFFFFFD;
  *(_DWORD *)(v5 + 96) = v9;
  return KeReleaseQueuedSpinLock(5, v6);
}
