// PopInvokeStateHandlerTargetProcessor 
 
int __fastcall PopInvokeStateHandlerTargetProcessor(int a1, unsigned int a2)
{
  int result; // r0
  int v4[8]; // [sp+0h] [bp-20h] BYREF

  memset(v4, 0, 24);
  v4[0] = 0;
  RtlpInterlockedPushEntrySList((unsigned __int64 *)(a2 + 48), &v4[5]);
  do
    result = PopHandleNextState(__SPAIR64__(v4, a2));
  while ( v4[0] != 13 );
  return result;
}
