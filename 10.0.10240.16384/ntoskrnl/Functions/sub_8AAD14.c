// sub_8AAD14 
 
int __fastcall sub_8AAD14(int a1)
{
  int result; // r0

  result = IoGetDeviceAttachmentBaseRef(a1);
  if ( !result || (*(_DWORD *)(result + 28) & 0x1000) == 0 )
    result = 0;
  return result;
}
