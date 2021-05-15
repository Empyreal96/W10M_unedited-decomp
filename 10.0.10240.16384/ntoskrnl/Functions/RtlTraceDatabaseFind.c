// RtlTraceDatabaseFind 
 
int __fastcall RtlTraceDatabaseFind(int a1, int a2, int a3, int a4)
{
  int v8; // r4

  RtlpTraceDatabaseAcquireLock();
  v8 = RtlpTraceDatabaseInternalFind(a1, a2, a3, a4);
  if ( v8 )
    ++*(_DWORD *)(a1 + 80);
  RtlpTraceDatabaseReleaseLock(a1);
  return v8;
}
