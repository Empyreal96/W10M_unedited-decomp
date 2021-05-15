// CmpDeleteKeyObject 
 
int __fastcall CmpDeleteKeyObject(int result)
{
  int v1; // r1
  _DWORD v2[20]; // [sp+18h] [bp-50h] BYREF

  v1 = *(_DWORD *)(result + 24);
  v2[2] = 0;
  v2[3] = 0;
  v2[4] = 0;
  v2[5] = 0;
  v2[0] = v2;
  v2[1] = v2;
  if ( (v1 & 4) == 0 )
    result = sub_7FEEFC();
  return result;
}
