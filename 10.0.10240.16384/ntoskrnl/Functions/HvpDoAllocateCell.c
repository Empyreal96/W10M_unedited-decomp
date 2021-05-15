// HvpDoAllocateCell 
 
int __fastcall HvpDoAllocateCell(int a1, unsigned int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v6; // r4
  unsigned int v9; // r0
  int v10; // r10
  int v11; // r8
  unsigned __int8 *v12; // r0
  unsigned int v13; // r2
  int v14; // r8
  unsigned int *v15; // r4
  unsigned int v16; // r1
  unsigned int v17; // r6
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r3
  unsigned int *v21; // r6
  unsigned int v22; // r1
  int v24; // r0
  int v25; // [sp+8h] [bp-30h] BYREF
  unsigned __int8 *v26; // [sp+Ch] [bp-2Ch]
  unsigned int v27; // [sp+10h] [bp-28h] BYREF
  _DWORD *v28; // [sp+14h] [bp-24h]

  v6 = (a2 >> 3) - 1;
  v28 = a4;
  v25 = -1;
  if ( v6 >= 0x10 )
  {
    if ( v6 >> 4 > 0xFF )
      v6 = 23;
    else
      v6 = 47 - __clz(v6 >> 4);
  }
  v9 = *(_DWORD *)(a1 + 1868);
  v10 = 0;
  v26 = *(unsigned __int8 **)(a1 + 1868);
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = KeAbPreAcquire(v9, 0, 0);
  v12 = v26;
  do
    v13 = __ldrex(v26);
  while ( __strex(v13 & 0xFE, v26) );
  __dmb(0xBu);
  if ( (v13 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)v26, v11);
    v12 = v26;
  }
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  *((_DWORD *)v12 + 1) = v27;
  v14 = HvpFindFreeCell(a1, v6, a2, a3, &v27, &v25);
  if ( v14 == -1 )
  {
    v24 = HvpAddBin(a1, a2, a3);
    if ( v24 == -1 )
      JUMPOUT(0x8042A2);
    v14 = v24 + 32;
    v15 = (unsigned int *)HvpGetHCell(a1, v24 + 32, &v25);
    if ( !v15 )
      return sub_804284();
    v10 = 1;
  }
  else
  {
    v15 = (unsigned int *)v27;
  }
  v16 = *v15;
  if ( a2 + 8 > *v15 )
  {
    HvpDelistFreeCell(a1, v14);
    *v15 = -*v15;
  }
  else
  {
    v17 = v16 - a2;
    *(unsigned int *)((char *)v15 + a2) = v16 - a2;
    *v15 = -a2;
    if ( !v10 )
    {
      v18 = (v16 >> 3) - 1;
      if ( v18 >= 0x10 )
      {
        if ( v18 >> 4 > 0xFF )
          v18 = 23;
        else
          v18 = 47 - __clz(v18 >> 4);
      }
      v19 = (v17 >> 3) - 1;
      if ( v19 >= 0x10 )
      {
        v20 = v19 >> 4;
        if ( v20 > 0xFF )
          v19 = 23;
        else
          v19 = 47 - __clz(v20);
      }
      if ( v18 == v19 )
        goto LABEL_19;
      HvpRemoveFreeCellHint(a1, v14, v18, a3);
    }
    HvpEnlistFreeCell(a1, v14 + a2, v17, a3, 1);
  }
LABEL_19:
  v21 = *(unsigned int **)(a1 + 1868);
  v21[1] = 0;
  __dmb(0xBu);
  do
    v22 = __ldrex(v21);
  while ( !v22 && __strex(1u, v21) );
  if ( v22 )
    ExpReleaseFastMutexContended(v21, v22);
  KeAbPostRelease((unsigned int)v21);
  if ( v28 )
  {
    *v28 = v15 + 1;
    *a5 = v25;
  }
  else
  {
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v25);
  }
  return v14;
}
