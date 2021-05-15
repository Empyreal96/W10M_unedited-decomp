// ObpCloseDirectoryObject 
 
int __fastcall ObpCloseDirectoryObject(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a4 == 1 && (*(_DWORD *)(a2 + 168) & 1) != 0 )
    result = ObpRemoveNamespaceFromTable(a2);
  return result;
}
