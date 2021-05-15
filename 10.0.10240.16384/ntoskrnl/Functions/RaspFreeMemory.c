// RaspFreeMemory 
 
int __fastcall RaspFreeMemory(int a1, int a2)
{
  int result; // r0
  int v3; // r2

  result = RaspProvidesWorkspace(a2);
  if ( !result )
    result = BgpFwFreeMemory(v3);
  return result;
}
