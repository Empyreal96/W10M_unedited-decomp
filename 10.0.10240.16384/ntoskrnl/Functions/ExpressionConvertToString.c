// ExpressionConvertToString 
 
int __fastcall ExpressionConvertToString(_DWORD *a1, unsigned int a2, _WORD *a3, unsigned int *a4)
{
  unsigned int v5; // r5
  _WORD *v6; // r7
  int result; // r0
  int v11; // r3
  __int16 *v12; // r4
  unsigned int v13; // r3
  unsigned int v14; // r8
  int v15; // r4
  unsigned int v16; // r8
  signed int v17; // r2
  __int16 *v18; // r4
  unsigned int v19; // r9
  unsigned int v20; // r4
  unsigned int v21; // [sp+8h] [bp-30h] BYREF
  _WORD *v22; // [sp+Ch] [bp-2Ch] BYREF
  unsigned int v23; // [sp+10h] [bp-28h] BYREF
  unsigned int *v24; // [sp+14h] [bp-24h]

  v24 = a4;
  v5 = 0;
  v6 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  if ( !a1 )
    return -1073741811;
  if ( a2 >= 2 )
    *a3 = 0;
  v11 = *a1 & 0xFF00000;
  if ( v11 )
  {
    switch ( v11 )
    {
      case 1048576:
        v12 = L"AND(";
        goto LABEL_16;
      case 2097152:
        goto LABEL_12;
      case 3145728:
        v12 = L"OR(";
        goto LABEL_16;
      case 4194304:
        goto LABEL_12;
      case 5242880:
        v12 = L"NOT(";
        goto LABEL_16;
      case 6291456:
LABEL_12:
        v12 = L")";
LABEL_16:
        v13 = 2 * (wcslen((unsigned __int16 *)v12) + 1);
        if ( a4 )
          *a4 = v13;
        if ( v13 > a2 )
          result = -1073741789;
        else
          result = RtlStringCbCopyW((int)a3, a2);
        return result;
    }
    return -1073741811;
  }
  v14 = 6;
  if ( a2 >= 6 )
  {
    result = RtlStringCbCopyExW(a3, a2, L"[{", &v22, &v21, 1024);
    if ( result < 0 )
      return result;
    v5 = v21;
    v6 = v22;
  }
  v15 = *a1 & 0xF0000;
  if ( (*a1 & 0x10000) != 0 )
  {
    v15 = *a1 & 0xE0000;
    v14 = 2 * (wcslen(L"(NOT)") + 3);
    if ( v14 <= a2 )
    {
      result = RtlStringCbCopyExW(v6, v5, L"(NOT)", &v22, &v21, 1024);
      if ( result < 0 )
        return result;
      v5 = v21;
      v6 = v22;
    }
  }
  if ( (v15 & 0x20000) != 0 )
  {
    v15 &= 0xFFFDFFFF;
    v14 += 2 * wcslen(L"(IGNORE_CASE)");
    if ( v14 <= a2 )
    {
      result = RtlStringCbCopyExW(v6, v5, L"(IGNORE_CASE)", &v22, &v21, 1024);
      if ( result < 0 )
        return result;
      v5 = v21;
      v6 = v22;
    }
  }
  if ( v15 )
    return -1073741811;
  v16 = v14 + 2;
  if ( v16 <= a2 )
  {
    result = RtlStringCbCopyExW(v6, v5, L"}", &v22, &v21, 1024);
    if ( result < 0 )
      return result;
    v5 = v21;
    v6 = v22;
  }
  v17 = *a1 & 0xF000FFFF;
  if ( v17 > 4096 )
  {
    if ( v17 != 0x10000000 )
      return -1073741811;
    v18 = L"(array_contains)";
  }
  else
  {
    if ( v17 != 4096 )
    {
      switch ( v17 )
      {
        case 1:
          v18 = L"(Exists)";
          goto LABEL_53;
        case 2:
          v18 = L"(==)";
          goto LABEL_53;
        case 3:
          v18 = L"(>)";
          goto LABEL_53;
        case 4:
          v18 = L"(<)";
          goto LABEL_53;
        case 5:
          v18 = L"(>=)";
          goto LABEL_53;
        case 6:
          v18 = L"(<=)";
          goto LABEL_53;
        case 7:
          v18 = L"(&)";
          goto LABEL_53;
        case 8:
          v18 = L"(|)";
          goto LABEL_53;
        case 9:
          v18 = L"(begins_with)";
          goto LABEL_53;
        case 10:
          v18 = L"(ends_with)";
          goto LABEL_53;
        case 11:
          v18 = L"(contains)";
          goto LABEL_53;
        default:
          return -1073741811;
      }
    }
    v18 = L"(list_contains)";
  }
LABEL_53:
  v19 = v16 + 2 * wcslen((unsigned __int16 *)v18);
  if ( v19 <= a2 )
  {
    result = RtlStringCbCopyExW(v6, v5, v18, &v22, &v21, 1024);
    if ( result < 0 )
      return result;
    v5 = v21;
    v6 = v22;
  }
  result = ConvertDevpropertyToString(a1 + 1, v5, v6, &v23);
  if ( result >= 0 || result == -1073741789 )
  {
    result = 0;
    v20 = v23 + v19;
    if ( v5 >= v23 - 2 )
    {
      v5 = v5 - v23 + 2;
      v6 += (v23 - 2) >> 1;
    }
    if ( v20 > a2 || (result = RtlStringCbCopyExW(v6, v5, L"]", &v22, &v21, 1024), result >= 0) )
    {
      if ( v24 )
        *v24 = v20;
      if ( v20 > a2 )
        result = -1073741789;
    }
  }
  return result;
}
