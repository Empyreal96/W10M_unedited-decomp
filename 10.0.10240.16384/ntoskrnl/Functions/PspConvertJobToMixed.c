// PspConvertJobToMixed 
 
int __fastcall PspConvertJobToMixed(int a1)
{
  int v1; // r3
  int v3; // r0

  v1 = *(_DWORD *)(a1 + 232);
  __dmb(0xBu);
  if ( v1 != -2 )
  {
    v3 = PsGetCurrentSilo();
    if ( PsIsHostSilo(v3) || (*(_DWORD *)(a1 + 744) & 0x10) != 0 )
      return -1073741790;
    *(_DWORD *)(a1 + 232) = -2;
  }
  return 0;
}
