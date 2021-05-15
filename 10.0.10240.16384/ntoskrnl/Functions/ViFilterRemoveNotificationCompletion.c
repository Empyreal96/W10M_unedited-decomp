// ViFilterRemoveNotificationCompletion 
 
int __fastcall ViFilterRemoveNotificationCompletion(int a1, int a2)
{
  if ( *(_BYTE *)(a2 + 33) )
    KeSetEvent(*(_DWORD *)(a1 + 40) + 40, 0, 0);
  return -1073741802;
}
