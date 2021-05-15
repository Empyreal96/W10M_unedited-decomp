// MiFreeAweInfo 
 
unsigned int __fastcall MiFreeAweInfo(unsigned int a1)
{
  ExCleanupAutoExpandPushLock(a1 + 4);
  return ExFreePoolWithTag(a1);
}
