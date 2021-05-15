// CmpInitCallbacks 
 
_DWORD *CmpInitCallbacks()
{
  _DWORD *result; // r0

  CmpCallBackCount = 0;
  CallbackListHead = (int)&CallbackListHead;
  *(_DWORD *)algn_6324E4 = &CallbackListHead;
  CmpCallbackListLock = 0;
  CmpContextListLock = 0;
  CallbackListDeleteEvent = 0;
  RtlInitUnicodeString((unsigned int)&CmLegacyAltitude, L"425000");
  result = KeQuerySystemTime(&CmpCallbackCookie);
  CmpCallbackContextSList = 0;
  *(_DWORD *)&word_6324FC = 0;
  return result;
}
