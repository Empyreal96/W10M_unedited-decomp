// MiStoreFreeWriteSupport 
 
int __fastcall MiStoreFreeWriteSupport(_DWORD *a1, int a2)
{
  int result; // r0

  if ( *(unsigned __int16 *)(a2 + 732) >= 0x100u )
    result = ExFreePoolWithTag(a1);
  else
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)(a2 + 728), a1);
  return result;
}
