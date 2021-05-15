// ConvertDevpropertyToString 
 
int __fastcall ConvertDevpropertyToString(_DWORD *a1, unsigned int a2, _WORD *a3, unsigned int *a4)
{
  _WORD *v5; // r9
  unsigned int v6; // r8
  unsigned int v7; // r10
  int v8; // r0
  int v9; // r7
  unsigned int v10; // r5
  unsigned int v11; // r2
  __int16 *v12; // r4
  unsigned int v13; // r6
  int v14; // r3
  unsigned __int8 *v15; // r4
  unsigned int v16; // r2
  int v17; // r0
  double v18; // d0
  __int16 *v19; // r4
  unsigned int v20; // r2
  int *v21; // r5
  int v22; // r1
  int v23; // r2
  int v24; // r3
  unsigned int v25; // r3
  bool v26; // cf
  _WORD *v28; // [sp+38h] [bp-48h] BYREF
  unsigned int v29; // [sp+3Ch] [bp-44h] BYREF
  _DWORD *v30; // [sp+40h] [bp-40h]
  unsigned int v31; // [sp+44h] [bp-3Ch] BYREF
  unsigned int *v32; // [sp+48h] [bp-38h]
  int v33; // [sp+50h] [bp-30h]
  int v34; // [sp+54h] [bp-2Ch]
  int v35; // [sp+58h] [bp-28h]
  int v36; // [sp+5Ch] [bp-24h]

  v30 = a1;
  v32 = a4;
  v5 = a3;
  v6 = a2;
  if ( a2 >= 2 )
    *a3 = 0;
  v28 = a3;
  v29 = a2;
  v7 = a2;
  v8 = ConvertDevpropcompkeyToString(a1, a3, a2, &v31);
  v9 = v8;
  if ( v8 >= 0 || v8 == -1073741789 )
  {
    v10 = v31;
    v9 = 0;
    if ( v6 >= v31 - 2 )
    {
      v7 = v6 - v31 + 2;
      v5 += (v31 - 2) >> 1;
      v28 = v5;
      v29 = v7;
    }
    v11 = a1[7];
    if ( v11 > 0x1003 )
    {
      if ( v11 == 4109 )
      {
        v12 = L"GUID_ARRAY";
      }
      else
      {
        if ( v11 != 8210 )
          return -1073741811;
        v12 = L"STRING_LIST";
      }
    }
    else
    {
      if ( v11 != 4099 )
      {
        switch ( v11 )
        {
          case 0u:
            v12 = L"EMPTY";
            goto LABEL_42;
          case 1u:
            v12 = L"NULL";
            goto LABEL_42;
          case 2u:
            v12 = L"SBYTE";
            goto LABEL_42;
          case 3u:
            v12 = L"BYTE";
            goto LABEL_42;
          case 4u:
            v12 = L"INT16";
            goto LABEL_42;
          case 5u:
            v12 = L"UINT16";
            goto LABEL_42;
          case 6u:
            v12 = L"INT32";
            goto LABEL_42;
          case 7u:
            v12 = L"UINT32";
            goto LABEL_42;
          case 8u:
            v12 = L"INT64";
            goto LABEL_42;
          case 9u:
            v12 = L"UINT64";
            goto LABEL_42;
          case 0xAu:
            v12 = L"FLOAT";
            goto LABEL_42;
          case 0xBu:
            v12 = L"DOUBLE";
            goto LABEL_42;
          case 0xCu:
            v12 = L"DECIMAL";
            goto LABEL_42;
          case 0xDu:
            v12 = L"GUID";
            goto LABEL_42;
          case 0xEu:
            v12 = L"CURRENCY";
            goto LABEL_42;
          case 0xFu:
            v12 = L"DATE";
            goto LABEL_42;
          case 0x10u:
            v12 = L"FILETIME";
            goto LABEL_42;
          case 0x11u:
            v12 = L"BOOLEAN";
            goto LABEL_42;
          case 0x12u:
            v12 = L"STRING";
            goto LABEL_42;
          case 0x13u:
            v12 = L"SECURITY_DESCRIPTOR";
            goto LABEL_42;
          case 0x14u:
            v12 = L"SECURITY_DESCRIPTOR_STRING";
            goto LABEL_42;
          case 0x15u:
            v12 = L"DEVPROPKEY";
            goto LABEL_42;
          case 0x16u:
            v12 = L"DEVPROPTYPE";
            goto LABEL_42;
          case 0x17u:
            v12 = L"ERROR";
            goto LABEL_42;
          case 0x18u:
            v12 = L"NTSTATUS";
            goto LABEL_42;
          case 0x19u:
            v12 = L"STRING_INDIRECT";
            goto LABEL_42;
          default:
            return -1073741811;
        }
      }
      v12 = L"BINARY";
    }
LABEL_42:
    v13 = v10 + 2 * wcslen((unsigned __int16 *)v12);
    if ( v13 <= v6 )
    {
      v9 = RtlStringCbCopyExW(v5, v7, v12, &v28, &v29, 1024);
      if ( v9 < 0 )
        return v9;
      v5 = v28;
      v7 = v29;
    }
    v14 = (int)v30;
    if ( !v30[8] )
      goto LABEL_88;
    v15 = (unsigned __int8 *)v30[9];
    if ( !v15 )
      goto LABEL_88;
    v16 = v30[7];
    if ( v16 > 0x1003 )
    {
      if ( v16 == 4109 )
      {
LABEL_82:
        v20 = 0;
        v31 = 0;
        do
        {
          v21 = (int *)(*(_DWORD *)(v14 + 36) + v20);
          v22 = v21[1];
          v23 = v21[2];
          v24 = v21[3];
          v33 = *v21;
          v34 = v22;
          v35 = v23;
          v36 = v24;
          v13 += 80;
          if ( v13 <= v6 )
          {
            v9 = RtlStringCbPrintfExW(
                   v5,
                   v7,
                   &v28,
                   &v29,
                   1024,
                   L"({%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x})",
                   v33,
                   (unsigned __int16)v34,
                   HIWORD(v34),
                   (unsigned __int8)v35,
                   BYTE1(v35),
                   BYTE2(v35),
                   HIBYTE(v35),
                   (unsigned __int8)v36,
                   BYTE1(v36),
                   BYTE2(v36),
                   HIBYTE(v36));
            if ( v9 < 0 )
              return v9;
            v5 = v28;
            v7 = v29;
          }
          v25 = v30[8];
          v20 = v31 + 16;
          v31 = v20;
          v26 = v20 >= v25;
          v14 = (int)v30;
        }
        while ( !v26 );
      }
      else if ( v16 == 8210 )
      {
        while ( *(_WORD *)v15 )
        {
          v13 += 2 * (wcslen((unsigned __int16 *)v15) + 2);
          if ( v13 <= v6 )
          {
            v9 = RtlStringCbPrintfExW(v5, v7, &v28, &v29, 1024, L"[%s]", v15);
            if ( v9 < 0 )
              return v9;
            v5 = v28;
            v7 = v29;
          }
          v15 += 2 * wcslen((unsigned __int16 *)v15) + 2;
        }
      }
      else
      {
LABEL_74:
        v9 = -1073741811;
      }
      goto LABEL_88;
    }
    if ( v16 == 4099 )
      goto LABEL_88;
    switch ( v16 )
    {
      case 0u:
      case 1u:
        return -1073741811;
      case 2u:
      case 3u:
        v13 += 12;
        if ( v13 > v6 )
          goto LABEL_88;
        v17 = RtlStringCbPrintfExW(v5, v7, &v28, &v29, 1024, L"(0x%.2x)", *v15);
        break;
      case 4u:
      case 5u:
        v13 += 16;
        if ( v13 > v6 )
          goto LABEL_88;
        v17 = RtlStringCbPrintfExW(v5, v7, &v28, &v29, 1024, L"(0x%.4x)", *(__int16 *)v15);
        break;
      case 6u:
      case 7u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
        v13 += 24;
        if ( v13 > v6 )
          goto LABEL_88;
        v17 = RtlStringCbPrintfExW(v5, v7, &v28, &v29, 1024, L"(0x%.8x)", *(_DWORD *)v15);
        break;
      case 8u:
      case 9u:
        v13 += 40;
        if ( v13 > v6 )
          goto LABEL_88;
        v17 = RtlStringCbPrintfExW(v5, v7, &v28, &v29, 1024, L"(0x%.16I64x)", *(_DWORD *)v15, *((_DWORD *)v15 + 1));
        break;
      case 0xAu:
      case 0xBu:
        v13 += 32;
        if ( v13 > v6 )
          goto LABEL_88;
        if ( v16 == 10 )
          v18 = *(float *)v15;
        else
          v18 = *(double *)v15;
        v17 = RtlStringCbPrintfExW(v5, v7, &v28, &v29, 1024, L"(%.6e)", v18);
        break;
      case 0xCu:
      case 0xEu:
      case 0xFu:
      case 0x10u:
      case 0x13u:
      case 0x15u:
        goto LABEL_88;
      case 0xDu:
        v14 = (int)v30;
        goto LABEL_82;
      case 0x11u:
        if ( (char)*v15 == -1 )
          v19 = L"(TRUE)";
        else
          v19 = L"(FALSE)";
        v13 += 2 * wcslen((unsigned __int16 *)v19);
        if ( v13 > v6 )
          goto LABEL_88;
        v17 = RtlStringCbCopyExW(v5, v7, v19, &v28, &v29, 1024);
        break;
      case 0x12u:
      case 0x14u:
      case 0x19u:
        v13 += 2 * wcslen((unsigned __int16 *)v30[9]);
        if ( v13 > v6 )
          goto LABEL_88;
        v17 = RtlStringCbPrintfExW(v5, v7, &v28, &v29, 1024, L"(%s)", v15);
        break;
      default:
        goto LABEL_74;
    }
    v9 = v17;
    if ( v17 >= 0 )
    {
LABEL_88:
      if ( v32 )
        *v32 = v13;
      if ( v13 > v6 )
        v9 = -1073741789;
      return v9;
    }
  }
  return v9;
}
