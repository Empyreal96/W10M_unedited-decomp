// PspSetProcessSchedulingGroup 
 
int __fastcall PspSetProcessSchedulingGroup(int result, int a2)
{
  int v2; // r5
  int v3; // r6

  v2 = result;
  v3 = *(_DWORD *)(result + 192) & 8;
  if ( !v3 || !a2 )
    result = KeSetProcessSchedulingGroup(result, a2);
  if ( v3 != (*(_DWORD *)(v2 + 192) & 8) )
    result = sub_7C25F0(result);
  return result;
}
