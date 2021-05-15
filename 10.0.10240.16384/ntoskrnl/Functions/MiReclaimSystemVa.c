// MiReclaimSystemVa 
 
int __fastcall MiReclaimSystemVa(int result)
{
  if ( result == 1 || (unsigned int)dword_635310 <= 0x8000000 )
    result = sub_510734();
  return result;
}
