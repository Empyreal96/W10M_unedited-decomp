// LocalGetStringForControl 
 
int __fastcall LocalGetStringForControl(int a1, int a2, char **a3)
{
  int v4; // r5
  __int16 **v8; // r4
  unsigned int i; // r6
  int v10; // r3
  int v11; // r2
  unsigned int v12; // r4
  char *v13; // r0
  char v14[544]; // [sp-4h] [bp-220h] BYREF

  v4 = 0;
  if ( !a3 )
    return 87;
  v8 = &ControlLookup;
  *a3 = 0;
  for ( i = 0; i < 6; ++i )
  {
    if ( ((unsigned int)v8[3] & a2) == a2 )
    {
      v10 = (int)v8[1];
      if ( (unsigned int)(v10 + v4) >= 0x100 )
        return 87;
      if ( (a1 & (unsigned int)v8[2]) != 0 )
      {
        wcsncpy_s(&v14[2 * v4], 256 - v4, (char *)*v8, v10);
        v4 += (int)v8[1];
      }
    }
    v8 += 4;
  }
  v11 = 2 * v4;
  if ( (unsigned int)(2 * v4) >= 0x200 )
    _report_rangecheckfailure();
  *(_WORD *)&v14[v11] = 0;
  if ( v4 )
  {
    v12 = v11 + 2;
    v13 = (char *)SddlpAlloc(v11 + 2);
    *a3 = v13;
    if ( !v13 )
      return 8;
    wcscpy_s(v13, v12 >> 1, v14);
  }
  return 0;
}
