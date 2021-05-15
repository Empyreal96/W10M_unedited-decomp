// EtwpPrepareDirtyBuffer 
 
int __fastcall EtwpPrepareDirtyBuffer(int a1, int a2)
{
  __int64 v3; // r0

  if ( (*(_DWORD *)(a1 + 12) & 0x400) != 0 )
  {
    LODWORD(v3) = EtwpEnqueueFreeBuffer(a1, a2);
  }
  else
  {
    *(_DWORD *)(a2 + 44) = 3;
    v3 = ((__int64 (*)(void))*(_DWORD *)(a1 + 32))();
    *(_QWORD *)(a2 + 16) = v3;
  }
  return v3;
}
