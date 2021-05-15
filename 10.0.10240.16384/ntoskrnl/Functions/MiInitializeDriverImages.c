// MiInitializeDriverImages 
 
int MiInitializeDriverImages()
{
  dword_632F30 = -1;
  dword_632F40[0] = 0;
  dword_632F38 = (int)&dword_632F34;
  dword_632F34 = (int)&dword_632F34;
  if ( MmLargePageDriverBufferLength == -1 )
    JUMPOUT(0x9698BC);
  return sub_96981C();
}
