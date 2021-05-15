// SmProcessEmptyRequest 
 
int __fastcall SmProcessEmptyRequest(unsigned __int8 *a1, int a2, int a3, char a4)
{
  int v4; // r6
  _BYTE *v8; // r0
  int v10; // r5
  unsigned __int8 *v11; // r10
  unsigned int v12; // r9
  unsigned int v13; // t1
  unsigned __int8 *v14; // r4
  unsigned int *v15; // r6
  unsigned int v16; // r0
  unsigned int v17; // r1
  _DWORD *v18; // r4
  unsigned int v19; // r4
  unsigned int v20; // r1
  unsigned __int8 *v21; // r0
  unsigned int v22; // r4
  unsigned int v23; // r1
  unsigned __int8 v25[168]; // [sp+8h] [bp-A8h] BYREF

  v4 = a4;
  v8 = memset(v25, 0, 132);
  if ( a3 == 132 )
  {
    if ( v4 && (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v8);
    memmove((int)v25, a2, 0x84u);
    if ( v25[0] != 2 )
      return -1073741811;
    v10 = v25[1];
    if ( v25[1] > 0x20u || !v25[1] || (*(_DWORD *)v25 & 0xFFFF0000) != 0 )
      return -1073741811;
    v11 = v25;
    while ( 1 )
    {
      v13 = *((_DWORD *)v11 + 1);
      v11 += 4;
      v12 = v13;
      v14 = &a1[96 * (v13 & 0x1F)];
      v15 = (unsigned int *)(v14 + 4);
      __pld(v14 + 4);
      v16 = *((_DWORD *)v14 + 1) & 0xFFFFFFFE;
      do
        v17 = __ldrex(v15);
      while ( v17 == v16 && __strex(v16 + 2, v15) );
      __dmb(0xBu);
      if ( v17 != v16 && !ExfAcquireRundownProtection((_DWORD *)v14 + 1) )
        goto LABEL_23;
      if ( (*((_WORD *)v14 + 6) & 0x7FF) != v12 >> 5 )
        break;
      v18 = *(_DWORD **)v14;
LABEL_24:
      if ( v18 )
      {
        if ( (*v18 & 0x40000) == 0 )
          SMKM_STORE_MGR<SM_TRAITS>::SmEmptyStore(a1, v18[878] & 0x1F, 0);
        v21 = &a1[96 * (v18[878] & 0x1F) + 4];
        __pld(v21);
        v22 = *(_DWORD *)v21 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v23 = __ldrex((unsigned int *)v21);
        while ( v23 == v22 && __strex(v22 - 2, (unsigned int *)v21) );
        if ( v23 != v22 )
          ExfReleaseRundownProtection(v21);
      }
      if ( !--v10 )
        return 0;
    }
    __pld(v15);
    v19 = *v15 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v20 = __ldrex(v15);
    while ( v20 == v19 && __strex(v19 - 2, v15) );
    if ( v20 != v19 )
      ExfReleaseRundownProtection((unsigned __int8 *)v15);
LABEL_23:
    v18 = 0;
    goto LABEL_24;
  }
  return -1073741306;
}
