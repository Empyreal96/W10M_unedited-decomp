// KiSelectIdealProcessor 
 
unsigned int __fastcall KiSelectIdealProcessor(int a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r6
  unsigned int v5; // r5
  unsigned int v6; // r1

  v4 = *(_DWORD *)(a1 + 284);
  v3 = *(_DWORD *)(a1 + 280);
  if ( v3 != v4 )
  {
    v5 = *(unsigned __int8 *)(a1 + 270);
    do
    {
      a2 += v5;
      if ( a2 > v4 )
      {
        v6 = a2 - v3 + 1;
        if ( !*(_BYTE *)(a1 + 270) )
          __brkdiv0();
        a2 = v6 % v5 + v3;
      }
    }
    while ( ((*a3 >> a2) & 1) == 0 );
    v3 = a2;
  }
  return v3;
}
