// CmpOpenFileWithExtremePrejudice 
 
int __fastcall CmpOpenFileWithExtremePrejudice(_DWORD *a1)
{
  int v2; // r4
  int v4[10]; // [sp+30h] [bp-48h] BYREF

  memset(v4, 0, sizeof(v4));
  *a1 = 0;
  v2 = ZwQueryAttributesFile();
  if ( v2 >= 0 )
  {
    v4[8] &= 0xFFFFFFFE;
    v2 = ZwOpenFile();
    if ( v2 >= 0 )
    {
      v2 = ZwSetInformationFile();
      ZwClose();
      if ( v2 >= 0 )
        v2 = ZwCreateFile();
    }
  }
  return v2;
}
