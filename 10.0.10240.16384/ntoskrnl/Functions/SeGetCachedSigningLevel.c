// SeGetCachedSigningLevel 
 
int __fastcall SeGetCachedSigningLevel(int a1, int a2, int a3)
{
  if ( !dword_61D888 )
    return -1073741823;
  if ( a1 && a2 && a3 )
    return dword_61D888();
  return -1073741811;
}
