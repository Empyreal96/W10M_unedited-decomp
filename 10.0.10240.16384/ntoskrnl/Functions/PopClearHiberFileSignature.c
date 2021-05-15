// PopClearHiberFileSignature 
 
void PopClearHiberFileSignature()
{
  int v0[6]; // [sp+20h] [bp-28h] BYREF

  if ( dword_61EEA4 )
  {
    memset(v0, 0, sizeof(v0));
    v0[1] = 1;
    v0[2] = 4096;
    v0[3] = 0;
    v0[4] = -4097;
    v0[5] = -1;
    if ( ZwFsControlFile() == 259 )
      KeWaitForSingleObject(dword_61EEA4 + 92, 0, 0, 0, 0);
  }
}
