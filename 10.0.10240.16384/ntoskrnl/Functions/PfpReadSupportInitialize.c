// PfpReadSupportInitialize 
 
int __fastcall PfpReadSupportInitialize(_BYTE *a1)
{
  memset(a1, 0, 32);
  return PfpOpenHandleInitialize(a1 + 4);
}
