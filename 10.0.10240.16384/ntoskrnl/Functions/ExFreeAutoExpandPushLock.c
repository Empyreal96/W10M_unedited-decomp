// ExFreeAutoExpandPushLock 
 
int __fastcall ExFreeAutoExpandPushLock(int a1)
{
  int v2; // r3

  v2 = *(_DWORD *)(a1 + 4);
  if ( (v2 & 1) != 0 )
    ExSaFree(v2 & 0xFFFFFFF8);
  return ExFreePoolWithTag(a1);
}
