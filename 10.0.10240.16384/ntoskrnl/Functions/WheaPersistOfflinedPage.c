// WheaPersistOfflinedPage 
 
int __fastcall WheaPersistOfflinedPage(int a1)
{
  int v2; // r5
  int v3; // r4
  int v4; // r7
  int v5; // r6
  int v6; // r8
  unsigned int v7; // r4
  int v8; // r0
  unsigned int v9; // r8
  _DWORD *v10; // r3
  int v11; // r0
  unsigned int v13; // [sp+0h] [bp-30h] BYREF
  int v14; // [sp+4h] [bp-2Ch] BYREF
  int v15[10]; // [sp+8h] [bp-28h] BYREF

  v13 = 0;
  v14 = 0;
  v2 = 0;
  v3 = BcdOpenSystemStore(&v13);
  v4 = v13;
  if ( v3 < 0 )
    goto LABEL_20;
  if ( BcdOpenObject(v13, &GUID_BAD_MEMORY_GROUP, &v14) < 0 )
  {
    v15[0] = 1;
    v15[1] = 537919488;
    v3 = BcdCreateObject(v4, &GUID_BAD_MEMORY_GROUP, v15, &v14);
    if ( v3 < 0 )
    {
      v5 = v14;
      goto LABEL_18;
    }
  }
  v5 = v14;
  v13 = 0;
  v6 = BcdGetElementData(v14, 385875978, 0, &v13);
  if ( v6 == -1073741789 )
  {
    v7 = v13;
  }
  else
  {
    v7 = 0;
    v13 = 0;
  }
  v8 = ExAllocatePoolWithTag(1, v7 + 8);
  v2 = v8;
  if ( !v8 )
  {
    v3 = -1073741670;
    goto LABEL_18;
  }
  if ( v6 == -1073741789 )
  {
    v3 = BcdGetElementData(v5, 385875978, v8, &v13);
    if ( v3 < 0 )
      goto LABEL_18;
    v7 = v13;
  }
  v9 = v7 >> 3;
  if ( WheapIsPageInList(v2, v7 >> 3, a1) )
    goto LABEL_17;
  v10 = (_DWORD *)(v2 + 8 * v9);
  *v10 = a1;
  v10[1] = 0;
  v11 = WheapSortBadPages(v2, v9 + 1);
  if ( (unsigned int)WheapCountBadPageExtents(v11, v9 + 1) > 0x40 )
  {
    v3 = -1073741823;
    goto LABEL_18;
  }
  v3 = BcdSetElementData(v5, 385875978, v2, v7 + 8);
  if ( v3 >= 0 )
LABEL_17:
    v3 = 0;
LABEL_18:
  if ( v5 )
    BcdCloseObject(v5);
LABEL_20:
  if ( v4 )
    BcdCloseStore(v4);
  if ( v2 )
    ExFreePoolWithTag(v2);
  return v3;
}
