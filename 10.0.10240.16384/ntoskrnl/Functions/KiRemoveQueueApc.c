// KiRemoveQueueApc 
 
int __fastcall KiRemoveQueueApc(int a1)
{
  int result; // r0

  if ( *(_BYTE *)(a1 + 46) )
    result = sub_523718();
  else
    result = *(unsigned __int8 *)(a1 + 46);
  return result;
}
