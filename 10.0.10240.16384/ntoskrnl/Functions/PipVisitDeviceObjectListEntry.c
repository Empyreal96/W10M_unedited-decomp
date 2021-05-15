// PipVisitDeviceObjectListEntry 
 
int __fastcall PipVisitDeviceObjectListEntry(int *a1, _DWORD *a2, int *a3, int a4)
{
  int v4; // r3
  int v8; // r7
  int v9; // r9
  _DWORD *v10; // r4
  int v11; // r3
  int v12; // t1
  int v13; // r2
  _DWORD **v15; // r7
  _DWORD *v16; // r4
  int v17; // r3
  _DWORD *v18; // [sp+0h] [bp-28h] BYREF
  _DWORD *v19; // [sp+4h] [bp-24h] BYREF
  _DWORD v20[8]; // [sp+8h] [bp-20h] BYREF

  v19 = a2;
  v20[0] = a3;
  v20[1] = a4;
  v18 = 0;
  v4 = a1[3];
  if ( (v4 & 2) != 0 )
    return 0;
  a1[3] = v4 | 2;
  if ( *a1 )
    v8 = *(_DWORD *)(*(_DWORD *)(*a1 + 176) + 20);
  else
    v8 = 0;
  v9 = 0;
  if ( !*a2 )
  {
LABEL_12:
    v15 = (_DWORD **)PiGetDependentList(*a1);
    v16 = *v15;
    while ( v16 != v15 )
    {
      PiEnumerateDependentListEntry(v16, &v19, v20);
      v16 = (_DWORD *)*v16;
      if ( v19 )
      {
        if ( PipIsDeviceInDeviceObjectList(a2, v19, &v18) )
          PipVisitDeviceObjectListEntry(v18, a2, a3);
      }
    }
    v17 = *a3;
    a1[2] = *a3;
    *a3 = v17 + 1;
    return 0;
  }
  v10 = a2 + 4;
  while ( 1 )
  {
    v18 = v10;
    v12 = *v10;
    v10 += 4;
    v11 = v12;
    v13 = v12 ? *(_DWORD *)(*(_DWORD *)(v11 + 176) + 20) : 0;
    if ( *(_DWORD *)(v13 + 8) == v8 || (*(_DWORD *)(v13 + 412) & 0xFFFFFFFE) == v8 )
      return sub_7DF2E0();
    if ( (unsigned int)++v9 >= *a2 )
      goto LABEL_12;
  }
}
