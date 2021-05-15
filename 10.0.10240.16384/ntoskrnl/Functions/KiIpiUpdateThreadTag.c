// KiIpiUpdateThreadTag 
 
int __fastcall KiIpiUpdateThreadTag(int a1, int a2, _DWORD *a3)
{
  int result; // r0
  unsigned __int8 *v4; // r3
  unsigned int v5; // r2

  if ( *a3 )
    return sub_50F67C();
  v4 = (unsigned __int8 *)(a2 + 2);
  do
  {
    v5 = __ldrex(v4);
    result = __strex(v5 & 0xEF, v4);
  }
  while ( result );
  *(_BYTE *)(a2 + 84) = 0;
  return result;
}
