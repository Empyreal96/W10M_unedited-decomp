// RtlpImageDirectoryEntryToDataEx 
 
int __fastcall RtlpImageDirectoryEntryToDataEx(unsigned int a1, int a2, int a3, int a4, _DWORD *a5)
{
  unsigned int v5; // r4

  *a5 = 0;
  v5 = a1;
  if ( (a1 & 3) != 0 )
    v5 = a1 & 0xFFFFFFFC;
  return RtlImageNtHeaderEx(1, v5, 0, 0);
}
