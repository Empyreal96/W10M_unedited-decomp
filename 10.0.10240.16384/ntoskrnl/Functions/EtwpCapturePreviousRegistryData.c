// EtwpCapturePreviousRegistryData 
 
int __fastcall EtwpCapturePreviousRegistryData(__int64 *a1)
{
  __int64 v2; // kr00_8
  int v3; // r0
  int result; // r0
  int v5; // [sp+14h] [bp-14h] BYREF
  __int64 v6; // [sp+18h] [bp-10h]

  v2 = *a1;
  v5 = 0;
  v6 = *(_QWORD *)HIDWORD(v2);
  if ( ObOpenObjectByPointer(v2, 512, 0, 131097, (int)CmKeyObjectType, 0, &v5) >= 0 )
  {
    do
    {
      do
        v3 = ZwQueryValueKey();
      while ( v3 == -2147483643 );
    }
    while ( v3 == -1073741789 );
    if ( v3 >= 0 )
      *((_DWORD *)a1 + 6) = 0;
  }
  result = v5;
  if ( v5 )
    result = ZwClose();
  return result;
}
