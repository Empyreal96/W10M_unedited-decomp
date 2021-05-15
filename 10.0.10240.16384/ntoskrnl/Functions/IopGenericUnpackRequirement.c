// IopGenericUnpackRequirement 
 
int __fastcall IopGenericUnpackRequirement(int a1, _DWORD *a2, _DWORD *a3, _QWORD *a4, _DWORD *a5)
{
  __int64 v7; // r0
  int result; // r0

  LODWORD(v7) = RtlIoDecodeMemIoResource(a1, a5, a2, a3);
  *a4 = v7;
  if ( !*(_QWORD *)a5 )
  {
    *a5 = 1;
    a5[1] = 0;
  }
  if ( *(_BYTE *)(a1 + 1) == 3 && (*(_WORD *)(a1 + 4) & 0x10) != 0 )
    result = sub_80E658();
  else
    result = 0;
  return result;
}
