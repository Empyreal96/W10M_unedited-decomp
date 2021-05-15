// MiIncrementPageTableLockCheckWrap 
 
int __fastcall MiIncrementPageTableLockCheckWrap(int a1)
{
  int v1; // r1

  v1 = *(_DWORD *)(a1 + 12);
  if ( (v1 & 0x3FFFFFFFu) >= 0x3FFEFBFF )
    return 0;
  *(_DWORD *)(a1 + 12) = v1 & 0xC0000000 | (v1 + 0x10000) & 0x3FFFFFFF;
  return 1;
}
