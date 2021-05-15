// SmKmStoreFileDelete 
 
int __fastcall SmKmStoreFileDelete(int a1)
{
  int v2; // r5
  int v3; // r4
  int v5; // [sp+10h] [bp-18h]

  v2 = IoSetThreadHardErrorMode(0);
  v3 = ZwSetInformationFile();
  if ( v3 == 259 )
  {
    KeWaitForSingleObject(*(_DWORD *)(a1 + 4) + 92, 0, 0, 0, 0);
    v3 = v5;
  }
  if ( v3 >= 0 )
    v3 = 0;
  IoSetThreadHardErrorMode(v2);
  return v3;
}
