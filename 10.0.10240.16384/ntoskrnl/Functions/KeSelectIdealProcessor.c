// KeSelectIdealProcessor 
 
int __fastcall KeSelectIdealProcessor(int a1, int a2, int *a3)
{
  int *v3; // r4
  int result; // r0

  v3 = a3;
  if ( !a3 )
    v3 = (int *)(a1 + 144);
  result = KiSelectIdealProcessor(a1, *v3, a2);
  *v3 = result;
  return result;
}
