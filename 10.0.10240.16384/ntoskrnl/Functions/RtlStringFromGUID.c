// RtlStringFromGUID 
 
int __fastcall RtlStringFromGUID(int a1, int a2)
{
  return RtlStringFromGUIDEx(a1, a2, 1);
}
