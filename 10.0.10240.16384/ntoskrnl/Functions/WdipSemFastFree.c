// WdipSemFastFree 
 
int __fastcall WdipSemFastFree(int result, _DWORD *a2)
{
  if ( a2 )
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)&byte_61CAD8[8 * result], a2);
  return result;
}
