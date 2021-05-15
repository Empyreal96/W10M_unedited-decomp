// MmGetNextNode 
 
int __fastcall MmGetNextNode(int a1, int *a2)
{
  int v2; // r2
  int result; // r0

  v2 = *a2 + 1;
  *a2 = v2;
  if ( v2 == (unsigned __int16)KeNumberNodes )
    result = -1;
  else
    result = sub_5217FC();
  return result;
}
