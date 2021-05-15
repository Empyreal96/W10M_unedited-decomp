// sub_56449C 
 
int __fastcall sub_56449C(unsigned int a1, _DWORD *a2)
{
  unsigned int v3; // r3

  if ( *a2 + a1 < 0x1FFFC )
    return 1;
  if ( a1 >= 0x1FFFC )
    v3 = 0;
  else
    v3 = 131068 - a1;
  *a2 = v3;
  return 0;
}
