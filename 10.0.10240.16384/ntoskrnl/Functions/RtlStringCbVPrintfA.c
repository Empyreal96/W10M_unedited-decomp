// RtlStringCbVPrintfA 
 
int __fastcall RtlStringCbVPrintfA(_BYTE *a1, unsigned int a2)
{
  int v2; // r5
  unsigned int v4; // r4
  int v5; // r0

  v2 = 0;
  if ( !a2 || a2 > 0x7FFFFFFF )
    v2 = -1073741811;
  if ( v2 < 0 )
  {
    if ( a2 )
      *a1 = 0;
  }
  else
  {
    v4 = a2 - 1;
    v2 = 0;
    v5 = vsnprintf(a1, a2 - 1);
    if ( v5 < 0 || v5 > v4 )
    {
      a1[v4] = 0;
      v2 = -2147483643;
    }
    else if ( v5 == v4 )
    {
      return sub_529C84();
    }
  }
  return v2;
}
