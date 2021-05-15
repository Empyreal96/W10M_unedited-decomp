// sub_4DAE74 
 
int __fastcall sub_4DAE74(unsigned __int16 *a1)
{
  int result; // r0
  unsigned int v3; // r1
  unsigned int v4; // r2

  result = 0;
  if ( a1 )
  {
    v3 = *a1;
    if ( (v3 & 1) != 0 || (v4 = a1[1], (v4 & 1) != 0) || v3 > v4 || a1[1] == 0xFFFF )
    {
      result = -1073741811;
    }
    else if ( !*((_DWORD *)a1 + 1) )
    {
      result = sub_519430(0);
    }
  }
  return result;
}
