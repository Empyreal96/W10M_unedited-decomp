// PnpRequestHwProfileChangeNotification 
 
int __fastcall PnpRequestHwProfileChangeNotification(GUID *a1, int a2, _DWORD *a3, unsigned __int16 *a4)
{
  int result; // r0
  int v9; // [sp+8h] [bp-30h] BYREF
  char v10[40]; // [sp+10h] [bp-28h] BYREF

  if ( a1 == &GUID_HWPROFILE_QUERY_CHANGE )
    goto LABEL_11;
  if ( RtlCompareMemory((unsigned __int8 *)a1, (int)&GUID_HWPROFILE_QUERY_CHANGE, 16) != 16
    && a1 != &GUID_HWPROFILE_CHANGE_CANCELLED
    && RtlCompareMemory((unsigned __int8 *)a1, (int)&GUID_HWPROFILE_CHANGE_CANCELLED, 16) != 16
    && a1 != &GUID_HWPROFILE_CHANGE_COMPLETE
    && RtlCompareMemory((unsigned __int8 *)a1, (int)&GUID_HWPROFILE_CHANGE_COMPLETE, 16) != 16 )
  {
    return -1073741808;
  }
  if ( a1 != &GUID_HWPROFILE_QUERY_CHANGE
    && RtlCompareMemory((unsigned __int8 *)a1, (int)&GUID_HWPROFILE_QUERY_CHANGE, 16) != 16 )
  {
    return PnpSetHwProfileChangeEvent(a1, 0, 0, 0, 0);
  }
LABEL_11:
  if ( a2 != 1 )
    return PnpNotifyHwProfileChange((int *)a1, a3, a4);
  KeInitializeEvent((int)v10, 0, 0);
  result = PnpSetHwProfileChangeEvent(a1, v10, &v9, a3, a4);
  if ( result >= 0 )
  {
    KeWaitForSingleObject((unsigned int)v10, 0, 0, 0, 0);
    result = v9;
  }
  return result;
}
