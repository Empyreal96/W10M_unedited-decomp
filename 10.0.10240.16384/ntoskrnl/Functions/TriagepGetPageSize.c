// TriagepGetPageSize 
 
int __fastcall TriagepGetPageSize(int a1)
{
  if ( a1 != 332 && a1 != 452 )
  {
    if ( a1 == 512 )
      return 0x2000;
    if ( a1 != 34404 )
      return -1;
  }
  return 4096;
}
