// PnpIsDuplicateDevice 
 
int __fastcall PnpIsDuplicateDevice(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // r6
  int v3; // r3
  int v4; // r2
  int v5; // r0
  int v6; // r4
  _DWORD *v7; // r5
  unsigned int v8; // r1
  unsigned __int8 *v9; // r7
  int v10; // r3
  unsigned int v11; // r2
  unsigned __int8 *v12; // r10
  unsigned int v13; // r6
  int v14; // r2
  int v15; // r3
  __int64 v16; // r8
  BOOL v17; // r2
  _DWORD *v18; // r3
  int v19; // r3
  unsigned int v21; // [sp+Ch] [bp-54h]
  int v22; // [sp+10h] [bp-50h]
  int v23; // [sp+14h] [bp-4Ch]
  __int64 v24; // [sp+18h] [bp-48h]
  unsigned int v25; // [sp+20h] [bp-40h]
  _DWORD *v26; // [sp+24h] [bp-3Ch]
  int v27; // [sp+28h] [bp-38h]

  v2 = a1;
  v3 = *a1;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = a2;
  v26 = v2;
  v27 = 0;
  v22 = 0;
  v23 = 0;
  if ( v3 && *a2 )
  {
    while ( 1 )
    {
      v8 = 0;
      v25 = 0;
      v9 = (unsigned __int8 *)(v2 + 5);
      if ( v2[4] )
        break;
LABEL_17:
      if ( v6 )
        return 1;
      v18 = v7;
      v7 = v2;
      v2 = v18;
      v19 = v4;
      v4 = v5;
      v5 = v19;
      v6 = 1;
      v22 = v19;
      v23 = v4;
      v26 = v2;
      v27 = 1;
    }
    while ( 1 )
    {
      v10 = *v9;
      if ( v10 == 1 || v10 == 3 || v10 == 7 )
      {
        v11 = 0;
        v12 = (unsigned __int8 *)(v7 + 5);
        if ( v7[4] )
        {
          v13 = 0;
          do
          {
            v14 = *v12;
            v15 = *v9;
            if ( v15 == v14 )
            {
              LODWORD(v16) = *((_DWORD *)v9 + 2);
              HIDWORD(v16) = *((_DWORD *)v9 + 1);
              HIDWORD(v24) = *((_DWORD *)v12 + 1);
              LODWORD(v24) = *((_DWORD *)v12 + 2);
              v17 = v14 == 1;
              if ( v16 == v24 && (v15 == 1) == v17 )
                break;
            }
            ++v13;
            v12 += 16;
          }
          while ( v13 < v7[4] );
          v8 = v25;
          v5 = v22;
          v21 = v13;
          v2 = v26;
          v11 = v21;
        }
        if ( v11 == v7[4] )
          break;
      }
      ++v8;
      v9 += 16;
      v25 = v8;
      if ( v8 >= v2[4] )
      {
        v4 = v23;
        v6 = v27;
        goto LABEL_17;
      }
    }
  }
  return 0;
}
