// CmConvertHandleToKernelHandle 
 
int __fastcall CmConvertHandleToKernelHandle(int a1, int a2, char a3, int a4, _DWORD *a5)
{
  int v7; // r4
  int v9[6]; // [sp+10h] [bp-18h] BYREF

  if ( a1 )
  {
    v7 = ObReferenceObjectByHandle(a1, a4, a2, a3, v9, 0);
    if ( v7 >= 0 )
    {
      v7 = ObOpenObjectByPointer(v9[0], 512, 0, a4, a2, 0, a5);
      ObfDereferenceObject(v9[0]);
    }
  }
  else
  {
    v7 = 0;
    *a5 = 0;
  }
  return v7;
}
