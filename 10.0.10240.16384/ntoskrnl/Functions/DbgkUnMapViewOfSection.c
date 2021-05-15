// DbgkUnMapViewOfSection 
 
int __fastcall DbgkUnMapViewOfSection(int result)
{
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A)
    && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 4) == 0 )
  {
    if ( *(_DWORD *)(result + 340) )
      result = sub_7E8FEC();
  }
  return result;
}
