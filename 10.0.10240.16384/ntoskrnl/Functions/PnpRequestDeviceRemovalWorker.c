// PnpRequestDeviceRemovalWorker 
 
_DWORD **__fastcall PnpRequestDeviceRemovalWorker(_DWORD **result, _DWORD *a2, int a3, int a4)
{
  _DWORD **v6; // r10
  int v7; // r6
  int v8; // r3
  int v9; // r4
  _DWORD *i; // r4
  _DWORD *v11; // r5
  _DWORD *v12; // r4
  int v13; // [sp+8h] [bp-28h] BYREF

  v6 = result;
  v7 = 782;
  if ( a4 != 2 )
    return (_DWORD **)sub_8119E0();
  v8 = a2[43];
  v9 = 1;
  if ( v8 != 782 )
  {
    if ( v8 != 783 )
      goto LABEL_5;
    if ( a3 )
    {
      PipRestoreDevNodeState(a2);
      result = (_DWORD **)PipSetDevNodeState(a2, 782);
    }
  }
  v9 = 0;
LABEL_5:
  if ( v9 )
  {
    if ( !a3 )
      v7 = 783;
    PipSetDevNodeState(a2, v7);
    for ( i = (_DWORD *)a2[1]; i; i = (_DWORD *)*i )
      PnpRequestDeviceRemovalWorker(v6, i, 1, 2, 1);
    result = (_DWORD **)PiGetDependentList(a2[4]);
    v11 = result;
    v12 = *result;
    while ( v12 != v11 )
    {
      result = (_DWORD **)PiEnumerateDependentListEntry((int)v12, &v13);
      v12 = (_DWORD *)*v12;
      if ( v13 )
        result = (_DWORD **)PnpRequestDeviceRemovalWorker(v6, *(_DWORD *)(*(_DWORD *)(v13 + 176) + 20), 0, 1, 0);
    }
  }
  return result;
}
