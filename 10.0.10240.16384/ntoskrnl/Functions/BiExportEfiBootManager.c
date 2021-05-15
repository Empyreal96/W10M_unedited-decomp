// BiExportEfiBootManager 
 
int __fastcall BiExportEfiBootManager(int a1, int a2)
{
  int v2; // r5
  unsigned int v3; // r6
  unsigned int v4; // r10
  int v5; // r0
  int v6; // r8
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r9
  int v11; // r1
  int v12; // r0
  int v13; // r4
  int v14; // r8
  unsigned int v15; // r9
  unsigned int v16; // r4
  int v17; // r0
  int v18; // r0
  int v19; // r3
  int v20; // r0
  unsigned int v21; // r7
  int v22; // [sp+0h] [bp-68h] BYREF
  unsigned int v23; // [sp+4h] [bp-64h] BYREF
  int v24; // [sp+8h] [bp-60h] BYREF
  unsigned int v25; // [sp+Ch] [bp-5Ch] BYREF
  int v26; // [sp+10h] [bp-58h] BYREF
  unsigned int v27; // [sp+14h] [bp-54h]
  int v28; // [sp+18h] [bp-50h]
  unsigned int v29; // [sp+1Ch] [bp-4Ch] BYREF
  unsigned int v30; // [sp+20h] [bp-48h]
  unsigned int v31; // [sp+24h] [bp-44h] BYREF
  int *v32; // [sp+28h] [bp-40h] BYREF
  _DWORD *v33; // [sp+2Ch] [bp-3Ch] BYREF
  int v34[2]; // [sp+30h] [bp-38h] BYREF
  int v35; // [sp+38h] [bp-30h]
  int v36; // [sp+40h] [bp-28h]

  v28 = a2;
  v2 = 0;
  v3 = 0;
  v25 = 0;
  v26 = 0;
  v30 = 0;
  v31 = 0;
  v24 = 0;
  v4 = 0;
  v32 = 0;
  v33 = 0;
  v27 = 0;
  v29 = 0;
  v5 = BcdOpenObject(a1, &GUID_FIRMWARE_BOOTMGR, &v24);
  v6 = v24;
  if ( v5 < 0 )
    return sub_8136F8();
  v8 = BiGetElement(v24, 603979777, &v25, &v23);
  v9 = v8;
  v10 = v25;
  if ( v8 < 0 )
  {
    if ( v8 == -1073741275 )
    {
      v13 = v28;
      v23 = 0;
      goto LABEL_6;
    }
  }
  else
  {
    v11 = 4 * (v23 >> 4);
    v23 >>= 4;
    v12 = ExAllocatePoolWithTag(1, v11, 1262764866);
    v26 = v12;
    if ( v12 )
    {
      v13 = v28;
      BiTranslateDisplayOrder(v28, v10, v12, &v23);
LABEL_6:
      v14 = BiQueryBootEntryOrder(&v29, &v22);
      v9 = BiHandleFirmwareDefaultEntry(v13, v24, (int)&v26, (unsigned int)&v23);
      v15 = v26;
      v27 = v29;
      if ( v9 < 0
        || ((v16 = v23, v14 < 0) || !v23 || v22 != v23 || memcmp(v26, v29, 4 * v23))
        && (v9 = BiSetBootEntryOrder(v15, v16), v9 < 0) )
      {
        v6 = v24;
LABEL_25:
        if ( v15 )
          ExFreePoolWithTag(v15);
        if ( v30 )
          ExFreePoolWithTag(v30);
        v10 = v25;
        goto LABEL_30;
      }
      v6 = v24;
      v34[1] = 24;
      v34[0] = 1;
      v17 = BiGetElement(v24, 620756996, &v32, &v22);
      v9 = v17;
      v4 = (unsigned int)v32;
      if ( v17 >= 0 )
      {
        v2 = 1;
        if ( v32[1] )
          v35 = -1;
        else
          v35 = *v32;
      }
      else
      {
        if ( v17 != -1073741275 )
          goto LABEL_25;
        v9 = BiDeleteEfiVariable(L"Timeout");
        if ( v9 < 0 )
          goto LABEL_25;
        v35 = 0;
      }
      v18 = BiGetElement(v6, 603979778, &v31, &v22);
      v9 = v18;
      v30 = v31;
      if ( v18 >= 0 )
      {
        v2 |= 2u;
        v9 = BiTranslateObjectIdentifier(v28, v31, &v22);
        if ( v9 < 0 )
          goto LABEL_25;
        v19 = v22;
      }
      else
      {
        if ( v18 != -1073741275 )
          goto LABEL_25;
        v9 = BiDeleteEfiVariable(L"BootNext");
        if ( v9 < 0 )
          goto LABEL_25;
        v19 = 0;
      }
      v36 = v19;
      v22 = 0;
      v20 = BiQueryBootOptions(&v33, &v22);
      v3 = (unsigned int)v33;
      if ( v20 >= 0 && *v33 == v34[0] )
      {
        if ( (v2 & 1) != 0 && v33[2] == v35 )
          v2 &= 0xFFFFFFFE;
        if ( (v2 & 2) != 0 && v33[4] == v36 )
          v2 &= 0xFFFFFFFD;
      }
      if ( v2 )
        v9 = BiSetBootOptions(v34, v2);
      goto LABEL_25;
    }
    v9 = -1073741670;
  }
LABEL_30:
  if ( v10 )
    ExFreePoolWithTag(v10);
  v21 = v27;
  if ( v6 )
    BcdCloseObject(v6);
  if ( v4 )
    ExFreePoolWithTag(v4);
  if ( v21 )
    ExFreePoolWithTag(v21);
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v9;
}
