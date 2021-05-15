// WmipFindSMBiosStructure 
 
int __fastcall WmipFindSMBiosStructure(int a1, _DWORD *a2, unsigned int *a3, int *a4)
{
  int *v4; // r9
  unsigned int *v5; // r10
  unsigned __int8 **v6; // lr
  int v7; // r6
  unsigned __int8 *v8; // r0
  unsigned __int8 *v9; // r1
  unsigned __int8 *i; // r2
  int varg_r0; // [sp+38h] [bp+8h]
  _DWORD *varg_r1; // [sp+3Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v4 = a4;
  v5 = a3;
  v6 = (unsigned __int8 **)a2;
  v7 = 0;
  if ( WmipSMBiosTablePhysicalAddress )
  {
    v8 = (unsigned __int8 *)MmMapIoSpaceEx(
                              WmipSMBiosTablePhysicalAddress,
                              SHIDWORD(WmipSMBiosTablePhysicalAddress),
                              WmipSMBiosTableLength,
                              4);
    *v5 = (unsigned int)v8;
    v6 = (unsigned __int8 **)a2;
    if ( v8 )
    {
      *v4 = WmipSMBiosTableLength;
      goto LABEL_7;
    }
    v7 = -1073741670;
  }
  else
  {
    v7 = -1073741823;
  }
  v8 = 0;
LABEL_7:
  if ( v7 >= 0 )
  {
    *v6 = 0;
    v9 = &v8[WmipSMBiosTableLength];
    v7 = -1073741823;
    while ( v8 < v9 )
    {
      if ( *v8 == a1 )
      {
        *v6 = v8;
        v7 = 0;
        break;
      }
      for ( i = &v8[v8[1]]; *(_WORD *)i && i < v9; ++i )
        ;
      v8 = i + 2;
    }
    if ( v7 < 0 && *v5 )
      MmUnmapIoSpace(*v5, *v4);
  }
  return v7;
}
