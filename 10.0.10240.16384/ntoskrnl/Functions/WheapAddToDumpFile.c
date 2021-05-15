// WheapAddToDumpFile 
 
int __fastcall WheapAddToDumpFile(int result, int a2)
{
  if ( result )
  {
    if ( (result & 0xFFFFF000) != 0 )
      result = IoAddTriageDumpDataBlock(result & 0xFFFFF000, ((result & 0xFFFu) + a2 + 4095) >> 12 << 12);
  }
  return result;
}
