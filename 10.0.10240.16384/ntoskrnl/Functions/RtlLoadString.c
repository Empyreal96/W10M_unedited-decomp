// RtlLoadString 
 
int __fastcall RtlLoadString(int a1, unsigned int a2, _WORD *a3, int a4, _DWORD *a5, _WORD *a6, int *a7, int a8)
{
  BOOL v9; // r8
  int result; // r0
  unsigned int v11; // r4
  unsigned int v12; // r3
  int i; // r1
  int v14; // r2
  unsigned int v15; // [sp+14h] [bp-64h] BYREF
  unsigned int v16; // [sp+18h] [bp-60h]
  _DWORD v17[2]; // [sp+1Ch] [bp-5Ch] BYREF
  _DWORD *v18; // [sp+24h] [bp-54h]
  _WORD *v19; // [sp+28h] [bp-50h]
  _WORD *v20; // [sp+2Ch] [bp-4Ch]
  _WORD *v21; // [sp+30h] [bp-48h]
  int v22; // [sp+34h] [bp-44h]
  _DWORD *v23; // [sp+38h] [bp-40h]
  int *v24[3]; // [sp+3Ch] [bp-3Ch] BYREF
  _DWORD _48[18]; // [sp+48h] [bp-30h] BYREF

  _48[14] = a1;
  _48[16] = a3;
  _48[17] = a4;
  v16 = a2;
  _48[15] = a2;
  v15 = a1;
  v18 = a5;
  v23 = a5;
  v20 = a6;
  v21 = a6;
  v24[1] = a7;
  v22 = a8;
  v17[0] = 0;
  v9 = (a4 & 1) == 0;
  if ( !a1 || !a5 || (a4 & 0xFFFFFFFE) != 0 )
    return -1073741811;
  if ( (a4 & 1) != 0 && (a7 || a8) )
    return -1073741637;
  if ( (unsigned int)a3 > 0xFFFF )
  {
    if ( *a3 )
    {
      a3 = (_WORD *)DownLevelLanguageNameToLangID((int)a3, 2);
      v19 = a3;
      if ( !a3 )
      {
        result = -1073741811;
        v17[1] = -1073741811;
        return result;
      }
      a2 = v16;
    }
    else
    {
      a3 = 0;
      v19 = 0;
    }
  }
  _48[0] = 6;
  _48[1] = (a2 >> 4) + 1;
  _48[2] = a3;
  _48[3] = a2;
  v11 = 0;
  v15 = 0;
  if ( v9 )
  {
    result = LdrResSearchResource(a1, (int)_48, 4u, 1, v17, (int *)&v15, (int)a7, a8);
    v11 = v15;
    if ( result < 0 )
      return result;
    if ( v15 > 0xFFFF )
      result = -1073741701;
  }
  else
  {
    result = LdrpSearchResourceSection_U(a1, (int)_48, 4u, 1, v24);
    if ( result < 0 )
      return result;
    result = LdrpAccessResourceData(a1, (unsigned int)v24[0], (int)v17, 0);
  }
  if ( result >= 0 && v17[0] )
  {
    v12 = 0;
    for ( i = v16 & 0xF; i >= 0; --i )
    {
      v14 = *(unsigned __int16 *)(v17[0] + 2 * v12);
      v12 = (unsigned __int16)(v12 + v14 + 1);
      if ( v9 && v12 > v11 >> 1 )
        return -1073741701;
    }
    if ( v12 && v14 )
      v12 = (unsigned __int16)(v12 - v14);
    *v18 = v17[0] + 2 * v12;
    if ( v20 )
      *v20 = v14;
  }
  return result;
}
