// MiVadIsCfgBitmap 
 
int __fastcall MiVadIsCfgBitmap(int a1)
{
  unsigned int v1; // r2

  __mrc(15, 0, 13, 0, 3);
  v1 = 0;
  while ( *(_DWORD *)(v1 - 1069538988) != a1 )
  {
    v1 += 12;
    if ( v1 >= 0xC )
      return 0;
  }
  return 1;
}
