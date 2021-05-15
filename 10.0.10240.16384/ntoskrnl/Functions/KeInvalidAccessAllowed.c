// KeInvalidAccessAllowed 
 
int __fastcall KeInvalidAccessAllowed(int a1)
{
  int v1; // r2
  int (*v2)(); // r1

  if ( !a1 )
    return 0;
  v1 = 0;
  if ( (*(_DWORD *)(a1 + 132) & 0x1F) == 19 )
    v2 = ExpInterlockedPopEntrySListFault;
  else
    v2 = (int (*)())KeUserPopEntrySListFault;
  if ( *(int (**)())(a1 + 128) == v2 )
    v1 = 1;
  return v1;
}
