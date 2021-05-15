// RtlTraceDatabaseAdd 
 
int __fastcall RtlTraceDatabaseAdd(int a1, int a2, int a3, int a4)
{
  int v8; // r4

  RtlpTraceDatabaseAcquireLock();
  v8 = RtlpTraceDatabaseInternalAdd(a1, a2, a3, a4);
  RtlpTraceDatabaseReleaseLock(a1);
  return v8;
}
