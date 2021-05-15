// DrvDbSetDriverDatabaseMappedProperty 
 
int __fastcall DrvDbSetDriverDatabaseMappedProperty(int a1, unsigned __int16 *a2, int a3, unsigned int a4, int (*a5)[4], unsigned __int16 *a6, unsigned int a7)
{
  unsigned __int16 *v10; // r7
  int v11; // r4
  int v12; // r7
  bool v13; // zf
  unsigned __int16 *v14; // r3
  int v15; // r3
  unsigned int v16; // r3
  int v17; // r2
  int (**v18)[5]; // r8
  unsigned int v19; // r4
  unsigned int v20; // r0
  unsigned int v21; // t1
  int v22; // r3
  int (**v23)[4]; // r8
  int v24; // r4
  int (**v25)[4]; // r10
  int v26; // r0
  int (*v27)[4]; // t1
  int v28; // r7
  int *v29; // r6
  int v30; // r2
  int v31; // r3
  int v32; // r0
  int v33; // r0
  int v34; // r3
  unsigned int v35; // r3
  int (**v36)[5]; // r9
  int v37; // r4
  unsigned int v38; // r0
  int (*v39)[5]; // t1
  int v40; // r3
  unsigned __int16 *v41; // r10
  int v42; // r3
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r0
  unsigned int v47; // r1
  __int16 v48; // r3
  unsigned __int16 *v50; // [sp+10h] [bp-40h] BYREF
  int v51; // [sp+14h] [bp-3Ch]
  int v52; // [sp+18h] [bp-38h] BYREF
  int v53; // [sp+1Ch] [bp-34h]
  unsigned __int16 *v54; // [sp+20h] [bp-30h]
  int v55[10]; // [sp+28h] [bp-28h] BYREF

  v54 = a2;
  v10 = 0;
  v51 = a3;
  v52 = 0;
  v11 = 0;
  v50 = 0;
  if ( !wcsicmp((int)a2, L"*") )
  {
    v12 = *(_DWORD *)(a4 + 16);
    if ( v12 == 6 && !memcmp(a4, (unsigned int)DEVPKEY_DriverDatabase_Selected, 16) )
    {
      if ( a5 != (int (*)[4])17 || a7 != 1 || !a6 )
        goto LABEL_112;
      v13 = *(char *)a6 == -1;
      goto LABEL_8;
    }
    if ( v12 != 11 || memcmp(a4, (unsigned int)DEVPKEY_DriverDatabase_AccessMask, 16) )
    {
      v11 = -1073741637;
      goto LABEL_113;
    }
    if ( a5 != (int (*)[4])7 || a7 != 4 || !a6 )
      goto LABEL_112;
    v15 = *(_DWORD *)a6;
LABEL_17:
    v16 = v15 & 0xD0000000;
    *(_DWORD *)(a1 + 8) = v16;
    if ( v16 == 0x10000000 )
      *(_DWORD *)(a1 + 8) = -805306368;
    goto LABEL_113;
  }
  v17 = *(_DWORD *)(a4 + 16);
  v18 = off_6174D8;
  v19 = 0;
  v53 = v17;
  do
  {
    v21 = (unsigned int)*v18++;
    v20 = v21;
    if ( *(_DWORD *)(v21 + 16) == v17 )
    {
      if ( !memcmp(v20, a4, 16) )
      {
        v11 = DrvDbFindDatabaseNode(a1, a2, &v50, v22);
        if ( v11 < 0 )
          goto LABEL_113;
        v28 = *(_DWORD *)(a4 + 16);
        if ( v28 == 5 && !memcmp(a4, (unsigned int)DEVPKEY_DriverDatabase_Loaded, 16) )
        {
          if ( a5 != (int (*)[4])17 || a7 != 1 || !a6 )
            goto LABEL_112;
          v29 = (int *)v50;
          if ( (*((_DWORD *)v50 + 7) & 1) == 0 )
          {
            v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v31 = *(__int16 *)(v30 + 0x134) - 1;
            *(_WORD *)(v30 + 308) = v31;
            ExAcquireResourceExclusiveLite(v29[18], 1, v30, v31);
            if ( *(char *)a6 == -1 )
              v32 = DrvDbLoadDatabaseNode((int **)a1, v29);
            else
              v32 = DrvDbUnloadDatabaseNode(a1, v29);
            v11 = v32;
            v33 = v29[18];
            goto LABEL_108;
          }
        }
        else
        {
          if ( v28 == 6 && !memcmp(a4, (unsigned int)DEVPKEY_DriverDatabase_Selected, 16) )
          {
            if ( a5 != (int (*)[4])17 || a7 != 1 || !a6 )
              goto LABEL_112;
            if ( *(char *)a6 == -1 )
            {
              v14 = v50;
              goto LABEL_50;
            }
            if ( v50 == *(unsigned __int16 **)(a1 + 24) )
            {
LABEL_10:
              v14 = 0;
LABEL_50:
              *(_DWORD *)(a1 + 24) = v14;
              goto LABEL_113;
            }
            v13 = v50 == 0;
LABEL_8:
            if ( !v13 )
              goto LABEL_113;
            goto LABEL_10;
          }
          if ( v28 == 7 && !memcmp(a4, (unsigned int)DEVPKEY_DriverDatabase_Disabled, 16) )
          {
            if ( a5 == (int (*)[4])17 && a7 == 1 && a6 )
            {
              v34 = *((_DWORD *)v50 + 7);
              if ( *(char *)a6 == -1 )
                v35 = v34 | 4;
              else
                v35 = v34 & 0xFFFFFFFB;
              *((_DWORD *)v50 + 7) = v35;
              goto LABEL_113;
            }
            goto LABEL_112;
          }
          if ( v28 != 11 || memcmp(a4, (unsigned int)DEVPKEY_DriverDatabase_AccessMask, 16) )
            goto LABEL_113;
          if ( a5 != (int (*)[4])7 || a7 != 4 || !a6 )
          {
LABEL_112:
            v11 = -1073741811;
            goto LABEL_113;
          }
          if ( v50 == *(unsigned __int16 **)(a1 + 20) )
          {
            v15 = *(_DWORD *)a6;
            goto LABEL_17;
          }
        }
LABEL_38:
        v11 = -1073741790;
        goto LABEL_113;
      }
      v17 = v53;
    }
    ++v19;
  }
  while ( v19 < 5 );
  v23 = 0;
  v24 = 0;
  v25 = &off_406F48;
  while ( 1 )
  {
    v27 = *v25;
    v25 += 6;
    v26 = (int)v27;
    if ( (*v27)[4] == v17 )
      break;
LABEL_29:
    if ( (unsigned int)++v24 >= 7 )
      goto LABEL_70;
  }
  v26 = memcmp(v26, a4, 16);
  if ( v26 )
  {
    v17 = v53;
    goto LABEL_29;
  }
  v23 = &off_406F48 + 6 * v24;
LABEL_70:
  if ( v23 )
  {
    v41 = v54;
    goto LABEL_83;
  }
  v23 = 0;
  v36 = &off_41E27C;
  v37 = 0;
  while ( 1 )
  {
    v39 = *v36;
    v36 += 6;
    v38 = (unsigned int)v39;
    v40 = (*v39)[4];
    if ( v40 == v53 && !memcmp(v38, a4, 16) )
      break;
    if ( (unsigned int)++v37 >= 2 )
      goto LABEL_77;
  }
  v40 = 3 * v37;
  v23 = (int (**)[4])(&off_41E27C + 6 * v37);
LABEL_77:
  if ( !v23 )
  {
    v11 = -1073741802;
    goto LABEL_113;
  }
  v41 = v54;
  v26 = DrvDbFindDatabaseNode(a1, v54, &v50, v40);
  v11 = v26;
  if ( v26 < 0 )
    goto LABEL_113;
  v10 = v50;
  if ( (*((_DWORD *)v50 + 7) & 0x10) == 0 )
    goto LABEL_38;
LABEL_83:
  if ( a5 != v23[1] && a5 )
    goto LABEL_112;
  v42 = v51;
  if ( !v51 )
  {
LABEL_88:
    if ( v10 && (*((_DWORD *)v10 + 7) & 0x10) != 0 )
      v26 = DrvDbOpenObjectRegKey((int **)a1, *(_DWORD *)(a1 + 20), 1, (int)v41, 2, 0, (int)&v52, 0);
    else
      v26 = DrvDbOpenDriverDatabaseRegKey((int **)a1, v41, 2, 0, (int)&v52, 0);
    v11 = v26;
    if ( v26 >= 0 )
      goto LABEL_93;
    goto LABEL_113;
  }
  if ( v10 )
  {
    if ( (*((_DWORD *)v10 + 7) & 0x10) != 0 )
      goto LABEL_88;
LABEL_93:
    v42 = v51;
  }
  v43 = v52;
  if ( !v52 )
    v43 = v42;
  v11 = DrvDbSetRegValueMappedProperty(v26, v43);
  if ( v11 >= 0
    && v10
    && (*((_DWORD *)v10 + 7) & 0x10) != 0
    && *(_DWORD *)(a4 + 16) == 14
    && !memcmp(a4, (unsigned int)DEVPKEY_DriverDatabase_RegistryPath, 16)
    && a5 )
  {
    if ( a7 >= 2 && a6 && !*((_BYTE *)a6 + (a7 >> 1) - 1) )
    {
      if ( !RtlCreateUnicodeString((int)v55, a6) )
      {
        v11 = -1073741670;
        goto LABEL_113;
      }
      v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v45 = *(__int16 *)(v44 + 0x134) - 1;
      *(_WORD *)(v44 + 308) = v45;
      ExAcquireResourceExclusiveLite(*((_DWORD *)v10 + 18), 1, v44, v45);
      RtlFreeAnsiString((_DWORD *)v10 + 5);
      *((_DWORD *)v10 + 4) = 0;
      *((_DWORD *)v10 + 5) = v55[0];
      *((_DWORD *)v10 + 6) = v55[1];
      v33 = *((_DWORD *)v10 + 18);
LABEL_108:
      v46 = ExReleaseResourceLite(v33);
      v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v48 = *(_WORD *)(v47 + 0x134) + 1;
      *(_WORD *)(v47 + 308) = v48;
      if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
        KiCheckForKernelApcDelivery(v46);
      goto LABEL_113;
    }
    goto LABEL_112;
  }
LABEL_113:
  if ( v52 )
    ZwClose();
  return v11;
}
