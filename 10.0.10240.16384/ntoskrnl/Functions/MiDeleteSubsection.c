// MiDeleteSubsection 
 
int __fastcall MiDeleteSubsection(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(*(_DWORD *)a1 + 28) & 0x40000000) != 0 )
    result = sub_527110();
  else
    result = ExFreePoolWithTag(a1, 0);
  return result;
}
