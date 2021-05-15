// VfCtxUnhookAndDisconnectInterruptEx 
 
unsigned int __fastcall VfCtxUnhookAndDisconnectInterruptEx(int *a1, int a2)
{
  int v2; // r2
  unsigned int v3; // r4
  int v4; // r3
  int v5; // r3
  unsigned int result; // r0

  v2 = *a1;
  v3 = 0;
  v4 = ViCtxInitializedIsrStateBlocks;
  __dmb(0xBu);
  if ( !v4 )
    goto LABEL_9;
  if ( v2 == 1 || v2 == 2 )
  {
    v5 = a1[1];
  }
  else
  {
    if ( v2 != 3 )
      goto LABEL_9;
    v5 = *(_DWORD *)(a1[1] + 20);
  }
  if ( v5 )
    v3 = *(_DWORD *)(v5 + 24);
LABEL_9:
  result = pXdvIoDisconnectInterruptEx(a1, a2, v2);
  if ( v3 )
    result = ExFreePoolWithTag(v3);
  return result;
}
