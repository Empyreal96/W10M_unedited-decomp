// AdtpBuildRegistryValueString 
 
int __fastcall AdtpBuildRegistryValueString(int a1, unsigned int a2, unsigned __int16 *a3, unsigned __int16 *a4, _BYTE *a5)
{
  int v5; // r6
  unsigned __int16 *v7; // r7
  int v9; // lr
  unsigned __int16 *v10; // r8
  unsigned int v11; // r0
  int v12; // r0
  unsigned int v13; // r5
  unsigned int v14; // r2
  unsigned __int16 *v15; // r1
  unsigned __int16 *v17; // r1
  unsigned int v18; // r2
  int v19; // t1
  int v20; // r0
  unsigned int v21; // r3
  unsigned int v22; // lr
  unsigned __int16 *v23; // r2
  int v24; // r1
  int v25; // t1
  int v26; // r0
  int v27; // r0
  unsigned __int16 *v28; // r8
  unsigned int v29; // r2
  unsigned __int16 v30; // r3
  unsigned int v31; // r0

  v5 = 0;
  *a5 = 0;
  v7 = a3;
  v9 = 0;
  v10 = 0;
  switch ( a1 )
  {
    case 4:
      if ( a2 >= 4 )
      {
        v11 = *(_DWORD *)a3;
LABEL_7:
        v12 = AdtpBuildUlongString(v11, a4, 0, 0, 0, a5);
LABEL_40:
        v5 = v12;
        goto LABEL_53;
      }
      goto LABEL_38;
    case 5:
      if ( a2 >= 4 )
      {
        v11 = ((*(_DWORD *)a3 & 0xFF00 | (*(_DWORD *)a3 << 16)) << 8) | ((*(_DWORD *)a3 & 0xFF0000u | HIWORD(*(_DWORD *)a3)) >> 8);
        goto LABEL_7;
      }
      goto LABEL_38;
    case 11:
      if ( a2 >= 8 )
      {
        v12 = AdtpBuildHexInt64String((int)a3, (int)a4, (int)a3, (int)a4, a2, a5);
        goto LABEL_40;
      }
      goto LABEL_38;
    case 1:
    case 2:
      if ( a2 < 2 )
      {
        v7 = 0;
      }
      else if ( a3[(a2 >> 1) - 1] )
      {
        v27 = ExAllocatePoolWithTag(1, a2 + 2, 1799447891);
        v28 = (unsigned __int16 *)v27;
        if ( !v27 )
          goto LABEL_25;
        memmove(v27, (int)v7, a2);
        v28[a2 >> 1] = 0;
        RtlInitUnicodeString((unsigned int)a4, v28);
        *a5 = 1;
LABEL_48:
        v29 = *a4;
        v30 = a2;
        if ( v29 >= (unsigned __int16)a2 )
          LOWORD(v29) = a2;
        *a4 = v29;
        if ( a4[1] < (unsigned int)(unsigned __int16)a2 )
          v30 = a4[1];
        a4[1] = v30;
LABEL_53:
        if ( v5 >= 0 )
          return v5;
        goto LABEL_54;
      }
      RtlInitUnicodeString((unsigned int)a4, v7);
      *a5 = 0;
      goto LABEL_48;
  }
  if ( a1 != 7 )
  {
LABEL_38:
    v26 = ExAllocatePoolWithTag(1, 26, 1799447891);
    *((_DWORD *)a4 + 1) = v26;
    if ( v26 )
    {
      *a5 = 1;
      a4[1] = 26;
      *a4 = 0;
      v12 = AdtpBuildReplacementString(1800, a4);
      goto LABEL_40;
    }
LABEL_25:
    v5 = -1073741801;
LABEL_54:
    if ( *a5 )
    {
      v31 = *((_DWORD *)a4 + 1);
      if ( v31 )
        ExFreePoolWithTag(v31);
    }
    *a5 = 0;
    return v5;
  }
  v13 = a2 >> 1;
  v14 = 0;
  if ( a2 >> 1 )
  {
    v15 = &v7[v13];
    do
    {
      if ( *--v15 )
        break;
      if ( v14 >= 2 )
        break;
      --v13;
      ++v14;
    }
    while ( v13 );
  }
  if ( v13 )
  {
    v17 = v7;
    v18 = v13;
    do
    {
      v19 = *v17++;
      if ( v19 == 42 )
        ++v9;
      --v18;
    }
    while ( v18 );
    v10 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * (v9 + v13 + 1), 1799447891);
    if ( !v10 )
      goto LABEL_25;
    v20 = 0;
    v21 = 0;
    v22 = v9 + v13;
    v23 = v10;
    while ( 1 )
    {
      if ( v21 >= v22 )
      {
LABEL_35:
        v10[v21] = 0;
        goto LABEL_36;
      }
      v25 = *v7++;
      v24 = v25;
      if ( !v25 )
        break;
      if ( v24 != 42 )
      {
        *v23++ = v24;
        goto LABEL_33;
      }
      *v23 = 42;
      v23[1] = 42;
      v21 += 2;
      v23 += 2;
LABEL_34:
      if ( ++v20 >= v13 )
        goto LABEL_35;
    }
    *v23++ = 42;
LABEL_33:
    ++v21;
    goto LABEL_34;
  }
LABEL_36:
  RtlInitUnicodeString((unsigned int)a4, v10);
  if ( v10 )
    *a5 = 1;
  return v5;
}
