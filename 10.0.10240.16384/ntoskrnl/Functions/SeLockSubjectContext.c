// SeLockSubjectContext 
 
int __fastcall SeLockSubjectContext(_DWORD *a1)
{
  unsigned int v2; // r3
  int result; // r0
  unsigned int v4; // r2

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  result = ExAcquireResourceSharedLite(*(_DWORD *)(a1[2] + 48), 1);
  if ( *a1 )
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v4 + 308);
    result = ExAcquireResourceSharedLite(*(_DWORD *)(*a1 + 48), 1);
  }
  return result;
}
