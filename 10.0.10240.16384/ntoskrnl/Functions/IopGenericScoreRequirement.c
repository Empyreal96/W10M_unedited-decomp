// IopGenericScoreRequirement 
 
unsigned int __fastcall IopGenericScoreRequirement(int a1)
{
  __int64 v1; // r0
  unsigned int result; // r0
  __int64 v3; // r0
  int v4; // r2
  __int64 v5; // [sp+0h] [bp-30h] BYREF
  __int64 v6; // [sp+8h] [bp-28h] BYREF
  __int64 v7[4]; // [sp+10h] [bp-20h] BYREF

  LODWORD(v1) = RtlIoDecodeMemIoResource(a1, &v5, &v6, v7);
  if ( !v5 )
    return sub_80E388();
  LODWORD(v3) = _rt_udiv64(v5, v7[0] - ((v6 + v5 - 1) & ~(v5 - 1)) - v1 + 1);
  v4 = (unsigned __int64)(v3 + 1) >> 32;
  result = v3 + 1;
  if ( v4 <= 0 && v4 < 0 )
    return -1;
  if ( v4 > 0 || result > 0x7FFFFFFF )
    result = 0x7FFFFFFF;
  return result;
}
