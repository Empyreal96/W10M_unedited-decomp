// RtlpInsertStringAtom 
 
int __fastcall RtlpInsertStringAtom(int a1)
{
  int result; // r0

  if ( ExCreateHandleEx(*(_DWORD *)(a1 + 12)) )
    result = sub_7C01E0();
  else
    result = 0;
  return result;
}
