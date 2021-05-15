// MiIsSubsectionClean 
 
int __fastcall MiIsSubsectionClean(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r5
  unsigned int v5; // r4
  unsigned int v6; // r8
  int v7; // r6
  int v8; // r7
  int v9; // r0
  unsigned int v10; // t1
  unsigned int *v11; // r2
  unsigned int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r4
  int v20[8]; // [sp+0h] [bp-20h] BYREF

  v20[0] = a4;
  if ( !a1[16] )
    return 0;
  v5 = a1[1];
  v4 = 0;
  v6 = v5 + 4 * a1[7];
  if ( !*(_DWORD *)(*a1 + 16) )
    return 0;
  v7 = 17;
  v8 = 0;
  LOBYTE(v20[0]) = 17;
  if ( v5 >= v6 )
    goto LABEL_33;
  while ( 1 )
  {
    if ( (v5 & 0xFFF) == 0 || v7 == 17 )
    {
      if ( v7 != 17 )
        MiUnlockProtoPoolPage(v8, v7);
      v8 = MiCheckProtoPtePageState(v5, v20);
      v7 = LOBYTE(v20[0]);
      if ( !v8 )
      {
        v5 = (v5 & 0xFFFFF000) + 4096;
        goto LABEL_19;
      }
    }
    v9 = MiLockLeafPage((unsigned int *)v5, 0);
    if ( !v9 )
    {
      v5 += 4;
      goto LABEL_19;
    }
    v10 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 2) != 0 )
      break;
    if ( *(_WORD *)(v9 + 16) )
    {
      __dmb(0xBu);
      v15 = (unsigned int *)(v9 + 12);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 & 0x7FFFFFFF, v15) );
      v4 = 2;
      goto LABEL_33;
    }
    if ( (*(_BYTE *)(v9 + 18) & 0x10) != 0 || (*(_BYTE *)(v9 + 18) & 8) != 0 )
    {
      __dmb(0xBu);
      v13 = (unsigned int *)(v9 + 12);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 & 0x7FFFFFFF, v13) );
      v4 = 1;
      goto LABEL_33;
    }
    __dmb(0xBu);
    v11 = (unsigned int *)(v9 + 12);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 & 0x7FFFFFFF, v11) );
LABEL_19:
    if ( v5 >= v6 )
      goto LABEL_33;
  }
  if ( (*(_BYTE *)(v9 + 18) & 0x10) != 0 || (*(_BYTE *)(v9 + 18) & 8) != 0 )
    v4 = 1;
  else
    v4 = 2;
  __dmb(0xBu);
  v17 = (unsigned int *)(v9 + 12);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 & 0x7FFFFFFF, v17) );
LABEL_33:
  if ( v7 != 17 )
    MiUnlockProtoPoolPage(v8, v7);
  return v4;
}
