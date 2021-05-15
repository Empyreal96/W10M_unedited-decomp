// AslpFileGetChecksum 
 
int __fastcall AslpFileGetChecksum(unsigned int *a1, int a2)
{
  unsigned int v3; // r4
  int v4; // r5
  unsigned int v5; // r2
  unsigned int v6; // r3
  int *v7; // r0
  unsigned int i; // r1
  int v9; // t1
  bool v10; // zf

  v3 = 4096;
  v4 = 512;
  v5 = 0;
  v6 = *(_DWORD *)(a2 + 8);
  if ( v6 >= 0x1000 )
  {
    if ( v6 < 0x1200 )
      v4 = v6 - 4096;
  }
  else
  {
    v4 = 0;
    v3 = *(_DWORD *)(a2 + 8);
  }
  if ( v3 >= 4 )
  {
    v7 = (int *)(*(_DWORD *)(a2 + 16) + v4);
    for ( i = 0; i < v3 >> 2; ++i )
    {
      v9 = *v7++;
      v10 = ((v9 + v5) & 1) == 0;
      v5 = (v9 + v5) >> 1;
      if ( !v10 )
        v5 |= 0x80000000;
    }
  }
  *a1 = v5;
  return 0;
}
