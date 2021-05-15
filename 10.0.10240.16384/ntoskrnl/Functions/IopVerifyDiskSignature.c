// IopVerifyDiskSignature 
 
int __fastcall IopVerifyDiskSignature(_DWORD *a1, int a2, _DWORD *a3)
{
  if ( *(_BYTE *)(a2 + 20) )
  {
    if ( !*a1 && *(_DWORD *)(a2 + 8) == a1[2] )
      return 1;
    if ( *a1 == 1 && *(_BYTE *)(a2 + 22) && !memcmp(a2 + 24, (unsigned int)(a1 + 2), 16) )
    {
      if ( a3 )
        *a3 = 0;
      return 1;
    }
  }
  return 0;
}
