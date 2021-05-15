// RtlLookupEntryHashTable 
 
int __fastcall RtlLookupEntryHashTable(_DWORD *a1, unsigned int a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // r5
  int v7; // r3
  __int64 v8; // r0
  _DWORD *v9; // r2
  unsigned int v10; // r3
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a2;
  v11[1] = a3;
  v11[2] = a4;
  v4 = a3;
  if ( !a3 )
    v4 = v11;
  if ( (a1[4] & ((69069 * (a2 >> a1[1]) + 1) & 0xFFFF0000 | ((1103515245 * (a2 >> a1[1]) + 12345) >> 16))) < a1[3] )
    return sub_517F88();
  v7 = a1[8];
  if ( a1[2] > 0x80u )
    v7 = *(_DWORD *)(v7 + 4 * ((unsigned __int16)(a1[4] & ((1103515245 * (a2 >> a1[1]) + 12345) >> 16)) >> 7));
  LODWORD(v8) = v7 + 8 * ((_BYTE)a1[4] & (unsigned __int8)((1103515245 * (a2 >> a1[1]) + 12345) >> 16) & 0x7F);
  HIDWORD(v8) = v8;
  if ( *(_DWORD *)v8 != (_DWORD)v8 )
  {
    do
    {
      v9 = (_DWORD *)*(_DWORD *)HIDWORD(v8);
      v10 = *(_DWORD *)(*(_DWORD *)HIDWORD(v8) + 8);
      if ( v10 >= a2 && v10 )
        break;
      HIDWORD(v8) = *(_DWORD *)HIDWORD(v8);
    }
    while ( *v9 != (_DWORD)v8 );
  }
  *(_QWORD *)v4 = v8;
  v4[2] = a2;
  if ( (_DWORD)v8 == *(_DWORD *)HIDWORD(v8) )
    return 0;
  if ( *(_DWORD *)(*(_DWORD *)HIDWORD(v8) + 8) == a2 )
    return *(_DWORD *)HIDWORD(v8);
  return 0;
}
