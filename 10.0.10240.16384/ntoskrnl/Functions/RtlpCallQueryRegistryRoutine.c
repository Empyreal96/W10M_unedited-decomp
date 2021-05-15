// RtlpCallQueryRegistryRoutine 
 
int __fastcall RtlpCallQueryRegistryRoutine(int a1, int a2, _DWORD *a3, int *a4, int a5, int a6, char a7)
{
  int v7; // r9
  _DWORD *v9; // r5
  int v11; // r6
  char *v12; // r8
  int v13; // r10
  __int64 v14; // r4
  unsigned __int16 *v15; // r2
  int v16; // r1
  int v17; // r2
  int result; // r0
  char *v19; // r3
  unsigned int v20; // r2
  signed int v21; // r4
  int v22; // r1
  bool v23; // zf
  int v25; // r2
  unsigned __int16 *v26; // r0
  int v27; // t1
  unsigned int v28; // r6
  int v29; // t1
  int i; // r3
  int v32; // [sp+8h] [bp-28h]
  unsigned int v33; // [sp+Ch] [bp-24h]

  v7 = *a4;
  v9 = a3;
  *a4 = 0;
  v33 = (unsigned int)a3;
  v11 = *(unsigned __int8 *)(a2 + 16);
  v12 = (char *)a3 + v7;
  if ( a3[1] )
  {
    v16 = a3[2];
    if ( v16 != -1 )
    {
      v17 = a3[3];
      if ( !v17 )
        return sub_80A874(32);
      if ( (*(_DWORD *)(a2 + 4) & 0x20) != 0 )
      {
        v13 = *(_DWORD *)(a2 + 8);
        v32 = v13;
LABEL_15:
        v11 = v9[1];
        LODWORD(v14) = (char *)v9 + v9[2];
        HIDWORD(v14) = v9[3];
        goto LABEL_16;
      }
      v19 = (char *)v9 + v17 + v16;
      v20 = v9[4];
      v13 = (unsigned int)(v19 + 7) & 0xFFFFFFF8;
      v21 = v20 + 2;
      v32 = v13;
      if ( v20 < 0xFFFFFFFE )
      {
        if ( (int)&v12[-v13] < v21 )
        {
          result = -1073741789;
          *a4 = v21 - (_DWORD)v9 + v13;
          return result;
        }
        memmove(v13, (int)(v9 + 5), v20);
        *(_WORD *)(v9[4] + v13) = 0;
        v33 = (v21 + v13 + 7) & 0xFFFFFFF8;
        v7 = (int)&v12[-v33];
        goto LABEL_15;
      }
      return -1073741764;
    }
  }
  if ( !v11 )
  {
    v23 = (*(_DWORD *)(a2 + 4) & 4) == 0;
    goto LABEL_34;
  }
  v13 = *(_DWORD *)(a2 + 8);
  v14 = *(_QWORD *)(a2 + 20);
  v32 = v13;
  if ( !HIDWORD(v14) )
  {
    v15 = *(unsigned __int16 **)(a2 + 20);
    if ( v11 == 1 || v11 == 2 )
    {
      if ( (_DWORD)v14 )
      {
        while ( *v15++ )
          ;
        HIDWORD(v14) = (char *)v15 - v14;
        goto LABEL_16;
      }
    }
    else
    {
      if ( v11 != 7 )
        goto LABEL_16;
      if ( (_DWORD)v14 )
      {
        for ( i = *(unsigned __int16 *)v14; i; i = *v15 )
        {
          while ( *v15++ )
            ;
        }
        HIDWORD(v14) = (char *)v15 - v14 + 2;
        goto LABEL_16;
      }
    }
    return -1073741764;
  }
LABEL_16:
  v22 = *(_DWORD *)(a2 + 4);
  if ( (v22 & 0x20) != 0 )
  {
    if ( (v22 & 0x100) != 0 )
    {
      if ( *(unsigned __int8 *)(a2 + 19) != v11 )
        return -1073741788;
      goto LABEL_17;
    }
    if ( (v22 & 0x80) != 0 && (v11 == 1 || v11 == 7 || v11 == 2) )
    {
      v23 = (*(_DWORD *)(a2 + 4) & 4) == 0;
LABEL_34:
      if ( !v23 )
        return -1073741772;
      return 0;
    }
  }
LABEL_17:
  if ( (v22 & 0x10) != 0 )
    goto LABEL_20;
  if ( v11 == 7 )
  {
    v28 = HIDWORD(v14) + v14 - 4;
    result = 0;
    for ( HIDWORD(v14) = v14; HIDWORD(v14) < v28; LODWORD(v14) = HIDWORD(v14) )
    {
      do
      {
        v29 = (unsigned __int16)*(_WORD *)HIDWORD(v14);
        HIDWORD(v14) += 2;
      }
      while ( v29 );
      if ( (*(_DWORD *)(a2 + 4) & 0x20) != 0 )
      {
        if ( a7 )
          RtlpValidateKeyTrust(a1);
        result = RtlpQueryRegistryDirect(1, v14, HIDWORD(v14) - v14, *(_DWORD *)(a2 + 12));
        *(_DWORD *)(a2 + 12) += 8;
      }
      else
      {
        result = (*(int (__fastcall **)(int, int, _DWORD, _DWORD, int, _DWORD))a2)(
                   v32,
                   1,
                   v14,
                   HIDWORD(v14) - v14,
                   a5,
                   *(_DWORD *)(a2 + 12));
      }
      if ( result == -1073741789 )
        result = 0;
      if ( result < 0 )
        break;
    }
    return result;
  }
  if ( v11 != 2
    || (v25 = HIDWORD(v14) - 2, (unsigned int)(HIDWORD(v14) - 2) > 0xFFFA)
    || (v26 = (unsigned __int16 *)v14, HIDWORD(v14) == 2) )
  {
LABEL_20:
    if ( (v22 & 0x20) != 0 )
    {
      if ( a7 )
        RtlpValidateKeyTrust(a1);
      result = RtlpQueryRegistryDirect(v11, v14, HIDWORD(v14), *(_DWORD *)(a2 + 12));
    }
    else
    {
      result = (*(int (__fastcall **)(int, int, _DWORD, _DWORD, int, _DWORD))a2)(
                 v13,
                 v11,
                 v14,
                 HIDWORD(v14),
                 a5,
                 *(_DWORD *)(a2 + 12));
    }
    if ( result != -1073741789 )
      return result;
    return 0;
  }
  while ( 1 )
  {
    v27 = *v26++;
    if ( v27 == 37 )
      break;
    v25 -= 2;
    if ( !v25 )
      goto LABEL_20;
  }
  if ( v7 > 0 )
  {
    if ( (unsigned int)v7 > 0xFFFE )
      *(_WORD *)(v33 + 65532) = 0;
    else
      *(_WORD *)(v33 + 2 * ((unsigned int)v7 >> 1) - 2) = 0;
  }
  return -1073741811;
}
