// sub_7FE670 
 
void __fastcall sub_7FE670(int a1, int a2)
{
  int v2; // r8
  int v3; // r3

  v3 = *(_DWORD *)(v2 + 28);
  if ( v3 && a2 != v3 )
  {
    CmpLockRegistry();
    JUMPOUT(0x734036);
  }
  JUMPOUT(0x733E68);
}
