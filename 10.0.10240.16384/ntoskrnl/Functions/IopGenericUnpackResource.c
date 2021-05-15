// IopGenericUnpackResource 
 
int __fastcall IopGenericUnpackResource(int a1, _DWORD *a2, _QWORD *a3)
{
  __int64 v4; // r0

  LODWORD(v4) = RtlCmDecodeMemIoResource(a1, a2);
  *a3 = v4;
  return 0;
}
