// ViCheckMdlLength 
 
unsigned int __fastcall ViCheckMdlLength(_DWORD *a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  _DWORD *v5; // r1
  unsigned int result; // r0
  unsigned int v7; // r4
  unsigned int v8; // r3
  int v9; // r3
  unsigned int v10; // r3
  _DWORD *varg_r0; // [sp+10h] [bp+8h]
  unsigned int varg_r2; // [sp+18h] [bp+10h]
  unsigned int varg_r3; // [sp+1Ch] [bp+14h]
  int varg_r3a; // [sp+1Ch] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a1;
  result = a5;
  v7 = a4;
  if ( !a5 )
    return 0;
  if ( v5 )
  {
    do
    {
      v8 = v5[5];
      if ( !v7 && a3 <= v8 )
        break;
      v5 = (_DWORD *)*v5;
      v7 = (__PAIR64__(v7, a3) - v8) >> 32;
      a3 -= v8;
    }
    while ( v5 );
    while ( v5 && result )
    {
      v9 = v5[5];
      v5 = (_DWORD *)*v5;
      v10 = v9 - a3;
      if ( v10 >= result )
        v10 = result;
      result -= v10;
      a3 = 0;
      varg_r3a = 0;
    }
  }
  return result;
}
