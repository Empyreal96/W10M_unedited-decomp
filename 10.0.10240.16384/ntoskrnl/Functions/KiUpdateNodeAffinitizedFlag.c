// KiUpdateNodeAffinitizedFlag 
 
int __fastcall KiUpdateNodeAffinitizedFlag(int result)
{
  int v1; // r2
  unsigned int v2; // r1

  if ( *(_DWORD *)(result + 356) == dword_681D78[*(unsigned __int16 *)(result + 360)] )
  {
    v1 = 1;
  }
  else
  {
    if ( (unsigned __int16)KeNumberNodes > 1u )
      return sub_50EB78();
    v1 = 0;
  }
  if ( v1 == ((*(unsigned __int8 *)(result + 2) >> 3) & 1) )
  {
    do
      v2 = __ldrex((unsigned int *)result);
    while ( __strex(v2 ^ 0x80000, (unsigned int *)result) );
  }
  return result;
}
