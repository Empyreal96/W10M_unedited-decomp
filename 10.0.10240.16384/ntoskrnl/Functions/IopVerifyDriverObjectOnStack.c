// IopVerifyDriverObjectOnStack 
 
int __fastcall IopVerifyDriverObjectOnStack(int a1)
{
  int i; // r0
  int v2; // r1

  for ( i = IopGetDeviceAttachmentBase(a1); ; i = *(_DWORD *)(i + 16) )
  {
    if ( !i )
      return 0;
    if ( *(_DWORD *)(i + 8) == v2 )
      break;
  }
  return 1;
}
