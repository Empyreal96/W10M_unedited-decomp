// CmpMarkKcbDeleted 
 
int __fastcall CmpMarkKcbDeleted(_DWORD *a1)
{
  int v2; // r3
  _DWORD *v3; // r1
  int v4; // r0
  int result; // r0

  v2 = a1[1];
  v3 = a1 + 3;
  v4 = a1[5];
  a1[1] = v2 | 0x20000;
  result = CmpRemoveKeyHash(v4, v3);
  a1[4] = -1;
  return result;
}
