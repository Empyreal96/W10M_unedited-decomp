// IoIsValidIrpStatus 
 
int __fastcall IoIsValidIrpStatus(unsigned int a1)
{
  unsigned int v1; // r1
  unsigned int v3; // r2
  bool v4; // cf

  v1 = HIWORD(a1) & 0xFFF;
  if ( (a1 & 0x20000000) != 0 )
    return 1;
  if ( v1 < 0xEB )
  {
    v3 = a1 >> 30;
    if ( a1 >> 30 )
    {
      if ( v3 != 1 && (v3 != 2 || v1 == 7) )
        return 1;
      v4 = (unsigned __int16)a1 >= 0x400u;
    }
    else
    {
      v4 = (unsigned __int16)a1 >= 0x250u;
    }
    if ( !v4 )
      return 1;
  }
  return 0;
}
