// PsLocateSystemDlls 
 
int PsLocateSystemDlls()
{
  void **v1; // r4
  int i; // r5
  int v3; // r0

  if ( ExVerifySuite(6) )
    return sub_81B000();
  v1 = &PspSystemDlls;
  for ( i = 0; i <= 1; ++i )
  {
    if ( *v1 )
    {
      v3 = PspLocateSystemDll();
      if ( v3 < 0 && (*((_DWORD *)*v1 + 2) & 1) != 0 )
        KeBugCheckEx(107, v3, 2, i, 0);
    }
    ++v1;
  }
  return 0;
}
