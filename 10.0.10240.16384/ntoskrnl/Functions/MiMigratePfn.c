// MiMigratePfn 
 
int __fastcall MiMigratePfn(int a1, int a2, int a3)
{
  int result; // r0

  if ( (unsigned __int16)KeNumberNodes <= 1u )
    result = a3;
  else
    result = sub_532B00();
  return result;
}
