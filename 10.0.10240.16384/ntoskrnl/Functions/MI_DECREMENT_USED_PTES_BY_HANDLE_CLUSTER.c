// MI_DECREMENT_USED_PTES_BY_HANDLE_CLUSTER 
 
unsigned int __fastcall __spoils<R0,R2,R3,R12> MI_DECREMENT_USED_PTES_BY_HANDLE_CLUSTER(_WORD *a1, __int16 a2)
{
  unsigned int result; // r0

  result = (unsigned __int16)(*a1 - a2);
  if ( result >= 0x400 )
    sub_524CDC();
  *a1 = result;
  return result;
}
