// RtlReplaceSidInSd 
 
int __fastcall RtlReplaceSidInSd(int a1, unsigned __int8 *a2, int a3, _DWORD *a4)
{
  int v6; // r10
  int v8; // r8
  int result; // r0
  unsigned __int8 *v10; // r6
  int v11; // r2
  int v12; // r3
  unsigned __int8 *v14; // r4
  int v15; // r3
  int v16; // r2
  int v18; // r7
  unsigned __int8 *v19; // r4
  int v20; // r10
  unsigned int v21; // r3
  unsigned __int8 *v22; // r6
  int v23; // r3
  int v24; // r2
  int v26; // r7
  unsigned __int8 *v27; // r4
  unsigned int v28; // r3
  unsigned __int8 *v29; // r6
  int v30; // r2
  int v31; // r3
  bool v33; // [sp+0h] [bp-30h] BYREF
  char v34[3]; // [sp+1h] [bp-2Fh] BYREF
  unsigned __int8 *v35; // [sp+4h] [bp-2Ch] BYREF
  int v36; // [sp+8h] [bp-28h]
  int v37; // [sp+Ch] [bp-24h]

  v6 = a1;
  v36 = a3;
  v37 = a1;
  *a4 = 0;
  v8 = *(unsigned __int8 *)RtlSubAuthorityCountSid((int)a2);
  v35 = 0;
  result = RtlGetOwnerSecurityDescriptor(v6, &v35, &v33);
  if ( result >= 0 )
  {
    v10 = v35;
    if ( v35 )
    {
      if ( *v35 == *a2 )
      {
        v11 = v35[1];
        v12 = a2[1];
        if ( (v11 == v12 || v11 == v12 + 1)
          && !memcmp((unsigned int)(v35 + 2), (unsigned int)(a2 + 2), 6)
          && !memcmp((unsigned int)(v10 + 8), (unsigned int)(a2 + 8), 4 * v8) )
        {
          memmove((int)(v10 + 8), a3 + 8, 4 * v8);
          ++*a4;
        }
      }
    }
    v35 = 0;
    result = RtlGetGroupSecurityDescriptor(v6, &v35, &v33);
    if ( result >= 0 )
    {
      v14 = v35;
      if ( v35 )
      {
        if ( *v35 == *a2 )
        {
          v15 = a2[1];
          v16 = v35[1];
          if ( (v16 == v15 || v16 == v15 + 1)
            && !memcmp((unsigned int)(v35 + 2), (unsigned int)(a2 + 2), 6)
            && !memcmp((unsigned int)(v14 + 8), (unsigned int)(a2 + 8), 4 * v8) )
          {
            memmove((int)(v14 + 8), a3 + 8, 4 * v8);
            ++*a4;
          }
        }
      }
      v35 = 0;
      result = RtlGetDaclSecurityDescriptor(v6, v34, &v35, &v33);
      if ( result >= 0 )
      {
        if ( v34[0] )
        {
          if ( v35 )
          {
            v18 = *((unsigned __int16 *)v35 + 2);
            v19 = v35 + 8;
            if ( *((_WORD *)v35 + 2) )
            {
              v20 = v36;
              while ( 1 )
              {
                v21 = *v19;
                if ( v21 <= 3 )
                  break;
                if ( v21 == 4 )
                {
                  v22 = &v19[RtlLengthSid((int)(v19 + 12)) + 12];
LABEL_32:
                  if ( *v22 == *a2 )
                  {
                    v23 = a2[1];
                    v24 = v22[1];
                    if ( (v24 == v23 || v24 == v23 + 1)
                      && !memcmp((unsigned int)(v22 + 2), (unsigned int)(a2 + 2), 6)
                      && !memcmp((unsigned int)(v22 + 8), (unsigned int)(a2 + 8), 4 * v8) )
                    {
                      memmove((int)(v22 + 8), v20 + 8, 4 * v8);
                      ++*a4;
                    }
                  }
                }
                --v18;
                v19 += *((unsigned __int16 *)v19 + 1);
                if ( !v18 )
                {
                  v6 = v37;
                  goto LABEL_43;
                }
              }
              v22 = v19 + 8;
              goto LABEL_32;
            }
          }
        }
LABEL_43:
        v35 = 0;
        result = RtlGetSaclSecurityDescriptor(v6, v34, &v35, &v33);
        if ( result >= 0 && v34[0] && v35 )
        {
          v26 = *((unsigned __int16 *)v35 + 2);
          v27 = v35 + 8;
          if ( *((_WORD *)v35 + 2) )
          {
            while ( 1 )
            {
              v28 = *v27;
              if ( v28 <= 3 )
                break;
              if ( v28 == 4 )
              {
                v29 = &v27[RtlLengthSid((int)(v27 + 12)) + 12];
                goto LABEL_51;
              }
LABEL_60:
              --v26;
              v27 += *((unsigned __int16 *)v27 + 1);
              if ( !v26 )
                goto LABEL_61;
            }
            v29 = v27 + 8;
LABEL_51:
            if ( *v29 == *a2 )
            {
              v30 = v29[1];
              v31 = a2[1];
              if ( (v30 == v31 || v30 == v31 + 1)
                && !memcmp((unsigned int)(v29 + 2), (unsigned int)(a2 + 2), 6)
                && !memcmp((unsigned int)(v29 + 8), (unsigned int)(a2 + 8), 4 * v8) )
              {
                memmove((int)(v29 + 8), v36 + 8, 4 * v8);
                ++*a4;
              }
            }
            goto LABEL_60;
          }
LABEL_61:
          result = 0;
        }
      }
    }
  }
  return result;
}
