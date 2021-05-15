// sub_818FD4 
 
void __fastcall sub_818FD4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned __int16 *a9, int a10, int a11, int a12, unsigned __int16 *a13, unsigned int *a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, char *a26, unsigned int a27)
{
  unsigned int v27; // r6
  _DWORD *v28; // r8
  int v29; // r9
  _DWORD *v30; // r10
  int v31; // r2
  int (**v32)[5]; // r5
  int v33; // r4
  unsigned int v34; // r0
  unsigned int v35; // t1
  int v36; // r3
  int v37; // r4
  unsigned int *i; // r3
  unsigned int v39; // r0
  int v40; // r5
  char *v41; // r2
  bool v42; // zf
  char *v43; // r1
  char v44; // r3
  char v45; // r3
  char *v46; // r2
  int v47; // r3

  v31 = *(_DWORD *)(v27 + 16);
  v32 = off_6174D8;
  v33 = 0;
  a10 = v31;
  while ( 1 )
  {
    v35 = (unsigned int)*v32++;
    v34 = v35;
    if ( *(_DWORD *)(v35 + 16) == v31 )
    {
      if ( !memcmp(v34, v27, 16) )
      {
        if ( DrvDbFindDatabaseNode(v29, a13, &a9, v36) < 0 )
          goto LABEL_48;
        v40 = *(_DWORD *)(v27 + 16);
        if ( v40 == 5 && !memcmp(v27, (unsigned int)DEVPKEY_DriverDatabase_Loaded, 16) )
        {
          v41 = a26;
          *v30 = 17;
          *v28 = 1;
          if ( v41 && a27 )
          {
            v42 = *((_DWORD *)a9 + 11) == 0;
            goto LABEL_32;
          }
        }
        else if ( v40 == 6 && !memcmp(v27, (unsigned int)DEVPKEY_DriverDatabase_Selected, 16) )
        {
          v43 = a26;
          *v30 = 17;
          *v28 = 1;
          if ( v43 && a27 )
          {
            if ( *(unsigned __int16 **)(v29 + 24) == a9 )
              v44 = -1;
            else
              v44 = 0;
            *v43 = v44;
          }
        }
        else
        {
          if ( v40 != 7 || memcmp(v27, (unsigned int)DEVPKEY_DriverDatabase_Disabled, 16) )
          {
            if ( v40 == 11 && !memcmp(v27, (unsigned int)DEVPKEY_DriverDatabase_AccessMask, 16) )
            {
              v46 = a26;
              *v30 = 7;
              *v28 = 4;
              if ( !v46 || a27 < 4 )
                goto LABEL_48;
              v47 = *(_DWORD *)(v29 + 8);
            }
            else
            {
              if ( v40 != 15 )
                goto LABEL_48;
              if ( memcmp(v27, (unsigned int)DEVPKEY_DriverDatabase_LoadStatus, 16) )
                goto LABEL_48;
              v46 = a26;
              *v30 = 24;
              *v28 = 4;
              if ( !v46 || a27 < 4 )
                goto LABEL_48;
              v47 = *((_DWORD *)a9 + 19);
            }
            *(_DWORD *)v46 = v47;
            goto LABEL_48;
          }
          v41 = a26;
          *v30 = 17;
          *v28 = 1;
          if ( v41 && a27 )
          {
            v42 = (*((_DWORD *)a9 + 7) & 4) == 0;
LABEL_32:
            if ( v42 )
              v45 = 0;
            else
              v45 = -1;
            *v41 = v45;
          }
        }
LABEL_48:
        JUMPOUT(0x7B46E0);
      }
      v31 = a10;
    }
    if ( (unsigned int)++v33 >= 5 )
    {
      v37 = 0;
      for ( i = (unsigned int *)&off_406F48; ; i = a14 )
      {
        v39 = *i;
        a14 = i + 6;
        if ( *(_DWORD *)(v39 + 16) == v31 )
        {
          if ( !memcmp(v39, v27, 16) )
            goto LABEL_47;
          v31 = a10;
        }
        if ( (unsigned int)++v37 >= 7 )
LABEL_47:
          JUMPOUT(0x7B46EC);
      }
    }
  }
}
