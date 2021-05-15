// CcSetAdditionalCacheAttributesEx 
 
int __fastcall CcSetAdditionalCacheAttributesEx(int a1, char a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r3
  unsigned int v6; // r3
  int v7; // r3
  unsigned int v9; // r3
  int v10; // r3
  unsigned int v11; // r3
  int v12; // r3
  unsigned int v13; // r3

  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  if ( !*(_DWORD *)(v3 + 4) )
    KeBugCheckEx(52, 173, -1073740768);
  if ( (*(_DWORD *)(v3 + 96) & 0x2000) == 0 )
    CcSetAdditionalCacheAttributes();
  v4 = KeAcquireQueuedSpinLock(5);
  v5 = *(_DWORD *)(v3 + 96);
  if ( (a2 & 1) != 0 )
    v6 = v5 | 0x800000;
  else
    v6 = v5 & 0xFF7FFFFF;
  *(_DWORD *)(v3 + 96) = v6;
  v7 = *(_DWORD *)(v3 + 96);
  if ( (a2 & 8) != 0 )
  {
    v9 = v7 | 0x4000000;
  }
  else
  {
    if ( (v7 & 0x4000000) != 0 )
      return sub_5218F4(v4);
    v9 = *(_DWORD *)(v3 + 96) & 0xFBFFFFFF;
  }
  *(_DWORD *)(v3 + 96) = v9;
  v10 = *(_DWORD *)(v3 + 96);
  if ( (a2 & 0x10) != 0 )
    v11 = v10 | 0x10000000;
  else
    v11 = v10 & 0xEFFFFFFF;
  *(_DWORD *)(v3 + 96) = v11;
  v12 = *(_DWORD *)(v3 + 96);
  if ( (a2 & 0x20) != 0 )
    v13 = v12 | 0x8000000;
  else
    v13 = v12 & 0xF7FFFFFF;
  *(_DWORD *)(v3 + 96) = v13;
  return KeReleaseQueuedSpinLock(5, v4);
}
