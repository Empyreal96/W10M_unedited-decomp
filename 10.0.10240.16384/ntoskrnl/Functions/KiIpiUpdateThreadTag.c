// KiIpiUpdateThreadTag 
 
void __fastcall KiIpiUpdateThreadTag(int a1, int a2, _DWORD *a3)
{
  unsigned __int8 *v3; // r3
  unsigned int v4; // r2

  if ( *a3 )
  {
    sub_50F67C();
  }
  else
  {
    v3 = (unsigned __int8 *)(a2 + 2);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 & 0xEF, v3) );
    *(_BYTE *)(a2 + 84) = 0;
  }
}
