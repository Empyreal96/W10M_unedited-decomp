// RtlpInterlockedPopEntrySList 
 
int __fastcall RtlpInterlockedPopEntrySList(unsigned __int64 *a1)
{
  unsigned __int64 v1; // r2

  v1 = __ldrexd(a1);
  if ( !(_DWORD)v1 )
    JUMPOUT(0x42335E);
  return ExpInterlockedPopEntrySListFault(a1);
}
