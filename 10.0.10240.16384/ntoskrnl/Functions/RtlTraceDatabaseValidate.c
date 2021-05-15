// RtlTraceDatabaseValidate 
 
int __fastcall RtlTraceDatabaseValidate(int a1)
{
  int v2; // r1
  int v3; // r2

  RtlpTraceDatabaseAcquireLock();
  v2 = *(_DWORD *)(a1 + 64);
  if ( v2 )
  {
    v3 = *(_DWORD *)(a1 + 68);
    do
    {
      v3 += 4;
      --v2;
    }
    while ( v2 );
  }
  RtlpTraceDatabaseReleaseLock(a1);
  return 1;
}
