// RtlTraceDatabaseDestroy 
 
int __fastcall RtlTraceDatabaseDestroy(int a1)
{
  int v1; // r0
  int v2; // r4

  v1 = *(_DWORD *)(a1 + 12);
  if ( v1 )
  {
    do
    {
      v2 = *(_DWORD *)(v1 + 8);
      if ( !v2 )
        v1 -= 148;
      ExFreePoolWithTag(v1);
      v1 = v2;
    }
    while ( v2 );
  }
  return 1;
}
