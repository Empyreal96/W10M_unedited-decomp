// MiScanRelocationPage 
 
int __fastcall MiScanRelocationPage(int a1, unsigned int a2, int a3, unsigned __int16 *a4, _DWORD *a5)
{
  _DWORD *v6; // r0
  int v7; // r6
  int v9; // r1
  unsigned int v10; // r9
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // r4
  int result; // r0
  int v16; // [sp+10h] [bp-38h]
  int v17; // [sp+18h] [bp-30h]
  char v19[40]; // [sp+20h] [bp-28h] BYREF

  v16 = 0;
  v17 = 0;
  v6 = a5;
  v7 = a3;
  v9 = 0;
  v10 = *(_DWORD *)(*(_DWORD *)(*a5 + 36) + 48);
  if ( !a3 )
    return 0;
  while ( 1 )
  {
    v11 = *a4;
    --v7;
    v12 = v11 >> 12;
    v13 = v11 & 0xFFF;
    v14 = v13;
    switch ( v12 )
    {
      case 3u:
        if ( v13 > 0xFFC )
          return sub_7D4EE0();
        break;
      case 0u:
        goto LABEL_7;
      case 7u:
        if ( v13 > 0xFF8 )
        {
          v9 = 1;
          v16 = 8;
        }
        break;
      default:
        return -1073741207;
    }
    if ( (a2 & 0xFFF) != 0 && (a2 & 0xFFF) + v13 > 0xFFE || v13 + a2 < v10 )
      return -1073741207;
LABEL_7:
    if ( v9 == 1 )
      break;
LABEL_8:
    ++a4;
    if ( !v7 )
      return 0;
  }
  if ( v17 != 1 )
  {
    result = MiCreateFixupRecord(v6, a1, v13 + a2);
    if ( result < 0 )
      return result;
    if ( (BYTE2(MiFlags) & 3) != 3
      || (MiOffsetToProtos(a5, (unsigned int)v16 + (unsigned __int64)v14 + a2, (int)v19)[4] & 4) == 0 )
    {
      v9 = 0;
      v6 = a5;
      v17 = 1;
      goto LABEL_8;
    }
  }
  return -1073741701;
}
