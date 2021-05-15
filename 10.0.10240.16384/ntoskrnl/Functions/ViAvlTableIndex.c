// ViAvlTableIndex 
 
int __fastcall ViAvlTableIndex(int a1)
{
  int result; // r0

  if ( *(_DWORD *)(a1 + 12) == 1 )
    result = 0;
  else
    result = sub_518C00();
  return result;
}
