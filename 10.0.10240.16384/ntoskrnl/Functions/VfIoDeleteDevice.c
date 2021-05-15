// VfIoDeleteDevice 
 
int __fastcall VfIoDeleteDevice(int result, int a2)
{
  int v3; // r4
  int v4; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r0
  int v8; // r5

  v3 = result;
  if ( ViVerifyDma )
  {
    v4 = *(_DWORD *)(result + 176);
    if ( !v4 )
      goto LABEL_17;
    do
    {
      v5 = *(_DWORD *)(v4 + 24);
      if ( !v5 )
        break;
      result = v5;
      v4 = *(_DWORD *)(v5 + 176);
    }
    while ( v4 );
    if ( result == v3 )
    {
LABEL_17:
      while ( 1 )
      {
        result = (int)VF_FIND_DEVICE_INFORMATION_AND_REMOVE(v3);
        if ( !result )
          break;
        ViReleaseDmaAdapter(result);
      }
    }
    else
    {
      result = VF_MARK_FOR_DEFERRED_REMOVE(result);
    }
  }
  v6 = VfIoDisabled;
  __dmb(0xBu);
  if ( !v6 )
  {
    ViDevObjRemove(v3);
    if ( IovUtilIsDeviceObjectMarked(v3, 0) )
      VfErrorReport9(576, a2);
    v7 = IovUtilMarkDeviceObject(v3, 0);
    v8 = IovUtilGetLowerDeviceObject(v7);
    if ( v8 )
    {
      VfErrorReport9(513, a2);
      ObfDereferenceObject(v8);
    }
    result = VfIrpLogDeleteDeviceLogs(v3);
  }
  return result;
}
