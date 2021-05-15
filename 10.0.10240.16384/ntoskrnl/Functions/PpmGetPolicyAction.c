// PpmGetPolicyAction 
 
int __fastcall PpmGetPolicyAction(__int64 *a1, _DWORD *a2)
{
  int result; // r0
  __int64 v3; // kr00_8

  v3 = *a1;
  result = *((_DWORD *)a1 + 1);
  if ( result & 0x3C0 | v3 & 0x700 )
  {
    if ( (result & 0x40) != 0 )
      *a2 |= 0x40u;
    if ( (v3 & 0x100) != 0 )
      *a2 |= 0x800u;
    if ( (v3 & 0x400) != 0 )
      *a2 |= 0x100u;
    if ( (v3 & 0x200) != 0 )
      *a2 |= 0x80u;
    if ( (result & 0x100) != 0 )
      return sub_7E8C1C();
    if ( (result & 0x80) != 0 )
      *a2 |= 0x400u;
    if ( (result & 0x200) != 0 )
      *a2 |= 0x1000u;
  }
  if ( result & 0x100 | v3 & 0xEC0 )
    *a2 |= 0xAu;
  if ( (v3 & 0x30000) != 0 )
    *a2 |= 0xCu;
  if ( (v3 & 0x30DC0) != 0 )
    *a2 |= 8u;
  if ( (result & 0x3F) != 0 )
    *a2 |= 0x20u;
  if ( (v3 & 0xD8000000) != 0 )
    *a2 |= 1u;
  if ( (v3 & 0x1000) != 0 )
    *a2 |= 0x10u;
  return result;
}
