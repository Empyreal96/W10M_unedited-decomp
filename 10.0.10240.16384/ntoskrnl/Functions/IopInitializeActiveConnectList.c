// IopInitializeActiveConnectList 
 
void IopInitializeActiveConnectList()
{
  ActiveConnectList = (int)&ActiveConnectList;
  dword_630CCC = (int)&ActiveConnectList;
  ActiveConnectListLock = 1;
  byte_630CD1 = 0;
  byte_630CD2 = 4;
  dword_630CD4 = 1;
  dword_630CDC = (int)&dword_630CD8;
  dword_630CD8 = (int)&dword_630CD8;
}
