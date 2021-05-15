// LdrpGenericProcessRelocation 
 
int __fastcall LdrpGenericProcessRelocation(unsigned __int16 *a1, int a2, int a3)
{
  unsigned int v3; // r5
  int result; // r0
  _DWORD *v5; // r1

  v3 = *a1;
  result = 1;
  v5 = (_DWORD *)(a2 + (v3 & 0xFFF));
  if ( v3 >> 12 )
  {
    if ( v3 >> 12 == 3 )
      *v5 += a3;
    else
      result = sub_54DFC0(1, v5);
  }
  return result;
}
