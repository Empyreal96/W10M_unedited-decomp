// PopInternalAddToDumpFile 
 
int __fastcall PopInternalAddToDumpFile(int a1, int a2, int a3)
{
  unsigned int v4; // r3

  if ( a1 )
  {
    if ( a2 )
      v4 = ((a1 & 0xFFFu) + a2 + 4095) >> 12;
    else
      v4 = 1;
    IoAddTriageDumpDataBlock(a1 & 0xFFFFF000, v4 << 12);
  }
  if ( a3 )
    PopInternalSaveStackToDumpFile(a3);
  IoAddTriageDumpDataBlock((int)&PopHiberInfo, 128);
  IoAddTriageDumpDataBlock((int)&PopAction, 256);
  if ( dword_61EC94 )
    IoAddTriageDumpDataBlock(dword_61EC94, 260);
  if ( dword_61EC98 )
    IoAddTriageDumpDataBlock(dword_61EC98, 312);
  return IoAddTriageDumpDataBlock((int)&PopCB, 304);
}
