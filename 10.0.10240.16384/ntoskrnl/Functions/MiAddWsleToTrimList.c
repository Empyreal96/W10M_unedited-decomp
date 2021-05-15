// MiAddWsleToTrimList 
 
int __fastcall MiAddWsleToTrimList(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  unsigned int v4; // r5
  int v6; // r3
  _DWORD *v8; // r7
  int v9; // t1
  unsigned int v10; // r1
  int *v11; // r2
  int v12; // t1
  int result; // r0
  _DWORD *varg_r0; // [sp+20h] [bp+8h]
  int varg_r1; // [sp+24h] [bp+Ch]
  unsigned int *varg_r3; // [sp+2Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v4 = *a1;
  v6 = 0;
  if ( *a1 )
  {
    v8 = a1;
    while ( 1 )
    {
      v9 = v8[1];
      ++v8;
      if ( v9 == a2 )
        break;
      if ( ++v6 >= v4 )
        goto LABEL_5;
    }
    result = 0;
  }
  else
  {
LABEL_5:
    if ( *a4 == 0xFFFFF )
      *a4 = v4;
    if ( (a3 & 0x80) == 0 )
    {
      v10 = *a4;
      v11 = &a1[v4];
      do
      {
        v12 = *v11--;
        --v4;
        v11[2] = v12;
      }
      while ( v4 != v10 );
    }
    a1[v4 + 1] = a2;
    ++*a1;
    result = 1;
  }
  return result;
}
