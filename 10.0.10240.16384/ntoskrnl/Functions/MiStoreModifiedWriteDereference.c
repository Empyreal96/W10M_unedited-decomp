// MiStoreModifiedWriteDereference 
 
int __fastcall MiStoreModifiedWriteDereference(int result)
{
  int v1; // r4
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  __int64 v5; // r2

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 24);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( !v4 )
  {
    LODWORD(v5) = 0;
    HIDWORD(v5) = *(_DWORD *)(result + 148);
    *(_QWORD *)(result + 8) = v5;
    KeInitializeApc(
      result + 28,
      *(_DWORD *)(*(_DWORD *)(result + 120) + 560),
      3,
      (int)MiStoreWriteModifiedCompleteApc,
      0,
      0,
      0,
      0);
    result = KeInsertQueueApc(v1 + 28, v1, 0, 0);
  }
  return result;
}
