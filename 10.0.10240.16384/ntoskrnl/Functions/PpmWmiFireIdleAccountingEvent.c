// PpmWmiFireIdleAccountingEvent 
 
int __fastcall PpmWmiFireIdleAccountingEvent(int a1)
{
  int v1; // r4
  __int64 v2; // kr00_8
  _BYTE *v3; // r0
  int v4; // r5
  int v5; // r4

  v1 = a1 + 2944;
  v2 = *(_QWORD *)(a1 + 2944);
  if ( !(_DWORD)v2 || !HIDWORD(v2) || !*(_DWORD *)(a1 + 3124) )
    return -1073741823;
  v3 = PpmAllocWmiEvent(a1 + 3120, PPM_IDLE_ACCOUNTING_EX_GUID, 416 * *(_DWORD *)HIDWORD(v2) + 24);
  v4 = (int)v3;
  if ( !v3 )
    return -1073741670;
  PpmTranslateIdleAccounting(v1, &v3[*((_DWORD *)v3 + 14)], 0);
  v5 = IoWMIWriteEvent(v4);
  if ( v5 >= 0 )
    return 0;
  ExFreePoolWithTag(v4);
  return v5;
}
