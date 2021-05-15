// PiDqPropertyCallback 
 
int __fastcall PiDqPropertyCallback(int *a1, int *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *v6; // r9
  _DWORD *v7; // r5
  int v8; // r7
  unsigned int v10; // r10
  int v11; // r3
  int v12; // r2
  int v13; // r4
  int v15; // r5
  _DWORD *v16; // r9
  int v17; // r0
  int v18; // r1
  _DWORD *v19; // r4
  int v20; // r0
  int v21; // r1
  int v22; // r2
  int v23; // r3
  _DWORD *v24; // r8
  int v25; // r2
  int v26; // r3
  int v27; // [sp+18h] [bp-28h]

  v6 = a3;
  v7 = a4;
  v8 = 0;
  v10 = 0;
  if ( !a1[3] )
  {
LABEL_2:
    v11 = a2[5];
    if ( !v11 )
    {
      v13 = PiDqGetPnpObjectType(*(_DWORD *)(*(_DWORD *)(a1[5] + 12) + 16));
LABEL_4:
      if ( v8 >= 0 )
      {
        v8 = PiDqPnPGetObjectProperty(a1[4], v13, v12, a2, a2[5], 0, (_DWORD *)(a1[2] + 40 * a1[3]));
        if ( v8 >= 0 )
        {
          *v6 = *(_DWORD *)(a1[2] + 40 * a1[3] + 28);
          *v7 = *(_DWORD *)(a1[2] + 40 * a1[3] + 32);
          *a5 = *(_DWORD *)(a1[2] + 40 * a1[3]++ + 36);
        }
      }
      return v8;
    }
    if ( v11 != 1 )
      return -1073741811;
    v13 = 0;
    if ( !*a1 )
    {
      v17 = PiDqGetPnpObjectType(*(_DWORD *)(*(_DWORD *)(a1[5] + 12) + 16));
      v8 = PiDqOpenObjectRegKey(1, a1[4], v17, 1, 0, v18 + 16, a1);
      if ( v8 == -1073741772 )
      {
        v8 = 0;
        *a1 = -1;
      }
    }
    v12 = *a1;
    if ( *a1 != -1 )
      goto LABEL_4;
    v19 = (_DWORD *)(a1[2] + 40 * a1[3]);
    v20 = *a2;
    v21 = a2[1];
    v22 = a2[2];
    v23 = a2[3];
    v24 = a2 + 4;
    *v19 = v20;
    v19[1] = v21;
    v19[2] = v22;
    v19[3] = v23;
    v19 += 4;
    v25 = v24[1];
    v26 = v24[2];
    *v19 = *v24;
    v19[1] = v25;
    v19[2] = v26;
    ++a1[3];
    *v6 = 0;
    *v7 = 0;
    *a5 = 0;
    return v8;
  }
  v15 = 0;
  v27 = 0;
  while ( 1 )
  {
    v16 = (_DWORD *)(a1[2] + v15);
    if ( a2[4] == v16[4] && !memcmp((unsigned int)a2, (unsigned int)v16, 16) && a2[5] == v16[5] )
      break;
    ++v10;
    v15 = v27 + 40;
    v27 += 40;
    if ( v10 >= a1[3] )
    {
      v7 = a4;
      v6 = a3;
      goto LABEL_2;
    }
  }
  if ( a2[6] == v16[6] )
  {
    *a3 = *(_DWORD *)(a1[2] + 40 * v10 + 28);
    *a4 = *(_DWORD *)(a1[2] + 40 * v10 + 32);
    *a5 = *(_DWORD *)(a1[2] + 40 * v10 + 36);
    return v8;
  }
  return sub_7EDFAC();
}
