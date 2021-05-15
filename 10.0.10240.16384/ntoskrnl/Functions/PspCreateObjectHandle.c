// PspCreateObjectHandle 
 
int __fastcall PspCreateObjectHandle(int a1, int a2, int a3)
{
  int result; // r0
  _DWORD *v5; // r3

  result = ObOpenObjectByPointer(
             a1,
             *(_DWORD *)(a2 + 312),
             (char *)a2,
             0,
             a3,
             *(_BYTE *)(a2 + 316),
             (_DWORD *)(a2 + 320));
  if ( result >= 0 )
  {
    v5 = **(_DWORD ***)(a2 + 48);
    if ( v5 )
    {
      if ( *v5 )
        result = sub_80348C();
    }
  }
  return result;
}
