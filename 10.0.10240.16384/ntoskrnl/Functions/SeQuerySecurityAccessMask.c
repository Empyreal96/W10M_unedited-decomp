// SeQuerySecurityAccessMask 
 
int __fastcall SeQuerySecurityAccessMask(int result, _DWORD *a2)
{
  *a2 = 0;
  if ( (result & 0x10000) != 0 )
    return sub_7DD9A4();
  if ( (result & 0x17) != 0 )
    *a2 |= 0x20000u;
  if ( (result & 0x20) != 0 )
    *a2 |= 0x20000u;
  if ( (result & 0x40) != 0 )
    *a2 |= 0x20000u;
  if ( (result & 0x80) != 0 )
    *a2 |= 0x20000u;
  if ( (result & 8) != 0 )
    *a2 |= 0x1000000u;
  return result;
}
