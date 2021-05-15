// KiAbSetMinimumThreadPriority 
 
int __fastcall KiAbSetMinimumThreadPriority(int a1, unsigned int a2, int a3, _DWORD *a4, int a5)
{
  int v6; // r4
  int v7; // r5
  int v8; // r6
  int v9; // r4
  int v10; // r10
  __int64 v11; // r0
  int v12; // r6
  int v13; // r2
  int result; // r0
  int v15; // r1
  int v16; // [sp+14h] [bp-34h] BYREF
  int v17; // [sp+18h] [bp-30h]
  unsigned int v18; // [sp+1Ch] [bp-2Ch]
  _DWORD *v19; // [sp+20h] [bp-28h]
  int v20; // [sp+24h] [bp-24h]
  int v21; // [sp+28h] [bp-20h]

  v6 = *(unsigned __int8 *)(a1 + 12);
  v18 = a2;
  v19 = a4;
  v17 = a3;
  v7 = a1 - 8 * v6;
  v8 = (*(_DWORD *)(v7 + 960) >> 9) & 7;
  v9 = *(_DWORD *)(v7 + 336);
  v21 = *(char *)(v7 + 123);
  if ( (*(_DWORD *)(v9 + 192) & 0x100000) != 0 )
    v8 = 0;
  if ( v8 < 2 )
  {
    if ( v7 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(v7 + 1000) )
      v8 = 2;
    if ( v8 < 2 && *(_DWORD *)(v7 + 1000) )
      v8 = 2;
  }
  v16 = 0;
  v10 = 0;
  v20 = v8;
  v11 = KiAbEntryGetCpuPriorityKey(a1);
  v12 = (char)*(_BYTE *)HIDWORD(v11);
  if ( (int)v11 < v12 )
  {
    v15 = v17;
    *(_WORD *)(a1 + 44) |= 2 * (1 << (v12 - 1));
    v11 = __PAIR64__(v18, KiSetPriorityFloor(v7, v15, v12));
    v10 = v11;
  }
  else
  {
    v12 = 0;
  }
  v13 = (*(_DWORD *)(v7 + 960) >> 9) & 7;
  if ( (*(_DWORD *)(*(_DWORD *)(v7 + 336) + 192) & 0x100000) != 0 )
    v13 = 0;
  if ( v13 < *(char *)(HIDWORD(v11) + 1) && (*(_WORD *)(a1 + 44) & 1) == 0 && KiAbThreadBoostIoPriority(v7, a5, &v16) )
  {
    *(_WORD *)(a1 + 44) |= 1u;
    v10 = 1;
  }
  if ( v10 && v19 && *(_BYTE *)(v7 + 485) )
    KiAbThreadInsertList(v7, v19, (_DWORD *)(v7 + 776));
  if ( (dword_682604 & 0x200) != 0 )
    result = sub_54A144();
  else
    result = v12 != 0;
  return result;
}
