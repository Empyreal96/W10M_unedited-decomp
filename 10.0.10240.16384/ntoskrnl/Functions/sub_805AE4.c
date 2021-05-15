// sub_805AE4 
 
void sub_805AE4()
{
  int v0; // r5
  _DWORD *v1; // r0

  if ( !*(_BYTE *)(v0 - 7) && ExReadyForErrors )
  {
    v1 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 538987843);
    if ( v1 )
    {
      *(_BYTE *)(v0 - 7) = 1;
      v1[2] = CmpQuotaWarningWorker;
      v1[3] = v1;
      *v1 = 0;
      ExQueueWorkItem(v1, 1);
    }
  }
  JUMPOUT(0x751770);
}
