// MiCfgEliminateZeroPages 
 
int __fastcall MiCfgEliminateZeroPages(int result, unsigned int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r5
  unsigned int *v5; // r10
  unsigned int v6; // r4
  int v7; // r9
  unsigned int i; // r8
  _DWORD *v9; // r6
  _DWORD *v10; // r1
  unsigned int varA8[45]; // [sp+14h] [bp-A8h] BYREF
  unsigned int varg_r1; // [sp+C8h] [bp+Ch]
  unsigned int varg_r2; // [sp+CCh] [bp+10h]
  int varg_r3; // [sp+D0h] [bp+14h]

  varA8[44] = result;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = a2;
  varg_r1 = a2;
  v5 = (unsigned int *)result;
  v6 = 0;
  varA8[0] = 0;
  v7 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  for ( i = a3 >> 12; i; --i )
  {
    v9 = (_DWORD *)v4;
    v10 = (_DWORD *)(v4 + 4092);
    do
    {
      if ( *v9 | *v10 )
        break;
      ++v9;
      --v10;
    }
    while ( v9 <= v10 );
    if ( v9 > v10 )
    {
      varA8[v6 + 1] = v4;
      v6 = varA8[0] + 1;
      varA8[0] = v6;
      if ( v6 == 32 )
      {
        result = MiConvertAndFlushWsleVas(v5, varA8);
        v6 = 0;
        varA8[0] = 0;
      }
    }
    v7 += 4;
    v4 += 4096;
    varg_r1 = v4;
  }
  if ( v6 )
    result = MiConvertAndFlushWsleVas(v5, varA8);
  return result;
}
