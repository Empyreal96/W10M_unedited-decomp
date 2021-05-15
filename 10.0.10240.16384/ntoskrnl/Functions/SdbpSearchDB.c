// SdbpSearchDB 
 
int __fastcall SdbpSearchDB(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int v7; // r6
  char v9[72]; // [sp+20h] [bp-48h] BYREF

  memset(a5, 0, 128);
  v7 = *(_DWORD *)(a4 + 20);
  if ( SdbGetIndex(a2, 28679, 24587, 0) )
    return sub_7CCD38();
  if ( !SdbGetIndex(a2, 28679, 24577, 0) )
    JUMPOUT(0x7CCD8A);
  if ( SdbFindFirstStringIndexedTag(a2, 28679, 24577, v7, (int)v9) )
    JUMPOUT(0x7CCDC8);
  if ( *(_DWORD *)(a4 + 24) )
    JUMPOUT(0x7CCE18);
  if ( SdbGetIndex(a2, 28679, 24587, 0) )
    JUMPOUT(0x7CCEC6);
  return 0;
}
