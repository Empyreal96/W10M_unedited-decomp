// PiDmListAddObjectWorker 
 
int __fastcall PiDmListAddObjectWorker(int a1, int a2, int a3, int a4, _BYTE *a5)
{
  int *v6; // r5
  int v8; // r6
  _DWORD *v9; // r7
  int result; // r0
  int v11; // r2
  int v12; // r3
  char v13; // r8
  unsigned int v14; // r5
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  _DWORD *v18; // r2

  v6 = &PiDmListDefs[5 * a1];
  v8 = v6[1] + a3;
  v9 = (_DWORD *)(v6[3] + a4);
  result = PiDmListIsObjectInList();
  v13 = result;
  if ( !result )
  {
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v14 + 308);
    ExAcquireResourceExclusiveLite(a2, 1, v11, v12);
    ++*(_DWORD *)(a3 + 8);
    v15 = ExReleaseResourceLite(a2);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 )
      return sub_7C8EF0(v15);
    v18 = *(_DWORD **)(v8 + 4);
    *v9 = v8;
    v9[1] = v18;
    if ( *v18 != v8 )
      __fastfail(3u);
    *v18 = v9;
    *(_DWORD *)(v8 + 4) = v9;
    ++*(_DWORD *)(v8 + 8);
    result = PiDmListUpdateAggregationCountWorker(a3, a4, 1);
  }
  if ( a5 )
    *a5 = v13;
  return result;
}
