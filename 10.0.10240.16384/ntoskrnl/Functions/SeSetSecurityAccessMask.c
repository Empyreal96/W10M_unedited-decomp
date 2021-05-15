// SeSetSecurityAccessMask 
 
int __fastcall SeSetSecurityAccessMask(int result, _DWORD *a2)
{
  *a2 = 0;
  if ( (result & 0x10000) != 0 )
    return sub_7DCD28();
  if ( (result & 0x13) != 0 )
    *a2 |= 0x80000u;
  if ( (result & 4) != 0 )
    *a2 |= 0x40000u;
  if ( (result & 0x20) != 0 )
    *a2 |= 0x40000u;
  if ( (result & 0x80) != 0 )
    *a2 |= 0x40000u;
  if ( (result & 0x40) != 0 )
    *a2 |= 0x1000000u;
  if ( (result & 8) != 0 )
    *a2 |= 0x1000000u;
  if ( (result & 0xF8) != 0 && (result & 0x50000000) != 0 )
    *a2 |= 0x1000000u;
  return result;
}
