// MiUnlinkStandbyBatch 
 
int __fastcall MiUnlinkStandbyBatch(int a1, int *a2, int a3, int a4, int a5, int *a6)
{
  int v6; // r6
  int *v8; // r5
  int v9; // r10
  int v10; // r0
  int v11; // r4
  int v12; // t1
  int v14; // r3
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned int *v19; // r2
  unsigned int v20; // r0

  v6 = a5;
  v8 = a2;
  if ( a5 )
  {
    v9 = a4 - (_DWORD)a2;
    do
    {
      v10 = MiTryLockLeafPage(v8, 1);
      v11 = v10;
      if ( !v10 )
        break;
      v12 = *v8++;
      if ( (v12 & 2) != 0 )
      {
        __dmb(0xBu);
        v17 = (unsigned int *)(v10 + 12);
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 & 0x7FFFFFFF, v17) );
        return a5 - v6;
      }
      if ( (*(_BYTE *)(v10 + 18) & 0x20) != 0 || (*(_BYTE *)(v10 + 19) & 0x40) != 0 )
        goto LABEL_22;
      if ( (unsigned int)dword_640580 < 0x80 )
        return sub_51F008();
      if ( (*(_BYTE *)(v10 + 18) & 7) != 2
        || ((*(_BYTE *)(v10 + 19) & 8) != 0 ? (v14 = 5) : (v14 = *(_BYTE *)(v10 + 19) & 7), v14 != a3) )
      {
LABEL_22:
        __dmb(0xBu);
        v19 = (unsigned int *)(v10 + 12);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 & 0x7FFFFFFF, v19) );
        return a5 - v6;
      }
      if ( !MiUnlinkPageFromList(v10, 1) )
      {
        *a6 = v11;
        return a5 - v6;
      }
      MiReadyStandbyPageForActive(v11, (char *)v8 + v9);
      __dmb(0xBu);
      v15 = (unsigned int *)(v11 + 12);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 & 0x7FFFFFFF, v15) );
      --v6;
    }
    while ( v6 );
  }
  return a5 - v6;
}
