// CmpDoSystemCacheWrite 
 
BOOL __fastcall CmpDoSystemCacheWrite(int a1, int *a2, unsigned int a3, int *a4, char a5)
{
  int v5; // r3
  unsigned int i; // r6
  int v9; // r10
  int v10; // r2
  unsigned int v11; // r8
  int v12; // r5
  int v13; // r4
  int v15; // r0
  int v17; // [sp+4h] [bp-3Ch]
  int v18; // [sp+8h] [bp-38h]
  int v19; // [sp+Ch] [bp-34h]
  int v20; // [sp+10h] [bp-30h]
  int v21; // [sp+14h] [bp-2Ch]
  int v22; // [sp+18h] [bp-28h]

  v5 = a1;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  if ( (a5 & 1) != 0 )
  {
    v18 = CmpSetIoPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
    v15 = CmpSetPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 4);
    v17 = 1;
    v5 = a1;
    v19 = v15;
  }
  for ( i = 0; i < a3; a2 += 3 )
  {
    v9 = a2[1];
    v20 = a2[2];
    v21 = *a2;
    v10 = *a2 + v20;
    v11 = (v10 + 4095) & 0xFFFFF000;
    v12 = *a2 & 0xFFFFF000;
    v22 = v10;
    if ( v9 )
    {
      v13 = HvViewMapPinForFileOffset(v5 + 152, v12, v11 - v12);
      if ( v13 < 0 )
        goto LABEL_10;
      v13 = HvViewMapCopyToFileOffset(a1 + 152, v21, v9, v20);
      if ( v13 < 0 )
        goto LABEL_10;
      v10 = v22;
    }
    *a4 = v10;
    v13 = HvViewMapFlush(a1 + 152, v12, v11 - v12);
    if ( v13 < 0 )
      goto LABEL_10;
    if ( v9 )
      HvViewMapUnpinForFileOffset(a1 + 152, v12, v11 - v12);
    ++i;
    v5 = a1;
  }
  v13 = 0;
LABEL_10:
  if ( v17 )
  {
    CmpSetIoPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v18);
    CmpSetPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v19);
  }
  return v13 >= 0;
}
