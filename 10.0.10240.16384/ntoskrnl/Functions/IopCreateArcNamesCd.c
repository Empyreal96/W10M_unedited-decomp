// IopCreateArcNamesCd 
 
int __fastcall IopCreateArcNamesCd(int a1)
{
  _DWORD *v1; // r6
  int *v3; // r0
  unsigned int v4; // r4
  _DWORD *v5; // r5
  unsigned int *v6; // r8
  _DWORD *v7; // r10
  unsigned int v9; // [sp+18h] [bp-180h] BYREF
  int v10[95]; // [sp+1Ch] [bp-17Ch] BYREF

  v1 = *(_DWORD **)(a1 + 128);
  v10[0] = 0;
  v10[13] = a1;
  v3 = IoGetConfigurationInformation();
  v9 = 0;
  IopFetchConfigurationInformation(
    &v9,
    GUID_DEVINTERFACE_CDROM.Data1,
    *(_DWORD *)&GUID_DEVINTERFACE_CDROM.Data2,
    -1610550636,
    -1946476855,
    v3[2],
    v10);
  v4 = v9;
  v5 = (_DWORD *)*v1;
  v10[8] = v9;
  if ( v5 != v1 )
  {
    v6 = *(unsigned int **)(a1 + 104);
    do
    {
      v7 = v5;
      if ( !strcmp(v5[3], v6) )
        break;
      v5 = (_DWORD *)*v5;
      v7 = 0;
    }
    while ( v5 != v1 );
    if ( v7 )
      return sub_96928C();
  }
  if ( v4 )
    ExFreePoolWithTag(v4);
  return 0;
}
