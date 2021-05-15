// SdbpGetNextIndexedRecord 
 
int __fastcall SdbpGetNextIndexedRecord(int a1, int a2, _DWORD *a3, int a4)
{
  int v8; // r0
  int v9; // r2
  int v10; // r7
  int v11; // r3
  unsigned int v12; // r0
  int v13; // r1
  int v14; // r3
  int v15; // r4
  int v16; // r6
  int v17; // r2
  int v18; // r3
  int v19; // r6
  int v20; // r2
  int v21; // r3
  int v22; // r0
  _DWORD v23[2]; // [sp+8h] [bp-28h] BYREF
  _DWORD v24[8]; // [sp+10h] [bp-20h] BYREF

  if ( SdbGetTagFromTagID(a1, a2, (int)a3, a4) != 38913 )
    return sub_8179D4();
  v8 = SdbpGetMappedTagData(a1, a2);
  v10 = v8;
  if ( !v8 )
    JUMPOUT(0x8179DC);
  v11 = a3[5];
  if ( (v11 & 1) != 0 )
  {
    v16 = a3[1];
    if ( !v16 )
      v16 = *(_DWORD *)(v8 + 12 * a3[4] + 8);
    v15 = SdbpGetNextTagId(a1, v16);
    v19 = SdbGetTagFromTagID(a1, v16, v17, v18);
    v22 = SdbGetTagFromTagID(a1, v15, v20, v21);
    if ( v22 && (v22 & 0xF000) == 28672 && v22 == v19 && v15 != a3[2] )
    {
      a3[1] = v15;
      return v15;
    }
    return 0;
  }
  v12 = SdbGetTagDataSize(a1, a2, v9, v11);
  v13 = a3[4];
  if ( v13 == v12 / 0xC - 1 )
    return 0;
  memmove((int)v23, v10 + 12 * v13, 8u);
  memmove((int)v24, v10 + 12 * (a3[4] + 1), 8u);
  if ( v23[0] != v24[0] || v23[1] != v24[1] )
    return 0;
  v14 = a3[4] + 1;
  a3[4] = v14;
  return *(_DWORD *)(v10 + 12 * v14 + 8);
}
