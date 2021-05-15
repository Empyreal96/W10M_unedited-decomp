// DbgkLkmdUnregisterCallback 
 
int __fastcall DbgkLkmdUnregisterCallback(int a1)
{
  int v2; // r6
  _DWORD *i; // r5
  int v4; // r0
  unsigned int *v5; // r4
  unsigned int v7; // r1

  v2 = 0;
  for ( i = &unk_641668; ; i += 2 )
  {
    v4 = ExReferenceCallBackBlock(i);
    v5 = (unsigned int *)v4;
    if ( v4 )
      break;
LABEL_6:
    if ( (unsigned int)++v2 >= 8 )
      return -1073741275;
  }
  if ( a1 != KeReadStateSemaphore(v4) || !ExCompareExchangeCallBack(i, 0, (int)v5) )
  {
    ExDereferenceCallBackBlock(i, (unsigned int)v5);
    goto LABEL_6;
  }
  ExDereferenceCallBackBlock((_DWORD *)&unk_641668 + 2 * v2, (unsigned int)v5);
  do
    v7 = __ldrex(v5);
  while ( !v7 && __strex(1u, v5) );
  __dmb(0xBu);
  if ( v7 )
  {
    if ( v7 != 1 )
      ExfWaitForRundownProtectionRelease(v5, v7);
  }
  ExFreePoolWithTag((unsigned int)v5);
  return 0;
}
