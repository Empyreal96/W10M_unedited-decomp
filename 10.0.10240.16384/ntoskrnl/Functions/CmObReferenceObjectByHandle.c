// CmObReferenceObjectByHandle 
 
int __fastcall CmObReferenceObjectByHandle(int a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int v6; // r4
  _DWORD *v7; // r0
  int result; // r0
  _DWORD *v9; // [sp+8h] [bp-8h] BYREF

  v9 = (_DWORD *)a4;
  v6 = ObReferenceObjectByHandle(a1, a2, a3, a4, (int)&v9, a6);
  v7 = v9;
  *a5 = v9;
  if ( v6 < 0 || *v7 == 1803104306 )
    result = v6;
  else
    result = sub_804B94();
  return result;
}
