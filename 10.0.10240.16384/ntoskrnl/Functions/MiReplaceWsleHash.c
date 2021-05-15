// MiReplaceWsleHash 
 
int __fastcall MiReplaceWsleHash(int result, int a2, int a3, int a4)
{
  int v4; // r5
  _DWORD *v5; // r4
  int v7; // r1
  unsigned int v8; // r4
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r3
  bool v12; // zf
  int varg_r0; // [sp+30h] [bp+8h]
  int varg_r2; // [sp+38h] [bp+10h]

  varg_r0 = result;
  varg_r2 = a3;
  v4 = a2;
  v5 = *(_DWORD **)(result + 92);
  if ( (a2 & 4) != 0 )
  {
    v7 = v5[12];
    if ( !v7 || (v7 & 1) != 0 )
    {
      *(_DWORD *)(v5[13] + 4 * ((unsigned int)(v4 - v5[11]) >> 12)) = a3;
    }
    else
    {
      if ( (v4 & 1) != 0 )
        v8 = v4 & 0xFFFFF000 | 1;
      else
        v8 = 0;
      v9 = (v8 >> 12) & 0x1FF;
      while ( 1 )
      {
        v10 = *(_DWORD *)(v7 + 8 * v9);
        result = 0xFFFFF;
        if ( v8 )
        {
          v11 = (v10 & 1) != 0 ? v10 & 0xFFFFF000 | 1 : 0;
          v12 = v11 == v8;
        }
        else
        {
          v12 = v10 == 0;
        }
        if ( v12 )
          break;
        if ( (unsigned int)++v9 >= 0x200 )
          v9 = 0;
        if ( v9 == ((v8 >> 12) & 0x1FF) )
        {
          v9 = 0xFFFFF;
          break;
        }
      }
      if ( v9 == 0xFFFFF )
        sub_51A2DC();
      *(_DWORD *)(v7 + 8 * v9 + 4) = a3;
    }
  }
  return result;
}
