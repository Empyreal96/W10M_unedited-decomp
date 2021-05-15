// KeVerifyContextRecord 
 
int __fastcall KeVerifyContextRecord(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(*(_DWORD *)(a1 + 336) + 100) & 0x20) != 0 )
    result = sub_54796C();
  else
    result = 0;
  return result;
}
