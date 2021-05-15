// EtwpDisassociateConsumer 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpDisassociateConsumer(int a1, int a2)
{
  int v3; // r1 OVERLAPPED
  _DWORD *v4; // r2 OVERLAPPED
  int v5; // r0

  *(_QWORD *)&v3 = *(_QWORD *)a2;
  if ( *(_DWORD *)(v3 + 4) != a2 || *v4 != a2 )
    sub_7EBB08(a1);
  *v4 = v3;
  *(_DWORD *)(v3 + 4) = v4;
  --*(_DWORD *)(a1 + 264);
  v5 = *(_DWORD *)(a2 + 24);
  *(_BYTE *)(a2 + 50) |= 4u;
  KeSetEvent(v5, 0, 0);
  return ObfDereferenceObject(a2);
}
