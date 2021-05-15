// RtlpInterlockedPushEntrySList 
 
int __fastcall RtlpInterlockedPushEntrySList(unsigned __int64 *a1, _DWORD *a2)
{
  unsigned __int64 v2; // r2
  unsigned __int64 v3; // r4

  do
  {
    do
    {
      v2 = *a1;
      *a2 = *(_DWORD *)a1;
      __dmb(0xBu);
      v3 = __ldrexd(a1);
    }
    while ( v2 != v3 );
  }
  while ( __strexd(__PAIR64__(HIDWORD(v2) + 1, (unsigned int)a2), a1) == 1 );
  return v2;
}
