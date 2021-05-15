// BgLibraryInitialize 
 
int __fastcall BgLibraryInitialize(int a1, int a2)
{
  int result; // r0

  if ( a2 == -1 || (unsigned int)BgpFwGetCurrentIrql(a1) <= 2 )
    result = BgpFwLibraryInitialize(a1, a2);
  else
    result = -1073741823;
  return result;
}
