// IoCreateFileEx 
 
int __fastcall IoCreateFileEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, _DWORD *a15)
{
  int v15; // r5
  int v19; // lr

  v15 = 0;
  if ( (a14 & 0x800) != 0 )
    v15 = 2;
  v19 = a1;
  if ( a15 )
  {
    if ( a15[2] )
      v15 |= 1u;
    if ( a15[1] )
    {
      FsRtlpValidateExtraCreateParameters();
      v19 = a1;
    }
    if ( a15[3] )
      v15 |= 4u;
  }
  return IopCreateFile(v19, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14 | 0x100, v15, a15);
}
