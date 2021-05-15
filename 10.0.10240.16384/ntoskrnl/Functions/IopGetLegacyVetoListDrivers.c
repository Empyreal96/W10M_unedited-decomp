// IopGetLegacyVetoListDrivers 
 
int __fastcall IopGetLegacyVetoListDrivers(int a1)
{
  int v3; // r5
  _WORD *v4; // r0
  int v5; // r0
  unsigned int v6; // r1
  _WORD *v7; // r0
  unsigned int v8; // r6
  int v9; // r6
  int v10; // [sp+14h] [bp-54h]
  int v11; // [sp+1Ch] [bp-4Ch] BYREF
  __int16 v12; // [sp+20h] [bp-48h] BYREF
  unsigned __int16 v13; // [sp+22h] [bp-46h]
  _WORD *v14; // [sp+24h] [bp-44h]
  __int16 v15[2]; // [sp+28h] [bp-40h] BYREF
  const __int16 *v16; // [sp+2Ch] [bp-3Ch]
  int v17; // [sp+30h] [bp-38h]
  int v18; // [sp+34h] [bp-34h]
  __int16 *v19; // [sp+38h] [bp-30h]
  int v20; // [sp+3Ch] [bp-2Ch]
  int v21; // [sp+40h] [bp-28h]
  int v22; // [sp+44h] [bp-24h]

  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15[1] = 16;
  v15[0] = 14;
  v16 = L"\\Driver";
  v17 = 24;
  v18 = 0;
  v20 = 576;
  v19 = v15;
  v21 = 0;
  v22 = 0;
  if ( ZwOpenDirectoryObject() < 0 )
    return sub_7EE068();
  v3 = ExAllocatePoolWithTag(257, 186, 1869181008);
  if ( v3 && (v13 = 188, v12 = 0, v4 = (_WORD *)ExAllocatePoolWithTag(257, 188, 1869181008), (v14 = v4) != 0) )
  {
    *v4 = 0;
    while ( 1 )
    {
      v5 = ZwQueryDirectoryObject();
      if ( v5 == -1073741789 )
      {
        ExFreePoolWithTag(v3);
        v3 = ExAllocatePoolWithTag(257, v10, 1869181008);
        if ( !v3 )
          goto LABEL_26;
        v5 = ZwQueryDirectoryObject();
      }
      if ( v5 < 0 )
        break;
      v6 = v13;
      v7 = v14;
      v8 = (unsigned __int16)(*(_WORD *)v3 + 18);
      if ( v8 > v13 )
      {
        ExFreePoolWithTag((unsigned int)v14);
        v13 = v8;
        v7 = (_WORD *)ExAllocatePoolWithTag(257, v8, 1869181008);
        v14 = v7;
        if ( !v7 )
          goto LABEL_26;
        v6 = v13;
      }
      v12 = v8 - 2;
      RtlStringCbPrintfW(v7, v6, (int)L"\\Driver\\%ws", *(_DWORD *)(v3 + 4));
      if ( ObReferenceObjectByName((int)&v12, 576, 0, 0, IoDriverObjectType, 0, 0, &v11) >= 0 )
      {
        v9 = v11;
        if ( (*(_DWORD *)(v11 + 8) & 0x40) != 0 )
        {
          **(_DWORD **)(a1 + 8) = 11;
          if ( *(_DWORD *)a1 )
            IopAppendLegacyVeto(a1, v3);
        }
        ObfDereferenceObject(v9);
        if ( **(_DWORD **)(a1 + 8) == 11 && !*(_DWORD *)a1 )
          break;
        if ( **(int **)(a1 + 12) < 0 )
          break;
      }
    }
  }
  else
  {
LABEL_26:
    **(_DWORD **)(a1 + 12) = -1073741670;
  }
  if ( v14 )
    ExFreePoolWithTag((unsigned int)v14);
  if ( v3 )
    ExFreePoolWithTag(v3);
  return 0;
}
