// AlpcpCaptureViewAttribute 
 
int __fastcall AlpcpCaptureViewAttribute(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r6
  _DWORD _8[16]; // [sp+8h] [bp-28h] BYREF

  _8[13] = a2;
  _8[15] = a4;
  _8[14] = a3;
  _8[12] = a1;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v4 = a2[1];
    v5 = a2[2];
    v6 = a2[3];
    _8[0] = *a2;
    _8[1] = v4;
    _8[2] = v5;
    _8[3] = v6;
    a2 = _8;
  }
  return AlpcpCaptureViewAttributeInternal(a1, a2, a3, a4);
}
