// PiDqQueryRelease 
 
unsigned int __fastcall PiDqQueryRelease(unsigned int result)
{
  unsigned int v1; // r5
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  unsigned int v5; // r0

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 112);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( !v4 )
  {
    if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x400000) != 0 )
    {
      result = sub_7C80B0();
    }
    else
    {
      PiDqQueryFreeActiveData(result);
      v5 = *(_DWORD *)(v1 + 12);
      if ( v5 )
        ExFreePoolWithTag(v5);
      if ( *(_DWORD *)(v1 + 8) )
        MesHandleFree_0();
      SeReleaseSubjectContext(v1 + 16);
      result = ExFreePoolWithTag(v1);
    }
  }
  return result;
}
