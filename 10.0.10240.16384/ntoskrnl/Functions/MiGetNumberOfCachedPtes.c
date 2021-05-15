// MiGetNumberOfCachedPtes 
 
int __fastcall MiGetNumberOfCachedPtes(int a1)
{
  int v1; // r1
  int v2; // r2
  int v3; // r0
  int v4; // r3

  v1 = *(_DWORD *)(a1 + 44);
  v2 = 0;
  if ( v1 )
  {
    v3 = (unsigned __int16)KeNumberNodes;
    if ( KeNumberNodes )
    {
      do
      {
        v4 = *(_DWORD *)(v1 + 64);
        v1 += 72;
        v2 += v4;
        --v3;
      }
      while ( v3 );
    }
  }
  return v2;
}
