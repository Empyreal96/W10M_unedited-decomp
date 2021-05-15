// IsSurrogate 
 
BOOL __fastcall IsSurrogate(unsigned int a1)
{
  return a1 >= 0xD800 && a1 <= 0xDFFF;
}
