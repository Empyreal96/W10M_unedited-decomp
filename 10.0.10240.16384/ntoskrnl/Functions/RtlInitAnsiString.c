// RtlInitAnsiString 
 
unsigned int __fastcall RtlInitAnsiString(unsigned int result, unsigned int a2)
{
  _WORD *v2; // r4

  v2 = (_WORD *)result;
  *(_WORD *)result = 0;
  *(_WORD *)(result + 2) = 0;
  *(_DWORD *)(result + 4) = a2;
  if ( a2 )
  {
    result = (unsigned int)strlen(a2);
    if ( result >= 0xFFFF )
      result = 65534;
    v2[1] = result + 1;
    *v2 = result;
  }
  return result;
}
