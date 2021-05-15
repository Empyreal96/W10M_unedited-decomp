// AlpcpReferenceReplyTargetPorts 
 
int __fastcall AlpcpReferenceReplyTargetPorts(int a1, int a2)
{
  int v2; // r5
  int result; // r0

  v2 = a1;
  if ( a1 && !ObReferenceObjectSafe(a1) )
    v2 = 0;
  if ( a2 && !ObReferenceObjectSafe(a2) )
    a2 = 0;
  if ( !v2 )
    JUMPOUT(0x7F7C0E);
  if ( !a2 )
    JUMPOUT(0x7F7C08);
  if ( (*(_DWORD *)(v2 + 244) & 0x20) != 0 || (*(_DWORD *)(a2 + 244) & 0x20) != 0 )
    result = sub_7F7C00();
  else
    result = 0;
  return result;
}
