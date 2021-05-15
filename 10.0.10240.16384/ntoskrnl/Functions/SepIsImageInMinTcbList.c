// SepIsImageInMinTcbList 
 
int __fastcall SepIsImageInMinTcbList(int a1, unsigned int a2, int a3, int a4, unsigned __int8 a5, _BYTE *a6, _BYTE *a7, _BYTE *a8)
{
  char v8; // r10
  unsigned __int16 *v9; // r3
  unsigned int v10; // r5
  int v12; // r7
  int v13; // r6
  int v14; // r9
  int v15; // r8
  int v17; // r4
  unsigned int v18; // r2
  unsigned int v19; // r5
  _BYTE *v20; // r4
  int v21; // r2
  int var28[16]; // [sp+8h] [bp-28h] BYREF

  var28[12] = a1;
  var28[13] = a2;
  var28[14] = a3;
  var28[15] = a4;
  v8 = a4;
  v9 = (unsigned __int16 *)a3;
  v10 = 0;
  var28[0] = a3;
  v12 = a1;
  if ( !a2 )
    return -1073741275;
  v13 = a1;
  v14 = dword_61A1F0;
  while ( 1 )
  {
    if ( RtlEqualUnicodeString(v9, (unsigned __int16 *)v13, 1) )
    {
      v17 = *(_DWORD *)(v13 + 12);
      if ( !v17 || v17 == v14 )
        break;
    }
    ++v10;
    v13 += 16;
    if ( v10 >= a2 )
      return -1073741275;
    v9 = (unsigned __int16 *)var28[0];
  }
  v18 = v12 + 16 * v10;
  v19 = *(unsigned __int8 *)(v18 + 10);
  v15 = 0;
  if ( *(_BYTE *)(v18 + 10) )
  {
LABEL_10:
    *a6 = *((_BYTE *)SeProtectedMapping + 2 * (v19 >> 4));
    *a7 = *((_BYTE *)SeProtectedMapping + 2 * (v19 >> 4) + 1);
    if ( !SeCompareSigningLevels() )
      *a6 = SeILSigningPolicy;
    if ( !SeCompareSigningLevels() )
      *a7 = SeILSigningPolicy;
    if ( (v19 & 7) != 1 && ((v8 & 1) != 0 || (v19 & 7) == 2) )
    {
      if ( (*a7 & 0xFu) < 4 )
        *a7 = *a6;
      v20 = a8;
      *a8 = v19 & 0xF0 | *a8 & 8 | 2;
    }
    else
    {
      v20 = a8;
      *a8 = v19;
    }
    if ( !*v20 && !*a7 && RtlpOpenImageFileOptionsKey(var28[0]) >= 0 )
    {
      if ( RtlQueryImageFileKeyOption(var28[1], L"AuditLevel", 4, var28, 4, 0) >= 0 )
      {
        v21 = var28[0] & 0xF;
        if ( (unsigned int)(v21 - 2) <= 0xD )
        {
          *a7 = v21;
          *v20 = 8;
        }
      }
      ZwClose();
    }
    return v15;
  }
  if ( a5 )
  {
    v19 = a5;
    goto LABEL_10;
  }
  return sub_7D5A60();
}
