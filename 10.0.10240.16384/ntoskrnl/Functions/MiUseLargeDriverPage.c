// MiUseLargeDriverPage 
 
int MiUseLargeDriverPage()
{
  int result; // r0

  if ( MmGetNumberOfFreeSystemPtes() < 0x4000 || (MiFlags & 0x30000) != 0 )
    goto LABEL_6;
  if ( byte_632F2D )
    JUMPOUT(0x7CDF98);
  if ( (int *)dword_632F34 == &dword_632F34 )
LABEL_6:
    result = 0;
  else
    result = sub_7CDF84();
  return result;
}
