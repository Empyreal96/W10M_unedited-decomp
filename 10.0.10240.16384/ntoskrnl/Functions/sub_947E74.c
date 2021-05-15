// sub_947E74 
 
void __noreturn sub_947E74()
{
  unsigned int *v0; // r2
  unsigned int v1; // r1
  __int64 v2; // r0
  int v3; // r0
  unsigned int *v4; // [sp+Ch] [bp-Ch] BYREF

  v4 = (unsigned int *)((char *)&v4 + 3);
  __dmb(0xBu);
  v0 = v4;
  do
    v1 = __ldrex(v0);
  while ( !v1 && __strex(0, v0) );
  __dmb(0xBu);
  v2 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
  if ( v2 )
  {
    if ( v2 == 1 )
      v3 = __ROR4__(-2147483490, 31);
    else
      v3 = __ROR4__(634, 1);
  }
  else
  {
    v3 = __ROR4__(162304, 9);
  }
  KeBugCheckEx(v3, 7, 0, 0, 0);
}
