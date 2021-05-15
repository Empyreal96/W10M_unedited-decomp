// IopDispatchSessionNotifications 
 
int __fastcall IopDispatchSessionNotifications(int a1, int a2)
{
  int v4; // r2
  int v5; // r1
  int result; // r0

  v4 = *(_DWORD *)(a2 + 16);
  v5 = *(_DWORD *)(a1 + 24);
  result = IopSessionEventType[v4];
  if ( (!v5 || v5 == *(_DWORD *)(a2 + 32)) && (*(_DWORD *)(a1 + 28) & result) != 0 )
    result = (*(int (__fastcall **)(_DWORD, _DWORD))(a1 + 12))(*(_DWORD *)(a2 + 32), *(_DWORD *)(a1 + 20));
  return result;
}
