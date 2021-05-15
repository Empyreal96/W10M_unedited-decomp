// IoGetBaseFileSystemDeviceObject 
 
int __fastcall IoGetBaseFileSystemDeviceObject(_DWORD *a1)
{
  int v2; // r3
  int result; // r0

  v2 = a1[2];
  if ( !v2 || (result = *(_DWORD *)(v2 + 8)) == 0 )
  {
    if ( (a1[11] & 0x800) != 0 || !*(_DWORD *)(a1[1] + 36) )
      result = a1[1];
    else
      result = sub_546B08();
  }
  return result;
}
