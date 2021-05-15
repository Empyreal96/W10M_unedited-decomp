// PfTFullEventListAdd 
 
int __fastcall PfTFullEventListAdd(_DWORD *a1)
{
  int result; // r0

  for ( result = RtlpInterlockedPushEntrySList((unsigned __int64 *)&unk_643A50, a1);
        (unsigned __int16)word_643A54 > (unsigned int)dword_643A58;
        result = PfFbBufferListInsertInFree(
                   &unk_643A00,
                   result,
                   *(_DWORD *)(result + 12) - result,
                   *(_DWORD *)(result + 20)) )
  {
    result = RtlpInterlockedPopEntrySList((unsigned __int64 *)&unk_643A50);
    if ( !result )
      break;
  }
  return result;
}
