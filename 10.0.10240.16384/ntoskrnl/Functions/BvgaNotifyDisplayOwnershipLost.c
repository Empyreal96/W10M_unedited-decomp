// BvgaNotifyDisplayOwnershipLost 
 
int (__fastcall *__fastcall BvgaNotifyDisplayOwnershipLost(int (__fastcall *result)(_DWORD, _DWORD)))(_DWORD, _DWORD)
{
  int (__fastcall *v1)(_DWORD, _DWORD); // r5
  unsigned int v2; // r0

  v1 = result;
  if ( BvgaBootDriverInstalled )
  {
    v2 = BvgaAcquireLock((int)result);
    if ( BvgaDisplayState != 2 )
      v2 = VidCleanUp_0();
    BvgaDisplayState = 2;
    BvgaResetDisplayParameters = v1;
    result = (int (__fastcall *)(_DWORD, _DWORD))BvgaReleaseLock(v2);
  }
  else
  {
    BvgaDisplayState = 2;
    BvgaResetDisplayParameters = result;
  }
  return result;
}
