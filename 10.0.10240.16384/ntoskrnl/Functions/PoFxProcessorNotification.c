// PoFxProcessorNotification 
 
int __fastcall PoFxProcessorNotification(int a1)
{
  int v1; // r3
  int (__fastcall *v2)(_DWORD); // r3

  v1 = *(_DWORD *)(a1 + 36);
  if ( !v1 )
    return -1073741822;
  v2 = *(int (__fastcall **)(_DWORD))(v1 + 68);
  if ( !v2 )
    return -1073741822;
  if ( v2(*(_DWORD *)(a1 + 40)) )
    return 0;
  return -1073741637;
}
