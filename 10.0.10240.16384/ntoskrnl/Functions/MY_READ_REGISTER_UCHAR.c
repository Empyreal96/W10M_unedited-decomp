// MY_READ_REGISTER_UCHAR 
 
int __fastcall MY_READ_REGISTER_UCHAR(unsigned __int8 *a1)
{
  __dsb(0xFu);
  return *a1;
}
