// __rt_udiv 
 
int __fastcall _rt_udiv(unsigned int a1, unsigned int a2)
{
  signed int v2; // r0
  signed int v3; // r3
  bool v4; // cc
  int (__fastcall *v5)(_DWORD); // r3
  int result; // r0

  if ( !a1 )
    __brkdiv0();
  v2 = __clz(a1);
  v3 = __clz(a2);
  v4 = v2 < v3;
  v5 = (int (__fastcall *)(_DWORD))((char *)&loc_423E70 - 2 * (v2 - v3) + -8 * (v2 - v3));
  result = 0;
  if ( !v4 )
    result = v5(0);
  return result;
}
