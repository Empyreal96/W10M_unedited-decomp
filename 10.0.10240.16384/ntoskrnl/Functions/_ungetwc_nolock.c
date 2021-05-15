// _ungetwc_nolock 
 
int __fastcall ungetwc_nolock(int a1, unsigned int *a2)
{
  int result; // r0
  unsigned int v4; // r2
  unsigned int v5; // r5
  unsigned int v6; // r3
  _WORD *v7; // r3

  if ( !a2 )
  {
    PopPoCoalescinCallback();
    return 0xFFFF;
  }
  result = 0xFFFF;
  if ( a1 != 0xFFFF )
  {
    v4 = a2[3];
    if ( (v4 & 1) != 0 || (v4 & 0x80) != 0 && (v4 & 2) == 0 )
    {
      v5 = a2[2] + 2;
      if ( *a2 < v5 )
      {
        if ( a2[1] || a2[6] < 2 )
          return result;
        *a2 = v5;
      }
      v6 = *a2;
      if ( (v4 & 0x40) != 0 )
      {
        *a2 = v6 - 2;
        if ( *(unsigned __int16 *)(v6 - 2) != a1 )
        {
          *a2 = v6;
          return result;
        }
      }
      else
      {
        v7 = (_WORD *)(v6 - 2);
        *a2 = (unsigned int)v7;
        *v7 = a1;
      }
      result = a1;
      a2[1] += 2;
      a2[3] = a2[3] & 0xFFFFFFEF | 1;
    }
  }
  return result;
}
