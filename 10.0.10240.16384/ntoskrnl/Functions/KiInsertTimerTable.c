// KiInsertTimerTable 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiInsertTimerTable(int a1, _DWORD *a2, int a3, unsigned int a4, char *a5)
{
  unsigned int v5; // r8
  char v6; // r5
  unsigned int v7; // r9 OVERLAPPED
  unsigned int v8; // r10 OVERLAPPED
  char *v10; // r2
  char *v11; // r7
  _DWORD *v12; // r4
  _DWORD *v13; // r0
  unsigned int v14; // r2
  _DWORD *v15; // r3
  unsigned int v16; // r6
  _DWORD *v17; // r2
  unsigned int v18; // r3
  _DWORD *v19; // r4
  _DWORD *v20; // r2
  char v21; // r3
  _DWORD *v22; // r2
  _DWORD *v23; // r4
  unsigned int v24; // r2
  unsigned int v25; // r1
  char v26; // r3
  int v27; // r1
  int v28; // r1
  int v29; // r2
  int v30; // r0
  unsigned __int8 *v31; // r3
  unsigned int v32; // r2
  _DWORD *v33; // r1 OVERLAPPED
  _DWORD *v34; // r2 OVERLAPPED
  int v35; // r1
  int v36; // r2
  int v37; // r1
  int v38; // r0
  unsigned __int8 *v39; // r3
  unsigned int v40; // r2
  char *v41; // [sp+0h] [bp-30h]
  unsigned int v43; // [sp+8h] [bp-28h]

  v5 = a4;
  v6 = 0;
  if ( !a2[10] )
    a2[1] = 0;
  *(_QWORD *)&v7 = *((_QWORD *)a2 + 2);
  v43 = a2[4];
  if ( !KiSerializeTimerExpiration )
    return sub_52F19C(a1);
  a2[9] = 0;
  v41 = (char *)KiProcessorBlock + 4096;
  v10 = (char *)KiProcessorBlock + 24 * a4 + 4096;
  v11 = v10 + 256;
  v12 = v10 + 260;
  v13 = v10 + 260;
  while ( 1 )
  {
    do
      v14 = __ldrex((unsigned int *)v11);
    while ( __strex(1u, (unsigned int *)v11) );
    __dmb(0xBu);
    if ( !v14 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *(_DWORD *)v11 );
  }
  v15 = (_DWORD *)*v12;
  if ( (_DWORD *)*v12 == v12 )
  {
    v6 = 6;
    goto LABEL_20;
  }
  v16 = *(v15 - 2);
  v17 = (_DWORD *)*v12;
  v18 = *(v15 - 1);
  if ( v8 < v18 )
    goto LABEL_18;
  if ( v8 <= v18 && v7 <= v16 )
  {
    if ( __PAIR64__(v8, v7) >= __PAIR64__(v18, v16) )
    {
      v21 = 0;
      goto LABEL_19;
    }
LABEL_18:
    v21 = 1;
LABEL_19:
    v6 = 2 * (v21 & 1);
    goto LABEL_20;
  }
  if ( __PAIR64__(v8, v7) - __PAIR64__(v18, v16) > (unsigned int)KeMaximumIncrement >> 2 )
  {
    v13 = (_DWORD *)v12[1];
    do
    {
      if ( __PAIR64__(v8, v7) >= *((_QWORD *)v13 - 1) )
        break;
      v13 = (_DWORD *)v13[1];
    }
    while ( v13 != v12 );
  }
  else
  {
    v19 = (_DWORD *)v12[1];
    v13 = v17;
    if ( v17 != v19 )
    {
      do
      {
        v20 = (_DWORD *)*v13;
        if ( __PAIR64__(v8, v7) <= *(_QWORD *)(*v13 - 8) )
          break;
        v13 = (_DWORD *)*v13;
      }
      while ( v20 != v19 );
    }
  }
LABEL_20:
  v22 = (_DWORD *)*v13;
  v23 = a2 + 6;
  a2[6] = *v13;
  a2[7] = v13;
  if ( (_DWORD *)v22[1] != v13 )
    __fastfail(3u);
  v22[1] = v23;
  *v13 = v23;
  if ( (v6 & 2) != 0 )
  {
    *((_QWORD *)v11 + 2) = *(_QWORD *)&v7;
    __dmb(0xFu);
    if ( (v6 & 4) != 0 )
    {
      v27 = KiPendingTimerBitmaps[2 * (unsigned __int8)*(v41 - 3044) + 1];
      if ( KiSerializeTimerExpiration )
      {
        v28 = v27 + 4 * (v5 >> 5);
        v29 = v5 & 0x1F;
      }
      else
      {
        v29 = (unsigned __int8)*(v41 - 3043);
        v28 = v27 + (v5 << 7);
      }
      __dmb(0xBu);
      v30 = 1 << (v29 & 7);
      v31 = (unsigned __int8 *)(v28 + (v29 >> 3));
      do
        v32 = __ldrex(v31);
      while ( __strex(v32 | v30, v31) );
      __dmb(0xBu);
    }
    while ( 1 )
    {
      v24 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v25 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v24 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
    if ( v8 <= v24 && (v8 < v24 || v43 <= v25) )
    {
      if ( a5 )
      {
        v26 = 1;
        goto LABEL_28;
      }
      *(_QWORD *)&v33 = *(_QWORD *)v23;
      v6 |= 1u;
      if ( *(_DWORD **)(*v23 + 4) != v23 || (_DWORD *)*v34 != v23 )
        __fastfail(3u);
      *v34 = v33;
      v33[1] = v34;
      if ( v34 != v33 )
      {
        v26 = 0;
        goto LABEL_28;
      }
      *((_DWORD *)v11 + 5) = -1;
      v35 = KiPendingTimerBitmaps[2 * (unsigned __int8)*(v41 - 3044) + 1];
      if ( KiSerializeTimerExpiration )
      {
        v36 = a4 & 0x1F;
        v37 = v35 + 4 * (a4 >> 5);
      }
      else
      {
        v36 = (unsigned __int8)*(v41 - 3043);
        v37 = v35 + (a4 << 7);
      }
      __dmb(0xBu);
      v38 = 1 << (v36 & 7);
      v39 = (unsigned __int8 *)(v37 + (v36 >> 3));
      do
        v40 = __ldrex(v39);
      while ( __strex(v40 & ~(_BYTE)v38, v39) );
      __dmb(0xBu);
    }
  }
  v26 = 0;
LABEL_28:
  __dmb(0xBu);
  *(_DWORD *)v11 = 0;
  if ( a5 )
    *a5 = v26;
  return (v6 & 1) == 0;
}
