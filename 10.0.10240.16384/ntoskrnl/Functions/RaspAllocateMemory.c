// RaspAllocateMemory 
 
int __fastcall RaspAllocateMemory(int a1, int a2)
{
  int result; // r0

  if ( RaspProvidesWorkspace(a2) )
    return sub_54DBD4();
  result = BgpFwAllocateMemory(a1);
  if ( result )
    *(_DWORD *)(a2 + 8) += a1;
  return result;
}
