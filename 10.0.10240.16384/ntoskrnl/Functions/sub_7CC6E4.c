// sub_7CC6E4 
 
void __fastcall sub_7CC6E4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int *a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20)
{
  int v20; // r8
  unsigned int *v21; // r10
  int v22; // r0
  unsigned int v23; // r4
  int v24; // r6
  int v25; // r5
  unsigned int v26; // r9
  _DWORD *v27; // r7
  int v28; // r2
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r0
  int v33; // r0
  int v34; // r0
  int v35; // r0

  if ( !SdbTagRefToTagID(v20, a1, &a9, &a10) || (v22 = SdbFindFirstTag(a9, a10, 28710)) == 0 )
    JUMPOUT(0x770194);
  v23 = 0;
  do
  {
    v22 = SdbFindNextTag(a9, a10, v22);
    ++v23;
  }
  while ( v22 );
  *v21 = v23;
  v24 = KsepPoolAllocatePaged(52 * v23);
  if ( v24 )
  {
    v25 = SdbFindFirstTag(a9, a10, 28710);
    v26 = 0;
    if ( !v25 )
    {
LABEL_21:
      *a11 = v24;
      JUMPOUT(0x7701A0);
    }
    v27 = (_DWORD *)v24;
    while ( 1 )
    {
      if ( v26 < *v21 )
      {
        v28 = SdbFindFirstTag(a9, v25, 36880);
        if ( v28 )
        {
          SdbReadGUIDTag(&a17, a9, v28, a13);
          v29 = a18;
          v30 = a19;
          v31 = a20;
          *v27 = a17;
          v27[1] = v29;
          v27[2] = v30;
          v27[3] = v31;
        }
        v32 = SdbFindFirstTag(a9, v25, 24577);
        if ( v32 && KsepDbGetSdbString(a9, v32, v27 + 4) < 0 )
          break;
        v33 = SdbFindFirstTag(a9, v25, 24579);
        if ( v33 )
        {
          if ( KsepDbGetSdbString(a9, v33, v27 + 6) < 0 )
            break;
        }
        v34 = SdbFindFirstTag(a9, v25, 16407);
        if ( v34 )
          v27[10] = SdbReadDWORDTag(a9, v34, 0);
        v35 = SdbFindFirstTag(a9, v25, 24584);
        if ( v35 )
        {
          if ( KsepDbGetSdbString(a9, v35, v27 + 8) < 0 )
            break;
        }
        v27[11] = 1;
      }
      v25 = SdbFindNextTag(a9, a10, v25);
      v27 += 13;
      ++v26;
      if ( !v25 )
        goto LABEL_21;
    }
  }
  JUMPOUT(0x770196);
}
