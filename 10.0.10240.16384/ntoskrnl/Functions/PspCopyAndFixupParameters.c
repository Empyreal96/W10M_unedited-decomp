// PspCopyAndFixupParameters 
 
int __fastcall PspCopyAndFixupParameters(int a1, int a2, int a3)
{
  int v3; // lr
  int *v4; // r6
  int v5; // r8
  int v6; // r10
  char *v7; // r4
  int v8; // r0
  int v9; // r5
  int v10; // r1
  int v11; // r0
  int v12; // r2
  int *v13; // r5
  int v14; // r8
  int *v15; // r3
  int v16; // r1
  int v17; // t1
  bool v18; // nf
  int result; // r0
  int v20; // r3
  int v21; // r5
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r3
  int v26; // r3
  int v27; // r3
  int v28; // r3
  int v29; // r3
  int v30; // r3
  int v31; // [sp+10h] [bp-40h] BYREF
  int v32; // [sp+14h] [bp-3Ch]
  int *v33; // [sp+18h] [bp-38h]
  int *v34; // [sp+1Ch] [bp-34h]
  int v35; // [sp+20h] [bp-30h]
  int v36; // [sp+24h] [bp-2Ch]
  int v37; // [sp+28h] [bp-28h]
  int v38; // [sp+2Ch] [bp-24h]

  v33 = (int *)a2;
  v3 = a1;
  v32 = a1;
  v4 = *(int **)(a3 + 120);
  v5 = v4[164];
  v37 = v5;
  v6 = *v4;
  v38 = *v4;
  v7 = *(char **)(a3 + 124);
  v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v36 = v8;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v35 = v9;
  if ( (*(_BYTE *)(a3 + 8) & 0x40) != 0 && (*(_BYTE *)(a3 + 9) & 1) == 0 )
    v4[2] |= 0x4000u;
  if ( *(_DWORD *)(a3 + 44) == 3 )
  {
    v10 = v4[4];
    if ( v10 > 0 )
    {
      v11 = ObDuplicateObject(v3, v10, v8, &v31, 0, 0, 6, v9);
      v3 = v32;
      if ( v11 >= 0 )
        v4[4] = v31;
    }
  }
  v12 = (int)v33;
  if ( v33 )
  {
    v13 = v4 + 6;
    v14 = 0;
    v15 = v33;
    while ( 1 )
    {
      v17 = *v15++;
      v16 = v17;
      v34 = v15;
      v18 = v17 < 0;
      if ( v17 )
      {
        if ( v18 )
        {
          v20 = 0;
          v31 = 0;
          result = -1073741816;
        }
        else
        {
          result = ObDuplicateObject(v3, v16, v36, &v31, 0, 0, 6, v35);
          v20 = v31;
          v12 = (int)v33;
        }
        if ( result < 0 )
        {
          if ( (int *)v12 == v4 + 6 )
            return result;
        }
        else
        {
          *v13 = v20;
        }
        v15 = v34;
      }
      ++v13;
      if ( (unsigned int)++v14 >= 3 )
        break;
      v3 = v32;
    }
    v5 = v37;
    v6 = v38;
  }
  v21 = v7 - (char *)v4;
  memmove((int)v7, (int)v4, v5 + v6);
  v22 = *((_DWORD *)v7 + 10);
  if ( v22 )
    *((_DWORD *)v7 + 10) = v22 + v21;
  v23 = *((_DWORD *)v7 + 13);
  if ( v23 )
    *((_DWORD *)v7 + 13) = v23 + v21;
  v24 = *((_DWORD *)v7 + 15);
  if ( v24 )
    *((_DWORD *)v7 + 15) = v24 + v21;
  v25 = *((_DWORD *)v7 + 17);
  if ( v25 )
    *((_DWORD *)v7 + 17) = v25 + v21;
  v26 = *((_DWORD *)v7 + 29);
  if ( v26 )
    *((_DWORD *)v7 + 29) = v26 + v21;
  v27 = *((_DWORD *)v7 + 31);
  if ( v27 )
    *((_DWORD *)v7 + 31) = v27 + v21;
  v28 = *((_DWORD *)v7 + 33);
  if ( v28 )
    *((_DWORD *)v7 + 33) = v28 + v21;
  v29 = *((_DWORD *)v7 + 35);
  if ( v29 )
    *((_DWORD *)v7 + 35) = v29 + v21;
  v30 = *((_DWORD *)v7 + 18);
  if ( v30 )
    *((_DWORD *)v7 + 18) = v30 + v21;
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 320) + 16) = v7;
  return 0;
}
