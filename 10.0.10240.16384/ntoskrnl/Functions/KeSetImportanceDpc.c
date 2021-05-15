// KeSetImportanceDpc 
 
int __fastcall KeSetImportanceDpc(int result, char a2)
{
  *(_BYTE *)(result + 1) = a2;
  return result;
}
