// PopProcessorQueryCoordiantedDependencyNotification 
 
int __fastcall PopProcessorQueryCoordiantedDependencyNotification(int a1, int a2)
{
  int v2; // r3
  int (__fastcall *v4)(_DWORD, int, int); // r3
  int v6; // r3

  v2 = *(_DWORD *)(a1 + 36);
  if ( !v2 )
    return -1073741822;
  v4 = *(int (__fastcall **)(_DWORD, int, int))(v2 + 68);
  if ( !v4 )
    return -1073741822;
  if ( !v4(*(_DWORD *)(a1 + 40), 30, a2) )
    return -1073741637;
  v6 = *(_DWORD *)(a2 + 16);
  if ( v6 )
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(v6 + 88);
  return 0;
}
