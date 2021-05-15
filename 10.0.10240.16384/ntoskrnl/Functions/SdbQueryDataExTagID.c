// SdbQueryDataExTagID 
 
int __fastcall SdbQueryDataExTagID(int a1, int a2, int a3, int *a4, int a5, unsigned int *a6, int *a7)
{
  __int16 *v7; // r4
  int v10; // r4
  int v11; // r0
  unsigned int v12; // r8
  _WORD *v13; // r7
  _WORD *v14; // r0
  _WORD *v15; // r5
  int v16; // r7
  int v17; // r0
  int v18; // r5
  int v19; // r0
  unsigned int v20; // r7
  __int64 *v21; // r8
  int v22; // r2
  int v23; // r0
  int v24; // r2
  int v25; // r3
  int v26; // r4
  unsigned __int16 *v27; // r0
  _WORD *v29; // [sp+8h] [bp-38h]
  int v30; // [sp+Ch] [bp-34h] BYREF
  int *v31; // [sp+10h] [bp-30h]
  __int64 v32; // [sp+18h] [bp-28h] BYREF

  v31 = a4;
  v7 = L"Policy";
  if ( !a5 && !a6 )
  {
    AslLogCallPrintf(1, (int)"SdbQueryDataExTagID", 4653, "One of lpBuffer or lpcbBufferSize should not be null");
    return 87;
  }
  v11 = wcslen(L"Policy");
  v12 = v11 + 1;
  v29 = AslAlloc(v11, 2 * (v11 + 1));
  if ( !v29 )
  {
    AslLogCallPrintf(
      1,
      (int)"SdbQueryDataExTagID",
      4665,
      "Cannot allocate temporary buffer for parsing the name \"%ws\"",
      L"Policy");
    return 8;
  }
  v13 = v29;
  while ( 1 )
  {
    v14 = wcschr(v7, 92);
    v15 = v14;
    if ( v14 )
    {
      v16 = v14 - v7;
      if ( RtlStringCchCopyNW(v29, v12, (int)v7, v16) < 0 )
      {
LABEL_55:
        v10 = 122;
        goto LABEL_56;
      }
      v29[v16] = 0;
      v13 = v29;
      v7 = v15 + 1;
    }
    else
    {
      if ( RtlStringCchCopyW(v13, v12, (int)v7) < 0 )
        goto LABEL_55;
      v7 = 0;
    }
    v17 = SdbFindFirstNamedTag(a1, a2, 28687, 24577, v13);
    a2 = v17;
    if ( !v7 || !*v7 )
      break;
    if ( !v17 )
      goto LABEL_17;
  }
  if ( !v17 )
  {
LABEL_17:
    v10 = 1168;
    goto LABEL_56;
  }
  v18 = 0;
  v19 = SdbFindFirstTag(a1, v17, 16408);
  if ( v19 )
    v18 = SdbReadDWORDTag(a1, v19, 0);
  else
    AslLogCallPrintf(1, (int)"SdbQueryDataExTagID", 4714, "The entry 0x%x does not have valuetype information", a2);
  v20 = 0;
  v21 = 0;
  switch ( v18 )
  {
    case 0:
LABEL_43:
      v10 = 0;
      if ( !v20 )
        goto LABEL_49;
      goto LABEL_44;
    case 1:
      v22 = 24606;
      break;
    case 3:
      v22 = 36869;
      break;
    case 4:
      v22 = 16409;
      break;
    case 11:
      v22 = 20487;
      break;
    default:
      AslLogCallPrintf(
        1,
        (int)"SdbQueryDataExTagID",
        4751,
        "The entry 0x%x contains bad valuetype information 0x%x",
        a2,
        v18);
      v10 = 1358;
      goto LABEL_56;
  }
  v23 = SdbFindFirstTag(a1, a2, v22);
  v26 = v23;
  if ( !v23 )
  {
    AslLogCallPrintf(1, (int)"SdbQueryDataExTagID", 4763, "The entry 0x%x contains no value", a2);
    goto LABEL_17;
  }
  if ( v18 == 1 )
  {
    v27 = (unsigned __int16 *)SdbGetStringTagPtr(a1, v23, v24, v25);
    v21 = (__int64 *)v27;
    if ( !v27 )
    {
      AslLogCallPrintf(1, (int)"SdbQueryDataExTagID", 4779, "The entry 0x%x contains bad string value 0x%x", a2, v26);
      goto LABEL_17;
    }
    v20 = 2 * (wcslen(v27) + 1);
    goto LABEL_43;
  }
  if ( v18 == 3 )
  {
    v20 = SdbGetTagDataSize(a1, v23, v24, v25);
    v21 = (__int64 *)SdbpGetMappedTagData(a1, v26);
    if ( !v21 )
    {
      AslLogCallPrintf(1, (int)"SdbQueryDataExTagID", 4793, "The entry 0x%x contains bad binary value 0x%x", a2, v26);
      goto LABEL_17;
    }
    goto LABEL_43;
  }
  if ( v18 != 4 )
  {
    v20 = 8;
    v32 = SdbReadQWORDTag(a1, v23, 0, 0);
    v21 = &v32;
    goto LABEL_43;
  }
  v20 = 4;
  v21 = (__int64 *)&v30;
  v30 = SdbReadDWORDTag(a1, v23, 0);
  v10 = 0;
LABEL_44:
  if ( a5 && a6 && *a6 >= v20 )
    memmove(a5, (int)v21, *a6);
  else
    v10 = 122;
LABEL_49:
  if ( a6 )
    *a6 = v20;
  if ( v31 )
    *v31 = v18;
  if ( a7 )
    *a7 = a2;
LABEL_56:
  ExFreePoolWithTag((unsigned int)v29);
  return v10;
}
