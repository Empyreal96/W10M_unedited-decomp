// KsepEvntLogShimsApplied 
 
int KsepEvntLogShimsApplied(unsigned __int16 *a1, int a2, ...)
{
  int v2; // r8
  int result; // r0
  __int16 v5; // r5
  int v6; // r4
  int v7; // r6
  unsigned int v8; // r9
  __int16 *v9; // r7
  __int16 v10; // t1
  unsigned int v11; // r2
  unsigned __int16 v12; // r3
  unsigned int v13; // r5
  unsigned __int16 *v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r7
  int v17; // r5
  unsigned __int16 v18; // [sp+8h] [bp-70h] BYREF
  __int16 v19; // [sp+Ah] [bp-6Eh]
  int v20; // [sp+Ch] [bp-6Ch]
  int v21; // [sp+10h] [bp-68h]
  unsigned __int16 *v22; // [sp+14h] [bp-64h]
  int v23; // [sp+18h] [bp-60h]
  int v24; // [sp+1Ch] [bp-5Ch]
  int v25; // [sp+20h] [bp-58h]
  int v26; // [sp+24h] [bp-54h]
  int v27; // [sp+28h] [bp-50h]
  int v28; // [sp+2Ch] [bp-4Ch]
  int v29; // [sp+30h] [bp-48h]
  int v30; // [sp+34h] [bp-44h]
  va_list v31; // [sp+38h] [bp-40h]
  int v32; // [sp+3Ch] [bp-3Ch]
  int v33; // [sp+40h] [bp-38h]
  int v34; // [sp+44h] [bp-34h]
  int v35; // [sp+48h] [bp-30h]
  int v36; // [sp+4Ch] [bp-2Ch]
  int v37; // [sp+50h] [bp-28h]
  int v38; // [sp+54h] [bp-24h]
  unsigned int varg_r2; // [sp+88h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+88h] [bp+10h]
  va_list varg_r3; // [sp+8Ch] [bp+14h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v19 = 0;
  v2 = a2;
  v21 = a2;
  result = KseEtwHandle;
  v5 = 0;
  v6 = 0;
  v22 = a1;
  v18 = 0;
  if ( KseEtwHandle )
  {
    result = EtwEventEnabled(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)KseShimsApplied);
    if ( result )
    {
      if ( varg_r2 )
      {
        if ( v2 )
        {
          if ( a1 )
          {
            result = KsepPoolAllocatePaged(8 * varg_r2);
            v7 = result;
            if ( result )
            {
              v8 = 0;
              v9 = (__int16 *)result;
              while ( RtlStringFromGUID(v2, v9) >= 0 )
              {
                v10 = *v9;
                v9 += 4;
                v11 = varg_r2;
                ++v8;
                v12 = v10 + v5 + 4;
                v5 = v12;
                v2 += 52;
                if ( v8 >= varg_r2 )
                {
                  if ( !v12 )
                    goto LABEL_23;
                  v6 = KsepPoolAllocatePaged(v12);
                  v20 = v6;
                  if ( v6 )
                  {
                    v19 = v5;
                    v13 = 0;
                    v14 = (unsigned __int16 *)v7;
                    do
                    {
                      if ( RtlAppendUnicodeStringToString(&v18, v14) < 0 )
                      {
LABEL_31:
                        v6 = v20;
                        goto LABEL_22;
                      }
                      v15 = varg_r2;
                      if ( v13 != varg_r2 - 1 )
                      {
                        if ( RtlAppendUnicodeToString(&v18, (int)L"\n", varg_r2, varg_r2 - 1) < 0 )
                          goto LABEL_31;
                        v15 = varg_r2;
                      }
                      ++v13;
                      v14 += 4;
                    }
                    while ( v13 < v15 );
                    v6 = v20;
                    v35 = v20;
                    v23 = *((_DWORD *)v22 + 1);
                    v24 = 0;
                    v25 = *v22 + 2;
                    v26 = 0;
                    v27 = v21 + 44;
                    v28 = 0;
                    v29 = 4;
                    v30 = 0;
                    va_copy(v31, varg_r2a);
                    v32 = 0;
                    v33 = 4;
                    v34 = 0;
                    v36 = 0;
                    v37 = v18 + 2;
                    v38 = 0;
                    EtwWrite(KseEtwHandle, SHIDWORD(KseEtwHandle), (int)KseShimsApplied, 0);
                  }
                  break;
                }
              }
LABEL_22:
              v11 = varg_r2;
LABEL_23:
              v16 = 0;
              if ( v11 )
              {
                v17 = v7;
                do
                {
                  if ( *(_DWORD *)(v17 + 4) )
                  {
                    RtlFreeAnsiString(v17);
                    v11 = varg_r2;
                  }
                  ++v16;
                  v17 += 8;
                }
                while ( v16 < v11 );
              }
              result = KsepPoolFreePaged(v7);
              if ( v6 )
                result = KsepPoolFreePaged(v6);
            }
          }
        }
      }
    }
  }
  return result;
}
