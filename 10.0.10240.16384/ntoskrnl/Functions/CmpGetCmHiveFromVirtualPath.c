// CmpGetCmHiveFromVirtualPath 
 
int __fastcall CmpGetCmHiveFromVirtualPath(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v6[4]; // [sp+0h] [bp-10h] BYREF

  v6[1] = a3;
  v6[2] = a4;
  result = CmpGetVirtualizationIDFromFullVirtualPath(a1, v6);
  if ( result >= 0 )
    result = CmpGetMappingHiveForString(v6, a2);
  return result;
}
