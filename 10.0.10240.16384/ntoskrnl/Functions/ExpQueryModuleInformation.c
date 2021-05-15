// ExpQueryModuleInformation 
 
int __fastcall ExpQueryModuleInformation(int a1, _DWORD *a2, int a3, unsigned int *a4)
{
  int v5; // r8
  int v6; // r0
  unsigned int v7; // r9
  _DWORD *v8; // r6
  int v9; // r5
  unsigned int v10; // r4
  unsigned int v11; // r3
  _BYTE *v13; // r3
  int v15; // [sp+4h] [bp-5Ch]
  _WORD v17[2]; // [sp+38h] [bp-28h] BYREF
  unsigned int v18; // [sp+3Ch] [bp-24h]
  int varg_r0; // [sp+68h] [bp+8h]
  _DWORD *varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  unsigned int *varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  v15 = a3;
  varg_r2 = a3;
  varg_r1 = a2;
  v5 = 0;
  v6 = 0;
  v7 = 4;
  v8 = a2 + 1;
  v9 = PsLoadedModuleList;
  v10 = a3;
  while ( (int *)v9 != &PsLoadedModuleList )
  {
    v11 = v7 + 284;
    if ( v7 + 284 < v7 )
      return -1073741823;
    v7 += 284;
    if ( v10 >= v11 )
    {
      v8[2] = *(_DWORD *)(v9 + 24);
      v8[3] = *(_DWORD *)(v9 + 32);
      v8[4] = *(_DWORD *)(v9 + 52);
      *((_WORD *)v8 + 12) = *(_WORD *)(v9 + 56);
      *((_WORD *)v8 + 10) = v5;
      *((_WORD *)v8 + 11) = 0;
      v18 = (unsigned int)(v8 + 7);
      v17[0] = 0;
      v17[1] = 256;
      v6 = RtlUnicodeStringToAnsiString(v17, v9 + 36, 0);
      if ( v6 >= 0 || v6 == -2147483643 )
      {
        v13 = (_BYTE *)(v17[0] + v18);
        while ( (unsigned int)v13 > v18 )
        {
          if ( !*--v13 )
            break;
          if ( *v13 == 92 )
          {
            LOWORD(v13) = (_WORD)v13 + 1;
            break;
          }
        }
        *((_WORD *)v8 + 13) = (_WORD)v13 - v18;
      }
      else
      {
        *((_BYTE *)v8 + 28) = 0;
        *((_WORD *)v8 + 13) = 0;
      }
      v10 = v15;
      v8 += 71;
    }
    else
    {
      if ( a4 )
        *a4 = v11;
      v6 = -1073741820;
    }
    ++v5;
    v9 = *(_DWORD *)v9;
  }
  if ( a4 )
    *a4 = v7;
  if ( v10 < 4 )
    return -1073741820;
  *a2 = v5;
  return v6;
}
