// RtlTraceDatabaseUnlock 
 
int __fastcall RtlTraceDatabaseUnlock(int a1)
{
  return RtlpTraceDatabaseReleaseLock(a1);
}
