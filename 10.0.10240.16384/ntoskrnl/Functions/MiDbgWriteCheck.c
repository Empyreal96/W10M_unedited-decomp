// MiDbgWriteCheck 
 
int __fastcall MiDbgWriteCheck(unsigned int a1, unsigned int *a2, int a3)
{
  unsigned int v5; // r4
  unsigned int v6; // r1
  unsigned int *v7; // r5
  unsigned int v8; // r6
  char *v9; // r2
  unsigned int v11; // r1
  unsigned int v12; // r6
  unsigned int v13; // r3
  int v14; // r7
  unsigned int v15; // r1
  int v16; // r0

  *a2 = 0;
  v5 = a1;
  if ( !MiIsAddressValid(a1, 0, a3, 0) )
    return 0;
  if ( (*(_DWORD *)(((v5 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return v5;
  v7 = (unsigned int *)(((v5 >> 10) & 0x3FFFFC) - 0x40000000);
  v8 = *v7;
  v9 = (char *)(((unsigned int)MiFlags >> 12) & 1);
  if ( v9 && (MiFlags & 0x30000) == 0 || !v9 )
  {
    if ( (v8 & 0x80) != 0 && (v8 & 0x200) == 0 )
    {
LABEL_7:
      if ( (MiFlags & 0x100) == 0 )
        KeFlushSingleCurrentTb(v5, v6, (int)v9, MiFlags);
      return v5;
    }
    if ( a3 && MiDbgMarkPfnModified(v5, *v7) )
    {
      *a2 = v8;
      do
        v11 = __ldrex((unsigned int *)algn_63458C);
      while ( __strex(v11 + 1, (unsigned int *)algn_63458C) );
      __dmb(0xBu);
      v12 = v8 & 0xFFFFFDFF | 0x90;
      v13 = *v7;
      v14 = 0;
      __dmb(0xBu);
      *v7 = v12;
      if ( (v13 & 2) == 0 && (v12 & 2) != 0 )
        v14 = 1;
      if ( (unsigned int)v7 >= 0xC0300000 && (unsigned int)v7 <= 0xC0300FFF )
      {
        v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * ((v5 >> 10) & 0xFFC)), v12);
      }
      if ( v14 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
      __dmb(0xBu);
      v9 = algn_63458C;
      do
      {
        v15 = __ldrex((unsigned int *)algn_63458C);
        v6 = v15 - 1;
      }
      while ( __strex(v6, (unsigned int *)algn_63458C) );
      goto LABEL_7;
    }
    return 0;
  }
  return sub_55257C();
}
