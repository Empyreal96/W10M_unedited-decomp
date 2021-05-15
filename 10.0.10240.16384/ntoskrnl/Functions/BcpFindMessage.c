// BcpFindMessage 
 
int __fastcall BcpFindMessage(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // r0
  unsigned __int16 *v5; // r4
  unsigned int v7; // r6
  _WORD *v8; // r5
  int v9; // r3

  v4 = ResFwFindMessage(a1, a2, a3, a4);
  v5 = (unsigned __int16 *)v4;
  if ( !v4 )
    return sub_975DC8();
  v7 = 0;
  v8 = (_WORD *)v4;
  while ( v7 < wcslen(v5) )
  {
    v9 = (unsigned __int16)*v8;
    if ( v9 == 13 || v9 == 10 )
      *v8 = 0;
    ++v7;
    ++v8;
  }
  return (int)v5;
}
