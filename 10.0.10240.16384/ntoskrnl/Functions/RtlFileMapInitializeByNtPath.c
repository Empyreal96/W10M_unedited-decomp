// RtlFileMapInitializeByNtPath 
 
int __fastcall RtlFileMapInitializeByNtPath(int a1)
{
  int v2; // r4

  v2 = ZwCreateFile();
  if ( v2 >= 0 )
  {
    *(_BYTE *)(a1 + 28) = 1;
    *(_DWORD *)a1 = 0;
    v2 = 0;
  }
  return v2;
}
