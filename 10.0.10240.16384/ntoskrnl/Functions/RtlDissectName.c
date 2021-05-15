// RtlDissectName 
 
unsigned int __fastcall RtlDissectName(unsigned int result, _WORD *a2, int a3, int a4)
{
  unsigned int v6; // r4
  unsigned int v7; // r5
  unsigned __int16 *v8; // r2
  int v9; // t1
  __int16 v10; // r3
  __int16 v11; // r3
  unsigned int varg_r0; // [sp+18h] [bp+8h]
  int varg_r2; // [sp+20h] [bp+10h]
  int varg_r3; // [sp+24h] [bp+14h]

  varg_r0 = result;
  varg_r2 = a3;
  varg_r3 = a4;
  result = (unsigned __int16)result;
  *(_WORD *)a3 = 0;
  *(_WORD *)(a3 + 2) = 0;
  *(_DWORD *)(a3 + 4) = 0;
  v6 = 0;
  *(_WORD *)a4 = 0;
  *(_WORD *)(a4 + 2) = 0;
  *(_DWORD *)(a4 + 4) = 0;
  v7 = (unsigned __int16)result >> 1;
  if ( v7 )
  {
    if ( *a2 == 92 )
      v6 = 1;
    result = v6;
    if ( v6 < v7 )
    {
      v8 = &a2[v6];
      do
      {
        v9 = *v8++;
        if ( v9 == 92 )
          break;
        ++v6;
      }
      while ( v6 < v7 );
    }
    v10 = 2 * (v6 - result);
    *(_WORD *)a3 = v10;
    *(_WORD *)(a3 + 2) = v10;
    *(_DWORD *)(a3 + 4) = &a2[result];
    if ( v6 < v7 )
    {
      v11 = 2 * (v7 - v6) - 2;
      *(_WORD *)a4 = v11;
      *(_WORD *)(a4 + 2) = v11;
      *(_DWORD *)(a4 + 4) = &a2[v6 + 1];
    }
  }
  return result;
}
