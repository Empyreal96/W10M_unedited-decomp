// IopGetDeviceAttachmentBase 
 
int __fastcall IopGetDeviceAttachmentBase(int result)
{
  int i; // r3
  int v2; // r3

  for ( i = *(_DWORD *)(result + 176); ; i = *(_DWORD *)(v2 + 176) )
  {
    v2 = *(_DWORD *)(i + 24);
    if ( !v2 )
      break;
    result = v2;
  }
  return result;
}
