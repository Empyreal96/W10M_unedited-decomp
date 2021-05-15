// PopMarshalSettingValues 
 
int __fastcall PopMarshalSettingValues(int a1, _DWORD *a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v8; // r6
  int v9; // r4
  unsigned int i; // r1
  int *v11; // r2
  int v12; // r0
  _DWORD *v13; // r2
  unsigned int j; // r4
  int v15; // r1
  unsigned int v16; // r4
  int *v17; // r5
  int v18; // r0
  int v19; // t1
  int v21; // [sp+4h] [bp-3Ch]
  int v22; // [sp+10h] [bp-30h] BYREF
  int v23; // [sp+14h] [bp-2Ch]
  int v24; // [sp+18h] [bp-28h]

  v22 = 0;
  v23 = 0;
  v24 = 0;
  v8 = 0;
  v9 = dword_61EC0C;
  for ( i = 0; i < 3; ++i )
  {
    if ( (*(_DWORD *)(a1 + 36) & 8) != 0 )
    {
      v11 = &v22 + i;
      *v11 = *(_DWORD *)(a1 + 4 * v9 + 48);
    }
    else
    {
      v12 = *(_DWORD *)(a1 + 4 * i + 48);
      v11 = &v22 + i;
      *v11 = v12;
      if ( i == 2 && !v12 )
        v24 = v23;
    }
    v8 += 8;
    v13 = (_DWORD *)*v11;
    if ( v13 )
    {
      ++*v13;
      v8 += v13[1];
    }
  }
  if ( a3 >= v8 )
  {
    for ( j = 0; j < 3; ++j )
    {
      v15 = *(&v22 + j);
      if ( v15 )
      {
        *a2 = *(_DWORD *)(v15 + 8);
        a2[1] = *(_DWORD *)(v15 + 4);
        memmove((int)(a2 + 2), v15 + 12, *(_DWORD *)(v15 + 4));
      }
      else
      {
        *a2 = 0;
        a2[1] = 0;
      }
      a2 = (_DWORD *)((char *)a2 + a2[1] + 8);
    }
    *a4 = v8;
    v21 = 0;
  }
  else
  {
    v21 = -1073741789;
  }
  v16 = 0;
  v17 = &v22;
  while ( v16 < 3 )
  {
    v19 = *v17++;
    v18 = v19;
    if ( v19 )
      PopUnreferencePowerSetting(v18);
    ++v16;
  }
  return v21;
}
