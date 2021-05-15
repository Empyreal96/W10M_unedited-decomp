// _CmGetInstallerClassMappedPropertyFromRegProp 
 
int __fastcall CmGetInstallerClassMappedPropertyFromRegProp(int a1, int a2, unsigned int a3, int a4, unsigned int *a5, unsigned __int16 *a6, unsigned int a7, int *a8)
{
  int v8; // r8
  unsigned __int16 *v9; // r4
  unsigned int v10; // r9
  unsigned int v11; // r10
  int (**v12)[5]; // r7
  unsigned int v13; // r5
  int v14; // r2
  int (**v15)[5]; // r6
  unsigned int v16; // r1
  int (*v17)[5]; // t1
  int v18; // r5
  int v19; // r7
  int v20; // r0
  int v21; // r1
  int v22; // r9
  int v23; // r0
  int v24; // r2
  unsigned int v25; // r3
  int v27; // r0
  unsigned int v28; // r9
  int v29; // r2
  unsigned __int16 *v30; // r1
  int v31; // r7
  unsigned __int16 *v32; // r2
  int v33; // r3
  int i; // r6
  int v35; // r1
  unsigned __int16 *v36; // r2
  int j; // r3
  char v38; // r3
  int v40; // [sp+10h] [bp-40h] BYREF
  int v41; // [sp+14h] [bp-3Ch]
  int v42[2]; // [sp+18h] [bp-38h] BYREF
  int (*v43)[5]; // [sp+20h] [bp-30h] BYREF
  unsigned int v44; // [sp+24h] [bp-2Ch] BYREF
  int v45; // [sp+28h] [bp-28h] BYREF
  int v46[9]; // [sp+2Ch] [bp-24h] BYREF

  v40 = a4;
  v41 = a2;
  v43 = 0;
  v44 = a3;
  v45 = 0;
  v46[0] = 0;
  v8 = 0;
  v9 = a6;
  *a5 = 0;
  *a8 = 0;
  v42[0] = a1;
  if ( a6 )
  {
    v10 = a7;
    if ( !a7 )
      v9 = 0;
  }
  else
  {
    v10 = 0;
  }
  v11 = v40;
  v12 = &CmClassRegPropMap;
  v13 = 0;
  v14 = *(_DWORD *)(v40 + 16);
  v40 = v14;
  do
  {
    v15 = v12;
    v17 = *v12;
    v12 += 4;
    v16 = (unsigned int)v17;
    if ( v14 == (*v17)[4] )
    {
      if ( !memcmp(v11, v16, 16) )
        break;
      v14 = v40;
    }
    ++v13;
    v15 = 0;
  }
  while ( v13 < 9 );
  if ( !v15 )
    return -1073741264;
  v19 = (int)v15[2];
  if ( v19 == 25 )
    return -1073741637;
  v21 = v41;
  v20 = v42[0];
  if ( v19 == 27 )
  {
    v40 = 4;
    v18 = CmGetInstallerClassRegProp(v42[0], v41, v44, 27, (int)&v43, (int)&v45, (int)&v40);
    if ( v18 >= 0 )
    {
      if ( v43 == v15[3] )
      {
        *a8 = 1;
        *a5 = (unsigned int)v15[1];
        if ( v10 >= *a8 )
        {
          v38 = -1;
          if ( !v45 )
            v38 = 0;
          *(_BYTE *)v9 = v38;
        }
        else
        {
          v18 = -1073741789;
        }
      }
      else
      {
        v18 = -1073741811;
      }
    }
  }
  else
  {
    *a8 = v10;
    v22 = v44;
    v23 = CmGetInstallerClassRegProp(v20, v21, v44, v19, (int)&v43, (int)v9, (int)a8);
    v18 = v23;
    v24 = -1073741789;
    if ( !v23 || v23 == -1073741789 )
    {
      v25 = (unsigned int)v15[1];
      *a5 = v25;
      if ( v25 == 18 )
      {
        if ( v23 )
        {
          v8 = ExAllocatePoolWithTag(1, *a8, 1380994640);
          if ( !v8 )
            return -1073741801;
          v40 = *a8;
          v27 = CmGetInstallerClassRegProp(v42[0], v41, v22, v19, (int)v46, v8, (int)&v40);
          if ( v27 < 0 )
          {
            v18 = v27;
            goto LABEL_53;
          }
          v9 = (unsigned __int16 *)v8;
        }
        if ( v9 )
        {
          if ( PnpParseIndirectInfString(v9, (int)a5, v24, v25) )
          {
LABEL_51:
            *a5 = 25;
            goto LABEL_52;
          }
          if ( RtlUnalignedStringCchLengthW(v9, 0x7FFF, &v44) >= 0 )
          {
            v28 = v44;
            if ( v44 >= 5 && *v9 == 64 )
            {
              v29 = 1;
              if ( v9[1] )
              {
                v30 = v9 + 1;
                do
                {
                  if ( *v30 == 44 )
                    break;
                  v30 = &v9[++v29];
                }
                while ( *v30 );
              }
              if ( v9[v29] == 44 )
              {
                v31 = v29 + 1;
                v32 = &v9[v29 + 1];
                v33 = *v32;
                if ( v33 == 45 || v33 == 35 )
                {
                  for ( i = v31 + 1; v9[i] && v9[i] != 59; ++i )
                    ;
                  if ( v9[i] != 59 )
                    i = 0;
                  if ( RtlInitUnicodeStringEx((int)v42, v32 + 1) >= 0 )
                  {
                    if ( i )
                    {
                      LOWORD(v42[0]) = 2 * (i - v31 - 1);
                      HIWORD(v42[0]) = v42[0];
                    }
                    if ( RtlUnicodeStringToInteger((unsigned __int16 *)v42, 0xAu, (int *)&v44) >= 0 )
                    {
                      if ( i )
                      {
                        v35 = i + 1;
                        v36 = &v9[i + 1];
                        for ( j = *v36; *v36; j = *v36 )
                        {
                          if ( j == 59 && v36[1] == 40 && v9[v28 - 1] == 41 )
                            break;
                          v36 = &v9[++v35];
                        }
                      }
                      goto LABEL_51;
                    }
                  }
                }
              }
            }
          }
        }
LABEL_52:
        if ( !v8 )
          return v18;
LABEL_53:
        ExFreePoolWithTag(v8);
        return v18;
      }
    }
  }
  return v18;
}
