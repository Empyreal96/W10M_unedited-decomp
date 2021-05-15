// MiBuildImportsForBootDrivers 
 
int MiBuildImportsForBootDrivers()
{
  int v0; // r8
  int v1; // r9
  int v2; // r2
  int v3; // r10
  int v4; // r1
  _BYTE *v5; // r7
  int *v6; // r6
  unsigned int *v7; // r4
  unsigned int v8; // r1
  unsigned int v9; // lr
  bool v10; // zf
  unsigned int v11; // r0
  unsigned int v12; // r8
  unsigned int v13; // r4
  int *v14; // r2
  int **v15; // r0
  int v16; // r1
  int *v17; // r3
  int *v18; // t1
  unsigned int *v20; // r0
  _BYTE *v21; // r1
  unsigned int *v22; // r7
  int v23; // r4
  int *v24; // r3
  int *v25; // r2
  int v26; // r7
  unsigned int v27; // r0
  unsigned int v28; // r3
  int v29; // r3
  int i; // r4
  unsigned int v31; // r0
  _BYTE *v32; // [sp+0h] [bp-30h]
  unsigned int v33; // [sp+4h] [bp-2Ch] BYREF
  int v34; // [sp+8h] [bp-28h]
  int v35; // [sp+Ch] [bp-24h]

  v0 = 0;
  v1 = 0;
  v2 = PsLoadedModuleList;
  v3 = 0;
  if ( (int *)PsLoadedModuleList == &PsLoadedModuleList )
    return -1073741275;
  do
  {
    v4 = *(_DWORD *)(v2 + 24);
    if ( PsNtosImageBase == v4 )
    {
      v1 = v2;
    }
    else if ( PsHalImageBase == v4 )
    {
      v3 = v2;
    }
    *(_WORD *)(v2 + 56) = (*(_DWORD *)(v2 + 52) & 0x4000000) == 0 || v2 == v3 || v2 == v1;
    *(_DWORD *)(v2 + 76) = 1;
    v2 = *(_DWORD *)v2;
    ++v0;
  }
  while ( (int *)v2 != &PsLoadedModuleList );
  v35 = v0;
  if ( !v1 || !v3 )
    return -1073741275;
  v5 = (_BYTE *)ExAllocatePoolWithTag(257, 4 * v0, 1413770573);
  v32 = v5;
  if ( v5 )
  {
    v6 = (int *)PsLoadedModuleList;
    v34 = 0;
    while ( v6 != &PsLoadedModuleList )
    {
      v7 = (unsigned int *)RtlImageDirectoryEntryToData(v6[6], 1, 12, (int)&v33);
      if ( !v7 )
        goto LABEL_55;
      memset(v5, 0, 4 * v0);
      v8 = 0;
      v9 = 0;
      v11 = v33 >> 2;
      v10 = v33 >> 2 == 0;
      v33 >>= 2;
      v12 = 0;
      if ( !v10 )
      {
        do
        {
          if ( !v8 || *v7 < v8 || *v7 >= v9 )
          {
            v25 = (int *)PsLoadedModuleList;
            v26 = 0;
            if ( (int *)PsLoadedModuleList != &PsLoadedModuleList )
            {
              v27 = *v7;
              while ( 1 )
              {
                v8 = v25[6];
                v9 = v25[8] + v8;
                if ( v27 >= v8 && v27 < v9 )
                  break;
                v25 = (int *)*v25;
                ++v26;
                if ( v25 == &PsLoadedModuleList )
                  goto LABEL_40;
              }
              *(_DWORD *)&v32[4 * v26] = v25;
LABEL_40:
              v11 = v33;
            }
            v28 = *v7;
            if ( *v7 < v8 || v28 >= v9 )
            {
              if ( v28 )
                return sub_969DEC();
              v8 = 0;
            }
          }
          ++v12;
          ++v7;
        }
        while ( v12 < v11 );
        v5 = v32;
      }
      v0 = v35;
      v13 = 0;
      v14 = 0;
      v33 = 0;
      if ( !v35 )
        goto LABEL_55;
      v15 = (int **)v5;
      v16 = v35;
      do
      {
        v18 = *v15++;
        v17 = v18;
        if ( v18 && v17 != (int *)v1 && v17 != (int *)v3 && v17 != v6 )
        {
          v14 = v17;
          ++v13;
        }
        --v16;
      }
      while ( v16 );
      v33 = v13;
      if ( v13 )
      {
        if ( v13 == 1 )
        {
          v6[19] = (unsigned int)v14 | 1;
          ++*((_WORD *)v14 + 28);
        }
        else
        {
          if ( v13 > 0x3FFFFFFE )
            return sub_969DEC();
          v20 = (unsigned int *)ExAllocatePoolWithTag(257, 4 * (v13 + 1), 1413770573);
          if ( !v20 )
            return sub_969DEC();
          *v20 = v13;
          v21 = v5;
          v22 = v20;
          v23 = v0;
          do
          {
            v24 = *(int **)v21;
            if ( *(_DWORD *)v21 && v24 != (int *)v1 && v24 != (int *)v3 && v24 != v6 )
            {
              v22[1] = (unsigned int)v24;
              ++*(_WORD *)(*(_DWORD *)v21 + 56);
              ++v22;
            }
            v21 += 4;
            --v23;
          }
          while ( v23 );
          v6[19] = (int)v20;
        }
      }
      else
      {
LABEL_55:
        v6[19] = -2;
      }
      v6 = (int *)*v6;
      v5 = v32;
    }
    ExFreePoolWithTag((unsigned int)v5);
    v29 = v34;
    *(_DWORD *)(v1 + 76) = 1;
    *(_DWORD *)(v3 + 76) = 1;
    if ( v29 != 1 )
      return 0;
    for ( i = PsLoadedModuleList; (int *)i != &PsLoadedModuleList; i = *(_DWORD *)i )
    {
      v31 = *(_DWORD *)(i + 76);
      if ( v31 != 1 && v31 != -2 && (v31 & 1) == 0 )
        ExFreePoolWithTag(v31);
      *(_DWORD *)(i + 76) = 1;
      *(_WORD *)(i + 56) = 1;
    }
  }
  return -1073741670;
}
