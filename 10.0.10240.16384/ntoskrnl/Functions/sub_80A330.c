// sub_80A330 
 
void sub_80A330()
{
  _DWORD *v0; // r0

  if ( !CmpSystemQuotaWarningPopupDisplayed && ExReadyForErrors )
  {
    v0 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 538987843);
    if ( v0 )
    {
      CmpSystemQuotaWarningPopupDisplayed = 1;
      v0[2] = CmpQuotaWarningWorker;
      v0[3] = v0;
      *v0 = 0;
      ExQueueWorkItem(v0, 1);
    }
  }
  JUMPOUT(0x75FA5E);
}
