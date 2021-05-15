// CmpFindPathByName 
 
int __fastcall CmpFindPathByName(int a1, int *a2, int a3, _DWORD *a4, int (__fastcall ***a5)(void *))
{
  int v7; // r4
  _WORD *v8; // r6
  unsigned int v9; // r5
  int v11; // r1
  int (__fastcall **v12)(void *); // r8
  int v13; // r0
  unsigned int v14; // r7
  unsigned int v15; // r2
  int v16; // r4
  int (__fastcall **v17)(void *); // r3
  int v18; // [sp+0h] [bp-38h] BYREF
  int v19; // [sp+4h] [bp-34h] BYREF
  int v20; // [sp+8h] [bp-30h]
  __int16 v21; // [sp+10h] [bp-28h] BYREF
  _WORD *v22; // [sp+14h] [bp-24h]

  v18 = -1;
  *a4 = -1;
  *a5 = 0;
  if ( a3 )
  {
    *(_WORD *)a3 = 0;
    *(_DWORD *)(a3 + 4) = 0;
  }
  v8 = (_WORD *)a2[1];
  v7 = *a2;
  v20 = *a2;
  v9 = (unsigned __int16)v20;
  if ( (_WORD)v20 )
  {
    if ( !a1 )
    {
      v12 = (int (__fastcall **)(void *))CmpMasterHive;
      do
      {
        if ( *v8 != 92 )
          break;
        v9 = (unsigned __int16)(v9 - 2);
        ++v8;
        LOWORD(v20) = v9;
      }
      while ( v9 );
      while ( v9 && *v8 != 92 )
      {
        ++v8;
        v9 = (unsigned __int16)(v9 - 2);
        LOWORD(v20) = v9;
      }
      goto LABEL_17;
    }
    v11 = *(_DWORD *)(a1 + 24);
    v12 = *(int (__fastcall ***)(void *))(a1 + 20);
    *a5 = v12;
    *a4 = v11;
    while ( 1 )
    {
      if ( v9 )
      {
        do
        {
          if ( *v8 != 92 )
            break;
          v9 = (unsigned __int16)(v9 - 2);
          ++v8;
          LOWORD(v20) = v9;
        }
        while ( v9 );
        v7 = v20;
      }
      if ( a3 )
      {
        *(_DWORD *)a3 = v7;
        *(_DWORD *)(a3 + 4) = v8;
      }
      if ( !v9 )
        break;
      v13 = v12[1](v12);
      if ( !v13 )
        return 0;
      v14 = 0;
      v21 = 0;
      v22 = v8;
      v15 = 0;
      do
      {
        if ( v8[v15 >> 1] == 92 )
          break;
        v14 = (unsigned __int16)(v15 + 2);
        v21 = v15 + 2;
        v15 = v14;
      }
      while ( v14 < v9 );
      if ( (*(_WORD *)(v13 + 2) & 2) != 0 )
      {
        v16 = *(_DWORD *)(v13 + 28);
        v17 = v12;
        v12 = *(int (__fastcall ***)(void *))(v13 + 32);
        ((void (__fastcall *)(int (__fastcall **)(void *), int *))v17[2])(v17, &v18);
        v13 = ((int (__fastcall *)(int (__fastcall **)(void *), int, int *))v12[1])(v12, v16, &v18);
        if ( !v13 )
          return 0;
      }
      CmpFindSubKeyByNameWithStatus((int)v12, v13, (int)&v21, &v19);
      ((void (__fastcall *)(int (__fastcall **)(void *), int *))v12[2])(v12, &v18);
      if ( v19 == -1 )
        return 0;
      *a4 = v19;
      *a5 = v12;
      v9 = (unsigned __int16)(v9 - v14);
      v8 += v14 >> 1;
      LOWORD(v20) = v9;
      if ( !v9 )
        return 1;
LABEL_17:
      v7 = v20;
    }
    return 1;
  }
  if ( a1 )
  {
    *a5 = *(int (__fastcall ***)(void *))(a1 + 20);
    *a4 = *(_DWORD *)(a1 + 24);
    return 1;
  }
  return 0;
}
