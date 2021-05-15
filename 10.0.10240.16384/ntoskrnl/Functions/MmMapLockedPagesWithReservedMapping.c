// MmMapLockedPagesWithReservedMapping 
 
int __fastcall MmMapLockedPagesWithReservedMapping(unsigned int a1, int a2, _DWORD *a3, int a4)
{
  unsigned int v5; // lr
  _DWORD *v6; // r5
  int v7; // r7
  _DWORD *v8; // r6
  unsigned int v9; // r2
  unsigned int v11; // r2

  v5 = (a3[5] + (((unsigned __int16)a3[6] + (unsigned __int16)a3[4]) & 0xFFFu) + 4095) >> 12;
  v6 = (_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v7 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 1073741828);
  v8 = (_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 1073741832);
  if ( (a2 & 0xFFFFF01C) != v7 )
    KeBugCheckEx(218, 260, a1, a2, v7);
  v9 = *v8 >> 12;
  if ( v9 <= 2 )
    KeBugCheckEx(218, 261, a1, a2, *v8 >> 12);
  if ( v5 > v9 - 2 )
    return 0;
  v11 = (unsigned int)&v6[v9 - 2];
  while ( (unsigned int)v6 < v11 )
  {
    if ( *v6++ )
      KeBugCheckEx(218, 263, a1, (int)(v6 - 1), v11);
  }
  return MiMapMdlCommon((int)a3, ((a1 >> 10) & 0x3FFFFC) - 0x40000000, v11, a4);
}
