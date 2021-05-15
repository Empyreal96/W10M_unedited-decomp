// WmipStaticInstanceNameSize 
 
int __fastcall WmipStaticInstanceNameSize(_DWORD *a1)
{
  int v2; // r4
  int v4; // r6
  int v5; // r3
  unsigned __int16 **v6; // r7
  unsigned __int16 *v7; // t1

  v2 = a1[10];
  if ( !v2 )
  {
    v4 = a1[9];
    v5 = a1[2];
    v2 = 4 * v4;
    if ( (v5 & 1) != 0 )
    {
      v2 += 2 * (wcslen((unsigned __int16 *)(a1[12] + 4)) + 8) * v4;
    }
    else if ( (v5 & 2) != 0 && v4 )
    {
      v6 = (unsigned __int16 **)a1[12];
      do
      {
        v7 = *v6++;
        v2 += 2 * (wcslen(v7) + 2);
        --v4;
      }
      while ( v4 );
    }
    a1[10] = v2;
  }
  return v2;
}
