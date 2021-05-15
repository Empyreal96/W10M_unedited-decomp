// AslpFileVerQueryValue 
 
int __fastcall AslpFileVerQueryValue(unsigned __int16 *a1, unsigned __int16 *a2, unsigned __int16 **a3, _DWORD *a4)
{
  unsigned __int16 *v4; // r5
  int v5; // r4
  int v7; // r4
  unsigned int v8; // r0
  unsigned int v9; // r3
  int v10; // r0
  _WORD *v11; // r0
  unsigned int v12; // r7
  unsigned int v13; // r1
  unsigned int v14; // r3
  _WORD *v15; // r4
  char *v16; // r10
  int v17; // r8
  int v18; // r2
  int v19; // r3
  unsigned __int16 *v20; // r2
  int v21; // r8
  unsigned int v22; // r3
  unsigned int v23; // r6
  unsigned int v24; // r3
  unsigned int v25; // r0
  int v26; // lr
  int v27; // r6
  int v28; // r2
  unsigned int v29; // r1
  int i; // [sp+8h] [bp-38h] BYREF
  int v32; // [sp+Ch] [bp-34h]
  unsigned int v33; // [sp+10h] [bp-30h]
  _WORD *v34; // [sp+14h] [bp-2Ch]
  _DWORD *v35; // [sp+18h] [bp-28h]
  unsigned __int16 **v36; // [sp+1Ch] [bp-24h]

  v4 = a1;
  v5 = a1[2];
  v35 = a4;
  v36 = a3;
  *a4 = 0;
  if ( v5 )
  {
    v7 = -1073741811;
    AslLogCallPrintf(1, (int)"AslpFileVerQueryValue", 1614, "Version block invalid");
    return v7;
  }
  v8 = wcslen(a2);
  v9 = v8 + 1;
  if ( v8 + 1 < v8 )
  {
    v7 = -1073741675;
    AslLogCallPrintf(1, (int)"AslpFileVerQueryValue", 1626, "RtlSIZETAdd failed [%x]", -1073741675);
    return v7;
  }
  i = v8 + 1;
  if ( v9 <= 1 )
  {
    v9 = 1;
    i = 1;
  }
  v10 = RtlULongLongToULong(2 * v9, (unsigned __int64)v9 >> 31, &i);
  v7 = v10;
  if ( v10 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslpFileVerQueryValue", 1634, "RtlSIZETMult failed [%x]", v10);
    return v7;
  }
  v11 = AslAlloc(v10, i);
  v12 = (unsigned int)v11;
  if ( !v11 )
  {
    v7 = -1073741801;
    AslLogCallPrintf(1, (int)"AslpFileVerQueryValue", 1641, "Out of memory");
    return v7;
  }
  v13 = i;
  *v11 = 0;
  v7 = RtlStringCchCopyW(v11, v13, (int)a2);
  if ( v7 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslpFileVerQueryValue", 1648, "RtlStringCchCopyW failed [%x]", v7);
LABEL_41:
    ExFreePoolWithTag(v12);
    return v7;
  }
  v14 = *v4;
  v15 = (_WORD *)v12;
  if ( v14 < 8 )
  {
    v7 = -1073741811;
    AslLogCallPrintf(1, (int)"AslpFileVerQueryValue", 1664, "VersionBlock not long enough");
    goto LABEL_41;
  }
  v16 = (char *)v4 + v14 - 2;
  v17 = *(unsigned __int16 *)v16;
  *(_WORD *)v16 = 0;
  v32 = v17;
  v18 = 0;
LABEL_15:
  for ( i = v18; ; i = 0 )
  {
    v19 = (unsigned __int16)*v15;
    if ( !*v15 )
      break;
    while ( v19 == 92 )
      v19 = (unsigned __int16)*++v15;
    v21 = (unsigned __int16)*v15;
    if ( !*v15 )
    {
LABEL_38:
      v18 = 1;
      goto LABEL_15;
    }
    v22 = v16 - (char *)v4 + 2;
    if ( v22 < 8 )
      goto LABEL_40;
    v23 = *v4;
    if ( v23 > (unsigned __int16)v22 )
      goto LABEL_40;
    v24 = ((2 * wcslen(v4 + 3) + 11) & 0xFFFFFFFC) + ((v4[1] + 3) & 0xFFFFFFFC);
    if ( v24 > v23 )
      goto LABEL_40;
    v25 = (unsigned int)v4 + v23;
    v4 = (unsigned __int16 *)((char *)v4 + v24);
    v33 = v25;
    v34 = v15;
    v26 = (int)v15;
    if ( v21 )
    {
      do
      {
        if ( *v15 == 92 )
          break;
        ++v15;
      }
      while ( *v15 );
    }
    v27 = (unsigned __int16)*v15;
    v28 = 1;
    *v15 = 0;
    if ( (unsigned int)v4 < v25 )
    {
      do
      {
        v29 = *v4;
        if ( v29 <= 8 || (int)v29 > (int)(v25 - (_DWORD)v4) )
          break;
        if ( !wcsicmp(v26, v4 + 3) )
        {
          v28 = 0;
          break;
        }
        v25 = v33;
        v26 = (int)v34;
        v28 = 1;
        v4 = (unsigned __int16 *)((char *)v4 + ((*v4 + 3) & 0xFFFFFFFC));
      }
      while ( (unsigned int)v4 < v33 );
    }
    *v15 = v27;
    if ( v28 )
    {
LABEL_40:
      v7 = -1073741275;
      *(_WORD *)v16 = v32;
      goto LABEL_41;
    }
    if ( !v27 )
      goto LABEL_38;
  }
  *v35 = v4[1];
  v20 = (unsigned __int16 *)((char *)v4 + ((2 * wcslen(v4 + 3) + 11) & 0xFFFFFFFC));
  if ( v20 >= (unsigned __int16 *)((char *)v4 + *v4) )
    v20 = &v4[wcslen(v4 + 3) + 3];
  *v36 = v20;
  *(_WORD *)v16 = v32;
  ExFreePoolWithTag(v12);
  return 0;
}
