// IopLiveDumpValidateCancelObject 
 
int __fastcall IopLiveDumpValidateCancelObject(int a1)
{
  int v1; // r2
  int result; // r0

  if ( !a1
    || (v1 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 - 12)],
        v1 == ExEventObjectType)
    || v1 == PsProcessType
    || v1 == PsThreadType
    || v1 == ExTimerObjectType )
  {
    result = 0;
  }
  else
  {
    result = -1073741811;
  }
  return result;
}
