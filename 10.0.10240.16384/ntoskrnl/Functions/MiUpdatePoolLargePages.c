// MiUpdatePoolLargePages 
 
int MiUpdatePoolLargePages()
{
  return MiMarkLargeNonPagedPool(
           ((((((unsigned int)MmSystemRangeStart >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC) - 0x40000000,
           -1070592004,
           1);
}
