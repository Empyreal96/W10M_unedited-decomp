// IoTransferActivityId 
 
__int64 __fastcall IoTransferActivityId(__int64 a1)
{
  unsigned int v1; // r6
  __int64 v2; // r4
  __int64 v5; // [sp+0h] [bp-20h]

  v5 = a1;
  v1 = HIDWORD(a1);
  v2 = IoTraceHandle;
  if ( IoTraceHandle && EtwEventEnabled(IoTraceHandle, SHIDWORD(IoTraceHandle), (int)IoTrace_ActivityIdTransfer) )
  {
    v5 = v1;
    EtwWriteTransfer(v2, SHIDWORD(v2), (int)IoTrace_ActivityIdTransfer);
  }
  return v5;
}
