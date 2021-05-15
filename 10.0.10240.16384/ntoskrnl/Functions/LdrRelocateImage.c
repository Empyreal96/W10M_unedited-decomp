// LdrRelocateImage 
 
int __fastcall LdrRelocateImage(int a1)
{
  int v2; // r0
  int v3; // r4
  int result; // r0
  _DWORD *v5; // r0
  int v6; // r7
  int v7; // r2
  int v8[6]; // [sp+8h] [bp-18h] BYREF

  v8[0] = 0;
  v2 = RtlImageNtHeader(a1);
  v3 = v2;
  if ( !v2 )
    return -1073741701;
  if ( *(_WORD *)(v2 + 24) != 267 )
    return sub_80E954();
  v5 = (_DWORD *)RtlImageDirectoryEntryToData(a1, 1, 5, (int)v8);
  if ( v5 )
  {
    v6 = v8[0];
    if ( v8[0] )
    {
      while ( 1 )
      {
        v7 = v5[1];
        v6 -= v7;
        v5 = (_DWORD *)LdrProcessRelocationBlockLongLong(
                         *(unsigned __int16 *)(v3 + 4),
                         *v5 + a1,
                         (unsigned int)(v7 - 8) >> 1,
                         v5 + 2);
        if ( !v5 )
          return -1073741701;
        if ( !v6 )
          goto LABEL_8;
      }
    }
  }
  if ( (*(_WORD *)(v3 + 22) & 1) != 0 )
    result = -1073741800;
  else
LABEL_8:
    result = 0;
  return result;
}
