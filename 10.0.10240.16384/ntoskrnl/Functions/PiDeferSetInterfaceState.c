// PiDeferSetInterfaceState 
 
int __fastcall PiDeferSetInterfaceState(int a1, unsigned __int16 *a2)
{
  int v3; // r0

  v3 = ExAllocatePoolWithTag(1, 16, 538996816);
  if ( v3 )
  {
    if ( IopAllocateUnicodeString(v3 + 8, *a2) < 0 )
      JUMPOUT(0x7C9550);
    JUMPOUT(0x7C955C);
  }
  return sub_7C954C();
}
