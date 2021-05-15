// PiDmObjectManagerPopulate 
 
int __fastcall PiDmObjectManagerPopulate(int a1)
{
  int v1; // r5
  int v4; // r4
  unsigned __int16 *i; // r7
  int v6; // r0
  int v7; // r2
  int v8; // r3
  int *v9; // r5
  int v10[9]; // [sp+14h] [bp-24h] BYREF

  v1 = 0;
  while ( 1 )
  {
    if ( v1 )
      return sub_815C6C();
    v1 = ExAllocatePoolWithTag(1, 0x80000, 1517317712);
    if ( !v1 )
      break;
    v4 = PnpGetObjectList(PiPnpRtlCtx, *(_DWORD *)(a1 + 112));
    if ( v4 != -1073741789 )
      goto LABEL_6;
  }
  v4 = -1073741670;
LABEL_6:
  if ( v4 >= 0 )
  {
    for ( i = (unsigned __int16 *)v1; *i; i += wcslen(i) + 1 )
    {
      v4 = PiDmObjectCreate(*(_DWORD *)(a1 + 112), i, v10);
      if ( v4 < 0 )
        break;
      *(_DWORD *)(v10[0] + 24) |= 1u;
      *(_DWORD *)(v10[0] + 8) = 1;
      if ( !RtlInsertElementGenericTableAvl(a1 + 56, (int)v10, 4, 0) )
      {
        PiDmObjectRelease(v10[0]);
        v4 = -1073741670;
        break;
      }
    }
  }
  if ( v1 )
    ExFreePoolWithTag(v1);
  if ( v4 < 0 )
  {
    while ( 1 )
    {
      v6 = RtlEnumerateGenericTableAvl(a1 + 56, 1);
      v9 = (int *)v6;
      if ( !v6 )
        break;
      RtlDeleteElementGenericTableAvl(a1 + 56, v6, v7, v8);
      PiDmObjectRelease(*v9);
    }
  }
  return v4;
}
