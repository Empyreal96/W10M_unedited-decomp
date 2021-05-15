// MiResolvePageTablePage 
 
int __fastcall MiResolvePageTablePage(int a1, unsigned int a2, int *a3, int a4, unsigned __int8 a5, char a6)
{
  int *v7; // r7
  unsigned int v8; // lr
  int v9; // r10
  unsigned int v10; // r8
  unsigned int v11; // r6
  int *v12; // r9
  int v13; // r4
  int *v14; // t1
  int v15; // r2
  unsigned int v17; // r2
  unsigned int v18; // r3
  _DWORD *v19; // r1
  int v20; // r0
  int v21; // r2
  int v22; // r0
  int v23; // r2
  int *v24; // r1
  _DWORD *v25; // t1
  int v26; // r3
  unsigned int v27; // r5
  int v28; // r3
  _DWORD *v29; // r1
  int v30; // r0
  int v31; // r1
  unsigned int v32; // r3
  int v33; // [sp+18h] [bp-50h]
  int v35; // [sp+28h] [bp-40h]
  _WORD *v37; // [sp+30h] [bp-38h]
  int v38; // [sp+34h] [bp-34h] BYREF
  unsigned int v39; // [sp+38h] [bp-30h]
  int v40; // [sp+3Ch] [bp-2Ch]
  int v41; // [sp+40h] [bp-28h]
  unsigned int v42[9]; // [sp+44h] [bp-24h] BYREF

  v7 = a3;
  v37 = 0;
  v40 = a4 & 1;
  v8 = a2;
  v9 = 0;
  if ( (a4 & 1) == 0 || (v10 = a4 & 0xFFFFFFFE, *(_BYTE *)(a4 & 0xFFFFFFFE) != 1) )
    v10 = 0;
  v11 = 0;
  v39 = -1070596096;
  v12 = a3;
  v13 = -1073741801;
  while ( 1 )
  {
    v14 = (int *)*v12++;
    v15 = *v14;
    if ( (*v14 & 2) == 0 )
      break;
LABEL_5:
    if ( ++v11 )
      return -1073741802;
  }
  if ( v8 >= 0xC0000000 )
    return sub_534870();
  v33 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v15 )
    goto LABEL_23;
  if ( v8 >= dword_63389C )
  {
    if ( v10 )
      return 0;
    if ( v8 + 0x40000000 <= 0x3FFFFF && a4 )
      KeBugCheckEx(80, v8, a1);
  }
  MiCheckVirtualAddress(v8, &v38, v42);
  if ( v38 != 24 )
  {
    if ( !v9 && *(_DWORD *)(v33 + 264) )
    {
      if ( v10 )
      {
        v17 = v10 + 28;
        if ( *(_DWORD *)(v10 + 28) != v10 + 28 )
          return -1073740748;
      }
      if ( MiWaitForForkToComplete(v33, a5, v17) == 1 )
        return -1073740748;
    }
    v18 = *(v12 - 1);
    if ( (v18 < v39 || v18 > 0xC0300FFF) && v8 <= MmHighestUserAddress )
    {
      v37 = (_WORD *)(2 * (((unsigned int)*v12 >> 22) - 534769440));
      MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(v37, 1u);
    }
    v19 = (_DWORD *)*(v12 - 1);
    if ( (unsigned int)(v19 + 0x10000000) > 0x3FFFFF )
    {
      *v19 = 128;
    }
    else
    {
      __dmb(0xBu);
      *v19 = 128;
      if ( (unsigned int)(v19 + 267649024) <= 0xFFF )
      {
        v20 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v20, v20 + 4 * ((unsigned __int16)v19 & 0xFFF), 128);
      }
    }
    ++v9;
LABEL_23:
    if ( v40 && ((v26 = *(unsigned __int8 *)(a4 & 0xFFFFFFFE), v26 == 2) || v26 == 1 || v26 == 3 || v26 == 5) )
      v21 = 0;
    else
      v21 = a4;
    v35 = v21;
    v22 = MiDispatchFault(1, *v12, 0);
    if ( v22 == -1073532109 )
    {
      v28 = v41;
      if ( a6 == 1 )
        *(_BYTE *)(v41 + 115) |= 2u;
      MiIssueHardFault(v33 + 492, a5, *v12, v28, v35, 1);
    }
    else if ( v22 == -1073741801 && v9 )
    {
      v29 = (_DWORD *)v7[v11];
      if ( (unsigned int)(v29 + 0x10000000) > 0x3FFFFF )
      {
        *v29 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v29 = 0;
        if ( (unsigned int)(v29 + 267649024) <= 0xFFF )
        {
          v30 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v30, v30 + 4 * ((unsigned __int16)v29 & 0xFFF), 0);
        }
      }
      if ( v37 )
      {
        MI_DECREMENT_USED_PTES_BY_HANDLE_CLUSTER(v37, 1);
        if ( !*v37 )
          MiDeletePageTableHierarchy(0, v7[v11]);
      }
      return v13;
    }
    v23 = 0;
    v24 = v7;
    while ( 1 )
    {
      v25 = (_DWORD *)*v24++;
      if ( (*v25 & 2) == 0 )
        return -1073740748;
      if ( ++v23 > v11 )
      {
        MiSetPageDirty((int *)*(v12 - 1), *v12);
        v8 = a2;
        goto LABEL_5;
      }
    }
  }
  v27 = v42[0];
  MiCheckBadSystemProcessAccess(__PAIR64__(v42[0], a2), a1);
  if ( v27 && a2 <= MmHighestUserAddress && v10 )
  {
    v31 = v7[v11] + 4;
    v32 = 2 - v11;
    do
    {
      v31 <<= 10;
      --v32;
    }
    while ( v32 );
    MiLeapPrefetch(v10, v31);
    *(_BYTE *)(v10 + 1) = 1;
  }
  return -1073741819;
}
