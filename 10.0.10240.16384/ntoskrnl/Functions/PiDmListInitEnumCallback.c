// PiDmListInitEnumCallback 
 
int __fastcall PiDmListInitEnumCallback(int a1, int *a2, _BYTE *a3)
{
  unsigned int v4; // r1
  int v6; // r4
  unsigned __int16 *v7; // r1
  int v8; // r6
  int v10; // r0
  int v11; // r0
  unsigned int v12; // [sp+20h] [bp-80h] BYREF
  int v13; // [sp+24h] [bp-7Ch] BYREF
  unsigned int v14; // [sp+28h] [bp-78h] BYREF
  char v15[112]; // [sp+30h] [bp-70h] BYREF

  v4 = 1024;
  v12 = 1024;
  v13 = 0;
  v14 = 0;
  *a3 = 0;
  while ( 1 )
  {
    if ( v4 <= a2[1] )
      goto LABEL_3;
    v10 = *a2;
    a2[1] = v4;
    if ( v10 )
      return sub_7C8F14();
    v11 = ExAllocatePoolWithTag(1, a2[1], 1517317712);
    *a2 = v11;
    if ( !v11 )
    {
      v6 = -1073741670;
LABEL_4:
      if ( v6 == -1073741275 )
        return 0;
      if ( v6 >= 0 )
      {
        if ( v13 == 13 )
        {
          PnpStringFromGuid(*a2, (int)v15);
          v7 = (unsigned __int16 *)v15;
          goto LABEL_8;
        }
        if ( v13 == 18 )
        {
          v7 = (unsigned __int16 *)*a2;
LABEL_8:
          v6 = PiDmAddCacheReferenceForObject(PiDmListDefs[5 * a2[2]], v7, (int *)&v14);
          v8 = v14;
          if ( v6 >= 0 )
            PiDmListAddObject(a2[2], v14, (unsigned int *)a1);
          if ( v8 )
          {
            PiDmRemoveCacheReferenceForObject(*(_DWORD *)(v8 + 20), *(_DWORD *)(v8 + 12));
            PiDmObjectRelease(v8);
          }
        }
      }
      return v6;
    }
LABEL_3:
    v12 = 0;
    v6 = PnpGetObjectProperty(
           PiPnpRtlCtx,
           *(_DWORD *)(a1 + 12),
           *(_DWORD *)(a1 + 20),
           0,
           0,
           PiDmListDefs[5 * a2[2] + 4],
           (int)&v13,
           *a2,
           a2[1],
           (int)&v12,
           0);
    if ( v6 != -1073741789 )
      goto LABEL_4;
    v4 = v12;
  }
}
