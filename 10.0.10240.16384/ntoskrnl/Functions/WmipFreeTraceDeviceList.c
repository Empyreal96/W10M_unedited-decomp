// WmipFreeTraceDeviceList 
 
unsigned int __fastcall WmipFreeTraceDeviceList(int *a1, int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  int *v4; // r5
  int v5; // t1

  v2 = a2;
  v3 = (unsigned int)a1;
  if ( a2 )
  {
    v4 = a1;
    do
    {
      v5 = *v4;
      v4 += 2;
      WmipUnreferenceRegEntry(v5);
      --v2;
    }
    while ( v2 );
  }
  return ExFreePoolWithTag(v3);
}
