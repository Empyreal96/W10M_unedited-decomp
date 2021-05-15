// IopFileUtilClearAttributes 
 
int IopFileUtilClearAttributes()
{
  int v0; // r4
  unsigned int v1; // r4
  int v3[10]; // [sp+30h] [bp-38h] BYREF

  v0 = ZwOpenFile();
  if ( v0 >= 0 )
  {
    v0 = ZwQueryInformationFile();
    if ( v0 >= 0 && (v3[8] & 7) != 0 )
    {
      v1 = v3[8] & 0xFFFFFFF8;
      if ( (v3[8] & 0xFFFFFFF8) == 0 )
        v1 = 128;
      memset(v3, 0, sizeof(v3));
      v3[8] = v1;
      v0 = ZwSetInformationFile();
    }
    ZwClose();
  }
  return v0;
}
