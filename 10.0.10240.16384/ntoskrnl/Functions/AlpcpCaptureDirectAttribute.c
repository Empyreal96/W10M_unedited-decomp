// AlpcpCaptureDirectAttribute 
 
int __fastcall AlpcpCaptureDirectAttribute(int *a1, int a2, int a3, int a4, int a5)
{
  int result; // r0
  int v8; // r3
  _DWORD _C[11]; // [sp+Ch] [bp-14h] BYREF

  _C[7] = a1;
  _C[8] = a2;
  _C[10] = a4;
  _C[0] = a3;
  _C[1] = a4;
  _C[9] = a3;
  if ( (a4 & 0x10010) != 0 || (a5 & 0x20000000) == 0 )
    result = -1073741811;
  else
    result = 0;
  if ( result >= 0 )
  {
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    {
      result = ObReferenceObjectByHandle(*a1, 2, ExEventObjectType, 1, _C);
      if ( result < 0 )
        return result;
      v8 = _C[0] | 1;
    }
    else
    {
      v8 = *a1;
    }
    *(_DWORD *)(a3 + 28) = v8;
  }
  return result;
}
