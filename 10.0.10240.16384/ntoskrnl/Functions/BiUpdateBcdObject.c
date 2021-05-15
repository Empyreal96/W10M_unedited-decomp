// BiUpdateBcdObject 
 
int __fastcall BiUpdateBcdObject(int a1, int a2)
{
  int v2; // r5
  unsigned int v4; // r8
  int v5; // r6
  int v6; // r7
  int v7; // r4
  int v9; // r7
  unsigned int v10; // r10
  int v11; // r9
  unsigned int v12; // r7
  int v13; // r0
  int v14; // r5
  int v15; // r0
  unsigned int v16; // r9
  unsigned int v17; // [sp+Ch] [bp-34h] BYREF
  unsigned int v18; // [sp+10h] [bp-30h] BYREF
  int v19; // [sp+14h] [bp-2Ch] BYREF
  int v20; // [sp+18h] [bp-28h] BYREF
  int v21[9]; // [sp+1Ch] [bp-24h] BYREF

  v2 = *(_DWORD *)(a2 + 28);
  v20 = 0;
  v21[0] = 0;
  v4 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v5 = 0;
  v6 = BcdOpenObject(a1, a2 + 8, &v19);
  v7 = v19;
  if ( v6 >= 0 )
  {
    if ( (*(_DWORD *)(a2 + 32) & 2) == 0 )
      goto LABEL_33;
    if ( BiGetRegistryValue(v19, L"FirmwareVariable", L"Description", 3, &v17, &v20) < 0 )
      return sub_813680();
    v9 = *(_DWORD *)(v2 + 4);
    if ( v9 != v20 )
      return sub_813680();
    v10 = v17;
    if ( RtlCompareMemory((unsigned __int8 *)v2, v17, *(_DWORD *)(v2 + 4)) != v9 )
LABEL_33:
      JUMPOUT(0x813684);
    v11 = *(_DWORD *)(v2 + 16);
    v12 = 2 * (wcslen((unsigned __int16 *)(v11 + v2)) + 1);
    v13 = BcdGetElementDataWithFlags(v7, 301989892);
    if ( v13 == -1073741789 )
    {
      v5 = ExAllocatePoolWithTag(1, 0, 1262764866);
      if ( !v5 )
      {
LABEL_32:
        BcdDeleteElement(v7, 301989892);
        BcdSetElementDataWithFlags(v7, 301989892);
LABEL_14:
        v14 = v2 + *(_DWORD *)(v2 + 20);
        if ( *(_DWORD *)(v14 + 8) == 4 )
        {
          v15 = BiGetDeviceFromEfiPath((_BYTE *)(v14 + 12), (int)v21, &v20, 4);
          v16 = v21[0];
          if ( v15 >= 0 )
          {
            BcdDeleteElement(v7, 285212673);
            BcdSetElementDataWithFlags(v7, 285212673);
          }
          if ( BiGetFilePathFromEfiPath(v14 + 12, &v18, v21) < 0 )
          {
            v4 = v18;
          }
          else
          {
            BcdDeleteElement(v7, 301989890);
            v4 = v18;
            BcdSetElementDataWithFlags(v7, 301989890);
          }
        }
        else
        {
          v16 = 0;
        }
        v6 = 0;
        if ( v16 )
          ExFreePoolWithTag(v16);
        if ( v4 )
          ExFreePoolWithTag(v4);
        if ( v10 )
          ExFreePoolWithTag(v10);
        goto LABEL_25;
      }
      v13 = BcdGetElementDataWithFlags(v7, 301989892);
    }
    if ( v13 >= 0 && v5 && !v12 && !RtlCompareMemory((unsigned __int8 *)(v11 + v2), v5, 0) )
      goto LABEL_14;
    goto LABEL_32;
  }
LABEL_25:
  if ( v7 )
    BcdCloseObject(v7);
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v6;
}
