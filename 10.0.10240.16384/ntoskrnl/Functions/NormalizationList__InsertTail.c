// NormalizationList__InsertTail 
 
int __fastcall NormalizationList__InsertTail(int result)
{
  void ***v1; // r1

  v1 = (void ***)off_6185B4;
  *(_DWORD *)result = &NormalizationListHead;
  *(_DWORD *)(result + 4) = v1;
  if ( *v1 != &NormalizationListHead )
    __fastfail(3u);
  *v1 = (void **)result;
  off_6185B4 = (void **)result;
  return result;
}
