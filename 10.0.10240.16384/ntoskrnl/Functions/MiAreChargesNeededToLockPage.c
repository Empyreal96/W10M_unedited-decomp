// MiAreChargesNeededToLockPage 
 
int __fastcall MiAreChargesNeededToLockPage(int a1)
{
  int v1; // r1
  int v2; // r3

  v1 = *(unsigned __int16 *)(a1 + 16);
  v2 = *(_DWORD *)(a1 + 12) & 0x3FFFFFFF;
  if ( *(_WORD *)(a1 + 16) )
  {
    if ( v1 != 1 )
      return sub_50DA1C(0, v1, a1, v2);
    if ( !v2 )
      JUMPOUT(0x50DA28);
  }
  return 1;
}
