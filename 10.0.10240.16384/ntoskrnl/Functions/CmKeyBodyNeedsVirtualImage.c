// CmKeyBodyNeedsVirtualImage 
 
int __fastcall CmKeyBodyNeedsVirtualImage(int a1)
{
  int v2; // r5
  _DWORD *v3; // r0

  v2 = 0;
  CmpLockRegistry();
  CmpLockKcbShared(*(_DWORD **)(a1 + 4));
  v3 = *(_DWORD **)(a1 + 4);
  if ( (v3[1] & 0x20000) == 0 && (*(_DWORD *)(v3[5] + 3228) & 0x10) != 0 )
    v2 = 1;
  CmpUnlockKcb(v3);
  CmpUnlockRegistry();
  return v2;
}
